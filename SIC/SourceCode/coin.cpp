#include "all.h"

int CoinState;

ENEMY_DATA CoinData = 
{ 
	NULL, 
	L"./Data/Images/archer.png", 
	{ 0, 0 }, 
	{ 128, 128 }, 
	{ 64, 64 }, 
};

OBJ2D coin[COIN_MAX];

ENEMY_SET CoinSet[] =
{
	{0,0,VECTOR2(SCREEN_W / 3, SCREEN_H / 2)},
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
		objcoin->scale = VECTOR2(1.0f, 1.0f);
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
			player.HitPoint++; //HACK:ちゃんと存在しているかのチェックです
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
			coin[i].pivot.x, coin[i].pivot.y,
			ToRadian(0),
			1, 1, 1, coin[i].color.w
		);
		primitive::rect(
			coin[i].pos - scroll,
			coin[i].HalfSize * 2,
			coin[i].HalfSize,
			ToRadian(0),
			VECTOR4(1, 1, 0, coin[i].color.w)
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