#include "stdafx.h"
#include "Setup.h"


CSetup::CSetup(bool* quit, int ScreenWidth, int ScreenHeight)
{
	window = NULL;
	window = SDL_CreateWindow("Load_Screen", 100, 100, ScreenWidth, ScreenHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

	if (window == NULL)
	{
		std::cout << "Error: Window could not be created." << std::endl;
		*quit = true;
	}

	renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	MainEvent = new SDL_Event();
}


CSetup::~CSetup()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete MainEvent;
}

SDL_Renderer* CSetup::GetRenderer()
{
	return renderer;
}

SDL_Event* CSetup::GetMainEvent()
{
	return MainEvent;
}

void CSetup::Begin()
{
	SDL_PollEvent(MainEvent);
	SDL_RenderClear(renderer);
}

void CSetup::End()
{
	SDL_RenderPresent(renderer);
}