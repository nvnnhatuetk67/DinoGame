#include "gameOver.h"

SDL_Texture* loadText(SDL_Renderer* renderer, string text, TTF_Font* font, SDL_Color color){
    SDL_Surface* surface = TTF_RenderText_Solid(font,text.c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);
    return texture;
}
void GameOver :: RenderGameOver(SDL_Renderer* renderer,TTF_Font* font,  int point){
    string pointText ;
    if(point < 10)
        pointText ="0" + to_string(point);
    else
        pointText = to_string(point);
    gOver.LoadImg("assets/gameover.png", renderer);
    gOver.SetEntireRect(220, 35, 570 , 440);

    gOver.Render(renderer, nullptr);

    
    SDL_Texture* pointTexture = loadText(renderer, pointText, font, {255,200,255});
    SDL_Rect pointRect = {430, 240, 160, 80};
    SDL_RenderCopy(renderer, pointTexture, nullptr, &pointRect);
    SDL_DestroyTexture(pointTexture);
}
void GameOver :: RenderOpt(SDL_Renderer* renderer, TTF_Font* font, SDL_Color color, SDL_Color color1){
    string startText = "Play Again";
    string exitText = "EXIT";

    SDL_Rect startRect  = {310 ,370, 200, 40};
    SDL_Rect exitRect = {590,370, 110,38};
    SDL_Texture* start = loadText(renderer, startText, font, color);
    SDL_Texture* exit = loadText(renderer, exitText, font, color1);
    SDL_RenderCopy(renderer, start, nullptr, &startRect);
    SDL_RenderCopy(renderer, exit, nullptr, &exitRect);
    SDL_DestroyTexture(start);
    SDL_DestroyTexture(exit);
}