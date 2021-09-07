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
	player.speed.y += 1.0f;
	if (player.pos.y > SCREEN_H-32)
	{
		player.pos.y = SCREEN_H-32;
		player.speed.y = 0.0f;
	}

}

void scrollMap()
{

	if (scroll.x < player.pos.x + player.HalfSize.x - SCREEN_W + SCROLL_MERGIN_X)
		scroll.x = player.pos.x + player.HalfSize.x - SCREEN_W + SCROLL_MERGIN_X;
	if (scroll.x > player.pos.x - player.HalfSize.x - SCROLL_MERGIN_X)
		scroll.x = player.pos.x - player.HalfSize.x - SCROLL_MERGIN_X;
	if (scroll.y < player.pos.y + player.HalfSize.y - SCREEN_H + SCROLL_MERGIN_Y)
		scroll.y = player.pos.y + player.HalfSize.y - SCREEN_H + SCROLL_MERGIN_Y;
	if (scroll.y > player.pos.y - player.HalfSize.y - SCROLL_MERGIN_Y)
		scroll.y = player.pos.y - player.HalfSize.y - SCROLL_MERGIN_Y;


	
}

void player_update()
{
	switch (PlayerState)
	{
	case 0:
		//èâä˙ê›íË
		++PlayerState;
		//fallthrough
	case 1:
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
		debug::setString("posx%f", player.pos.y);
	}
}

void player_render()
{
	primitive::rect(
		player.pos, player.HalfSize * 2,
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