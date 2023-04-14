#include "baseObject.h"

BaseObject::BaseObject(){
    texture = nullptr;
    rect.x = 0;
    rect.y = 0;
    rect.w = 0;
    rect.h = 0;
}
BaseObject::~BaseObject(){

}
bool BaseObject::LoadText(string text, TTF_Font* font, SDL_Color color, SDL_Renderer* renderer){
	SDL_Surface* surface = TTF_RenderText_Solid(font,text.c_str(), color);
    texture = SDL_CreateTextureFromSurface(renderer,surface);
    
    SDL_FreeSurface(surface);
    return texture != nullptr;
}
bool BaseObject::LoadImg(string path, SDL_Renderer* renderer) {
	Free();

	SDL_Texture* ntexture = NULL;

	SDL_Surface* loadimg = IMG_Load(path.c_str());
	if (loadimg != NULL) {
		//SDL_SetColorKey(loadimg, SDL_TRUE, SDL_MapRGB(loadimg->format, 0, 255, 255));

		ntexture = SDL_CreateTextureFromSurface(renderer, loadimg);
		if (ntexture != NULL) {
			rect.w = loadimg->w;
			rect.h = loadimg->h;
		}
		SDL_FreeSurface(loadimg);
	}
	texture = ntexture;

	return texture!= NULL;
}
void BaseObject::Render(SDL_Renderer* renderer, const SDL_Rect* clip ) {
	SDL_Rect renderquad = { rect.x,rect.y,rect.w,rect.h };
	SDL_RenderCopy(renderer, texture, clip, &renderquad);
}
void BaseObject::Free() {
	if (texture != NULL) {
		SDL_DestroyTexture(texture);
  		texture = NULL;
		rect.w = 0;
		rect.h = 0;
	}
}