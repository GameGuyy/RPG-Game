#include "GameObject.h"
#include "Texture Manager.h"
GameObject::GameObject(const char* textureSheet, int x,int y)
{
	
	objTexture = TextureManager::loadTexture(textureSheet);

	x_pos = x;
	y_pos = y;

}

void GameObject::Update()
{
	x_pos++;
	y_pos++;
	
	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	desRect.x = x_pos;
	desRect.y = y_pos;
	desRect.w = srcRect.w * 2;
	desRect.h = srcRect.h * 2;
}

void GameObject::Render()
{
	SDL_RenderCopy(Game::rendererG, objTexture, &srcRect, &desRect);
}

