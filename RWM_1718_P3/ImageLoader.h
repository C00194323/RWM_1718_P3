#pragma once
#include "SDL2\include\SDL.h"
#include "SDL2\include\SDL_image.h"
#include <string>
#include <iostream>

//Code Used in this class is mainly 
//derived From Example Project 
//TextureFiltersComponent


class ImageLoader
{
public:
	ImageLoader();
	~ImageLoader();
	SDL_Texture* Texture();
	SDL_Rect getRect();
	void* getPixel();
	bool loadfromfile(std::string ,SDL_Renderer*);
	int height();
	int width();
	int pitch();
	

private:
	SDL_Texture* m_Imagetexture;
	SDL_Rect m_rect;
	int m_pitch;
	void* m_pixels;
	int m_width;
	int m_height;
};

