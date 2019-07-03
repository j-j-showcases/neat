#pragma once
#include <string>
#include <SDL.h> 

namespace MarioDemo {
	class Game
	{
	private:
		//The window we'll be rendering to 
		SDL_Window* _window = NULL;
		//The surface contained by the window 
		SDL_Surface* _screenSurface = NULL;

	public:
		//Starts up SDL and creates window 
		bool Init(const int& width, const int& height);
		//Loads media
		bool LoadMedia(char* file);
		//Frees media and shuts down SDL 
		void Close();
	};
}
