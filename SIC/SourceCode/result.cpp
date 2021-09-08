#include "all.h"

int result_state;
int result_timer;
//std::string str;
//str = std::to_string(score);
void result_update()
{
	//switch (result_state)
	//{
	//case 0:
	//	result_state++;
	//	//fallthrough
	//case 1:
	//	GameLib::setBlendMode(Blender::BS_ALPHA);
	//	result_state++;
	//	//fallthrough
	//case 2:

	//}
	//result_timer++;
}

void result_render()
{
	GameLib::clear(1, 0.2f, 0.2f);
	text_out(1, "score", 300, 500, 2, 2, 1, 1, 0);
}

void result_init()
{

}

void result_deinit()
{

}


