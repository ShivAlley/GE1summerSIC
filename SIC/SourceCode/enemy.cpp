#include "all.h"

int EnemyState;

struct ENEMY_DATA {
    Sprite* spr;
    const wchar_t* filepath;
    VECTOR2 texPos;
    VECTOR2 texSize;
    VECTOR2 pivot;
};

ENEMY_DATA EnemyData[] =
{
    {NULL, L"./Data/Images/stickman.png", { 0, 0 }, { 128, 128 }, { 64, 64 }, },

};

struct ENEMY_SET
{
    int area;
    int enemyType;
    VECTOR2 pos;
};

OBJ2D enemy[ENEMY_MAX];

ENEMY_SET enemySet[] =
{
    {0,0,VECTOR2(SCREEN_W / 2, SCREEN_H )},

};

OBJ2D* searchSet0(OBJ2D enemy[], int dataNum, int moveAlg, VECTOR2 pos)
{
    for (int i = 0; i < dataNum; ++i)
    {
        if (enemy[i].MoveAlg != -1)continue;
        enemy[i] = {};
        enemy[i].MoveAlg = moveAlg;
        enemy[i].pos = pos;
        return &enemy[i];
    }
    return NULL;
}

void enemy_update()
{
    switch (EnemyState)
    {
    case 0:
    {

        int dataNum = sizeof(EnemyData) / sizeof(ENEMY_DATA);


        for (int i = 0; i < dataNum; ++i)
        {
            EnemyData[i].spr = sprite_load(EnemyData[i].filepath);
        }
        ++EnemyState;
        //fallthrough
    }
    case 1:
    {

        for (int i = 0; i < ENEMY_MAX; ++i)
        {
            enemy[i] = {};
            enemy[i].MoveAlg = -1;
        }



        for (int i = 0; ; ++i)
        {
            if (enemySet[i].enemyType == -1)
                break;
            OBJ2D* p = searchSet0(enemy, ENEMY_MAX, enemySet[i].enemyType, enemySet[i].pos);
            if (!p) break;
            p->area = enemySet[i].area;

        }


        ++EnemyState;
        //fallthrough
    }
    case 2:
    {

        for (int i = 0; i < ENEMY_MAX; ++i)
        {
            if (enemy[i].MoveAlg == -1)continue;
            if (player.area != enemy[i].area) continue;
            switch (enemy[i].MoveAlg)
            {
            case 0:moveEnemy0(&enemy[i]); break;
            /*case 1:moveEnemy1(&enemy[i]); break;
            case 2:moveEnemy2(&enemy[i]); break;
            case 3:moveEnemy3(&enemy[i]); break;*/
            default: break;
            }
            ++enemy[i].timer;
            
        }
        //debug::setString("Enemy%d", sizeof(enemySet) / sizeof(ENEMY_SET));
    }

    } //switch}


}

void enemy_render()
{

}

void moveEnemy0(OBJ2D* obj)
{
    switch (obj->state)
    {
    case 0:
        obj->scale = { 0.5f, 0.5f };
        obj->spr = EnemyData[0].spr;
        obj->TexPos = EnemyData[0].texPos;
        obj->TexSize = EnemyData[0].texSize;
        obj->pivot = EnemyData[0].pivot;
        obj->HalfSize.y = MAPCHIP_SIZE;
        obj->HalfSize.x = MAPCHIP_SIZE;
        obj->angle = ToRadian(0);
        obj->color.w = 1.0f;

        ++obj->state;
        //fallthrough
    case 1:

        //enemy_act(obj);

        obj->pos.y += obj->speed.y;

        obj->speed.y += 1.0f;

        

        obj->pos.x += obj->speed.x;



       


        


        break;
    }
}

void enemy_init()
{
    for (int i = 0; i < ENEMY_MAX; ++i)
    {
        enemy[i] = {};
        enemy[i].MoveAlg = -1;
    }
}

void enemy_deinit()
{

}