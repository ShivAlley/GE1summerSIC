#ifndef PLAYER_H
#define PLAYER_H

enum PLAYER_ACT
{
	IDLE_INIT,
	IDLE,
	ACCELERATION_Y_LOW_INIT,
	ACCELERATION_Y_LOW,
	ACCELERATION_Y_MED_INIT,
	ACCELERATION_Y_MED,
	ACCELERATION_Y_HI_INIT,
	ACCELERATION_Y_HI,
	CLEAR_INIT,
	CLEAR,
	DEAD_INIT,
	DEAD,
};

void player_init();
void player_update();
void player_render();
void player_deinit();

void OutEnSetText(int EnType);
void RecordResult(int stage);

bool HitCheck(OBJ2D* player, OBJ2D* enemy);
void fadeout();
void CalcResult();
void player_act();

extern OBJ2D player;
extern VECTOR2 MousePos;

#define PLAYER_TEX_W 256.0f  
#define PLAYER_TEX_H 512.0f  
#define PLAYER_PIVOT_X PLAYER_TEX_W / 2    
#define PLAYER_PIVOT_Y PLAYER_TEX_H / 2 



#endif // PLAYER_H
