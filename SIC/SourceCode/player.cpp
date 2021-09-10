#include "all.h"


int PlayerState;
float fade;
int score;
OBJ2D player;
VECTOR2 scroll;
VECTOR2 MousePos;
POINT mouse;


void player_moveX(OBJ2D* player)
{
	player->pos.x += player->speed.x;
	if (STATE(0) & PAD_RIGHT && !(STATE(0) & PAD_LEFT)) {
		player->speed.x += 0.3f;
		if (TRG(0) & PAD_RIGHT && player->scale.x < 0)
			player->scale.x *= -1.0f;
	}
	else if (STATE(0) & PAD_LEFT && !(STATE(0) & PAD_RIGHT)) {
		player->speed.x -= 0.3f;
		if (TRG(0) & PAD_LEFT && player->scale.x > 0)
			player->scale.x *= -1.0f;
	}
	if (player->pos.x < player->HalfSize.x) {
		player->pos.x = player->HalfSize.x;
		player->speed.x = 0;
	}
	if (player->pos.x > SCREEN_W - player->HalfSize.x) {
		player->pos.x = SCREEN_W - player->HalfSize.x;
		player->speed.x = 0;
	}

	player->speed.x *= 0.98f;
}
void player_moveY(OBJ2D* player)
{
	player->pos.y += player->speed.y;
	player->speed.y += GRAVITY; // 実質的にアクセルの加減として機能する
	
	if (!(STATE(0) & PAD_TRG1) && player->speed.y > (MAX_SPEED_Y + GRAVITY) / 4)
		player->speed.y -= GRAVITY * 2; //ブレーキの加減
	if (player->speed.y > MAX_SPEED_Y)
		player->speed.y = MAX_SPEED_Y;

	//HACK:暫定的な地面の実装のため改修が必要
	if (player->pos.y > SCREEN_H * 42/*masicNumber*/)
	{		  
		player->pos.y = SCREEN_H * 42;
		player->speed.y = 0.0f;
		player->OnGround = true;
	}

#if _DEBUG
	if (STATE(0) & PAD_UP)
	{
		player->speed.y -= GRAVITY * 4;
	}
#endif // _DEBUG


}

bool HitCheck(OBJ2D* player, OBJ2D* enemy)
{
	if (player->InvincibleTimer)
		return false;
	float PlLeft = player->pos.x - player->HalfSize.x + 1;
	float PlRight = player->pos.x + player->HalfSize.x - 1;
	float PlTop = player->pos.y - player->HalfSize.y + MAPCHIP_HALFSIZE;
	float PlBott = player->pos.y + player->HalfSize.y;

	float EnemyLeft = enemy->pos.x - enemy->HalfSize.x;
	float EnemyRight = enemy->pos.x + enemy->HalfSize.x;
	float EnemyTop = enemy->pos.y - enemy->HalfSize.y;
	float EnemyBott = enemy->pos.y + enemy->HalfSize.y;

	if (PlRight < EnemyLeft)return false;
	if (PlLeft >  EnemyRight)return false;
	if (PlBott <  EnemyTop)return false;
	if (PlTop >   EnemyBott)return false;

	return true;
}
int EnIntoCheck(VECTOR2 mousepos, OBJ2D enemy[], int EnMax)
{
	for (int i = 0; i < EnMax; ++i)
	{
		if (enemy[i].MoveAlg == -1) continue;
		float EnemyLeft =  enemy[i].pos.x - enemy[i].HalfSize.x;
		float EnemyRight = enemy[i].pos.x + enemy[i].HalfSize.x;
		float EnemyTop = enemy[i].pos.y - enemy[i].HalfSize.y;
		float EnemyBott = enemy[i].pos.y + enemy[i].HalfSize.y;

		if (mousepos.x < EnemyLeft) continue;
		if (mousepos.x > EnemyRight)continue;
		if (mousepos.y < EnemyTop)  continue;
		if (mousepos.y > EnemyBott) continue;

		return i;
	}
	return -1;

}


void player_update()
{
	switch (PlayerState)
	{
	case 0:
		//初期設定
		++PlayerState;
		//fallthrough
	case 1:
		//パラメータの設定
		player = {};
		player.pos = { SCREEN_W / 2 , SCREEN_H / 2 };
		player.HalfSize = { MAPCHIP_HALFSIZE, MAPCHIP_HALFSIZE };
		player.HitPoint = 3;
		player.color.z = 0;
		player.area = cursor;
		++PlayerState;
		//fallthrough
	case 2: 
		//loop
		player_moveX(&player);
		player_moveY(&player);
		debug::setString("posx%f", player.pos.x);
		debug::setString("posy%f", player.pos.y);
		debug::setString("OnGround%d", player.OnGround);
		debug::setString("fade%f", fade);
		debug::setString("speedY%f", player.speed.y);
		debug::setString("HP%d", player.HitPoint);
		
		GetCursorPos(&mouse);
		ScreenToClient(window::getHwnd(), &mouse);
		MousePos.x = mouse.x;
		MousePos.y = mouse.y;
		MousePos += scroll;

		if (player.InvincibleTimer > 0)
			--player.InvincibleTimer;
		if (player.OnGround)
		{
			score = player.pos.y;
		}
		if (fade > 1)
		{
			nextScene = SCENE_RESULT;
			fade = 0;
			player.OnGround = false;
		}
		if (!player.HitPoint)
		{
			game_reset();

		}
#if _DEBUG
		if (TRG(0) & PAD_TRG4)game_reset();
#endif;
		

		
		int EnNo = EnIntoCheck(MousePos, enemy, ENEMY_MAX);
		switch (EnNo)
		{
		case -1:
			break;
		default:
			if (TRG(0) & PAD_L1)
			{
				enemy[EnNo].MoveAlg = -1;
				//HACK:仮の敵消去処理
			}
			break;
		}

	}
}

void player_render()
{
	primitive::rect(
		player.pos - scroll, player.HalfSize * 2,
		player.HalfSize,
		player.angle,
		{ 1,0,player.color.z,1 }
	);
	if (player.OnGround)
	{
		fadeout();
	}
}

void player_init()
{
	fade = 0;
}

void player_deinit()
{

}

void fadeout()
{
	primitive::rect(
		0, 0,
		SCREEN_W, SCREEN_H,
		0, 0,
		0,
		1, 1, 1, fade
	);
	fade += 0.008f;
}