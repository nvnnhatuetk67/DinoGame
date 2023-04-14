#ifndef BASE_OBJECT_H_
#define BASE_OBJECT_H_

#include "baseFunction.h"

/// @brief 
class BaseObject
 {
    private:
		SDL_Texture* texture;
		SDL_Rect rect;

    public:
		BaseObject();//contructor
		~BaseObject();//destructor
		void SetRect(const int& x, const int& y) {
			rect.x = x;
			rect.y = y;
		}
		void SetSizeRect(const int& w, const int& h){
			rect.w = w;
			rect.h = h;
		}
		void SetEntireRect(const int& x, const int& y,const int& w, const int& h ){
			rect.x = x;
			rect.y = y;
			rect.w = w;
			rect.h = h;
		}
		void SetTexture(SDL_Texture* other){
			texture = nullptr;
			texture = other;	
		}
		SDL_Rect getRect() const {
			return rect;
		}
		SDL_Texture* gettexture() const {
			return texture;
		}

		virtual bool LoadImg(string path, SDL_Renderer* renderer);
		virtual bool LoadText(string text, TTF_Font* font, SDL_Color color, SDL_Renderer* renderer);
		void Render(SDL_Renderer* renderer, const SDL_Rect* clip );
		void Free();

};
#endif
