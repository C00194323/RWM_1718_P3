#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "ImageLoader.h"

class ColourModifications
{
public:
	ColourModifications();
	~ColourModifications();
	static Uint32* ModifyHue(ImageLoader* i);
	static Uint32* ModifySaturation(ImageLoader* i, Uint8 r, Uint8 g, Uint8 b);
	static Uint32* ModifyContrast(ImageLoader* i);
	static Uint32* ModifyBrightness(ImageLoader* i);
	static int redSat;
	static int blueSat;
	static int greenSat;
};


