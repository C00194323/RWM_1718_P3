#pragma once
#include "SDL2\include\SDL.h"
#include "SDL2\include\SDL_image.h"
#include "ImageLoader.h"

static struct ColourModification
{
	static Uint32* ModifyHue(ImageLoader* i)
	{
		int pixelImageCount = static_cast<int>(i->pitch() * 0.25f) *  i->height();
		Uint32* tempImagePixels = new Uint32[pixelImageCount];
		Uint32* pixels = (Uint32*)i->getPixel();

		//Gets Width and Height of the image
		int im_width = i->width();
		int im_height = i->height();

		//Values For modifiying rgb values 
		float modifiedR = 0;
		float modifiedG = 0;
		float modifiedB = 0;

		for (int a = 0; a < im_width; a++)
		{
			for (int b = 0; b < im_height; b++)
			{

			}
		}
		return tempImagePixels ;
	}
	static Uint32* ModifySaturation(ImageLoader* i)
	{

	}
	static Uint32* ModifyContrast(ImageLoader* i)
	{

	}
	static Uint32* ModifyBrightness(ImageLoader* i)
	{
		int pixelImageCount = static_cast<int>(i->pitch() * 0.25f) *  i->height();
		Uint32* tempImagePixels = new Uint32[pixelImageCount];
		Uint32* pixels = (Uint32*)i->getPixel();

		for (int i = 0; i < pixelImageCount; ++i)
		{
			Uint8 a = pixels[i] >> 24 & 0xFF;
			Uint8 r = pixels[i] >> 16 & 0xFF;
			Uint8 g = pixels[i] >> 8 & 0xFF;
			Uint8 b = pixels[i] & 0xFF;
			Uint8 v = static_cast<Uint8>((0.212671f * r) + (0.715160f * g) + (0.072169f * b));
			//tempImagePixels[i] = (a << 24) | (v << 16) | (v << 8) | v;

			if (v < 255)
				tempImagePixels[i] = (a << 24) | (0 << 16) | (0 << 8) | 0;
			else
				tempImagePixels[i] = (a << 24) | (r << 16) | (g << 8) | b;
		}
		return tempImagePixels;
	}
};
