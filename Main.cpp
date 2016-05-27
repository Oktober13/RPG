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
	camera = new CCamera(csetup, &CamX, &CamY, &SpriteX, &SpriteY, &SpriteVx, &SpriteVy, &SpriteWidth, &SpriteHeight, &LvWidth, &LvHeight, &ScreenWidth, &ScreenHeight);

}

CMain::~CMain(void)
{
	delete csetup;
	delete camera;
	delete chara;
}

void CMain::GameLoop()
{
	while (!quit && csetup->GetMainEvent()->type != SDL_QUIT)
	{
		csetup->Begin();

		camera->Draw();
		chara->Draw();

		//CamX = -SpriteX + (0.5 * ScreenWidth);
		//CamY = -SpriteY + (0.5 * ScreenHeight);

		/*if (CamX >= LvWidth)
		{
			CamX = LvWidth - (0.5 * ScreenWidth);
		}*/

		chara->Update();
		camera->Update();

		

		csetup->End();
	}
}
