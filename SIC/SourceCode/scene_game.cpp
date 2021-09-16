#include "all.h"

int GameState;
int GameTimer;
float ScrollMerginY = 0;
bool forcereset = false;

void scrollMap()
{

	if (scroll.x < player.pos.x + player.HalfSize.x - SCREEN_W + SCROLL_MERGIN_X)
		scroll.x = player.pos.x + player.HalfSize.x - SCREEN_W + SCROLL_MERGIN_X;
	if (scroll.x > player.pos.x - player.HalfSize.x - SCROLL_MERGIN_X)
		scroll.x = player.pos.x - player.HalfSize.x - SCROLL_MERGIN_X;
	if (STATE(0) & PAD_SPACE)
	{
		ScrollMerginY += GRAVITY * 10;
		if (ScrollMerginY > SCROLL_MARGIN_Y / 2) // SCROLL_MERGIN_Y / 2 === SCROLL_MERGIN_Y * 1.5f - SCROLL_MERGIN_Y
			ScrollMerginY = SCROLL_MARGIN_Y / 2;
	}
	else
	{
		ScrollMerginY -= GRAVITY * 10;
		if (ScrollMerginY < 0)
			ScrollMerginY = 0;
	}
	
	if (scroll.y < player.pos.y + player.HalfSize.y - SCREEN_H + SCROLL_MARGIN_Y * 1.5f - ScrollMerginY) //HACK:need balancing 1.5f ~ 1.7f
		scroll.y = player.pos.y + player.HalfSize.y - SCREEN_H + SCROLL_MARGIN_Y * 1.5f - ScrollMerginY;
	if (scroll.y > player.pos.y - player.HalfSize.y - SCROLL_MARGIN_Y * 0.1f)
		scroll.y = player.pos.y - player.HalfSize.y - SCROLL_MARGIN_Y * 0.1f;

#if 0 // backup
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
#endif
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
	GameState = 0;
	GameTimer = 0;
	srand((unsigned int)time(NULL));
}
void game_deinit()
{
	enemy_deinit();
	player_deinit();
	coin_deinit();
	
}
void game_update()
{

	switch (GameState)
	{
	case 0:
		//初期設定
		
		GameState++;
		
		/*fallthrough*/
	case 1:
		//パラメータの設定
		
		setBlendMode(Blender::BS_ALPHA);
		GameState++;
		/*fallthrough*/
	case 2:
		//通常時
		if (TRG(0) & PAD_SELECT)
		{
			nextScene = SCENE_TITLE;
			break;
		}

		map_update();
		player_update();  
		enemy_update();
		coin_update();
		scrollMap();
		//debug::setString("scrollY %f", scroll.y);

		GameTimer++;
		
		
	}
}
void game_render()
{
	GameLib::clear(0, 0, 0);
	map_render();
	enemy_render();
	coin_render();
	player_render();
	scrollBar(scroll);
	

}

void game_reset()
{
	GameState = 1;
	PlayerState = 1;
	EnemyState = 1;
	ResultState = 1;
	CoinState = 0;
	MapState = 1;
	forcereset = false;
	for (int i = 0; i < ENEMY_MAX; ++i)
	{
		if (enemy[i].state != 0)
			forcereset = true;
	}
	
}
void scrollBar(VECTOR2 scroll)
{
	float CalcMargin = 0.1f;
	float margin = SCREEN_H * CalcMargin;
	if (scroll.y < player.pos.y + player.HalfSize.y - SCREEN_H + SCROLL_MARGIN_Y * 0)
		scroll.y = player.pos.y + player.HalfSize.y - SCREEN_H + SCROLL_MARGIN_Y * 0;
	if (scroll.y > player.pos.y - player.HalfSize.y - SCROLL_MARGIN_Y * 0)
		scroll.y = player.pos.y - player.HalfSize.y - SCROLL_MARGIN_Y * 0;

	scroll.y /= mapHeight[player.area] / SCREEN_H;
	//シークバー現在地 = scroll.y / コースの全長 / スクリーンの高さ
	scroll.y *= 1 - CalcMargin * 2;




	
	primitive::rect(
		{ 1260,margin + scroll.y },
		{ 20,5 },
		{ 0,0 },
		ToRadian(0),
		{ 1, 1, 1, 1 }

	);
	primitive::rect(//シークバー上限
		{ 1275,margin },
		{ 5,5 },
		{ 0,0 },
		ToRadian(0),
		{ 0, 0, 1, 1 }
	);
	primitive::rect(//シークバー下限
		{ 1275,SCREEN_H - margin },
		{ 5,5 },
		{ 0,0 },
		ToRadian(0),
		{ 1, 0, 0, 1 }
	);
}
