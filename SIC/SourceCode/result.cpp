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
	GameLib::clear(0.5f, 0.2f, 0.2f);
	//text_out(1, "score", 300, 500, 2, 2, 1, 1, 0);
	text_out(1, str, 300, 500, 2, 2, 1, 1, 0);
}

void result_init()
{
	ResultState = 0;
	ResultTimer = 0;
}

void result_deinit()
{

}


