#pragma once
#include "SDL2\include\SDL.h"
#include "SDL2\include\SDL_image.h"
#include "ImageLoader.h"
#include "AdjustmentFunctions.h"
#include <iostream>

class AdjustmentManager
{
public:
	AdjustmentManager();
	~AdjustmentManager();
	bool LoadTexture(std::string imageName, SDL_Renderer * renderer);
	SDL_Texture* getTexture();
	SDL_Rect rect();
	void Hue();
	void Saturation();
	void Contrast();
	void Brightness();
	void reset();

private:
	ImageLoader* m_temp;

};

