#include "Game.h"

int main(int argc, char* args[])
{
	Game game; //Create the game object
	
	bool success = game.Initialize(); //Initialize the GAME
	
	if (success)
	{
		game.Runloop(); //Runs the game 
	}
	
	game.Shutdown(); //Shut er down, Cap'n!

	return 0;
}