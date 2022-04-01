#include "Texture Manager.h"

SDL_Texture* TextureManager::loadTexture(const char* texture)
{
	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::rendererG, tempSurface);

	SDL_FreeSurface(tempSurface);

	return tex;
}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect desRect)
{
	SDL_RenderCopy(Game::rendererG, tex, &src, &desRect);
}
