#pragma once

#ifndef Game_hpp
#define GAME_HPP

#include "SDL.h"
#include <cstdio>
#include <iostream>
#include "SDL_image.h"
class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int x_pos, int y_pos, int width, int height, bool fullscreen);

	void handEvents();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; }
	static SDL_Renderer *rendererG;
private:
	int cnt = 0;
	bool isRunning;
	SDL_Window *window_;
	
};


#endif

