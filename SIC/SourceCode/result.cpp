#include "all.h"

int ResultState;
int ResultTimer;
std::string str;

void result_update()
{
	switch (ResultState)
	{
	case 0:
		ResultState++;
		//fallthrough
	case 1:
		GameLib::setBlendMode(Blender::BS_ALPHA);
		str = std::to_string(score);
		ResultState++;
		//fallthrough
	case 2:
		if (TRG(0) & PAD_SPACE)
		{
			nextScene = SCENE_MENU;
		}
		break;
	}
	ResultTimer++;
}

void result_render()
{
	GameLib::clear(0.482f, 0.953f, 0.486f);

	text_out(1, str, SCREEN_W / 3, SCREEN_H / 2, 2, 2, 1, 1, 0);
	text_out(1, "your score", SCREEN_W / 3, SCREEN_H / 3, 2, 2, 1, 1, 0);
}

void result_init()
{
	ResultState = 0;
	ResultTimer = 0;
}

void result_deinit()
{

}


