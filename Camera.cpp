#include "stdafx.h"
#include "Camera.h"
#include "Sprite.h"
#include "Setup.h"


CCamera::CCamera(CSetup* Passed_Setup, float *Passed_CamX, float *Passed_CamY, int *Passed_SpriteX, int *Passed_SpriteY, int *Passed_SpriteVx, int *Passed_SpriteVy, int *Passed_SpriteWidth, int *Passed_SpriteHeight, int *Passed_ScreenWidth, int *Passed_ScreenHeight, int *Passed_LvWidth, int *Passed_LvHeight)
{
	csetup = Passed_Setup;

	CamX = Passed_CamX;
	CamY = Passed_CamY;

	ScreenWidth = Passed_ScreenWidth;
	ScreenHeight = Passed_ScreenHeight;
	MidScreenWidth = *ScreenWidth / 2;
	MidScreenHeight = *ScreenHeight / 2;

	LvWidth = Passed_LvWidth;
	LvHeight = Passed_LvHeight;

	SpriteX = Passed_SpriteX;
	SpriteY = Passed_SpriteY;
	SpriteVx = Passed_SpriteVx;
	SpriteVy = Passed_SpriteVy;
	SpriteWidth = Passed_SpriteWidth;
	SpriteHeight = Passed_SpriteHeight;

	//tile = new CSprite(csetup->GetRenderer(), "Tiles/test.bmp", 0, 0, *LvWidth, *LvHeight);
	tile = new CSprite(csetup->GetRenderer(), "Tiles/rm1.png", 0, 0, *LvWidth, *LvHeight);
}


CCamera::~CCamera()
{
	delete tile;
}

//void CCamera::SetCamera()
//{
//}

void CCamera::Draw()
{
	tile->Draw();
}

void CCamera::Update()
{
	//Scrolling to follow character
	if ((*SpriteX > (MidScreenWidth - 1) && -*CamX < (*LvWidth - *ScreenWidth)) || (*SpriteX < MidScreenWidth && -*CamX > 0))
	{
		*CamX = *CamX - *SpriteVx;
	}
	if ((*SpriteY > (MidScreenHeight - 1) && -*CamY < (*LvHeight - *ScreenHeight)) || (*SpriteY < MidScreenHeight && -*CamY > 0))
	{
		*CamY = *CamY - *SpriteVy;
	}

	//Block camera from going offscreen
	if (-*CamX < 0)
	{
		*CamX = 0;
	}
	if (-*CamX > (*LvWidth - *ScreenWidth))
	{
		*CamX = -(*LvWidth - *ScreenWidth);
	}
	if (-*CamY < 0)
	{
		*CamY = 0;
	}
	if (-*CamY > (*LvHeight - *ScreenHeight))
	{
		*CamY = -(*LvHeight - *ScreenHeight);
	}

	tile->SetX(*CamX);
	tile->SetY(*CamY);
}