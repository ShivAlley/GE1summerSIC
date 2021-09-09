#include "all.h"

int game_state;
int game_timer;

void scrollMap()
{

	if (scroll.x < player.pos.x + player.HalfSize.x - SCREEN_W + SCROLL_MERGIN_X)
		scroll.x = player.pos.x + player.HalfSize.x - SCREEN_W + SCROLL_MERGIN_X;
	if (scroll.x > player.pos.x - player.HalfSize.x - SCROLL_MERGIN_X)
		scroll.x = player.pos.x - player.HalfSize.x - SCROLL_MERGIN_X;
	/*if (STATE(0) & PAD_TRG1)
	{
		if (scroll.y < player.pos.y + player.HalfSize.y - SCREEN_H + SCROLL_MERGIN_Y)
			scroll.y = player.pos.y + player.HalfSize.y - SCREEN_H + SCROLL_MERGIN_Y;

	}
	else
	{
		if (scroll.y < player.pos.y + player.HalfSize.y - SCREEN_H + SCROLL_MERGIN_Y * 1.5f)
			scroll.y = player.pos.y + player.HalfSize.y - SCREEN_H + SCROLL_MERGIN_Y * 1.5f;
	}*/
	if (scroll.y < player.pos.y + player.HalfSize.y - SCREEN_H + SCROLL_MERGIN_Y * 1.5f)
		scroll.y = player.pos.y + player.HalfSize.y - SCREEN_H + SCROLL_MERGIN_Y * 1.5f;
	if (scroll.y > player.pos.y - player.HalfSize.y - SCROLL_MERGIN_Y * 0.1f)
		scroll.y = player.pos.y - player.HalfSize.y - SCROLL_MERGIN_Y * 0.1f;

	//scroll limit
	if (scroll.x < 0) scroll.x = 0;
	if (scroll.x > SCREEN_W - SCREEN_W)
		scroll.x = SCREEN_W - SCREEN_W;
	if (scroll.y < 0) scroll.y = 0;
	/*if (scroll.y > WorldHeight - SCREEN_H)
		scroll.y = WorldHeight - SCREEN_H;*/
	//TODO:地面が実装された際にスクロールの画面制限を付ける必要あり

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
		//初期設定
		
		game_state++;
		/*fallthrough*/
	case 1:
		//パラメータの設定
		
		setBlendMode(Blender::BS_ALPHA);
		game_state++;
		/*fallthrough*/
	case 2:
		//通常時
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

