#include "Game.hpp"
#include "Map.h"
#include "Texture Manager.h"
#include "ECS/Components.h"
Map* map;
SDL_Renderer* Game::rendererG = nullptr;
Manager manager;
auto& player(manager.addEntity());
Game::Game()
{}
Game::~Game()
{}

void Game::init(const char* title, int x_pos, int y_pos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if(fullscreen )
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if(SDL_Init(SDL_INIT_EVERYTHING)==0)
	{
		std::cout << "Subsystems Initialised!..." << std::endl;
		window_ = SDL_CreateWindow(title, x_pos, y_pos, width, height, flags);
		if(window_)
		{
			std::cout << "Window Created" << std::endl;
		}
		rendererG = SDL_CreateRenderer(window_, -1, 0);
		if(rendererG)
		{
			SDL_SetRenderDrawColor(rendererG, 255, 255, 255, 255);
			std::cout << "Renderer created" << std::endl;
		}
		isRunning = true;
		
	}
	else
	{
		isRunning = false;
	}

	
	
	
	map = new Map();
	player.addComponent<PositionComponent>();
	player.addComponent<SpriteCoponent>("assests/KoalaDamage.png");
	
	
}

void Game::handEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update()
{
	manager.update();
}
void Game::render()
{
	SDL_RenderClear(rendererG);
	map->DrawMap();

	//this is where we would add stuff to renderer
	SDL_RenderPresent(rendererG);

}
void Game::clean()
{
	SDL_DestroyWindow(window_);
	SDL_DestroyRenderer(rendererG);
	SDL_Quit();
	std::cout << "game cleaned" << std::endl;
}








