#ifndef NEXT_MAP_H_
#define NEXT_MAP_H_
#include"baseFunction.h"
#include"baseObject.h"

SDL_Texture* loadTexture(string path, SDL_Renderer* renderer);

SDL_Texture* updateBackground(SDL_Renderer* renderer, int point);

SDL_Texture* updateObject(SDL_Renderer* renderer, int point);
#endif//endif