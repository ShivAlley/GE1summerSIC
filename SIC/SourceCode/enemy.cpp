#include "all.h"

int EnemyState;



ENEMY_DATA EnemyData[] =
{
    {NULL, L"./Data/Images/stickman.png", { 0, 0 }, { 128, 128 }, { 64, 64 }, },

};



OBJ2D enemy[ENEMY_MAX];

ENEMY_SET enemySet[] =
{
    {0,0,VECTOR2(SCREEN_W / 2, SCREEN_H )},
    {0,1,VECTOR2(SCREEN_W / 3, SCREEN_H * 3)},
    {1,0,VECTOR2(SCREEN_W / 2, SCREEN_H )},
    {1,1,VECTOR2(SCREEN_W, SCREEN_H * 3)},
    {0,2,VECTOR2(SCREEN_W / 3, SCREEN_H * 2)},
    {-1,-1,{}},

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
            case 1:moveEnemy1(&enemy[i]); break;
            case 2:moveEnemy2(&enemy[i]); break;
            case 3:moveEnemy3(&enemy[i]); break;
            default: break;
            }
            ++enemy[i].timer;
            
        }
        //debug::setString("Enemy%d", sizeof(enemySet) / sizeof(ENEMY_SET));
        debug::setString("timer%d", player.InvincibleTimer);
    }

    } //switch}


}

void enemy_render()
{

    for (int i = 0; i < ENEMY_MAX; ++i)
    {

        if (enemy[i].MoveAlg == -1) continue;
        if (enemy[i].area != player.area) continue;
        sprite_render(
            enemy[i].spr,
            enemy[i].pos.x - scroll.x, enemy[i].pos.y - scroll.y,
            enemy[i].scale.x, enemy[i].scale.y,
            enemy[i].TexPos.x, enemy[i].TexPos.y,
            enemy[i].TexSize.x, enemy[i].TexSize.y,
            enemy[i].pivot.x, enemy[i].pivot.y,
            ToRadian(0),
            1, 1, 1, enemy[i].color.w
        );
        primitive::rect(
            enemy[i].pos - scroll, enemy[i].HalfSize * 2,
            enemy[i].HalfSize,
            enemy[i].angle,
            VECTOR4(1, 1, 1, enemy[i].color.w)
        );
    }
}
void moveEnemy0(OBJ2D* obj)
{
    switch (obj->state)
    {
    case 0:
        obj->scale = { 1.0f, 1.0f };
        obj->spr = EnemyData[0].spr;
        obj->TexPos = EnemyData[0].texPos;
        obj->TexSize = EnemyData[0].texSize;
        obj->pivot = EnemyData[0].pivot;
        obj->HalfSize.y = MAPCHIP_SIZE;
        obj->HalfSize.x = MAPCHIP_SIZE * 2;
        obj->angle = ToRadian(0);
        obj->speed.x = 1.0f;
        obj->color.w = 1.0f;

        ++obj->state;
        //fallthrough
    case 1:

        //enemy_act(obj);

        obj->pos.x += obj->speed.x;

        if (obj->pos.x > SCREEN_W - obj->HalfSize.x)
            obj->speed.x *= -1;
        if (obj->pos.x < 0 + obj->HalfSize.x)
            obj->speed.x *= -1;
        if (HitCheck(&player, obj))
        {
            player.HitPoint--;
            player.InvincibleTimer = INVINCIBLE_TIMER;
            player.color.z += 0.33f;
        }
        
        break;
    }
    return;
}
void moveEnemy1(OBJ2D* obj)
{
    switch (obj->state)
    {
    case 0:
    {

        obj->scale = { 1.0f, 1.0f };
        obj->spr = EnemyData[0].spr;
        obj->TexPos = EnemyData[0].texPos;
        obj->TexSize = EnemyData[0].texSize;
        obj->pivot = EnemyData[0].pivot;
        obj->HalfSize.y = MAPCHIP_SIZE;
        obj->HalfSize.x = MAPCHIP_SIZE;
        obj->angle = ToRadian(0);
        obj->color.w = 1.0f;

        
        

        if (obj->pos.y - player.pos.y < SCREEN_H / 2 )++obj->state;

        //fallthrough
    }
    case 1:
    {
        //enemy_act(obj);
        
        if (HitCheck(&player, obj))
        {
            player.HitPoint--;
            player.InvincibleTimer = INVINCIBLE_TIMER;
            player.color.z += 0.33f;
        }
        float dx = player.pos.x - obj->pos.x;
        float dy = player.pos.y + player.speed.y * 16 - obj->pos.y;
        float dist = sqrtf(dx * dx + dy * dy);
        obj->speed = { dx / dist * 5,dy / dist * 5 };
        if (obj->pos.y - player.pos.y <= SCREEN_H)
            ++obj->state;
        
        break;
    }//case1block
    case 2:
    {
        //enemy_act(obj);
        obj->pos += obj->speed;
        if (HitCheck(&player, obj))
        {
            player.HitPoint--;
            player.InvincibleTimer = INVINCIBLE_TIMER;
            player.color.z += 0.33f;
        }
        
        obj->pos += obj->speed;
        
    break;
        
    }//case2block
    
    }
    return;
}

void moveEnemy2(OBJ2D* obj)
{
    switch (obj->state)
    {
    case 0:
    {

        obj->scale = { 1.0f, 1.0f };
        obj->spr = EnemyData[0].spr;
        obj->TexPos = EnemyData[0].texPos;
        obj->TexSize = EnemyData[0].texSize;
        obj->pivot = EnemyData[0].pivot;
        obj->HalfSize.y = MAPCHIP_SIZE * 2;
        obj->HalfSize.x = MAPCHIP_SIZE * 2;
        obj->angle = ToRadian(0);
        obj->speed.x = 1.0f;
        obj->color.w = 1.0f;

        ++obj->state;
        //fallthrough
    }
    case 1:
    {

        //enemy_act(obj);

        //TODO:from shibutani
        //当たると風に押し返されるような動き
        if (HitCheck(&player, obj))
        {
            player.speed.x += 1;
            player.speed.y -= GRAVITY* player.speed.y;
        }
    }//case1block
        
    }
    return;
}

void moveEnemy3(OBJ2D* obj)
{
    switch (obj->state)
    {
    case 0:
    {

        obj->scale = { 1.0f, 1.0f };
        obj->spr = EnemyData[0].spr;
        obj->TexPos = EnemyData[0].texPos;
        obj->TexSize = EnemyData[0].texSize;
        obj->pivot = EnemyData[0].pivot;
        obj->HalfSize.y = MAPCHIP_SIZE * 2;
        obj->HalfSize.x = MAPCHIP_SIZE * 2;
        obj->angle = ToRadian(0);
        obj->speed.x = 1.0f;
        obj->color.w = 1.0f;

        ++obj->state;
        //fallthrough
    }
    case 1:
    {

        //enemy_act(obj);

        //TODO:from shibutani
        //当たると風に押し返されるような動き
        if (HitCheck(&player, obj))
        {
            player.speed.x -= 1;
            player.speed.y -= GRAVITY * player.speed.y;
        }
    }//case1block

    }
    return;
}
void enemy_init()
{
    EnemyState = 0;
    for (int i = 0; i < ENEMY_MAX; ++i)
    {
        enemy[i] = {};
        enemy[i].MoveAlg = -1;
    }
}

void enemy_deinit()
{
    int dataNum = sizeof(EnemyData) / sizeof(ENEMY_DATA);
    for (int i = 0; i < dataNum; ++i)
    {
        safe_delete(EnemyData[i].spr);
    }
}