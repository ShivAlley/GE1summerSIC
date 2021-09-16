#include "all.h"

int MenuState;
int MenuTimer;

int cursor;

Sprite* sprStage[4];
int hiscore[4];

enum stage
{
	first = 0,
	second,
	third,
	fourth,
};

void LoadHiscore()
{
	using namespace std;
	ifstream ifs;
	ifs.open("score0.txt");
	if (!ifs) return;
	if (ifs)
	{
		ifs >> hiscore[0];
		ifs.close();
	}
	ifs.open("score1.txt");
	if (!ifs) return;
	if (ifs)
	{
		ifs >> hiscore[1];
		ifs.close();
	}
}



void menu_update()
{


	switch (MenuState)
	{
	case 0:
		sprStage[0] = sprite_load(L"./Data/Images/stage1.png");
		//TODO load tutorial sprite
		sprStage[1] = sprite_load(L"./Data/Images/stage1.png");
		sprStage[2] = sprite_load(L"./Data/Images/stage2.png");
		sprStage[3] = sprite_load(L"./Data/Images/stage3.png");
		MenuState++;
		//fallthrough
	case 1:
		LoadHiscore();

		MenuState++;
		//fallthrough
	case 2:
		if (TRG(0) & PAD_SELECT)
		{
			nextScene = SCENE_TITLE;
			break;
		}
		if (TRG(0) & PAD_START)
		{
			player.area = cursor;
			nextScene = SCENE_GAME;
			break;
		}
		if (TRG(0) & PAD_RIGHT2)cursor++;
		if (TRG(0) & PAD_LEFT2)cursor--;
		if (cursor < first)cursor = first;
		if (cursor > fourth)cursor = fourth;
		//debug::setString("cursor%d", cursor);
	}
	MenuTimer++;
}

void menu_render()
{
	GameLib::clear(0.2f, 0.2f, 0.2f);
	/*primitive::rect(
		SCREEN_W / 5, SCREEN_H / 2,
		MAPCHIP_SIZE, MAPCHIP_SIZE,
		MAPCHIP_HALFSIZE, MAPCHIP_HALFSIZE,
		0,
		1, 0, 0, 1
	);

	primitive::rect(
		SCREEN_W / 5 * 2, SCREEN_H / 2,
		MAPCHIP_SIZE, MAPCHIP_SIZE,
		MAPCHIP_HALFSIZE, MAPCHIP_HALFSIZE,
		0,
		1, 0, 0, 1
	);
	primitive::rect(
		SCREEN_W / 5 * 3, SCREEN_H / 2,
		MAPCHIP_SIZE, MAPCHIP_SIZE,
		MAPCHIP_HALFSIZE, MAPCHIP_HALFSIZE,
		0,
		1, 0, 0, 1
	);
	primitive::rect(
		SCREEN_W / 5 * 4, SCREEN_H / 2,
		MAPCHIP_SIZE, MAPCHIP_SIZE,
		MAPCHIP_HALFSIZE, MAPCHIP_HALFSIZE,
		0,
		1, 0, 0, 1
	);
	primitive::rect(
		SCREEN_W / 5 * 5, SCREEN_H / 2,
		MAPCHIP_SIZE, MAPCHIP_SIZE,
		MAPCHIP_HALFSIZE, MAPCHIP_HALFSIZE,
		0,
		1, 0, 0, 1
	);*/
	if(cursor != first)
	sprite_render(
		sprStage[0],
		SCREEN_W / 4, SCREEN_H / 4,
		0.8f, 0.8f,
		0, 0,
		512, 256,
		256, 128,
		ToRadian(0),
		0.5f, 0.5f, 0.5f, 1
	);
	if (cursor != second)
	sprite_render(
		sprStage[1],
		SCREEN_W / 4 * 3, SCREEN_H / 4,
		0.8f, 0.8f,
		0, 0,
		512, 256,
		256, 128,
		ToRadian(0),
		0.5f, 0.5f, 0.5f, 1
	);
	if (cursor != third)
	sprite_render(
		sprStage[2],
		SCREEN_W / 4, SCREEN_H / 4 * 3,
		0.8f, 0.8f,
		0, 0,
		512, 256,
		256, 128,
		ToRadian(0),
		0.5f, 0.5f, 0.5f, 1
	);
	if (cursor != fourth)
	sprite_render(
		sprStage[3],
		SCREEN_W / 4 * 3, SCREEN_H / 4 * 3,
		0.8f, 0.8f,
		0, 0,
		512, 256,
		256, 128,
		ToRadian(0),
		0.5f, 0.5f, 0.5f, 1
	);
	switch (cursor)
	{
	case first:
		sprite_render(
			sprStage[0],
			SCREEN_W / 4, SCREEN_H / 4,
			1, 1.,
			0, 0,
			512, 256,
			256, 128,
			ToRadian(0),
			1, 1, 1, 1
		);
		break;
	case second:
		sprite_render(
			sprStage[1],
			SCREEN_W / 4 * 3, SCREEN_H / 4,
			1, 1,
			0, 0,
			512, 256,
			256, 128,
			ToRadian(0),
			1, 1, 1, 1
		);
		break;
	case third:
		sprite_render(
			sprStage[2],
			SCREEN_W / 4, SCREEN_H / 4 * 3,
			1, 1,
			0, 0,
			512, 256,
			256, 128,
			ToRadian(0),
			1, 1, 1, 1
		);
		break;
	case fourth:
		sprite_render(
			sprStage[3],
			SCREEN_W / 4 * 3, SCREEN_H / 4 * 3,
			1, 1,
			0, 0,
			512, 256,
			256, 128,
			ToRadian(0),
			1, 1, 1, 1
		);
		break;
	}

	

}

void menu_init()
{
	MenuState = 0;
	MenuTimer = 0;
	cursor = 0;
}

void menu_deinit()
{
	for (int i = 0; i < 4; ++i)
	{
		safe_delete(sprStage[i]);
	}
}
