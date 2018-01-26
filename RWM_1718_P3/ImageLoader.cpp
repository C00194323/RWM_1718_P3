#include "ImageLoader.h"

//Code Used in this class is mainly 
//derived From Example Project 
//TextureFiltersComponent


ImageLoader::ImageLoader()
{
	
	m_Imagetexture=NULL;
	m_height = 0;
	m_pitch = 0;
	m_width = 0;
	m_pixels=NULL;
	m_rect = SDL_Rect{ 0,0,0,0 };
	
}


ImageLoader::~ImageLoader()
{

}

SDL_Texture* ImageLoader::Texture()
{
	return m_Imagetexture;
}

void* ImageLoader::getPixel()
{
	return m_pixels;
}

int ImageLoader::height()
{
	return m_height;
}

int ImageLoader::width()
{
	return m_width;
}

int ImageLoader::pitch()
{
	return m_pitch;
}

SDL_Rect ImageLoader::getRect()
{
	return m_rect;
}

SDL_PixelFormat* ImageLoader::Format()
{
	return format;
}

SDL_Surface* ImageLoader::getSurface()
{
	return m_ImageSurface;
}




bool ImageLoader::loadfromfile(std::string name, SDL_Renderer* render)
{

	SDL_Texture* m_tempTexture = NULL;
	m_ImageSurface = IMG_Load(name.c_str());

	if (m_ImageSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", name.c_str(), IMG_GetError());
	}

	
	format = m_ImageSurface->format;
	
	std::cout << format << std::endl;
	if (format->BitsPerPixel != 24)
	{
		printf("Not an 32-bit surface.\n");
	}


	m_tempTexture=SDL_CreateTexture(render,SDL_PIXELFORMAT_RGB24,SDL_TEXTUREACCESS_STREAMING, m_ImageSurface->w, m_ImageSurface->h);
	
	//m_tempTexture = SDL_CreateTextureFromSurface(render, m_ImageSurface);
	
	SDL_LockTexture(m_tempTexture, NULL, &m_pixels, &m_pitch);

	memcpy(m_pixels, m_ImageSurface->pixels, m_ImageSurface->pitch * m_ImageSurface->h);

	SDL_UnlockTexture(m_tempTexture);

	m_rect = m_ImageSurface->clip_rect;
	m_height = m_ImageSurface->h;
	m_width = m_ImageSurface->w;
	

	// Enables Transparency 
	//SDL_SetTextureBlendMode(m_tempTexture, SDL_BLENDMODE_BLEND);
	

	// Clean Up Surface
	SDL_FreeSurface(m_ImageSurface);

	//Return Loading Image Success
	m_Imagetexture = m_tempTexture;
	std::cout << "Image Loaded" << std::endl;
	return true;
}
