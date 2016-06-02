#include "stdafx.h"
#include "Setup.h"
#include "Environment.h"
#include "Sprite.h"


CEnvironment::CEnvironment(CSetup* Passed_Setup, float *Passed_CamX, float *Passed_CamY, int *Passed_LvWidth, int *Passed_LvHeight)
{
	csetup = Passed_Setup;
	CamX = Passed_CamX;
	CamY = Passed_CamY;

	stone = new CSprite(csetup->GetRenderer(), "Tiles/stone.png", 400, 300, 195, 155);
}


CEnvironment::~CEnvironment()
{
	delete stone;
}

void CEnvironment::DrawBack()
{
	stone->Draw();
}

void CEnvironment::DrawFront()
{
	stone->Draw();
}

void CEnvironment::Update()
{
	stone->SetX(*CamX + 400);
	stone->SetY(*CamY + 350);
}