#pragma once
#include "Game.h"

Game::Game()
{
}


Game::~Game()
{
}

void Game::Init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG );
	window = SDL_CreateWindow("Colour Adjustment", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 800, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	m_adjustmentmanager = new AdjustmentManager();
	Load();
	std::cout << "Game Initialized" << std::endl;
}

void Game::CleanUp()
{
	std::cout << "Game Cleaning" << std::endl;
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::Load()
{
	m_adjustmentmanager->LoadTexture("test.bmp", renderer);
}

void Game::Loop()
{
	std::cout << "Game Looping" << std::endl;

	isRunning = true;

	while (isRunning)
	{
			
			Update();
			Render();
	}

}

void Game::Update()
{
	DetectEvents();
}

void Game::DetectEvents()
{
	while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				isRunning = false;
			}
			else
			{
				switch (event.type)
				{
				case SDL_KEYDOWN:
					switch (event.key.keysym.sym)
					{
					case SDLK_ESCAPE:
						isRunning = false;
						break;
					case SDLK_h:
						m_adjustmentmanager->Hue();
						std::cout << "Hue Modified" << std::endl;
						break;
					case SDLK_c:
						m_adjustmentmanager->Contrast();
						std::cout << "Contrast Modified" << std::endl;
						break;
					case SDLK_b:
						m_adjustmentmanager->Brightness();
						std::cout << "Brightness Modified" << std::endl;
						break;
					case SDLK_r:
						m_adjustmentmanager->reset();
						m_adjustmentmanager->r = 0;
						m_adjustmentmanager->g = 0;
						m_adjustmentmanager->b = 0;
						std::cout << "Image Reset" << std::endl;
						break;
					case SDLK_s:
						m_adjustmentmanager->Saturation();
						std::cout << "Saturation Modified" << std::endl;
						break;
					case SDLK_q:
						m_adjustmentmanager->r=255;
						std::cout << "Red Saturated" << std::endl;
						break;
					case SDLK_w:
						m_adjustmentmanager->g=255;
						std::cout << "Green Saturated" << std::endl;
						break;
					case SDLK_e:
						m_adjustmentmanager->b=255;
						std::cout << "Blue Saturated " << std::endl;
						break;
				}
			}
		}
	}
}

void Game::Render()
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);

	SDL_RenderCopy(renderer, m_adjustmentmanager->getTexture(), NULL, &m_adjustmentmanager->rect());

	SDL_RenderPresent(renderer);
}