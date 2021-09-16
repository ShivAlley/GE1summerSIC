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
    {0, 0, VECTOR2(1152,2144)},
{0, 0, VECTOR2(138,2558)},
{0, 0, VECTOR2(1020,3662)},
{0, 0, VECTOR2(942,3861)},
{0, 1, VECTOR2(1029,9902)},
{0, 2, VECTOR2(233,16789)},
{0, 3, VECTOR2(903,18799)},
{0, 4, VECTOR2(324,11595)},
{0, 4, VECTOR2(958,13444)},
{0, 0, VECTOR2(1152,24251)},
{0, 2, VECTOR2(1022,3243)},
{0, 2, VECTOR2(128,5081)},
{0, 2, VECTOR2(603,4395)},
{0, 4, VECTOR2(588,12677)},
{0, 4, VECTOR2(273,14542)},
{0, 0, VECTOR2(1119,15688)},
{0, 2, VECTOR2(336,17245)},
{0, 2, VECTOR2(336,17245)},
{0, 3, VECTOR2(1050,18246)},
{0, 1, VECTOR2(128,22382)},
{0, 1, VECTOR2(373,22607)},
{0, 0, VECTOR2(128,23961)},
{0, 4, VECTOR2(458,25393)},
{0, 4, VECTOR2(941,25768)},
{0, 4, VECTOR2(732,14094)},
{0, 4, VECTOR2(887,15893)},

{1, 0, VECTOR2(1018,693)},
{1, 0, VECTOR2(183,1081)},
{1, 4, VECTOR2(640,1868)},
{1, 1, VECTOR2(206,5549)},
{1, 1, VECTOR2(1152,8677)},
{1, 2, VECTOR2(248,3611)},
{1, 3, VECTOR2(927,3269)},
{1, 1, VECTOR2(128,20030)},
{1, 1, VECTOR2(1152,20816)},
{1, 4, VECTOR2(877,21248)},
{1, 4, VECTOR2(248,20734)},
{1, 0, VECTOR2(1152,16110)},
{1, 0, VECTOR2(128,15465)},
{1, 0, VECTOR2(173,12580)},
{1, 0, VECTOR2(128,17678)},
{1, 1, VECTOR2(271,12072)},
{1, 1, VECTOR2(1107,14838)},
{1, 0, VECTOR2(1152,10979)},
{1, 0, VECTOR2(1152,6458)},
{1, 0, VECTOR2(1119,3400)},
{1, 4, VECTOR2(228,2925)},
{1, 4, VECTOR2(236,2545)},
{1, 2, VECTOR2(1114,3012)},
{1, 4, VECTOR2(999,15789)},
{1, 0, VECTOR2(1152,19855)},
{1, 0, VECTOR2(173,12580)},
{1, 0, VECTOR2(128,17678)},
{2, 1, VECTOR2(1119,1793)},
{2, 1, VECTOR2(205,2596)},
{2, 0, VECTOR2(1067,447)},
{2, 0, VECTOR2(1109,3533)},
{2, 0, VECTOR2(128,7064)},
{2, 0, VECTOR2(264,7767)},
{2, 0, VECTOR2(1152,10924)},
{2, 0, VECTOR2(723,12754)},
{2, 0, VECTOR2(128,12105)},
{2, 0, VECTOR2(989,15682)},
{2, 0, VECTOR2(128,18922)},
{2, 0, VECTOR2(563,20300)},
{2, 0, VECTOR2(147,23195)},
{2, 0, VECTOR2(1152,25695)},
{2, 4, VECTOR2(319,1116)},
{2, 3, VECTOR2(1131,589)},
{2, 3, VECTOR2(871,1235)},
{2, 2, VECTOR2(166,3065)},
{2, 4, VECTOR2(1017,3104)},
{2, 4, VECTOR2(1037,4431)},
{2, 4, VECTOR2(128,5000)},
{2, 4, VECTOR2(1074,6662)},
{2, 2, VECTOR2(620,6424)},
{2, 2, VECTOR2(725,6543)},
{2, 4, VECTOR2(1144,6827)},
{2, 4, VECTOR2(230,7541)},
{2, 1, VECTOR2(164,10661)},
{2, 1, VECTOR2(1152,10225)},
{2, 1, VECTOR2(288,13365)},
{2, 1, VECTOR2(1074,15475)},
{2, 1, VECTOR2(128,15265)},
{2, 1, VECTOR2(128,21642)},
{2, 3, VECTOR2(999,20791)},
{2, 2, VECTOR2(202,21522)},
{2, 3, VECTOR2(659,25317)},
{2, 4, VECTOR2(128,26848)},
{2, 4, VECTOR2(1152,28175)},
{2, 0, VECTOR2(1152,27416)},
{3, 0, VECTOR2(1152,1109)},
{3, 0, VECTOR2(219,1529)},
{3, 0, VECTOR2(182,3020)},
{3, 0, VECTOR2(176,4980)},
{3, 0, VECTOR2(996,6927)},
{3, 0, VECTOR2(128,10284)},
{3, 0, VECTOR2(1059,13285)},
{3, 0, VECTOR2(1059,13720)},
{3, 0, VECTOR2(128,16410)},
{3, 0, VECTOR2(404,17566)},
{3, 0, VECTOR2(932,18927)},
{3, 0, VECTOR2(1125,19392)},
{3, 0, VECTOR2(128,22797)},
{3, 0, VECTOR2(1152,24627)},
{3, 0, VECTOR2(164,26816)},
{3, 0, VECTOR2(374,27981)},
{3, 0, VECTOR2(1152,29752)},
{3, 0, VECTOR2(507,30997)},
{3, 0, VECTOR2(245,32593)},
{3, 0, VECTOR2(139,33259)},
{3, 0, VECTOR2(338,34368)},
{3, 0, VECTOR2(1152,35268)},
{3, 0, VECTOR2(183,35682)},

{ 3, 1, VECTOR2(128,591) },
{ 3, 1, VECTOR2(1041,926) },
{ 3, 1, VECTOR2(1152,3598) },
{ 3, 1, VECTOR2(134,4846) },
{ 3, 1, VECTOR2(1037,7696) },
{ 3, 1, VECTOR2(176,9482) },
{ 3, 1, VECTOR2(501,10517) },
{ 3, 1, VECTOR2(921,12368) },
{ 3, 1, VECTOR2(128,14448) },
{ 3, 1, VECTOR2(200,16281) },
{ 3, 1, VECTOR2(1034,18346) },
{ 3, 1, VECTOR2(128,20213) },
{ 3, 1, VECTOR2(1082,22383) },
{ 3, 1, VECTOR2(128,23523) },
{ 3, 1, VECTOR2(359,25159) },
{ 3, 1, VECTOR2(1025,26644) },
{ 3, 1, VECTOR2(749,27821) },
{ 3, 1, VECTOR2(539,28811) },
{ 3, 1, VECTOR2(263,30137) },
{ 3, 1, VECTOR2(563,31313) },
{ 3, 1, VECTOR2(1152,32637) },
{ 3, 1, VECTOR2(774,33474) },
{ 3, 1, VECTOR2(321,35221) },
{ 3, 1, VECTOR2(672,35474) },
{ 3, 1, VECTOR2(1152,35808) },
{ 3, 0, VECTOR2(1152,1109) },
{ 3, 0, VECTOR2(219,1529) },
{ 3, 0, VECTOR2(182,3020) },
{ 3, 0, VECTOR2(176,4980) },
{ 3, 0, VECTOR2(996,6927) },
{ 3, 0, VECTOR2(128,10284) },
{ 3, 0, VECTOR2(1059,13285) },
{ 3, 0, VECTOR2(1059,13720) },
{ 3, 0, VECTOR2(128,16410) },
{ 3, 0, VECTOR2(404,17566) },
{ 3, 0, VECTOR2(932,18927) },
{ 3, 0, VECTOR2(1125,19392) },
{ 3, 0, VECTOR2(128,22797) },
{ 3, 0, VECTOR2(1152,24627) },
{ 3, 0, VECTOR2(164,26816) },
{ 3, 0, VECTOR2(374,27981) },
{ 3, 0, VECTOR2(1152,29752) },
{ 3, 0, VECTOR2(507,30997) },
{ 3, 0, VECTOR2(245,32593) },
{ 3, 0, VECTOR2(139,33259) },
{ 3, 0, VECTOR2(338,34368) },
{ 3, 0, VECTOR2(1152,35268) },
{ 3, 0, VECTOR2(183,35682) },
{ 3, 1, VECTOR2(128,591) },
{ 3, 1, VECTOR2(1041,926) },
{ 3, 1, VECTOR2(1152,3598) },
{ 3, 1, VECTOR2(134,4846) },
{ 3, 1, VECTOR2(1037,7696) },
{ 3, 1, VECTOR2(176,9482) },
{ 3, 1, VECTOR2(501,10517) },
{ 3, 1, VECTOR2(921,12368) },
{ 3, 1, VECTOR2(128,14448) },
{ 3, 1, VECTOR2(200,16281) },
{ 3, 1, VECTOR2(1034,18346) },
{ 3, 1, VECTOR2(128,20213) },
{ 3, 1, VECTOR2(1082,22383) },
{ 3, 1, VECTOR2(128,23523) },
{ 3, 1, VECTOR2(359,25159) },
{ 3, 1, VECTOR2(1025,26644) },
{ 3, 1, VECTOR2(749,27821) },
{ 3, 1, VECTOR2(539,28811) },
{ 3, 1, VECTOR2(263,30137) },
{ 3, 1, VECTOR2(563,31313) },
{ 3, 1, VECTOR2(1152,32637) },
{ 3, 1, VECTOR2(774,33474) },
{ 3, 1, VECTOR2(321,35221) },
{ 3, 1, VECTOR2(672,35474) },
{ 3, 1, VECTOR2(1152,35808) },
{ 3, 2, VECTOR2(627,807) },
{ 3, 3, VECTOR2(131,1304) },
{ 3, 3, VECTOR2(1083,1285) },
{ 3, 2, VECTOR2(180,1721) },
{ 3, 2, VECTOR2(377,2462) },
{ 3, 3, VECTOR2(997,3247) },
{ 3, 3, VECTOR2(862,3393) },
{ 3, 4, VECTOR2(128,4486) },
{ 3, 4, VECTOR2(1152,7516) },
{ 3, 4, VECTOR2(128,10115) },
{ 3, 4, VECTOR2(1066,12755) },
{ 3, 3, VECTOR2(818,12648) },
{ 3, 2, VECTOR2(141,14352) },
{ 3, 4, VECTOR2(766,15550) },
{ 3, 0, VECTOR2(306,15969) },
{ 3, 0, VECTOR2(827,17276) },
{ 3, 2, VECTOR2(999,18388) },
{ 3, 2, VECTOR2(950,19965) },
{ 3, 3, VECTOR2(135,21421) },
{ 3, 3, VECTOR2(541,23017) },
{ 3, 2, VECTOR2(318,24237) },
{ 3, 2, VECTOR2(893,24883) },
{ 3, 4, VECTOR2(1016,26096) },
{ 3, 3, VECTOR2(971,27806) },
{ 3, 2, VECTOR2(179,30439) },
{ 3, 3, VECTOR2(558,31423) },
{ 3, 4, VECTOR2(527,33019) },
{ 3, 2, VECTOR2(312,35037) },
{ 3, 3, VECTOR2(1087,35503) },
{ 3, 0, VECTOR2(1152,8405) },
{ 3, 0, VECTOR2(264,9808) },
{ 3, 1, VECTOR2(656,9229) },
{ 3, 4, VECTOR2(1142,9770) },
{ 3, 0, VECTOR2(1067,10954) },
{ 3, 1, VECTOR2(143,12046) },
{ 3, 0, VECTOR2(1152,1109) },
{ 3, 0, VECTOR2(219,1529) },
{ 3, 0, VECTOR2(182,3020) },
{ 3, 0, VECTOR2(176,4980) },
{ 3, 0, VECTOR2(996,6927) },
{ 3, 0, VECTOR2(128,10284) },
{ 3, 0, VECTOR2(1059,13285) },
{ 3, 0, VECTOR2(1059,13720) },
{ 3, 0, VECTOR2(128,16410) },
{ 3, 0, VECTOR2(404,17566) },
{ 3, 0, VECTOR2(932,18927) },
{ 3, 0, VECTOR2(1125,19392) },
{ 3, 0, VECTOR2(128,22797) },
{ 3, 0, VECTOR2(1152,24627) },
{ 3, 0, VECTOR2(164,26816) },
{ 3, 0, VECTOR2(374,27981) },
{ 3, 0, VECTOR2(1152,29752) },
{ 3, 0, VECTOR2(507,30997) },
{ 3, 0, VECTOR2(245,32593) },
{ 3, 0, VECTOR2(139,33259) },
{ 3, 0, VECTOR2(338,34368) },
{ 3, 0, VECTOR2(1152,35268) },
{ 3, 0, VECTOR2(183,35682) },
{ 3, 1, VECTOR2(128,591) },
{ 3, 1, VECTOR2(1041,926) },
{ 3, 1, VECTOR2(1152,3598) },
{ 3, 1, VECTOR2(134,4846) },
{ 3, 1, VECTOR2(1037,7696) },
{ 3, 1, VECTOR2(176,9482) },
{ 3, 1, VECTOR2(501,10517) },
{ 3, 1, VECTOR2(921,12368) },
{ 3, 1, VECTOR2(128,14448) },
{ 3, 1, VECTOR2(200,16281) },
{ 3, 1, VECTOR2(1034,18346) },
{ 3, 1, VECTOR2(128,20213) },
{ 3, 1, VECTOR2(1082,22383) },
{ 3, 1, VECTOR2(128,23523) },
{ 3, 1, VECTOR2(359,25159) },
{ 3, 1, VECTOR2(1025,26644) },
{ 3, 1, VECTOR2(749,27821) },
{ 3, 1, VECTOR2(539,28811) },
{ 3, 1, VECTOR2(263,30137) },
{ 3, 1, VECTOR2(563,31313) },
{ 3, 1, VECTOR2(1152,32637) },
{ 3, 1, VECTOR2(774,33474) },
{ 3, 1, VECTOR2(321,35221) },
{ 3, 1, VECTOR2(672,35474) },
{ 3, 1, VECTOR2(1152,35808) },
{ 3, 2, VECTOR2(627,807) },
{ 3, 3, VECTOR2(131,1304) },
{ 3, 3, VECTOR2(1083,1285) },
{ 3, 2, VECTOR2(180,1721) },
{ 3, 2, VECTOR2(377,2462) },
{ 3, 3, VECTOR2(997,3247) },
{ 3, 3, VECTOR2(862,3393) },
{ 3, 4, VECTOR2(128,4486) },
{ 3, 4, VECTOR2(1152,7516) },
{ 3, 4, VECTOR2(128,10115) },
{ 3, 4, VECTOR2(1066,12755) },
{ 3, 3, VECTOR2(818,12648) },
{ 3, 2, VECTOR2(141,14352) },
{ 3, 4, VECTOR2(766,15550) },
{ 3, 0, VECTOR2(306,15969) },
{ 3, 0, VECTOR2(827,17276) },
{ 3, 2, VECTOR2(999,18388) },
{ 3, 2, VECTOR2(950,19965) },
{ 3, 3, VECTOR2(135,21421) },
{ 3, 3, VECTOR2(541,23017) },
{ 3, 2, VECTOR2(318,24237) },
{ 3, 2, VECTOR2(893,24883) },
{ 3, 4, VECTOR2(1016,26096) },
{ 3, 3, VECTOR2(971,27806) },
{ 3, 2, VECTOR2(179,30439) },
{ 3, 3, VECTOR2(558,31423) },
{ 3, 4, VECTOR2(527,33019) },
{ 3, 2, VECTOR2(312,35037) },
{ 3, 3, VECTOR2(1087,35503) },
{ 3, 0, VECTOR2(1152,8405) },
{ 3, 0, VECTOR2(264,9808) },
{ 3, 1, VECTOR2(656,9229) },
{ 3, 4, VECTOR2(1142,9770) },
{ 3, 0, VECTOR2(1067,10954) },
{ 3, 1, VECTOR2(143,12046) },
{ 3, 3, VECTOR2(817,35096) },
{ 3, 4, VECTOR2(393,6590) },
{ 3, 2, VECTOR2(387,5738) },
{ 3, 2, VECTOR2(529,6047) },
{ 3, 3, VECTOR2(451,7095) },
{ 3, 3, VECTOR2(896,8811) },
{ 3, 2, VECTOR2(386,9461) },
{ 3, 2, VECTOR2(167,13117) },
{ 3, 2, VECTOR2(473,14000) },
{ 3, 3, VECTOR2(996,15138) },
{ 3, 3, VECTOR2(1019,16739) },
{ 3, 3, VECTOR2(504,18126) },
{ 3, 4, VECTOR2(282,19157) },
{ 3, 3, VECTOR2(747,18300) },
{ 3, 3, VECTOR2(474,18545) },
{ 3, 2, VECTOR2(838,21129) },
{ 3, 3, VECTOR2(905,29017) },
{ 3, 4, VECTOR2(896,30250) },
{ 3, 2, VECTOR2(349,34138) },
{ 3, 4, VECTOR2(352,35419) },

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

