#pragma once
#include "stdafx.h"
#include "Sprite.h"
#include "Setup.h"

class Chara
{
public:
	Chara(CSetup* Passed_Setup, int *Passed_SpriteX, int *Passed_SpriteY, int *Passed_SpriteVx, int *Passed_SpriteVy, int *Passed_SpriteWidth, int *Passed_SpriteHeight, float *CamX, float *CamY, int *Passed_ScreenWidth, int *Passed_ScreenHeight, int *Passed_LvWidth, int *Passed_LvHeight);
	//Chara(CSetup* Passed_Setup, int *Passed_SpriteX, int *Passed_SpriteY, int *Passed_SpriteVx, int *Passed_SpriteVy, int *Passed_SpriteWidth, int *Passed_SpriteHeight, int *Passed_LvWidth, int *Passed_LvHeight);
	~Chara();

	void Update();
	void Draw();

private:
	CSetup* csetup;

	CSprite* character;
	int TimeCheck;

	int *SpriteX;
	int *SpriteY;
	int *SpriteVx;
	int *SpriteVy;
	int *SpriteWidth;
	int *SpriteHeight;

	float *CamX;
	float *CamY;

	int *ScreenWidth;
	int *ScreenHeight;
	int MidScreenWidth;
	int MidScreenHeight;

	int *LvWidth;
	int *LvHeight;

	int StartFrame;
	int EndFrame;
	int Row;
	int Speed = 200;

	bool StopAnimation;
};

