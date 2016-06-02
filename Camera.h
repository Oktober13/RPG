#pragma once
#include "stdafx.h"
#include "Sprite.h"
#include "Setup.h"

class CCamera
{
public:
	CCamera(CSetup* Passed_Setup, float *Passed_CamX, float *Passed_CamY, int *Passed_SpriteX, int *Passed_SpriteY, int *Passed_SpriteVx, int *Passed_SpriteVy, int *Passed_SpriteWidth, int *Passed_SpriteHeight, int *Passed_ScreenWidth, int *Passed_ScreenHeight, int *Passed_LvWidth, int *Passed_LvHeight);
	~CCamera();

	void Update();
	void Draw();

private:
	CSetup* csetup;
	CSprite* tile;
	CSprite* stone1;

	float *CamX;
	float *CamY;

	int *LvWidth;
	int *LvHeight;
	int *ScreenWidth;
	int *ScreenHeight;
	int MidScreenWidth;
	int MidScreenHeight;

	int *SpriteX;
	int *SpriteY;
	int *SpriteVx;
	int *SpriteVy;
	int *SpriteWidth;
	int *SpriteHeight;
};

