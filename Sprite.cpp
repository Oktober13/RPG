#include "stdafx.h"
#include "Sprite.h"


//CSprite::CSprite(SDL_Renderer* passed_renderer,std::string FilePath, int x, int y, int w, int h, float *Passed_CamX, float *Passed_CamY)
CSprite::CSprite(SDL_Renderer* passed_renderer, std::string FilePath, int x, int y, int w, int h)
{
	renderer = passed_renderer;

	image = NULL;
	image = IMG_LoadTexture(renderer, FilePath.c_str());

	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	SDL_QueryTexture(image, NULL, NULL, &img_width, &img_height);
	
	viewport.x = 0;
	viewport.y = 0;
	viewport.w = img_width;
	viewport.h = img_height;

	/*CamX = Passed_CamX;
	CamY = Passed_CamY;
	Cam.x = rect.x + *CamX;
	Cam.y = rect.y + *CamY;
	Cam.w = rect.w;
	Cam.h = rect.h;*/

	X_pos = x;
	Y_pos = y;

	Amount_Frame_X = 0;
	Amount_Frame_Y = 0;
	CurrentFrame = 0;

	if (image == NULL)
	{
		std::cout << "Error: Could not load" << FilePath.c_str() << "." << std::endl;
	}
}

CSprite::~CSprite()
{
	SDL_DestroyTexture(image);
}

void CSprite::Draw()
{

	//Cam.x = rect.x + *CamX;
	//Cam.y = rect.y + *CamY;

	//SDL_RenderCopy(renderer, image, &viewport, &Cam);
	SDL_RenderCopy(renderer, image, &viewport, &rect);
}

void CSprite::SetupAnimation(int Passed_Amount_X, int Passed_Amount_Y)
{
	Amount_Frame_X = Passed_Amount_X;
	Amount_Frame_Y = Passed_Amount_Y;

}

void CSprite::PlayAnimation(int StartFrame, int EndFrame, int Row, float speed)
{
	if (AnimationDelay + speed < SDL_GetTicks())
	{
		if (EndFrame <= CurrentFrame)
			CurrentFrame = StartFrame;
		else
			CurrentFrame++;

		viewport.x = CurrentFrame * (img_width / Amount_Frame_X);
		viewport.y = Row * (img_height / Amount_Frame_Y);
		viewport.w = img_width / Amount_Frame_X;
		viewport.h = img_height / Amount_Frame_Y;

		AnimationDelay = SDL_GetTicks();
	}
}

int CSprite::GetX()
{
	return rect.x;
}

int CSprite::GetY()
{
	return rect.y;
}


void CSprite::SetX(int SpriteX)
{
	X_pos = SpriteX;
	rect.x = SpriteX;
}

void CSprite::SetY(int SpriteY)
{
	Y_pos = SpriteY;
	rect.y = SpriteY;
}

void CSprite::SetPosition(int SpriteX, int SpriteY)
{
	X_pos = SpriteX;
	Y_pos = SpriteY;
	rect.x = SpriteX;
	rect.y = SpriteY;
}

int CSprite::GetWidth()
{
	return rect.w;
}

int CSprite::GetHeight()
{
	return rect.h;
}

void CSprite::SetWidth(int W)
{
	rect.w = W;
}

void CSprite::SetHeight(int H)
{
	rect.h = H;
}