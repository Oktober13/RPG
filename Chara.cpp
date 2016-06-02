#include "stdafx.h"
#include "Setup.h"
#include "Chara.h"
#include "Sprite.h"


Chara::Chara(CSetup* Passed_Setup, int *Passed_SpriteX, int *Passed_SpriteY, int *Passed_SpriteVx, int *Passed_SpriteVy, int *Passed_SpriteWidth, int *Passed_SpriteHeight, float *Passed_CamX, float *Passed_CamY, int *Passed_ScreenWidth, int *Passed_ScreenHeight, int *Passed_LvWidth, int *Passed_LvHeight)
{
	csetup = Passed_Setup;

	SpriteX = Passed_SpriteX;
	SpriteY = Passed_SpriteY;
	SpriteVx = Passed_SpriteVx;
	SpriteVy = Passed_SpriteVy;
	SpriteWidth = Passed_SpriteWidth;
	SpriteHeight = Passed_SpriteHeight;

	CamX = Passed_CamX;
	CamY = Passed_CamY;

	ScreenWidth = Passed_ScreenWidth;
	ScreenHeight = Passed_ScreenHeight;
	MidScreenWidth = *ScreenWidth / 2;
	MidScreenHeight = *ScreenHeight / 2;

	LvWidth = Passed_LvWidth;
	LvHeight = Passed_LvHeight;

	character = new CSprite(csetup->GetRenderer(), "Sprites/CharaSprite.fw.png", *Passed_SpriteX, *Passed_SpriteY, *SpriteWidth, *SpriteHeight);
	character->SetupAnimation(4, 4);

	Row = 0;
	StartFrame = 1;
	EndFrame = 1;

	TimeCheck = SDL_GetTicks();
	StopAnimation = false;
}


Chara::~Chara()
{
	delete character;
}

void Chara::Update()
{
	character->PlayAnimation(StartFrame, EndFrame, Row, Speed);

	*SpriteX = character->GetX();
	*SpriteY = character->GetY();

	switch (csetup->GetMainEvent()->type)
	{
	case SDL_KEYDOWN:
		switch (csetup->GetMainEvent()->key.keysym.sym)
		{
		case SDLK_UP:	case SDLK_w:	*SpriteVy = -1;	Row = 3; StartFrame = 0; EndFrame = 2; break;
		case SDLK_DOWN:	case SDLK_s:	*SpriteVy = 1;	Row = 0; StartFrame = 0; EndFrame = 2; break;
		case SDLK_LEFT:	case SDLK_a:	*SpriteVx = -1;	Row = 1; StartFrame = 0; EndFrame = 2; break;
		case SDLK_RIGHT:case SDLK_d:	*SpriteVx = 1;	Row = 2; StartFrame = 0; EndFrame = 2; break;
		default:						break;
		}
	}

	switch (csetup->GetMainEvent()->type)
	{
		//If a key was released
	case SDL_KEYUP:
		switch (csetup->GetMainEvent()->key.keysym.sym)
		{
		case SDLK_UP:
		case SDLK_w:
			if (*SpriteVy < 0)
				*SpriteVy = 0;
			StartFrame = 0; EndFrame = 0;
			break;

		case SDLK_DOWN:
		case SDLK_s:
			if (*SpriteVy > 0)
				*SpriteVy = 0;
			StartFrame = 0; EndFrame = 0;
			break;
		case SDLK_LEFT:
		case SDLK_a:
			if (*SpriteVx)
				*SpriteVx = 0;
			StartFrame = 0; EndFrame = 0;
			break;
		case SDLK_RIGHT:
		case SDLK_d:
			if (*SpriteVx)
				*SpriteVx = 0;
			StartFrame = 0; EndFrame = 0;
			break;
		}
	default:break;
	}


	//If the sprite is walking near the end of a room- eg: Camera is not scrolling, activates sprite "walking"
	if ((*SpriteX <= (MidScreenWidth + 5) && *CamX == 0) || (*SpriteX >= (MidScreenWidth - 5) && *CamX <= -(*LvWidth - *ScreenWidth)))
	{
		character->SetX(*SpriteX + *SpriteVx);
	}

	if ((*SpriteY <= (MidScreenHeight + 5) && *CamY == 0) || (*SpriteY >= (MidScreenHeight - 5) && *CamY <= -(*LvHeight - *ScreenHeight)))
	{
		character->SetY(*SpriteY + *SpriteVy);
	}


	//If the sprite is walking in the middle of a room- eg: the Camera IS scrolling. This prevents the sprite from walking "off screen."
	if ((*SpriteX > MidScreenWidth) && *CamX < -(*LvWidth - *ScreenWidth))
	{
		character->SetX(MidScreenWidth);
	}
	if ((*SpriteY > MidScreenHeight) && *CamY < -(*LvHeight - *ScreenHeight))
	{
		character->SetY(MidScreenHeight);
	}

	//If the sprite went too far to the left or right
	if ((*SpriteX < 0 && *SpriteVx < 0) || ((*SpriteX + *SpriteWidth) > *ScreenWidth && *SpriteVx > 0))
	{
		character->SetX(*SpriteX -= *SpriteVx);
	}
	if ((*SpriteY < 0 && *SpriteVy < 0) || (*SpriteY + *SpriteHeight > *ScreenHeight && *SpriteVy > 0))
	{
		character->SetY(*SpriteY -= *SpriteVy);
	}
	//std::cout << *CamX + 400 << std::endl;
}

void Chara::Draw()
{
	character->Draw();
}