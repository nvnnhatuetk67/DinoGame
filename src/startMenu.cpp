#include"startMenu.h"

void StartMenu::renderStart(SDL_Renderer* renderer, TTF_Font* font,  int highscore, SDL_Color color){
    start.LoadText("DINO RUNING", font, {255,255,255}, renderer);
    start.SetEntireRect(100, 50, 800, 100);
    start.Render(renderer, nullptr);

    string hiscore = "HIGHSCORE: " + to_string(highscore);
    hscore.LoadText(hiscore, font, {255,255,255}, renderer);
    hscore.SetEntireRect(290,190,400,80);
    hscore.Render(renderer, nullptr);

    play.LoadText("Press to PLAY", font, color, renderer);
    play.SetEntireRect(270,330,450,40);
    play.Render(renderer, nullptr);
}
 void StartMenu::introduceGame(SDL_Renderer* renderer){
    intro.LoadImg("assets/menu.png", renderer);
    intro.SetEntireRect(200, 50, 600, 420);
    intro.Render(renderer, nullptr);
    intro.Free();
 }