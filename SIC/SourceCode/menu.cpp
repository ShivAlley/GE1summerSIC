#include "all.h"

int MenuState;
int MenuTimer;
int Hiscore[2];
int cursor;

enum stage
{
	first = 0,
	second,
	third,
	fourth,
	fifth,
};

void menu_update()
{


	switch (MenuState)
	{
	case 0:
		MenuState++;
		//fallthrough
	case 1:
		GameLib::setBlendMode(Blender::BS_ALPHA);
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
		if (TRG(0) & PAD_RIGHT)cursor++;
		if (TRG(0) & PAD_LEFT)cursor--;
		if (cursor < first)cursor = first;
		if (cursor > fifth)cursor = fifth;
		if (cursor == 0)
		{
			debug::setString("Hiscore%d", Hiscore[0]);
		}
		if (cursor == 1)
		{
			debug::setString("Hiscore%d", Hiscore[1]);
		}
		//debug::setString("cursor%d", cursor);
	}
	MenuTimer++;
}

void menu_render()
{
	GameLib::clear(0.2f, 0.2f, 0.2f);
	primitive::rect(
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
	);

	switch (cursor)
	{
	case first:
		primitive::rect(
			SCREEN_W / 5, SCREEN_H / 2,
			MAPCHIP_SIZE, MAPCHIP_SIZE,
			MAPCHIP_HALFSIZE, MAPCHIP_HALFSIZE,
			0,
			0, 0, 1, 1
		);
		break;
	case second:
		primitive::rect(
			SCREEN_W / 5 * 2, SCREEN_H / 2,
			MAPCHIP_SIZE, MAPCHIP_SIZE,
			MAPCHIP_HALFSIZE, MAPCHIP_HALFSIZE,
			0,
			0, 0, 1, 1
		);
		break;
	case third:
		primitive::rect(
			SCREEN_W / 5 * 3, SCREEN_H / 2,
			MAPCHIP_SIZE, MAPCHIP_SIZE,
			MAPCHIP_HALFSIZE, MAPCHIP_HALFSIZE,
			0,
			0, 0, 1, 1
		);
		break;
	case fourth:
		primitive::rect(
			SCREEN_W / 5 * 4, SCREEN_H / 2,
			MAPCHIP_SIZE, MAPCHIP_SIZE,
			MAPCHIP_HALFSIZE, MAPCHIP_HALFSIZE,
			0,
			0, 0, 1, 1
		);
		break;
	case fifth:
		primitive::rect(
			SCREEN_W / 5 * 5, SCREEN_H / 2,
			MAPCHIP_SIZE, MAPCHIP_SIZE,
			MAPCHIP_HALFSIZE, MAPCHIP_HALFSIZE,
			0,
			0, 0, 1, 1
		);
		break;
	}

	

}

void menu_init()
{
	MenuState = 0;
	MenuTimer = 0;
	cursor = 0;
	Hiscore[2] = { 0 };
}

void menu_deinit()
{

}

void LoadHiscore()
{
	using namespace std;
	ifstream ifs;
	ifs.open("score0.txt");
	if (ifs)
	{
		ifs >> Hiscore[0];
		ifs.close();
	}
	ifs.open("score1.txt");
	if (ifs)
	{
		ifs >> Hiscore[1];
		ifs.close();
	}
}