#include "all.h"
int title_state;
int title_timer;


void title_init()
{
	title_state = 0;
	title_timer = 0;
}

void title_deinit()
{
	
}

void title_update()
{
	int choose = 0;
	switch (title_state)
	{
	case 0:
		
		title_state++;
		/*fallthrough*/
	case 1:
		GameLib::setBlendMode(Blender::BS_ALPHA);
		/*fallthrough*/
	case 2:
		if (TRG(0) & PAD_START) {
			//title_state = 3;
			nextScene = SCENE_GAME;
			break;
		}
		break;
		/*switch (choose)
		{
		case 0:

		default:
			break;
		}*/

	}
	title_timer++;
}

void title_render()
{
	//debug::setString("title_state:%d", title_state);
	//debug::setString("title_timer:%d", title_timer);
	//debug::setString("title_timer/2:%d", title_timer / 32);
	//debug::setString("title_timer%%2:%d", title_timer / 32 % 2);
	GameLib::clear(0.2f, 0.2f, 0.2f);
	//if (title_timer / 32 % 2)
	//{
	//	text_out(1, "Push Enter Key", 300, 500, 2, 2, 1, 1, 0);
	//}
	
	text_out(1, "SampleText", SCREEN_W / 3, SCREEN_H / 2,
		2, 2,
		1, 1,
		0);
}
