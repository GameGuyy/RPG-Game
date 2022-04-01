#pragma once
#include "Game.hpp"

class GameObject
{
public:
	GameObject(const char* textureSheet,int x,int y);
	~GameObject();

	void Update();
	void Render();
private:
	int x_pos;
	int y_pos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, desRect;
	
};
