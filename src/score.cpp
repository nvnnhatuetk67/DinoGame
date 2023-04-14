#include "score.h"
SDL_Color colorScore = { 250 , 119 , 218 };
void Point::setScore( SDL_Renderer* renderer, int x, int y, int w, int h, TTF_Font* font){
    string text = "Score:  "+ to_string(point);
    score.LoadText(text.c_str(), font, {255,255,255}, renderer);
    score.SetEntireRect(x , y, w ,h);
}
void Point::setHighScore(SDL_Renderer* renderer, SDL_Color color, int x, int y, int w, int h, TTF_Font* font){
    
    if(comparePoint()){
        setHighPoint(point);
        color = colorScore;
    }
    else 
        color = {255,255,255};
    

    string text = "HighScore:  "+ to_string(highPoint);
    highscore.LoadText(text.c_str(), font,color, renderer);
    highscore.SetEntireRect(x , y, w ,h);
}
void Point::displayScore(SDL_Renderer* renderer){
    
    score.Render(renderer, nullptr);
    highscore.Render(renderer, nullptr);  
    score.Free();
    highscore.Free();  
}
bool Point::checkPoint(BaseObject ob1, BaseObject ob2){
    SDL_Rect rect1 = ob1.getRect();
    SDL_Rect rect2 = ob2.getRect();
    return  rect1.x >= rect2.x + 2 && rect1.x <= rect2.x + 12   ;
}