//1:インクルードガード
#ifndef ALL_H
#define ALL_H
//システムやライブラリのヘッダーは上のほうへ
#include "../GameLib/game_lib.h"

//共通で使われるヘッダー
#include "common.h"
#include "obj2d.h"


//個々のヘッダーは下のほうへ
#include "scene_title.h"
#include "scene_game.h"
#include "menu.h"

#include "player.h"
#include "enemy.h"
#include "map.h"
#include "audio.h"
#include "result.h"



//#include "mapdata.h"
using namespace GameLib;
using namespace input;
//2インクルードガード終了
#endif //ALL_H

