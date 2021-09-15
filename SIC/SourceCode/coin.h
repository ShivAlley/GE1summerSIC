#ifndef COIN_H
#define COIN_H



void coin_update();
void coin_render();
void coin_init();
void coin_deinit();

#define COIN_MAX 1000


extern int CoinState;
extern int getCoinCount;


#endif // !COIN_H
