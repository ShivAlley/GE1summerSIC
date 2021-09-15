#ifndef ENEMY_H
#define ENEMY_H

struct ENEMY_DATA {
    GameLib::Sprite* spr;
    const wchar_t* filepath;
    VECTOR2 texPos;
    VECTOR2 texSize;
    VECTOR2 pivot;
};

struct ENEMY_SET
{
    int area;
    int enemyType;
    VECTOR2 pos;
};

enum ENEMY_ACT
{
    EnIDLE_INIT,
    EnIDLE,
    EnMOVE_INIT,
    EnMOVE,
    EnDEAD_INIT,
    EnDEAD,

};

#define ENEMY_MAX 1000

void enemy_init();
void enemy_update();
void enemy_render();
void enemy_deinit();

extern OBJ2D enemy[ENEMY_MAX];

void moveEnemy0(OBJ2D* obj);
void moveEnemy1(OBJ2D* obj);
void moveEnemy2(OBJ2D* obj);
void moveEnemy3(OBJ2D* obj);
void moveEnemy4(OBJ2D* obj);
void enemy_act(OBJ2D* enemy);


#endif // ENEMY_H
