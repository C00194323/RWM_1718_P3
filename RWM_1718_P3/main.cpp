#include "Game.h"

using namespace std;
#undef main

int main(int argc, char* argv[])
{
	Game* game=new Game();
	
	game->Init();	
	game->Loop();
	game->CleanUp();

	system("Pause");
	return 0;

}