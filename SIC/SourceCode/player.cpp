#include "all.h"



int PlayerState;
int PlayerTimer;
float fade;
int score;
OBJ2D player;
VECTOR2 scroll;
VECTOR2 MousePos;
POINT mouse;





void player_moveX()
{
	if (STATE(0) & PAD_RIGHT && !(STATE(0) & PAD_LEFT)) {
		player.speed.x += 0.3f;
		if (STATE(0) & PAD_RIGHT && player.scale.x < 0)
			player.scale.x *= -1.0f;
	}
	else if (STATE(0) & PAD_LEFT && !(STATE(0) & PAD_RIGHT)) {
		player.speed.x -= 0.3f;
		if (STATE(0) & PAD_LEFT && player.scale.x > 0)
			player.scale.x *= -1.0f;
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
	
	if (!(STATE(0) & PAD_SPACE) && player.speed.y > MAX_SPEED_Y / 4)
		player.speed.y -= GRAVITY * 2; //deccle
	//HACK:temp ground
	if (player.pos.y > SCREEN_H * TEMP_MASICNUMBER)
	{		  
		player.pos.y = SCREEN_H * TEMP_MASICNUMBER;
		player.speed.y = 0.0f;
		player.OnGround = true;
	}
	player.pos.y += player.speed.y;
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
		++PlayerState;
		//fallthrough
	case 1:
		//param set
		player = {};
		player.pos = VECTOR2(0, SCREEN_W / 2);
		player.HalfSize = VECTOR2(MAPCHIP_HALFSIZE, MAPCHIP_HALFSIZE);
		player.HitPoint = 3;
		player.color.z = 0;
		player.area = cursor;
		PlayerTimer = 0;
		++PlayerState;

		//fallthrough
	case 2: 
	{

		//loop
		player_moveX();
		player_moveY();
		debug::setString("posx%f", player.pos.x);
		debug::setString("posy%f", player.pos.y);
		debug::setString("OnGround%d", player.OnGround);
		debug::setString("fade%f", fade);
		debug::setString("speedY%f", player.speed.y);
		debug::setString("HP%d", player.HitPoint);
		debug::setString("TIMER%d", PlayerTimer);
		GetCursorPos(&mouse);
		ScreenToClient(window::getHwnd(), &mouse);
		MousePos.x = mouse.x;
		MousePos.y = mouse.y;
		MousePos += scroll;

		if (PlayerTimer==5)
		{
			player.speed = {0,0};
			player.pos.x -= player.speed.x;
		}
		if (PlayerTimer > 5)
		{
			player.speed.y += GRAVITY; // accele
		}
		if (TRG(0) & PAD_SPACE)
		{
			PlayerTimer++;
		}
		if (PlayerTimer < 5)
		{
			PlayerTimer++;
		}
		
		if (player.InvincibleTimer > 0)
			--player.InvincibleTimer;
		if (player.OnGround)
		{
			CalcResult();
			if (Hiscore[player.area] < score)
			{
				RecordResult(player.area);
			}
		}
			
		if (fade > 1)
		{
			CalcResult();
			if (Hiscore[player.area] < score)
			{
				RecordResult(player.area);
			}
			fade = 0;
			player.OnGround = false;
		}
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
	PlayerState = 0;
	PlayerTimer = 0;
	fade = 0;
}

void player_deinit()
{

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

void CalcResult()
{
	score = player.pos.y;
	nextScene = SCENE_RESULT;
	//HACK:temporary score calc
}

void RecordResult(int stage)
{
	using namespace std;
	ofstream ofs;
	switch (stage)
	{
	case 0:
		ofs.open("score0.txt");
		if (!ofs)return;
		if (ofs)
		{
			ofs << score;
			ofs.close();
		}
		break;
	case 1:
		ofs.open("score1.txt");
		if (!ofs)return;
		if (ofs)
		{
			ofs << score;
			ofs.close();
		}
		break;
	}
		
	
	
}

