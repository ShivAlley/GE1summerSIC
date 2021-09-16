#include "all.h"

int MapState;
Sprite* mapBack[3];
int mapHeight[4];

void map_update()
{
	switch (MapState)
	{
	case 0:
		//ini setting
		mapBack[0] = sprite_load(L"./Data/Images/haikei0.png");
		mapBack[1] = sprite_load(L"./Data/Images/haikei0.png");
		mapBack[2] = sprite_load(L"./Data/Images/haikei0.png");
		//TODO need load haikei1 and haikei2
		++MapState;
		//fallthrough
	case 1:
		//param set
		mapHeight[0] = SCREEN_H * 10000;
		mapHeight[1] = 14400;
		mapHeight[2] = 14400;
		mapHeight[3] = 14400;
		//TODO setting map height

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
		sprite_render(
			mapBack[0],
			0 - scroll.x, 0 - scroll.y,
			1, 1,
			0, 0,
			SCREEN_W, mapHeight[1],
			0, 0,
			0,
			1, 1, 1, 1
		);
		break;
		
	}
	case 2:
	{
		for (int i = 0; i < TEMP_MASICNUMBER; ++i)
		{
			if (i % 2)
			{
				primitive::rect(
					{ 0 - scroll.x, SCREEN_H * i - scroll.y },
					{ SCREEN_W, SCREEN_H },
					{ 0,0 },
					ToRadian(0),
					{ 0.529f, 0.949f,0.361f, 1 }
				);
			}
			else
			{
				primitive::rect(
					{ 0 - scroll.x, SCREEN_H * i - scroll.y },
					{ SCREEN_W, SCREEN_H },
					{ 0,0 },
					ToRadian(0),
					{ 0.973f, 1, 0.388f, 1 }
				);
			}

		}
		break;

	}
	case 3:
	{
		for (int i = 0; i < TEMP_MASICNUMBER; ++i)
		{
			if (i % 2)
			{
				primitive::rect(
					{ 0 - scroll.x, SCREEN_H * i - scroll.y },
					{ SCREEN_W, SCREEN_H },
					{ 0,0 },
					ToRadian(0),
					{ 0.125f, 0.008f,0.412f, 1 }
				);
			}
			else
			{
				primitive::rect(
					{ 0 - scroll.x, SCREEN_H * i - scroll.y },
					{ SCREEN_W, SCREEN_H },
					{ 0,0 },
					ToRadian(0),
					{ 0.357f, 0.027f, 0.522f, 1 }
				);
			}

		}
		break;

	}
	case 4:
	{
		for (int i = 0; i < TEMP_MASICNUMBER; ++i)
		{
			if (i % 2)
			{
				primitive::rect(
					{ 0 - scroll.x, SCREEN_H * i - scroll.y },
					{ SCREEN_W, SCREEN_H },
					{ 0,0 },
					ToRadian(0),
					{ 0.18f, 0.769f,1, 1 }
				);
			}
			else
			{
				primitive::rect(
					{ 0 - scroll.x, SCREEN_H * i - scroll.y },
					{ SCREEN_W, SCREEN_H },
					{ 0,0 },
					ToRadian(0),
					{ 0.98f, 0.8f, 0.118f, 1 }
				);
			}

		}
		break;

	}
	}
	
}

void map_init()
{
	
}

void map_deinit()
{
	for (int i = 0; i < 3; ++i)
	{
		safe_delete(mapBack[i]);
	}
	
}