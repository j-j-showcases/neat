#include <iostream>
#include "Game.h"

using namespace MarioDemo;
bool Game::Init(const int& width, const int& height) {
	//Initialize flag
	bool success = false;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	else {
		//Create window 
		_window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

		if (_window == NULL)
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		else {
			//Get window surface 
			_screenSurface = SDL_GetWindowSurface(_window);
			success = true;
		}
	}

	return success;
}

bool Game::LoadMedia(char* file) {
	//Loading flag
	bool success = false;
	SDL_Surface* image = NULL;

	//Load image
	image = SDL_LoadBMP(file);

	if (image == NULL)
		printf("Unable to load image %s! SDL Error: %s\n", file, SDL_GetError());
	else {
		//Apply the image 
		SDL_BlitSurface( image, NULL, _screenSurface, NULL );
		//Update the surface 
		SDL_UpdateWindowSurface( _window );

		success = true;
	}

	return success;
}

void Game::Close() {
	//Deallocate surface
	SDL_FreeSurface(_screenSurface);
	_screenSurface = NULL;

	//Destroy window
	SDL_DestroyWindow(_window);
	_window = NULL;

	//Quit SDL
	SDL_Quit();
}