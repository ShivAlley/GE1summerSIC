#include "all.h"

int game_state;
int game_timer;


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
		//‰Šúİ’è
		
		game_state++;
		/*fallthrough*/
	case 1:
		//ƒpƒ‰ƒ[ƒ^‚Ìİ’è
		
		setBlendMode(Blender::BS_ALPHA);
		game_state++;
		/*fallthrough*/
	case 2:
		//’Êí
		if (TRG(0) & PAD_SELECT)
		{
			nextScene = SCENE_TITLE;
			break;
		}

		player_update();
		enemy_update();
		map_update();

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

