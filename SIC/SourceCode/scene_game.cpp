#include "all.h"

int game_state;
int game_timer;

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

	if (scroll.x < 0) scroll.x = 0;
	if (scroll.x > SCREEN_W - SCREEN_W)
		scroll.x = SCREEN_W - SCREEN_W;
	if (scroll.y < 0) scroll.y = 0;
	/*if (scroll.y > WorldHeight - SCREEN_H)
		scroll.y = WorldHeight - SCREEN_H;*/

}

void game_init()
{
	game_state = 0;
	game_timer = 0;
	srand((unsigned int)time(NULL));
}
void game_deinit()
{
	
	
}
void game_update()
{

	switch (game_state)
	{
	case 0:
		//èâä˙ê›íË
		
		game_state++;
		/*fallthrough*/
	case 1:
		//ÉpÉâÉÅÅ[É^ÇÃê›íË
		
		setBlendMode(Blender::BS_ALPHA);
		game_state++;
		/*fallthrough*/
	case 2:
		//í èÌéû
		if (TRG(0) & PAD_SELECT)
		{
			nextScene = SCENE_TITLE;
			break;
		}

		player_update();
		enemy_update();
		map_update();
		scrollMap();

		game_timer++;
		
		
	}
}
void game_render()
{
	GameLib::clear(0, 0, 0);
	map_render();
	enemy_render();
	player_render();
	

}

