#pragma once
class CSetup
{
public:
	CSetup(bool* quit, int ScreenWidth, int ScreenHeight);
	~CSetup(void);

	SDL_Renderer* GetRenderer();
	SDL_Event* GetMainEvent();

	void Begin();
	void End();

private:
	bool quit;

	SDL_Window* window;
	SDL_Renderer* renderer;

	SDL_Event* MainEvent;
};

