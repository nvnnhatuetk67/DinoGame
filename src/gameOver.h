#ifndef GAME_OVER_H_
#define GAME_OVER_H_
#include "baseFunction.h"
#include "baseObject.h"

class GameOver : public BaseObject{
    private:
        BaseObject gOver;
        BaseObject optOver;
    public:
        void RenderGameOver(SDL_Renderer* renderer,TTF_Font* font,  int point);
        void RenderOpt(SDL_Renderer* renderer, TTF_Font* font, SDL_Color color, SDL_Color color1);
};
SDL_Texture* loadText(SDL_Renderer* renderer, string text, TTF_Font* font, SDL_Color color);
#endif//gameover
