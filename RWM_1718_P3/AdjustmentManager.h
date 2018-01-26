#pragma once
#include "SDL2\include\SDL.h"
#include "SDL2\include\SDL_image.h"
#include "ImageLoader.h"
#include "ColourModifications.h"
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
	Uint8 r;
	Uint8 g;
	Uint8 b;
private:
	ImageLoader* m_temp;

};

