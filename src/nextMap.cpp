#include "nextMap.h"

SDL_Texture* loadTexture(string path, SDL_Renderer* renderer){
    SDL_Texture* newTexture = nullptr;
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if(loadedSurface == nullptr){
        cout<<"Unable to  load image " << path << " SDL_image Error: "
        << IMG_GetError() << endl;
    }
    else{
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if(newTexture == nullptr)
            cout<<"Unable to create texture from " << path << " SDL Error: "
                << SDL_GetError()<< endl;
                SDL_FreeSurface( loadedSurface);
    }
    return newTexture;
}
SDL_Texture* updateBackground(SDL_Renderer* renderer, int point){
    SDL_Texture* background;
    if(point >= 100 && point < 200) background = loadTexture("assets/background1.png", renderer);
    else if(point >= 200 && point < 300) background = loadTexture("assets/background2.png", renderer);
    else if(point >= 300 && point < 400) background = loadTexture("assets/background3.png", renderer);
    else if(point >= 400 && point < 500) background = loadTexture("assets/background4.png", renderer);
    else
        background = loadTexture("assets/background.png", renderer);
    return background;
}
SDL_Texture* updateObject(SDL_Renderer* renderer, int point){
     SDL_Texture* object;
    if(point >= 100 && point < 200) object = loadTexture("assets/cactus.png", renderer);
    else if( point >= 200 && point < 300) object= loadTexture("assets/chainsaw.png", renderer);
    else if (point >= 300 && point < 400) object = loadTexture("assets/plantviolet.png", renderer);
    else if(point >= 400 && point < 500) object = loadTexture("assets/ice.png", renderer);
    else{
        object = loadTexture("assets/fire.png", renderer);
        point = 100;
    }
    return object;
}
