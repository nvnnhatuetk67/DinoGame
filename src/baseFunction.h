#ifndef BASE_FUNCTION_H_
#define BASE_FUNCTION_H_
#include <Windows.h>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
using namespace std;

static SDL_Window* gwindow = nullptr;
static SDL_Renderer* gscreen = nullptr;
static SDL_Event event;

const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 512;
const string WINDOW_TITLE = "Nguyen Van Nhat 22028249";


#endif //Basefunction