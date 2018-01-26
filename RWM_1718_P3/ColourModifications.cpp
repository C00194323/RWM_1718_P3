#include "ColourModifications.h"

ColourModifications::ColourModifications()
{
}


ColourModifications::~ColourModifications()
{
}

Uint32* ColourModifications::ModifyHue(ImageLoader* i)
{
	int pixelCount = static_cast<int>(i->pitch() * 0.25f) *  i->height();
	Uint32* tempImagePixels = new Uint32[pixelCount];
	Uint32* pixels = (Uint32*)i->getPixel();


	return tempImagePixels;
}

Uint32* ColourModifications::ModifySaturation(ImageLoader* i, Uint8 r, Uint8 g, Uint8 b)
{

	//Change the RGB Values to increase/decrease the intensity of a certain colour
	// 0 been the lowest and 255 been the highest
	Uint8 redsat = r;
	Uint8 bluesat = g;
	Uint8 greenSat = b;
	Uint32*  tempImagePixels= (Uint32* )SDL_SetTextureColorMod(i->Texture(), redsat, bluesat, greenSat);
	return tempImagePixels;
}

Uint32* ColourModifications::ModifyContrast(ImageLoader* i)
{
	int pixelCount = static_cast<int>(i->pitch() * 0.25f) *  i->height();
	Uint32* tempImagePixels = new Uint32[pixelCount];
	Uint32* pixels = (Uint32*)i->getPixel();
	Uint8 v;
	for (int i = 0; i < pixelCount; ++i)
	{
		Uint8 half = pixels[i] & 0x7D;
		if (pixels[i] < half)
		{
			Uint8 r = pixels[i] >> 24 & 0x7D;
			Uint8 g = pixels[i] >> 24 & 0x7D;
			Uint8 b = pixels[i] >> 24 & 0x7D;
			v = static_cast<Uint8>(( r) - (g) - (b));
		}
		else if (pixels[i] > half)
		{
			Uint8 r = pixels[i] >> 24 & 0xFF;
			Uint8 g = pixels[i] >> 24 & 0xFF;
			Uint8 b = pixels[i] >> 24 & 0xFF;
			v = static_cast<Uint8>((r) + (g) + (b));
		}
		
		tempImagePixels[i] = v;
	}

	return tempImagePixels;
}

Uint32* ColourModifications::ModifyBrightness(ImageLoader* i)
{
	int pixelCount = static_cast<int>(i->pitch() * 0.25f) *  i->height();
	Uint32* tempImagePixels = new Uint32[pixelCount];
	Uint32* pixels = (Uint32*)i->getPixel();

	//Maximum Values will be set for ARGB
	float totalAlpha = 0;
	float totalRed = 0;
	float totalGreen = 0;
	float totalBlue = 0;

	// Change This value to increase the brightness
   // Applied to the image
  // Value must be between 0 - 1

	float modifiedBrightness = 0.5;

	// Cycles Through each Pixel
	for (int i = 0; i < pixelCount; ++i)
	{
		Uint8 ModifiedBrightness_alpha = tempImagePixels[i] >> 24 & 0xFF;
		Uint8 ModifiedBrightness_red = tempImagePixels[i] >> 16 & 0xFF;
		Uint8 ModifiedBrightness_green = tempImagePixels[i] >> 8 & 0xFF;
		Uint8 ModifiedBrightness_blue = tempImagePixels[i] & 0xFF;

		Uint8 a = pixels[i] >> 24 & 0xFF;
		Uint8 r = pixels[i] >> 16 & 0xFF;
		Uint8 g = pixels[i] >> 8 & 0xFF;
		Uint8 b = pixels[i] & 0xFF;

		totalAlpha = a + ((ModifiedBrightness_alpha * modifiedBrightness));
		totalRed = r + ((ModifiedBrightness_red * modifiedBrightness));
		totalGreen = g + ((ModifiedBrightness_green * modifiedBrightness));
		totalBlue = b + ((ModifiedBrightness_blue * modifiedBrightness));

		//Value cannot be over 255 if it is reset it to 255 
		if (totalAlpha > 255)
		{
			totalAlpha = 255;
		}
		if (totalRed > 255)
		{
			totalRed = 255;
		}
		if (totalGreen > 255)
		{
			totalGreen = 255;
		}
		if (totalBlue > 255)
		{
			totalBlue = 255;
		}

		tempImagePixels[i] = Uint8(totalAlpha) << 24 | Uint8(totalRed) << 16 | Uint8(totalGreen) << 8 | Uint8(totalBlue);
	}

	return tempImagePixels;
}

