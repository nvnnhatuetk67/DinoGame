#include "sound.h"


bool checkMute = false;
Mix_Music*  loadMusic(string filePath,Mix_Music* music ){
    if(SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cerr << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
    }
    // Initialize SDL_mixer
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
    }
    // Load MP3 file
     music = Mix_LoadMUS(filePath.c_str());//"sound/sound1.mp3"
    if(music == NULL) {
        std::cerr << "Failed to load music! SDL_mixer Error: " << Mix_GetError() << std::endl;
    }
    return music;
}
void playMusic(Mix_Music* music){

    Mix_PlayMusic( music, -1 );
    Mix_VolumeMusic(50);
    Sleep(30);
}
void quitMusic(Mix_Music* music){
    Mix_FreeMusic(music);
}
// void checkLoadSound(){
// if (!soundPointing || !soundJump || !soundLose) {
//         // error handling
//         cout<<"Can't load sound\n";
//     }
// }
// void playPointSound(){
//     soundPointing = Mix_LoadWAV("sounds/point.wav");
//     Mix_PlayChannel(-1, soundPointing, 0);
//     Mix_VolumeChunk(soundPointing, 200);

// }
// void playSoundLose(){
//     soundLose = Mix_LoadWAV("sounds/hit.wav");
//     Mix_PlayChannel(-1 , soundLose, 0);
//     Mix_VolumeChunk(soundLose, 100);

// }
// void playSoundJump(){
//     soundJump = Mix_LoadWAV("sounds/jump.wav");
//     Mix_PlayChannel(-1, soundJump, 0);
//     Mix_VolumeChunk(soundJump, 50);

// }
// void playSoundNext(){
//     soundNext = Mix_LoadWAV("sounds/nextMap.wav");
//     Mix_PlayChannel(-1, soundNext, 0);
//     Mix_VolumeChunk(soundNext, 100);

// }

SDL_Texture* muteSound(SDL_Renderer* renderer, SDL_Texture* mute, int x, int y, Mix_Music* music ){

        if(!checkMute){
                if((x >= 10 && x <= 60)&&( y >= 10 && y <= 60)){
                    Mix_PauseMusic();
                    mute = loadTexture("assets/mute.png", renderer);
                    checkMute = true;
                    }
                }
                else{
                    if((x >= 10 && x <= 60)&&( y >= 10 && y <= 60)){
                    Mix_ResumeMusic();

                    mute = loadTexture("assets/unmute.png", renderer);
                    checkMute = 0;
                    }
                }
    return mute;
}
