#pragma once
#include "Setup.h"
#include "Sprite.h"
#include "Camera.h"
#include "Chara.h"
#include "Environment.h"

class CMain
{
public:
	CMain(int PassedScreenWidth, int PassedScreenHeight, int PassedLvX, int PassedLvY);
	~CMain(void);
	 
	void GameLoop();

	int SpriteVx;
	int SpriteVy;
	int SpriteX;
	int SpriteY;

	int TileX;
	int TileY;

private:
	float CamX;
	float CamY;

	bool quit;

	int ScreenWidth;
	int ScreenHeight;

	int LvWidth;
	int LvHeight;

	int SpriteWidth;
	int SpriteHeight;

	CSprite* character;
	//CSprite* tile;

	Chara *chara;
	CCamera *camera;

	CEnvironment *Rm1;

	CSetup* csetup;
};

