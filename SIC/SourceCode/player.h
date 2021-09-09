#ifndef PLAYER_H
#define PLAYER_H

void player_init();
void player_update();
void player_render();
void player_deinit();

bool HitCheck(OBJ2D* player, OBJ2D* enemy);
void fadeout();

extern OBJ2D player;
extern VECTOR2 MousePos;

#endif // PLAYER_H
