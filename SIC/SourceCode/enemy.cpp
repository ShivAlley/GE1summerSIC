#include "all.h"

int EnemyState;



ENEMY_DATA EnemyData[] =
{
    {NULL, L"./Data/Images/enemy1twitbird.png", { 0, 0 }, { 256, 256 }, { 128, 128 }, },
    {NULL, L"./Data/Images/enemy1_player_target_bird.png", { 0, 0 }, { 256, 256 }, { 128, 128 }, },
    {NULL, L"./Data/Images/wind.png", { 0, 0 }, { 256, 256 }, { 128, 128 }, },
    {NULL, L"./Data/Images/wind.png", { 0, 0 }, { 256, 256 }, { 128, 128 }, },
    {NULL, L"./Data/Images/enemy4notmove_flyingbird.png", { 0, 0 }, { 256, 256 }, { 128, 128 }, },
};



OBJ2D enemy[ENEMY_MAX];

ENEMY_SET enemySet[] =
{
    {0,0,VECTOR2(SCREEN_W / 2, SCREEN_H )},
    {0,1,VECTOR2(SCREEN_W / 3, SCREEN_H * 3)},
    {1,0,VECTOR2(SCREEN_W / 2, SCREEN_H )},
    {1,1,VECTOR2(SCREEN_W, SCREEN_H * 3)},
    {0,2,VECTOR2(SCREEN_W / 3, SCREEN_H * 2)},
    {0,3,VECTOR2(SCREEN_W / 1.5f, SCREEN_H * 2)},
    {0,4,VECTOR2(SCREEN_W / 3, SCREEN_H * 6)},
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
        
        if (forcereset)
            game_reset();

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
            case 4:moveEnemy4(&enemy[i]); break;
            default: break;
            }
            ++enemy[i].timer;
            
        }
        //debug::setString("Enemy%d", sizeof(enemySet) / sizeof(ENEMY_SET));
        //debug::setString("timer%d", player.InvincibleTimer);
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
            VECTOR4(0, 1, 1, 0.4f)
        );
    }
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
        obj->speed.x = -1.0f;
        obj->color.w = 1.0f;

        ++obj->state;
        //fallthrough
    case 1:

        enemy_act(obj);
        obj->pos += obj->speed;

        if (obj->pos.x > SCREEN_W - obj->HalfSize.x) {
            obj->speed.x *= -1;
            obj->scale.x *= -1;
        }
        if (obj->pos.x < 0 + obj->HalfSize.x) {
            obj->speed.x *= -1;
            obj->scale.x *= -1;
        }
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

        obj->scale = { 0.5f, 0.5f };
        obj->spr = EnemyData[1].spr;
        obj->TexPos = EnemyData[1].texPos;
        obj->TexSize = EnemyData[1].texSize;
        obj->pivot = EnemyData[1].pivot;
        obj->HalfSize.y = MAPCHIP_SIZE;
        obj->HalfSize.x = MAPCHIP_SIZE;
        obj->angle = ToRadian(0);
        obj->color.w = 1.0f;

        
        

        if (obj->pos.y - player.pos.y < SCREEN_H)
            ++obj->state;
        else
        {
            break;
        }
        //fallthrough
    }
    case 1:
    {
        enemy_act(obj);
        
        if (HitCheck(&player, obj))
        {
            player.HitPoint--;
            player.InvincibleTimer = INVINCIBLE_TIMER;
            player.color.z += 0.33f;
        }
        float dx = player.pos.x - obj->pos.x;
        float dy = player.pos.y + player.speed.y * 32 - obj->pos.y;
        float dist = sqrtf(dx * dx + dy * dy);
        obj->speed = { dx / dist * 6,dy / dist * 6 };
        obj->pos += obj->speed;

        if (obj->speed.x > 0)
            obj->scale.x = fabs(obj->scale.x);
        else if(obj->speed.x < 0)
            obj->scale.x = fabs(obj->scale.x) * -1;

        if (obj->pos.y < player.pos.y)
            ++obj->state;
        else
        {
            break;
        }
    }//case1block
    case 2:
    {
        enemy_act(obj);
        obj->pos += obj->speed;
        if (HitCheck(&player, obj))
        {
            player.HitPoint--;
            player.InvincibleTimer = INVINCIBLE_TIMER;
            player.color.z += 0.33f;
        }
        
        
        break;
        
    }//case2block
    
    }
    //debug::setString("state%d", obj->state);
    return;
}

void moveEnemy2(OBJ2D* obj)
{
    switch (obj->state)
    {
    case 0:
    {

        obj->scale = { -0.5f, 0.5f };
        obj->spr = EnemyData[2].spr;
        obj->TexPos = EnemyData[2].texPos;
        obj->TexSize = EnemyData[2].texSize;
        obj->pivot = EnemyData[2].pivot;
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

        enemy_act(obj);

        
        if (HitCheck(&player, obj))
        {
            player.speed.x += 1;
            player.speed.y -=player.speed.y*GRAVITY;
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

        obj->scale = { 0.5f, 0.5f };
        obj->spr = EnemyData[3].spr;
        obj->TexPos = EnemyData[3].texPos;
        obj->TexSize = EnemyData[3].texSize;
        obj->pivot = EnemyData[3].pivot;
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

        enemy_act(obj);

        
        if (HitCheck(&player, obj))
        {
            player.speed.x -= 1;
            player.speed.y -= GRAVITY*player.speed.y;
        }
    }//case1block

    }
    return;
}

void moveEnemy4(OBJ2D* obj)
{
    switch (obj->state)
    {
    case 0:
        obj->scale = { 0.6f, 0.6f };
        obj->spr = EnemyData[4].spr;
        obj->TexPos = EnemyData[4].texPos;
        obj->TexSize = EnemyData[4].texSize;
        obj->pivot = EnemyData[4].pivot;
        obj->HalfSize.y = MAPCHIP_SIZE + MAPCHIP_HALFSIZE;
        obj->HalfSize.x = MAPCHIP_SIZE + MAPCHIP_HALFSIZE;
        obj->angle = ToRadian(0);
        obj->speed.x = 1.0f;
        obj->color.w = 1.0f;

        ++obj->state;
        //fallthrough
    case 1:

        enemy_act(obj);

        


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

void enemy_act_init(int action, OBJ2D* enemy)
{
    enemy->AnimeKoma = 0;
    enemy->AnimeTimer = 0;
    enemy->TexPos.y = enemy->TexSize.y * action;
    enemy->TexPos.x = 0;
}

void enemy_act(OBJ2D* enemy)
{
    //0=twitbird
    if (enemy->MoveAlg == 0)
    {

        switch (enemy->act)
        {
        case EnIDLE_INIT:
            ++enemy->act;
            //force fallthrough
        case EnIDLE:
            ++enemy->act;
            //force fallthrough
            //twitbird is not stop
        case EnMOVE_INIT:
            enemy_act_init(0, enemy);
            ++enemy->act;
            //fallthrough
        case EnMOVE:
            enemy->AnimeKoma = enemy->AnimeTimer / 12 % 2;
            enemy->TexPos.x = enemy->AnimeKoma * enemy->TexSize.x;
            ++enemy->AnimeTimer;


            break;
        case EnDEAD_INIT:
            enemy_act_init(1, enemy);
            ++enemy->act;
            //fallthrough
        case EnDEAD:
            //TODOneedanimation


            break;
        }
    }
    //1=hawk
    else if (enemy->MoveAlg == 1)
    {
        switch (enemy->act)
        {
        case EnIDLE_INIT:
            enemy_act_init(0, enemy);
            ++enemy->act;
        case EnIDLE:
            //no animation
            if (enemy->speed.y) {
                enemy->act = EnMOVE_INIT;
                break;
            }
            break;
        case EnMOVE_INIT:
            enemy_act_init(0, enemy);
            ++enemy->act;
            //fallthrough
        case EnMOVE:
            enemy->AnimeKoma = enemy->AnimeTimer / 6 % 3;
            enemy->TexPos.x = enemy->AnimeKoma * enemy->TexSize.x;
            ++enemy->AnimeTimer;


            break;
        case EnDEAD_INIT:
            enemy_act_init(1, enemy);
            ++enemy->act;
            //fallthrough
        
        case EnDEAD:
        
            enemy->TexPos.x = 0;
        
        
            

            break;

           
        }//case endead init ~ endead block
    }
    //2||3 = wind
    else if (enemy->MoveAlg == 2 || enemy->MoveAlg == 3)
    {
        switch (enemy->act)
        {
        case EnIDLE_INIT:
            enemy_act_init(0, enemy);
            ++enemy->act;
            //fallthrough
        case EnIDLE:
            enemy->AnimeKoma = enemy->AnimeTimer / 8 % 4;
            enemy->TexPos.x = enemy->AnimeKoma * enemy->TexSize.x;
            ++enemy->AnimeTimer;
            break;
        }
    }
    //4 = not move bird
    else if (enemy->MoveAlg == 4)
    {
        switch (enemy->act)
        {
        case EnIDLE_INIT:
            enemy_act_init(0, enemy);
            ++enemy->act;
            //fallthrough
        case EnIDLE:
            enemy->AnimeKoma = enemy->AnimeTimer / 12 % 2;
            enemy->TexPos.x = enemy->AnimeKoma * enemy->TexSize.x;
            ++enemy->AnimeTimer;
            break;
        case EnDEAD_INIT:
            //TODOneedanimation
            break;
        }
    }
}

