#include "all.h"

int menu_state;
int menu_timer;
int StageSelect = 0;
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
	switch (menu_state)
	{
	case 0:

		menu_state++;
		//fallthrough
	case 1:
		GameLib::setBlendMode(Blender::BS_ALPHA);

		menu_state++;
		//fallthrough
	case 2:
		if (TRG(0) & PAD_SELECT)
		{
			nextScene = SCENE_TITLE;
			break;
		}

		


	}
	menu_timer++;
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
}

void menu_init()
{

}

void menu_deinit()
{

}
