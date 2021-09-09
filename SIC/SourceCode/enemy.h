#ifndef ENEMY_H
#define ENEMY_H

#define ENEMY_MAX 100

void enemy_init();
void enemy_update();
void enemy_render();
void enemy_deinit();

extern OBJ2D enemy[ENEMY_MAX];

void moveEnemy0(OBJ2D* obj);
void moveEnemy1(OBJ2D* obj);


#endif // ENEMY_H
