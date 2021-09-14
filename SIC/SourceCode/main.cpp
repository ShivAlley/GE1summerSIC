//1:�K�v�ȃt�@�C�����C���N���[�h
#include "../GameLib/game_lib.h"
#include "all.h"

int curScene = SCENE_NONE;
int nextScene = SCENE_TITLE;

//2:WinMain�֐����L�q����
int APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int)
{
	//4;�Q�[�����C�u�����̏����ݒ�
	GameLib::init(L"DropAction", SCREEN_W, SCREEN_H);
	//6:�Q�[�����[�v

	while (GameLib::gameLoop(true))
	{
		//�V�[���؂�ւ�����
		if (curScene != nextScene)
		{
			//���݂̃V�[���ɉ������I������
			switch (curScene)
			{
			case SCENE_TITLE:
				title_deinit();
				break;
			case SCENE_GAME:
				game_deinit();
				break;
			case SCENE_MENU:
				menu_deinit();
				break;
			case SCENE_RESULT:
				result_deinit();
				break;
			}

			//���̃V�[���ɉ����������ݒ菈��
			switch (nextScene)
			{
			case SCENE_TITLE:
				title_init();
				break;
			case SCENE_GAME:
				game_init();
				break;
			case SCENE_MENU:
				menu_init();
				break;
			case SCENE_RESULT:
				result_init();
				break;
			}
			//nextscene��Curscene�ɂȂ�
			curScene = nextScene;
		}

		//���͂��X�V����
		input::update();

		music::update();

		//���݂̃V�[���ɉ������X�V�ƕ`�揈��
		switch (curScene)
		{
		case SCENE_TITLE:
			title_update();
			title_render();
			break;
		case SCENE_GAME:
			game_update();
			game_render();
			break;
		case SCENE_MENU:
			menu_update();
			menu_render();
			break;
		case SCENE_RESULT:
			result_update();
			result_render();
			break;
		}

		//7:��ʂ�`�ʂ���
		debug::display(1, 1, 1, 1, 1);

		GameLib::present(1, 0);

			
	}
	//���݂̃V�[���ɉ������I���������s��
	switch (curScene)
	{
	case SCENE_TITLE:
		title_deinit();
		break;
	case SCENE_GAME:
		game_deinit();
		break;
	case SCENE_MENU:
		menu_deinit();
		break;
	case SCENE_RESULT:
		result_deinit();
		break;
	}

	
	//5:�Q�[�����C�u�����̏I������
	GameLib::uninit();
	
	//3:�߂�l�͂O�B
	return 0;
}