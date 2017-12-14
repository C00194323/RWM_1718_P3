#include "SDL2\include\SDL.h"
#include "SDL2\include\SDL_image.h"

using namespace std;
#undef main

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
	SDL_Window* window = SDL_CreateWindow("Colour Adjustment", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 800, SDL_WINDOW_SHOWN);

	bool isRunning = true;

	while (isRunning)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				isRunning = false;
			}
		}
	}
	
	SDL_Quit();
	return 0;

}