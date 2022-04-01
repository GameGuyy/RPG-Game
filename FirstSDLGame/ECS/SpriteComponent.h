#pragma once
#include "Components.h"
#include "SDL.h"

class SpriteCoponent : public Component
{
private:
	PositionComponent *position;
	SDL_Texture *texture;
	SDL_Rect srcRect, desRect;

public:
	SpriteCoponent() = default;
	SpriteCoponent(const char* path)
	{
		texture = TextureManager::loadTexture(path);
	}
	void init() override
	{
		position = &entity->getComponent<PositionComponent>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = srcRect.h = 32;
		desRect.w = desRect.h = 64;
	}
	void update() override
	{
		desRect.x = position->x();
		desRect.y = position->y();
	}
	void draw() override
	{
		TextureManager::Draw(texture, srcRect, desRect);
	}
};