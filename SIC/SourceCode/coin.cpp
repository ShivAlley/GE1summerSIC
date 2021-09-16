#include "all.h"

int CoinState;
int getCoinCount = 0;

ENEMY_DATA CoinData = 
{ 
	NULL, 
	L"./Data/Images/mail.png", 
	{ 0, 0 }, 
	{ 128, 128 }, 
	{ 64, 64 }, 
};

OBJ2D coin[COIN_MAX];

ENEMY_SET CoinSet[] =
{
	{0,0,VECTOR2(SCREEN_W / 3, SCREEN_H / 2)},
	{0, 0, VECTOR2(413,16245)},
{0, 0, VECTOR2(1038,17675)},
{0, 0, VECTOR2(848,17865)},
{0, 0, VECTOR2(218,18607)},
{0, 0, VECTOR2(408,19616)},
{0, 0, VECTOR2(642,20922)},
{0, 0, VECTOR2(1074,22745)},
{0, 0, VECTOR2(249,23738)},
{0, 0, VECTOR2(655,24995)},
{0, 0, VECTOR2(346,26067)},
{0, 0, VECTOR2(959,28297)},
{1, 0, VECTOR2(130,1288)},
{1, 0, VECTOR2(994,2363)},
{1, 0, VECTOR2(986,4516)},
{1, 0, VECTOR2(282,6110)},
{1, 0, VECTOR2(1050,7833)},
{1, 0, VECTOR2(233,10314)},
{1, 0, VECTOR2(804,12561)},
{1, 0, VECTOR2(238,15745)},
{1, 0, VECTOR2(979,17486)},
{1, 0, VECTOR2(376,19434)},
{1, 0, VECTOR2(1069,19982)},
{1, 0, VECTOR2(335,21061)},
{1, 0, VECTOR2(828,20521)},
{2, 0, VECTOR2(186,815)},
{2, 0, VECTOR2(364,1813)},
{2, 0, VECTOR2(959,2296)},
{2, 0, VECTOR2(461,2692)},
{2, 0, VECTOR2(626,3332)},
{2, 0, VECTOR2(395,3604)},
{2, 0, VECTOR2(720,4199)},
{2, 0, VECTOR2(222,5232)},
{2, 0, VECTOR2(226,6497)},
{2, 0, VECTOR2(994,6102)},
{2, 0, VECTOR2(877,7241)},
{2, 0, VECTOR2(233,8921)},
{2, 0, VECTOR2(233,10391)},
{2, 0, VECTOR2(414,11115)},
{2, 0, VECTOR2(900,11967)},
{2, 0, VECTOR2(496,12529)},
{2, 0, VECTOR2(972,13793)},
{2, 0, VECTOR2(839,14559)},
{2, 0, VECTOR2(221,15036)},
{2, 0, VECTOR2(785,15955)},
{2, 0, VECTOR2(308,16565)},
{2, 0, VECTOR2(128,17638)},
{2, 0, VECTOR2(555,18713)},
{2, 0, VECTOR2(306,19550)},
{2, 0, VECTOR2(459,20015)},
{2, 0, VECTOR2(905,19995)},
{2, 0, VECTOR2(502,21234)},
{2, 0, VECTOR2(1074,22573)},
{2, 0, VECTOR2(368,23911)},
{2, 0, VECTOR2(865,25040)},
{2, 0, VECTOR2(198,26627)},
{2, 0, VECTOR2(641,27882)},
{2, 0, VECTOR2(374,28379)},
{2, 0, VECTOR2(752,28620)},

{3, 0, VECTOR2(930,699)},
{3, 0, VECTOR2(357,1511)},
{3, 0, VECTOR2(261,2053)},
{3, 0, VECTOR2(1152,3154)},
{3, 0, VECTOR2(227,4316)},
{3, 0, VECTOR2(300,4142)},
{3, 0, VECTOR2(910,4803)},
{3, 0, VECTOR2(469,5561)},
{3, 0, VECTOR2(1123,6832)},
{3, 0, VECTOR2(1003,6832)},
{3, 0, VECTOR2(1016,6385)},
{3, 0, VECTOR2(193,6808)},
{3, 0, VECTOR2(939,8191)},
{3, 0, VECTOR2(1110,8844)},
{3, 0, VECTOR2(128,9097)},
{3, 0, VECTOR2(947,9974)},
{3, 0, VECTOR2(229,10599)},
{3, 0, VECTOR2(975,11556)},
{3, 0, VECTOR2(374,13000)},
{3, 0, VECTOR2(1016,13553)},
{3, 0, VECTOR2(817,13816)},
{3, 0, VECTOR2(1086,14670)},
{3, 0, VECTOR2(876,14970)},
{3, 0, VECTOR2(298,15751)},
{3, 0, VECTOR2(379,15961)},
{3, 0, VECTOR2(173,17145)},
{3, 0, VECTOR2(309,17376)},
{3, 0, VECTOR2(128,18745)},
{3, 0, VECTOR2(436,18963)},
{3, 0, VECTOR2(1151,18510)},
{3, 0, VECTOR2(1152,18624)},
{3, 0, VECTOR2(1152,18777)},
{3, 0, VECTOR2(1152,20389)},
{3, 0, VECTOR2(926,20834)},
{3, 0, VECTOR2(1152,21484)},
{3, 0, VECTOR2(486,21184)},
{3, 0, VECTOR2(614,22557)},
{3, 0, VECTOR2(263,23728)},
{3, 0, VECTOR2(1152,24878)},
{3, 0, VECTOR2(206,24840)},
{3, 0, VECTOR2(278,24973)},
{3, 0, VECTOR2(401,25109)},
{3, 0, VECTOR2(534,25993)},
{3, 0, VECTOR2(303,27262)},
{3, 0, VECTOR2(1152,27585)},
{3, 0, VECTOR2(155,28538)},
{3, 0, VECTOR2(128,29594)},
{3, 0, VECTOR2(1131,29051)},
{3, 0, VECTOR2(953,30859)},
{3, 0, VECTOR2(1058,31184)},
{3, 0, VECTOR2(128,32363)},
{3, 0, VECTOR2(1094,33424)},
{3, 0, VECTOR2(291,33514)},
{3, 0, VECTOR2(128,33980)},
{3, 0, VECTOR2(1041,34866)},
{3, 0, VECTOR2(128,35679)},
{3, 0, VECTOR2(128,35379)},
{ 3, 0, VECTOR2(902,35797) },

	{-1,-1,{}},//endflag
};

OBJ2D* searchSetCoin(OBJ2D coin[], int CoMax, int moveAlg, VECTOR2 pos)
{
	for (int i = 0; i < CoMax; ++i)
	{
		if (coin[i].MoveAlg != -1)continue;
		coin[i] = {};
		coin[i].MoveAlg = moveAlg;
		coin[i].pos = pos;
		return &coin[i];
	}
	return NULL;
}

void NormalCoin0(OBJ2D* objcoin)
{
	switch (objcoin->state)
	{
	case 0:
		objcoin->scale = VECTOR2(0.5f, 0.5f);
		objcoin->spr = CoinData.spr;
		objcoin->TexPos = CoinData.texPos;
		objcoin->TexSize = CoinData.texSize;
		objcoin->pivot = CoinData.pivot;
		objcoin->HalfSize = VECTOR2(MAPCHIP_SIZE, MAPCHIP_SIZE);
		objcoin->color.w = 1.0f;
		++objcoin->state;
		//fallthrough
	case 1:
		if (HitCheck(&player, objcoin))
		{
			++getCoinCount;
			objcoin->MoveAlg = -1;
			
		}
	

		break;
	}
}


void coin_update()
{
	switch (CoinState)
	{
	case 0:
	{

		CoinData.spr = sprite_load(CoinData.filepath);
		++CoinState;
		//fallthrough
	}
	case 1:
	{
		for (int i = 0; i < COIN_MAX; ++i)
		{
			coin[i] = {};
			coin[i].MoveAlg = -1;
		}

		for (int i = 0; ; ++i)
		{
			if (CoinSet[i].enemyType == -1)
				break;
			OBJ2D* coinp = searchSetCoin(coin, COIN_MAX, CoinSet[i].enemyType, CoinSet[i].pos);
			if (!coinp) break;
			coinp->area = CoinSet[i].area;
		}

	}
		++CoinState;
		//fallthrough
	case 2:
	{
		for (int i = 0; i < COIN_MAX; ++i)
		{
			if (coin[i].MoveAlg == -1)continue;
			if (player.area != coin[i].area) continue;
			switch (coin[i].MoveAlg)
			{
			case 0:NormalCoin0(&coin[i]); break;

			default:
				break;
			}
		}
		//debug::setString("coincount%d", getCoinCount);


	}



	}
}

void coin_render()
{
	for (int i = 0; i < COIN_MAX; ++i)
	{
		if (coin[i].MoveAlg == -1)continue;
		if (coin[i].area != player.area)continue;
		
		sprite_render(
			coin[i].spr,
			coin[i].pos.x - scroll.x, coin[i].pos.y - scroll.y,
			coin[i].scale.x, coin[i].scale.y,
			coin[i].TexPos.x, coin[i].TexPos.y,
			coin[i].TexSize.x, coin[i].TexSize.y,
			coin[i].pivot.x, coin[i].pivot.y,
			ToRadian(0),
			1, 1, 1, 1
		);
		
	}
}

void coin_init()
{
	CoinState = 0;
	for (int i = 0; i < COIN_MAX; ++i)
	{
		coin[i] = {};
		coin[i].MoveAlg = -1;
	}
}

void coin_deinit()
{
	safe_delete(CoinData.spr);
}