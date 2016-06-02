#pragma once
#include "stdafx.h"
#include "Sprite.h"
#include "Setup.h"

class CEnvironment
{
public:
	CEnvironment(CSetup* Passed_Setup, float *CamX, float *CamY, int *Passed_LvWidth, int *Passed_LvHeight);
	~CEnvironment();
	void DrawBack();
	void DrawFront();
	void Update();

private:
	CSetup* csetup;
	CSprite* stone;

	float *CamX;
	float *CamY;

	float StoneX;
	float StoneY;

	int *ScreenWidth;
	int *ScreenHeight;

	int *LvWidth;
	int *LvHeight;
};

