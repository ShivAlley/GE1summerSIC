//1:必要なファイルをインクルード
#include "../GameLib/game_lib.h"
#include "all.h"

int curScene = SCENE_NONE;
int nextScene = SCENE_TITLE;

//2:WinMain関数を記述する
int APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int)
{
	//4;ゲームライブラリの初期設定
	GameLib::init(L"DropAction", SCREEN_W, SCREEN_H);
	//6:ゲームループ

	while (GameLib::gameLoop(true))
	{
		//シーン切り替え処理
		if (curScene != nextScene)
		{
			//現在のシーンに応じた終了処理
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

			//次のシーンに応じた初期設定処理
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
			//nextsceneがCursceneになる
			curScene = nextScene;
		}

		//入力を更新する
		input::update();

		music::update();

		//現在のシーンに応じた更新と描画処理
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

		//7:画面を描写する
		debug::display(1, 1, 1, 1, 1);

		GameLib::present(1, 0);

			
	}
	//現在のシーンに応じた終了処理を行う
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

	
	//5:ゲームライブラリの終了処理
	GameLib::uninit();
	
	//3:戻り値は０。
	return 0;
}