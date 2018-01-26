#pragma once
#include "SDL2\include\SDL.h"
#include "SDL2\include\SDL_image.h"
#include "SDL2\include\SDL_ttf.h"
#include "ImageLoader.h"
#include "AdjustmentManager.h"
#include "ColourModifications.h"
#include <iostream>
#include <vector>

class Game
{
public:
	Game();
	~Game();
	void Init();
	void CleanUp();
	void Loop();
	void Load();
	void Render();
	void DetectEvents();
	void Update();

private:
	SDL_Window* window;
	SDL_Event event;
	bool isRunning = true;
	SDL_Renderer* renderer;
	AdjustmentManager* m_adjustmentmanager;

};

