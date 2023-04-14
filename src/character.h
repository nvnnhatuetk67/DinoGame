#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "baseFunction.h"
#include "baseObject.h"

class Character : public BaseObject{
    private:
        BaseObject dino;

    public:
        void Idle(SDL_Renderer* renderer, int x, int y, int w, int h);
        void SetDinoRect(int x, int y, int w, int h);
        
};

#endif//character