#ifndef START_MENU_H_
#define START_MENU_H
#include "baseFunction.h"
#include "baseObject.h"
class StartMenu : public BaseObject {
    private:
        BaseObject start;
        BaseObject intro;
        BaseObject play;
        BaseObject hscore;
       
        
    public:
        void renderStart(SDL_Renderer* renderer, TTF_Font* font,  int highscore,  SDL_Color color);
         void introduceGame(SDL_Renderer* renderer);
        // void startScreen(SDL_Renderer* renderer ,TTF_Font* font, int highcore, SDL_Color color);
        // void highScore(SDL_Renderer* renderer ,TTF_Font* font, int highcore, SDL_Color color)
        
        // void playButton(SDL_Renderer* renderer, TTF_Font* font, SDL_Color color);

};


#endif//startmenu