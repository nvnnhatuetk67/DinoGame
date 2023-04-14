#ifndef SOUND_H_
#define SOUND_H_
#include "baseFunction.h"
#include "baseObject.h"
#include "nextMap.h"
// extern bool checkMute;
// //extern BaseObject mute;
// class Sound{
//     private:
//         Mix_Chunk *soundPointing;
//         Mix_Chunk *soundLose ;
//         Mix_Chunk *soundJump ;
//         Mix_Chunk *soundNext ;
//         Mix_Music * music;
//     public:
//         void loadMusic(string filePath );
//         void SetChunkSound();
//         void playMusic(Mix_Music* music );
//         void quitMusic(Mix_Music* music );
//         void checkLoadSound();
//         void playPointSound();
//         void playSoundLose();
//         void playSoundJump();
//         void playSoundNext();
//         SDL_Texture* muteSound(SDL_Renderer* renderer, SDL_Texture* mute, int x, int y,Mix_Music* music);
// };

extern bool checkMute;
// static Mix_Chunk *soundPointing =  nullptr;
// static Mix_Chunk *soundLose =  nullptr;
// static Mix_Chunk *soundJump =  nullptr;
// static Mix_Chunk *soundNext = nullptr;

Mix_Music* loadMusic(string filePath,Mix_Music* music );
void playMusic(Mix_Music* music );
void quitMusic(Mix_Music* music );
void checkLoadSound();
void playPointSound();
void playSoundLose();
void playSoundJump();
void playSoundNext();
SDL_Texture* muteSound(SDL_Renderer* renderer, SDL_Texture* mute, int x, int y,Mix_Music* music);


#endif//sound