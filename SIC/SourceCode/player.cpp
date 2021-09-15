#include "all.h"



int PlayerState;
float fade;
int score;
OBJ2D player;
VECTOR2 scroll;
VECTOR2 MousePos;
POINT mouse;
Sprite* playerSpr;





void player_moveX()
{
	if (STATE(0) & PAD_RIGHT && !(STATE(0) & PAD_LEFT)) {
		player.speed.x += 0.3f;
	}
	else if (STATE(0) & PAD_LEFT && !(STATE(0) & PAD_RIGHT)) {
		player.speed.x -= 0.3f;
	}
	if (player.pos.x < player.HalfSize.x * 2) {
		player.pos.x = player.HalfSize.x * 2;
		player.speed.x = 0;
	}
	if (player.pos.x > SCREEN_W - player.HalfSize.x) {
		player.pos.x = SCREEN_W - player.HalfSize.x;
		player.speed.x = 0;
	}

	player.speed.x *= 0.98f;
	player.pos.x += player.speed.x;
}



void player_moveY()
{
	player.speed.y += GRAVITY; // ƒAƒNƒZƒ‹
	if (!(STATE(0) & PAD_SPACE) && player.speed.y > MAX_SPEED_Y / 4)
		player.speed.y -= GRAVITY * 2; //deccle
	
	
	if (player.pos.y > mapHeight[player.area])
	{
		player.pos.y = mapHeight[player.area];
		player.speed.y = 0.0f;
		player.OnGround = true;
	}
	
	player.pos.y += player.speed.y;
	score += player.speed.y;
	if (player.speed.y > MAX_SPEED_Y)
		player.speed.y = MAX_SPEED_Y;
	
#if _DEBUG
	if (STATE(0) & PAD_UP)
	{
		player.speed.y -= GRAVITY * 4;
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
		if (enemy[i].MoveAlg == 2) continue;
		if (enemy[i].MoveAlg == 3) continue;
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
		//ini setting
		//player.spr = sprite_load(L"./Data/Images/chara_marged.png");
		playerSpr = sprite_load(L"./Data/Images/chara_marged.png");
		++PlayerState;
		//fallthrough
	case 1:
		//param set
		player = {}; //if .spr ignore can use player.spr member
		player.HalfSize = VECTOR2(PLAYER_CHIP_HALFSIZE, PLAYER_CHIP_SIZE);
		player.scale = VECTOR2(
			1.0f / (PLAYER_TEX_W / (player.HalfSize.x * 2)),
			1.0f / (PLAYER_TEX_H / (player.HalfSize.y * 2)));
		//common.h "#define player_chip_size" can change player size
		player.TexPos = VECTOR2(0, 0); 
		player.TexSize = VECTOR2(PLAYER_TEX_W, PLAYER_TEX_H);
		player.pivot = VECTOR2(PLAYER_PIVOT_X, PLAYER_PIVOT_Y);
		player.pos = VECTOR2(SCREEN_W / 2, player.HalfSize.y);
		player.HitPoint = 3;
		player.color.z = 0;
		player.area = cursor;
		score = 0;
		++PlayerState;

		//fallthrough
	case 2: 
	{
		//loop
		player_act();
		debug::setString("scalex%f", player.scale.x);
		debug::setString("scaley%f", player.scale.y);
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
			fadeout();
		if (!player.HitPoint)
		{
			game_reset();
		}
		int EnNo = EnIntoCheck(MousePos, enemy, ENEMY_MAX);
		if (EnNo != -1 && (TRG(0) & PAD_MOUSE1))
		{
			enemy[EnNo].MoveAlg = -1;
			//HACK:temporary enemy kill
		}

		

#if _DEBUG
		if (TRG(0) & PAD_KB_R)game_reset();
		if ((STATE(0) & PAD_LEFT) && (STATE(0) & PAD_RIGHT) && (STATE(0) & PAD_DOWN) && (TRG(0) & PAD_SPACE))
			++PlayerState;
			//toggle god mode
		break;
	}//case2block
	case 3:
		player.pos.x = (int)player.pos.x;
		player.pos.y = (int)player.pos.y;
		player.pos.x += player.speed.x;

		if (STATE(0) & PAD_UP2 && !(STATE(0) & PAD_LSHIFT))
			player.speed.y += -1;
		else if (STATE(0) & PAD_DOWN2 && !(STATE(0) & PAD_LSHIFT))
			player.speed.y += 1;
		else if ((STATE(0) & PAD_LSHIFT) && (TRG(0) & PAD_UP2))
			player.speed.y = -1.0f;
		else if ((STATE(0) & PAD_LSHIFT) && (TRG(0) & PAD_DOWN2))
			player.speed.y = 1.0f;
		else
			player.speed.y = 0;

		player.pos.y += player.speed.y;
		if (STATE(0) & PAD_LEFT2 && !(STATE(0) & PAD_LSHIFT))
			player.speed.x += -1;
		else if (STATE(0) & PAD_RIGHT2 && !(STATE(0) & PAD_LSHIFT))
			player.speed.x += 1;
		else if ((STATE(0) & PAD_LSHIFT) && (TRG(0) & PAD_LEFT2))
			player.speed.x = -1.0f;
		else if ((STATE(0) & PAD_LSHIFT) && (TRG(0) & PAD_RIGHT2))
			player.speed.x = 1.0f;
		else
			player.speed.x = 0;

		if (player.pos.x < player.HalfSize.x * 4) {
			player.pos.x = player.HalfSize.x * 4;
			
		}
		if (player.pos.x > SCREEN_W - player.HalfSize.x * 4) {
			player.pos.x = SCREEN_W - player.HalfSize.x * 4;
			
		}//prevent enemy stack on spawn

		debug::setString("god mode is enabled");
		debug::setString("0~4 : enemy set");
		debug::setString("posx%f", player.pos.x);
		debug::setString("posy%f", player.pos.y);

		if (TRG(0) & PAD_R0) OutEnSetText(0); 
		if (TRG(0) & PAD_R1) OutEnSetText(1); 
		if (TRG(0) & PAD_R2) OutEnSetText(2); 
		if (TRG(0) & PAD_R3) OutEnSetText(3); 
		if (TRG(0) & PAD_R4) OutEnSetText(4); 
		if ((STATE(0) & PAD_LEFT) && (STATE(0) & PAD_RIGHT) && (STATE(0) & PAD_DOWN) && (TRG(0) & PAD_SPACE))
			--PlayerState;
			//force fallback
		break;
#endif

	}
	++player.timer;
}


void tuto_end()
{
	primitive::rect(
		0, 0,
		SCREEN_W, SCREEN_H,
		0, 0,
		0,
		1, 1, 1, fade
	);
	fade += 0.008f;
	if (fade > 1)
		nextScene = SCENE_MENU;
}

void tuto_text_render()
{
	if (player.area == 0)
	{
		if (player.pos.y < 4000)
			text_out(
				1, "A or D to move",
				player.pos.x - player.HalfSize.x * 10 - scroll.x, player.pos.y - player.HalfSize.y * 2 - scroll.y,
				0.75f, 1,
				1, 1, 0, 1
			);
		if (player.pos.y > 4000 && player.pos.y < 10000)
			text_out(
				1, "SPACE to acceleration",
				player.pos.x - player.HalfSize.x * 10 - scroll.x, player.pos.y - player.HalfSize.y * 2 - scroll.y,
				0.75f, 1,
				1, 1, 0, 1
			);
		if (player.pos.y > 10000 && player.pos.y < 15000)
			text_out(
				1, "LEFT CLICK to can cut enemy",
				player.pos.x - player.HalfSize.x * 10 - scroll.x, player.pos.y - player.HalfSize.y * 2 - scroll.y,
				0.75f, 1,
				1, 1, 0, 1
			);
		if (player.pos.y > 15000 && player.pos.y < 25000)
			text_out(
				1, "correct more letters!",
				player.pos.x - player.HalfSize.x * 10 - scroll.x, player.pos.y - player.HalfSize.y * 2 - scroll.y,
				0.75f, 1,
				1, 1, 0, 1
			);
		if (player.pos.y > 25000 && player.pos.y < 30000)
			text_out(
				1, "good luck!",
				player.pos.x - player.HalfSize.x * 10 - scroll.x, player.pos.y - player.HalfSize.y * 2 - scroll.y,
				0.75f, 1,
				1, 1, 0, 1
			);
		if (player.pos.y > 28000)
			tuto_end();

	}
}

void player_render()
{
	sprite_render(
		playerSpr,
		player.pos.x - scroll.x, player.pos.y - scroll.y,
		player.scale.x, player.scale.y,
		player.TexPos.x, player.TexPos.y,
		player.TexSize.x, player.TexSize.y,
		player.pivot.x, player.pivot.y,
		ToRadian(0),
		1, 1, 1, 1
	);

	tuto_text_render();

	primitive::rect(
		player.pos - scroll, player.HalfSize * 2,
		player.HalfSize,
		player.angle,
		{ 1,0,player.color.z,0.5f }
	);
	
	if (player.OnGround)
	{
		fadeout();
	}
	
}

void player_init()
{
	PlayerState = 0;
	fade = 0;
}

void player_deinit()
{
	safe_delete(playerSpr);
}

void OutEnSetText(int EnType)
{
	using namespace std;
	const wchar_t* EnSetPos = L"Enpos.txt";
	//const wchar_t* EnSetPos = L"Coinpos.txt";
	//HACK coin change anotation
	ofstream ofs;
	ofs.open(EnSetPos, ios::app);
	if (!EnSetPos)
		return;
	switch (EnType)
	{
	case 0://coin or 0Enemy
		ofs << "{" << player.area << ", " << EnType << ", VECTOR2("
			<< player.pos.x << "," << player.pos.y << "))}," << endl;
		break;
	case 1://1enemy
		ofs << "{" << player.area << ", " << EnType << ", VECTOR2("
			<< player.pos.x << "," << player.pos.y << "))}," << endl;
		break;
	case 2://2enemy
		ofs << "{" << player.area << ", " << EnType << ", VECTOR2("
			<< player.pos.x << "," << player.pos.y << "))}," << endl;
		break;
	case 3://3enemy
		ofs << "{" << player.area << ", " << EnType << ", VECTOR2("
			<< player.pos.x << "," << player.pos.y << "))}," << endl;
		break;
	case 4://4enemy
		ofs << "{" << player.area << ", " << EnType << ", VECTOR2("
			<< player.pos.x << "," << player.pos.y << "))}," << endl;
		break;
	}
	ofs.close();
	return;

}

void CalcResult()
{
	score += player.pos.y;
	score += getCoinCount * 1000;
	nextScene = SCENE_RESULT;
	//HACK:temporary score calc
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
	if (fade > 1) {
		player.OnGround = false;
		CalcResult();
	}
}


void player_act_init(int action)
{
	player.AnimeKoma = 0;
	player.AnimeTimer = 0;
	player.TexPos.y = PLAYER_TEX_H * action;
}

void player_act()
{
	switch (player.act)
	{
	case IDLE_INIT:
		player_act_init(0);
		++player.act;
		//fallthrough
	case IDLE:
		player_moveX();
		player_moveY();
		//no animation
		player.TexPos.x = 0;
		if (player.speed.y > 7.0f) {
			player.act = ACCELERATION_Y_LOW_INIT;
			break;
		}
		break;
	case ACCELERATION_Y_LOW_INIT:
		player_act_init(1);
		++player.act;
		//fallthrough
	case ACCELERATION_Y_LOW:
		player_moveX();
		player_moveY();
		//no animation
		player.TexPos.x = 0;
		if (player.speed.y > 14.0f) {
			player.act = ACCELERATION_Y_MED_INIT;
			break;
		}
		player.TexPos.x = 0;
		if (player.speed.y < 7.0f) {
			player.act = IDLE_INIT;
			break;
		}
		break;
	case ACCELERATION_Y_MED_INIT:
		player_act_init(2);
		++player.act;
		//fallthrough
	case ACCELERATION_Y_MED:
		player_moveX();
		player_moveY();
		//no animation
		player.TexPos.x = 0;
		player.TexPos.x = 0;
		if (player.speed.y > 20.0f) {
			player.act = ACCELERATION_Y_HI_INIT;
			break;
		}
		player.TexPos.x = 0;
		if (player.speed.y < 14.0f) {
			player.act = ACCELERATION_Y_LOW_INIT;
			break;
		}
		break;
	case ACCELERATION_Y_HI_INIT:
		player_act_init(3);
		++player.act;
		//fallthrough
	case ACCELERATION_Y_HI:
		player_moveX();
		player_moveY();
		//no animation
		player.TexPos.x = 0;
		if (player.speed.y < 20.0f) {
			player.act = ACCELERATION_Y_MED_INIT;
			break;
		}
		break;
	case CLEAR_INIT:
		player_act_init(4);
		++player.act;
		//fallthrough
	case CLEAR:
		//no move
		player.AnimeKoma = player.AnimeTimer / 12 % 2;
		player.TexPos.x = player.AnimeKoma * player.TexSize.x;
		++player.AnimeTimer;
		//TODO loop animation

		break;
	case DEAD_INIT:
		player_act_init(3);
		++player.act;
		//fallthrough
	case DEAD:
		player_moveY();
		//noanimation
		player.TexPos.x = 0;
		//TODO dead script
		break;

	}
}