#include "all.h"

int MapState;
Sprite* mapBack[4];
int mapHeight[4];

void map_update()
{
	switch (MapState)
	{
	case 0:
		//ini setting
		mapBack[0] = sprite_load(L"./Data/Images/haikei0R.png");
		mapBack[1] = sprite_load(L"./Data/Images/haikei0G.png");
		mapBack[2] = sprite_load(L"./Data/Images/haikei2.png");
		mapBack[3] = sprite_load(L"./Data/Images/haikei3.png");
		//TODO need load haikei1 and haikei2
		++MapState;
		//fallthrough
	case 1:
		//param set
		mapHeight[0] = SCREEN_H * 1000;
		mapHeight[1] = SCREEN_H * 30;
		mapHeight[2] = SCREEN_H * 40;
		mapHeight[3] = SCREEN_H * 50;
		

		++MapState;
		//fallthrough
	case 2:
	{

	}//case2block

	break;
	}
}

void map_render()
{

	switch (player.area)
	{
	case 0:
	{
		for (int i = 0; i < 10000; ++i)
		{
			if (i % 2)
			{
				primitive::rect(
					{ 0 - scroll.x, SCREEN_H * i - scroll.y },
					{ SCREEN_W, SCREEN_H },
					{ 0,0 },
					ToRadian(0),
					{ 0.039f, 0.812f, 0.98f, 1 }
				);
			}
			else
			{
				primitive::rect(
					{ 0 - scroll.x, SCREEN_H * i - scroll.y },
					{ SCREEN_W, SCREEN_H },
					{ 0,0 },
					ToRadian(0),
					{ 0.184f, 0.333f, 0.667f, 1 }
				);
			}
		}
		
		break;
	}
	case 1:
	{
		primitive::rect(
			0, 0,
			SCREEN_W, SCREEN_H,
			0, 0,
			ToRadian(0),
			1, 1, 1, 1
		);
		for (int i = 0; i < 30; ++i)
		{
			if (i % 2 == 0)
			{
				sprite_render(
					mapBack[0],
					0, SCREEN_H * i - scroll.y ,
					1, 1,
					0, 0,
					SCREEN_W, SCREEN_H * 2,
					0, 0,
					ToRadian(0),
					1, 1, 1, 1
				);
			}
			if (i == 29)
			{
				sprite_render(
					mapBack[1],
					0, SCREEN_H * i - scroll.y,
					1, 1,
					0, 0,
					SCREEN_W, SCREEN_H,
					0, 0,
					ToRadian(0),
					1, 1, 1, 1
				);
			}
		}
		break;
		
	}
	case 2:
	{
		primitive::rect(
			0, 0,
			SCREEN_W, SCREEN_H,
			0, 0,
			ToRadian(0),
			1, 1, 1, 1
		);
		
		for (int i = 0; i < 40; ++i)
		{
			if (i % 2 == 0)
			{
				sprite_render(
					mapBack[0],
					0, SCREEN_H * i - scroll.y,
					1, 1,
					0, 0,
					SCREEN_W, SCREEN_H * 2,
					0, 0,
					ToRadian(0),
					1, 1, 1, 1
				);
			}
			if (i == 39)
			{
				sprite_render(
					mapBack[1],
					0, SCREEN_H * i - scroll.y,
					1, 1,
					0, 0,
					SCREEN_W, SCREEN_H,
					0, 0,
					ToRadian(0),
					1, 1, 1, 1
				);
			}
		}
		break;


	}
	case 3:
	{
		primitive::rect(
			0, 0,
			SCREEN_W, SCREEN_H,
			0, 0,
			ToRadian(0),
			1, 1, 1, 1
		);
		for (int i = 0; i < 50; ++i)
		{
			if (i % 2 == 0)
			{
				sprite_render(
					mapBack[0],
					0, SCREEN_H* i - scroll.y,
					1, 1,
					0, 0,
					SCREEN_W, SCREEN_H * 2,
					0, 0,
					ToRadian(0),
					1, 1, 1, 1
				);
			}
			if (i == 49)
			{
				sprite_render(
					mapBack[1],
					0, SCREEN_H * i - scroll.y,
					1, 1,
					0, 0,
					SCREEN_W, SCREEN_H,
					0, 0,
					ToRadian(0),
					1, 1, 1, 1
				);
			}
		}
		break;

	}
	
	}
	
}

void map_init()
{
	MapState = 0;
}

void map_deinit()
{
	for (int i = 0; i < 4; ++i)
	{
		safe_delete(mapBack[i]);
	}
	
}