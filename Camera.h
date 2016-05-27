#pragma once
#include "stdafx.h"
#include "Sprite.h"
#include "Setup.h"

class CCamera
{
public:
	CCamera(CSetup* Passed_Setup, float *Passed_CamX, float *Passed_CamY, int *Passed_SpriteX, int *Passed_SpriteY, int *Passed_SpriteVx, int *Passed_SpriteVy, int *Passed_SpriteWidth, int *Passed_SpriteHeight, int *Passed_LvWidth, int *Passed_LvHeight, int *Passed_ScreenWidth, int *Passed_ScreenHeight);
	~CCamera();

	void Update();
	void Draw();

private:
	CSetup* csetup;
	CSprite* tile;

	float *CamX;
	float *CamY;

	int *LvWidth;
	int *LvHeight;
	int *ScreenWidth;
	int *ScreenHeight;

	int *SpriteX;
	int *SpriteY;
	int *SpriteVx;
	int *SpriteVy;
	int *SpriteWidth;
	int *SpriteHeight;
};

