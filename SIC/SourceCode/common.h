#ifndef COMMON_H
#define COMMON_H
//ÉVÅ[ÉìÇÃÉâÉxÉã
#define SCENE_NONE 0
#define SCENE_TITLE 1
#define SCENE_GAME 2
#define SCENE_MENU 3
#define SCENE_RESULT 4


#define MAPCHIP_SIZE 32.0f
#define MAPCHIP_HALFSIZE (MAPCHIP_SIZE / 2)
#define GRAVITY 0.1f
#define MAX_SPEED_Y 24.0f
#define JUMP_POWER -15.0f * 2
#define INVINCIBLE_TIMER 180


//âÊñ ÇÃëÂÇ´Ç≥
#define SCREEN_W 1280
#define SCREEN_H 720



#define MAP_MAX_WIDTH 100
#define MAP_MAX_HEIGHT 100
#define WorldWidth (MAPCHIP_SIZE * MapWidth) 
#define WorldHeight (MAPCHIP_SIZE * MapHeight)
#define SCROLL_MERGIN_X (SCREEN_W / 2)
#define SCROLL_MERGIN_Y (SCREEN_H / 2)
#define ToRadian( x )   DirectX::XMConvertToRadians( x )    
#define ToDegree( x )   DirectX::XMConvertToDegrees( x )    

//ïœêîÇÃêÈåæ
extern int curScene;
extern int nextScene;
extern int TitleState;
extern int GameState;
extern int MenuState;
extern int ResultState;
extern int EnemyState;
extern int PlayerState;
extern int CoinState;
extern int TitleTimer;
extern int GameTimer;
extern int MenuTimer;
extern int ResultTimer;
extern int score;
extern int cursor;
extern VECTOR2 scroll;




#endif// COMMON_H
