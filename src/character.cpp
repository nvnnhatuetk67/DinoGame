#include "character.h"
#include<windows.h>
int dem = 0;
void Character::SetDinoRect(int x, int y, int w, int h){
    dino.SetEntireRect(x, y , w ,h);
}
void Character :: Idle(SDL_Renderer* renderer, int x, int y, int w, int h){
    Sleep(100);
    if(dem%3 == 0){
        dino.Free();
        dino.LoadImg("character/Idle1.png", renderer);
         dino.SetEntireRect(x, y , w ,h);
        dino.Render(renderer, nullptr);
        
    }
    else if(dem % 3 == 1){
        dino.Free();
        dino.LoadImg("character/Idle2.png", renderer);
         dino.SetEntireRect(x, y , w ,h);
        dino.Render(renderer, nullptr);
        
    }
    else{
        dino.Free();
        dino.LoadImg("character/Idle3.png", renderer);
         dino.SetEntireRect(x, y , w ,h);
        dino.Render(renderer, nullptr);
       
    }
    
    dem++;
    if(dem > 100)
            dem = 0;
}
