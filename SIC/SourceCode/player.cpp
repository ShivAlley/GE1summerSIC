#include "all.h"


int PlayerState;
float fade;
int score;
OBJ2D player;
VECTOR2 scroll;


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

}

bool HitCheck(OBJ2D* player, OBJ2D* enemy)
{
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
		

		if (player.OnGround)
		{
			fade += 0.008f;
			score = player.pos.y;
		}
		if (fade > 1)
		{
			nextScene = SCENE_RESULT;
			fade = 0;
			player.OnGround = false;
		}


	}
}

void player_render()
{
	primitive::rect(
		player.pos - scroll, player.HalfSize * 2,
		player.HalfSize,
		player.angle,
		{ 1,0,0,1 }
	);
	if (player.OnGround)
	{
		primitive::rect(
			0, 0,
			SCREEN_W, SCREEN_H,
			0, 0,
			0,
			1, 1, 1, fade
		);
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
	
}