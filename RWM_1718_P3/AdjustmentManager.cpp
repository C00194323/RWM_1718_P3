#include "AdjustmentManager.h"



AdjustmentManager::AdjustmentManager()
{
	m_temp = new ImageLoader();
}


AdjustmentManager::~AdjustmentManager()
{
}

SDL_Texture* AdjustmentManager::getTexture()
{
	return m_temp->Texture();
}
SDL_Rect AdjustmentManager::rect()
{
	return m_temp->getRect();
}

bool AdjustmentManager::LoadTexture(std::string imageName, SDL_Renderer * renderer)
{
	if (m_temp->loadfromfile(imageName, renderer))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void AdjustmentManager::Hue()
{
	Uint32* tempPixels = ColourModification::ModifyHue(m_temp);
	SDL_UpdateTexture(m_temp->Texture(), &m_temp->getRect(), tempPixels, m_temp->pitch());
}

void AdjustmentManager::Contrast()
{

}

void AdjustmentManager::Brightness()
{
	Uint32* tempPixels = ColourModification::ModifyBrightness(m_temp);
	SDL_UpdateTexture(m_temp->Texture(), &m_temp->getRect(), tempPixels, m_temp->pitch());
}

void AdjustmentManager::Saturation()
{

}

// Resets the pixels of the image
void AdjustmentManager::reset()
{
	Uint32* m_resetpixels = new Uint32();
	m_resetpixels = (Uint32*)m_temp->getPixel();

	SDL_UpdateTexture(m_temp->Texture(), &m_temp->getRect(), m_resetpixels, m_temp->pitch());
}