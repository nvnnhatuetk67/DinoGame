#ifndef SCORE_H_
#define SCORE_H_
#include "baseFunction.h"
#include "baseObject.h"

static SDL_Color colorText = { 200 , 255 , 200};

class Point {
   private:
        int point;
        int highPoint;
        BaseObject score;
        BaseObject highscore;
   public: 
       // Point();
        //~Point();
        void setPoint(int p ){ point = p;};
        void setHighPoint(int hp){ highPoint = hp;};
        bool comparePoint(){ return point >= highPoint;};
        int getPoint(){ return point;};
        int getHightPoint(){return highPoint;};
        void setScore(SDL_Renderer* renderer, int x, int y , int w, int h,TTF_Font* font);
        void setHighScore( SDL_Renderer* renderer, SDL_Color color,int x, int y , int w, int h, TTF_Font* font);
        bool checkPoint(BaseObject ob1, BaseObject ob2);
        void displayScore(SDL_Renderer* renderer);


};

#endif// score