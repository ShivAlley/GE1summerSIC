#include "all.h"


int PlayerState;
OBJ2D player;
VECTOR2 scroll;

void player_moveX()
{
	if (STATE(0) & PAD_RIGHT && !(STATE(0) & PAD_LEFT)) {
		player.speed.x += 0.3f;
		if (TRG(0) & PAD_RIGHT && player.scale.x < 0)
			player.scale.x *= -1.0f;
	}
	else if (STATE(0) & PAD_LEFT && !(STATE(0) & PAD_RIGHT)) {
		player.speed.x -= 0.3f;
		if (TRG(0) & PAD_LEFT && player.scale.x > 0)
			player.scale.x *= -1.0f;
	}
	player.speed.x *= 0.98f;
}
void player_moveY()
{
	//if (STATE(0) & PAD_DOWN && !(STATE(0) & PAD_UP)) {
	//	player.speed.y += 0.3f;
	//}
	//else if (STATE(0) & PAD_UP && !(STATE(0) & PAD_DOWN)) {
	//	player.speed.y -= 0.3f;
	//}
	//if (player.pos.x<0 || player.pos.x>SCREEN_W)
	//{
	//	player.speed.x = -player.speed.x;
	//}
	//if (player.pos.y < 0||player.pos.y>SCREEN_H)
	//{
	//	player.speed.y = -player.speed.y;
	//}
	player.speed.y += GRAVITY;
	if (player.speed.y < MAX_SPEED)
		player.speed.y = MAX_SPEED;
	//HACK:暫定的な地面の実装のため改修が必要
	if (player.pos.y > SCREEN_H * 4)
	{
		player.pos.y = SCREEN_H * 4;
		player.speed.y = 0.0f;
		player.OnGround = true;
	}

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
		player_moveX();
		player.pos.x += player.speed.x;
		player_moveY();
		player.pos.y += player.speed.y;
		debug::setString("posx%f", player.pos.x);
		debug::setString("posy%f", player.pos.y);
		if (STATE(0) & PAD_TRG1) {
			player.speed.y *= 0.95f;
			if (player.speed.y < MAX_SPEED / 2)
				player.speed.y = MAX_SPEED / 2;
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
}

void player_init()
{

}

void player_deinit()
{

}