#ifndef COMMON_H
#define COMMON_H
//ƒV[ƒ“‚Ìƒ‰ƒxƒ‹
#define SCENE_NONE 0
#define SCENE_TITLE 1
#define SCENE_GAME 2
#define SCENE_MENU 3
#define SCENE_RESULT 4


#define MAPCHIP_SIZE 64.0f
#define MAPCHIP_HALFSIZE (MAPCHIP_SIZE / 2)
#define GRAVITY 0.2f
#define MAX_SPEED 1.0f
#define JUMP_POWER -15.0f * 2

//‰æ–Ê‚Ì‘å‚«‚³
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

//•Ï”‚ÌéŒ¾
extern int curScene;
extern int nextScene;
extern int title_state;
extern int game_state;
extern int menu_state;
extern int result_state;
extern int title_timer;
extern int game_timer;
extern int menu_timer;
extern int result_timer;
extern VECTOR2 scroll;




#endif// COMMON_H
