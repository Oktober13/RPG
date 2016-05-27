#pragma once
class CSprite
{
public:
	//CSprite(SDL_Renderer* passed_renderer, std::string FilePath, int x, int y, int w, int h, float *CamX, float *CamY);
	CSprite(SDL_Renderer* passed_renderer, std::string FilePath, int x, int y, int w, int h);
	~CSprite(void);
	
	void Draw();

	void SetupAnimation(int Passed_Amount_X, int Passed_Amount_Y);
	void PlayAnimation(int StartFrame, int EndFrame, int Row, float speed);

	void SetX(int SpriteX);
	void SetY(int SpriteY);
	void SetPosition(int SpriteX, int SpriteY);

	int GetX();
	int GetY();

	void SetWidth(int W);
	void SetHeight(int H);
	int GetWidth();
	int GetHeight();

private:

	int X_pos;
	int Y_pos;
	float *CamX;
	float *CamY;

	int img_width;
	int img_height;

	int CurrentFrame;
	int EndFrame;
	int AnimationDelay;

	int Amount_Frame_X;
	int Amount_Frame_Y;


	SDL_Texture* image;
	SDL_Rect rect;
	SDL_Rect viewport;
	SDL_Rect Cam;

	SDL_Renderer* renderer;
};

