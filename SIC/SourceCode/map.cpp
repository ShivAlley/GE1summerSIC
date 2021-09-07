#include "all.h"

void map_update()
{

}

void map_render()
{
	primitive::rect(
		{ 0 - scroll.x, 0 - scroll.y },
		{ SCREEN_W, SCREEN_H * 2},
		{ 0,0 },
		ToRadian(0),
		{ 1, 0.5f, 0, 1 }
	);
	primitive::rect(
		{ 0 - scroll.x, SCREEN_H * 2 - scroll.y },
		{ SCREEN_W, SCREEN_H * 2 },
		{ 0,0 },
		ToRadian(0),
		{ 1, 0, 1, 1 }
	);
}

void map_init()
{

}

void map_deinit()
{

}