#include "stdafx.h"
#include "Main.h"

CMain::CMain(int PassedScreenWidth, int PassedScreenHeight, int PassedLvWidth, int PassedLvHeight)
{
	quit = false;

	CamX = 0;
	CamY = 0;
	SpriteX = 100;
	SpriteY = 200;

	ScreenWidth = PassedScreenWidth;
	ScreenHeight = PassedScreenHeight;

	LvWidth = PassedLvWidth;
	LvHeight = PassedLvHeight;
	
	SpriteWidth = 100;
	SpriteHeight = 125;

	csetup = new CSetup(&quit, ScreenWidth, ScreenHeight);

	chara = new Chara(csetup, &SpriteX, &SpriteY, &SpriteVx, &SpriteVy, &SpriteWidth, &SpriteHeight, &CamX, &CamY, &ScreenWidth, &ScreenHeight, &LvWidth, &LvHeight);
	camera = new CCamera(csetup, &CamX, &CamY, &SpriteX, &SpriteY, &SpriteVx, &SpriteVy, &SpriteWidth, &SpriteHeight, &ScreenWidth, &ScreenHeight, &LvWidth, &LvHeight);
	Rm1 = new CEnvironment(csetup, &CamX, &CamY, &LvWidth, &LvHeight);
}

CMain::~CMain(void)
{
	delete csetup;
	delete camera;
	delete chara;
	delete Rm1;
}

void CMain::GameLoop()
{
	while (!quit && csetup->GetMainEvent()->type != SDL_QUIT)
	{
		csetup->Begin();

		camera->Draw();

		Rm1->DrawBack();

		chara->Draw();
		chara->Update();
		
		Rm1->DrawFront();
		Rm1->Update();

		camera->Update();

		

		csetup->End();
	}
}
