#include "Game.h"
#include <stdio.h>

Game::Game()
{
	this->mWindow = nullptr;
	this->mIsRunning = true;

}

bool Game::Initialize()
{

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL failed to initialize! SDL ERROR: %s\n", SDL_GetError());
		return false;
	}

	//Create the window
	mWindow = SDL_CreateWindow(
		"Chapter One!",  //Title
		100, 100, //x & y coordinates for the window
		1024, 768, //Window size
		0 //No flags needed
	);
	if (!mWindow)
	{
		printf("Failed to create window! SDL ERROR: %s\n", SDL_GetError());
		return false;
	 }



	return true;
}

void Game::Shutdown()
{
	SDL_DestroyWindow(mWindow); //Destroys window to remove it from memory
	SDL_Quit(); //Quits SDL subsystems
}

void Game::Runloop()
{
	while (mIsRunning)
	{
		ProcessInput();
		//UpdateGame();
		//GenerateOutput();
	}
}

void Game::ProcessInput()
{
	//Create an event object
	SDL_Event event;
	//Parse through events
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			//Handle each event type
		case SDL_QUIT:
			mIsRunning = false;
			break;
		}
	}

	//Get the state of the keyboard
	const Uint8* state = SDL_GetKeyboardState(NULL);
	//If escape is pressed, end the loop 
	if (state[SDL_SCANCODE_ESCAPE])
	{
		mIsRunning = false;
	}
}