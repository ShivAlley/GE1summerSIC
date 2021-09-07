#ifndef OBJ2D_H
#define	OBJ2D_H

struct OBJ2D
{
	bool OnGround;
	char pad[3];
	VECTOR2 speed;
	VECTOR2 pos;
	VECTOR2 HalfSize;
	VECTOR2 scale;
	VECTOR2 TexPos;
	VECTOR2 TexSize;
	VECTOR2 pivot;
	float angle;
	VECTOR4 color;
	int HitPoint;
	int MoveAlg;
	unsigned int timer;
	int act;
	int AnimeKoma;
	int AnimeTimer;
	GameLib::Sprite* spr;

};

#endif //OBJ2D_H