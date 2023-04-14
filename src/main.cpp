#include <cmath>
#include "baseFunction.h"
#include "initSDL.h"
#include "baseObject.h"
#include "score.h"
#include "startMenu.h"
#include "character.h"
#include "sound.h"
#include "gameOver.h"
#include "nextMap.h"

using namespace std;
BaseObject g_background;
StartMenu startScreen;
GameOver gameover;
SDL_Color white = {255,255,255};

SDL_Color yellow = { 255 , 253 , 79 };
SDL_Color black = { 0 , 0 , 0 };
SDL_Color pink ={ 250 , 119 , 218 };
SDL_Color orange = { 247 , 160 , 46 };
Mix_Music* ingameSound= loadMusic("sounds/mainbackground.wav", ingameSound);
Mix_Music* introSound = loadMusic("sounds/menu.wav", introSound);
Mix_Music* Music = nullptr;

 Mix_Chunk *soundPointing = Mix_LoadWAV("sounds/point.wav");
 Mix_Chunk *soundLose = Mix_LoadWAV("sounds/hit.wav");
 Mix_Chunk *soundJump = Mix_LoadWAV("sounds/jumping.wav");
 Mix_Chunk *soundNext = Mix_LoadWAV("sounds/nextMap.wav");

bool checkCollision(SDL_Rect rect1, SDL_Rect rect2);




int main(int argv, char** args)
{
    //Create game screen
    SDL_Renderer* renderer;
    SDL_Window* window;
    SDL_Texture* texture = NULL;
    initSDL(window, renderer);
    TTF_Init();
    TTF_Font* font = TTF_OpenFont("fonts/04B_19__.ttf", 28);
    SDL_SetRenderDrawColor(renderer, 10, 10, 10 ,255 );
    SDL_RenderClear(renderer);
     
    //Set up sound
//    Mix_Music* introSound = loadMusic("sounds/menu.wav", introSound);
//     Mix_PlayMusic( introSound, -1 );
//     Mix_VolumeMusic(50);

    //Set up background
    int bg_x = 0, bg_y = 0;
    int bg_w = 4248, bg_h = 512;
    int  bg_speed= 15;
    g_background.LoadImg("assets/background.png", renderer);
    g_background.SetSizeRect(bg_w, bg_h);
    
    
    //......................
    //.....SET UP SCORE.....
    //......................
    // BaseObject score;
    // score.LoadText("Score: ", font, {0,255,255}, renderer);
    // score.SetRect(750, 20);
    // score.SetSizeRect(100,30);
    

    // BaseObject hscore;
    // hscore.LoadText("HighScore: ", font, {0,255,255}, renderer);
    // hscore.SetRect(750, 50);
    // hscore.SetSizeRect(100,30);

    //Background
    

    Point pointText;
    int p = 0, hp = 200;
    pointText.setPoint(p);
    pointText.setHighPoint(hp);
    

    BaseObject dino;
    int dino_x = 80, dino_y = 325;
    dino.LoadImg("character/run1.png", renderer);
    dino.SetRect(dino_x, dino_y);
    dino.SetSizeRect(66*2 , 59*2);

   // Obstacles 
    int x_ob = 800, y_ob = 302;
    int x_ob1 = 1280;
    int ob_w = 73, ob_h = 135;
    BaseObject ob;
    ob.LoadImg("assets/fire.png", renderer);
    ob.SetEntireRect(x_ob , y_ob , ob_w ,ob_h);
    BaseObject ob1;
    ob1.LoadImg("assets/fire.png", renderer);
    ob1.SetEntireRect(x_ob1 , y_ob , ob_w ,ob_h);

    BaseObject opt;
    opt.LoadImg("assets/intro.png", renderer);
    opt.SetEntireRect(10, 80 , 50 , 50);

    BaseObject Mute;
    Mute.LoadImg("assets/mute.png", renderer);
    Mute.SetEntireRect(10 , 10 , 50 , 50);
     SDL_Texture* mute = loadTexture("assets/unmute.png", renderer);

    Character Dino;
    SDL_Texture* run1 = loadTexture("character/Run1.png", renderer);
    SDL_Texture* run2 = loadTexture("character/Run2.png", renderer);
    SDL_Texture* run3 = loadTexture("character/Run3.png", renderer);
    SDL_Texture* run4 = loadTexture("character/Run4.png", renderer);

    SDL_Texture* dead = loadTexture("character/Dead.png", renderer);
    SDL_Texture* jump = loadTexture("character/Jump.png", renderer);
    //Dino.SetDinoRect(dino_x, dino_y, 66*2 , 59*2);

 
    // Create motion for main character
   
   // SDL_RenderCopy(renderer, background , nullptr , nullptr);
   
     
    
    // Jump 
    int vy = -15;
    int ay = 1;
    bool isJumping = false;
    bool running = true;
    bool checkStart = true;// Start screen appears only one time on the first background
    bool checkLose = 1; // if collided, character will stop moving;
    bool checkPlay = 0;// If mouse click at play button, game will run
    int countBg = 0;// To change background when you get enough point.
    bool checkIntro = 0;// To check display Intro image
    int checkMap = 100;// To change map if score is greater than it

    SDL_Color color = {255,255,255};
    SDL_Color color1 = {255,255,255};
    SDL_Color colorPlay = white;
    SDL_Color colorScore = white;

    while(running){
        g_background.Render(renderer, nullptr);
        opt.Render(renderer, nullptr);
        
        Mute.Render(renderer,nullptr);
        Mute.SetTexture(mute);
        //  score.Render(renderer, nullptr);
        //  hscore.Render(renderer, nullptr);
        if(!checkPlay){
            if( !checkIntro ){
                Dino.Idle(renderer,dino_x, dino_y - 51, 233 , 59*3);
             }
            if(Music != introSound){
            Mix_HaltMusic();
               Music = introSound;
            }
 
            while(SDL_PollEvent(&event)) {
                if(event.type == SDL_QUIT){
                    running = 0;
                }
                    if(event.type == SDL_MOUSEMOTION){
                        int x, y;
                        SDL_GetMouseState(&x, &y);
                       if((x >= 270 && x <= 720)&&( y >= 330 && y <= 370))
                             colorPlay = pink;
                        else
                             colorPlay = white;
                    }
                    if(event.type == SDL_MOUSEBUTTONDOWN){
                       if(event.button.button == SDL_BUTTON_LEFT){
                        int x, y;
                        SDL_GetMouseState(&x, &y);
                        // playRect = {270, 330, 450, 40 };
                        if((x >= 270 && x <= 720)&&( y >= 330 && y <= 370)&& checkIntro == 0) {checkPlay = true;}

                        //introRect ={ 10, 80 , 50 , 50 }
                        if(!checkIntro){
                            if((x >= 10 && x <= 60)&&( y >= 80  && y <= 130) ) checkIntro = true;
                        }
                        else {
                            if((x >= 10 && x <= 60)&&( y >= 80  && y <= 130)) checkIntro = false;
                        }

                        mute = muteSound(renderer, mute, x, y,Music);

                        }
                    }
                }
            }
        if(checkPlay){
            if(Music != ingameSound){
                Mix_HaltMusic();
                Music = ingameSound;
            }
         }

         if(!Mix_PlayingMusic()  && !checkMute )
                playMusic(Music);    

        while(SDL_PollEvent(&event)) {
                if(event.type == SDL_QUIT){
                    running = false; 
                }
                if(event.type == SDL_KEYDOWN)
                    switch(event.key.keysym.sym){
                        case SDLK_RIGHT:{
                         
                        }   
                           
                            break;
                        case SDLK_UP:{
                            
                            Mix_PlayChannel(-1, soundJump, 0);
                            Mix_VolumeChunk(soundJump, 50);

                           // playSoundJump();
                            if (!isJumping) {
                                    isJumping = true;
                                    vy = -20;

                                }
                          
                        }
                        break;
                        }
                if(event.type == SDL_MOUSEBUTTONDOWN){
                    if(event.button.button == SDL_BUTTON_LEFT){
                        int x, y;
                        SDL_GetMouseState(&x, &y);
                        mute = muteSound(renderer, mute, x, y, Music);
                     }
                }        
                            

        }
        //
         if(checkLose){
            if(pointText.checkPoint(dino, ob) ){
                p += 10;
                pointText.setPoint(p); 
                countBg+=10;
                Mix_PlayChannel(-1, soundPointing, 0);
                Mix_VolumeChunk(soundPointing, 200);
            }
            if(pointText.checkPoint(dino, ob1) ){
                p += 10;
                pointText.setPoint(p); 
                countBg+=10;
                Mix_PlayChannel(-1, soundPointing, 0);
                Mix_VolumeChunk(soundPointing, 200);
            }
        }
        // Render score
        pointText.setScore(renderer, 750, 20, 100, 30, font);
        pointText.setHighScore(renderer, colorScore, 750, 50, 150, 30, font);
        if(checkPlay){
            pointText.displayScore(renderer);
        }

         // Map movement
        if(checkLose && checkPlay){
            bg_x -= bg_speed/5;
            g_background.SetRect(bg_x, bg_y);
        }




        // The map should be reset if it runs out during gameplay.
        if(bg_x <= SCREEN_WIDTH - bg_w && checkPlay ){bg_x = -10;}

        //Movement of obstacles
        if(checkLose && checkPlay && bg_x > 960 - bg_w){
            x_ob -= bg_speed/2;
            x_ob1 -= bg_speed/2;
            ob.SetRect(x_ob, y_ob);
            ob1.SetRect(x_ob1, y_ob);
        }

        // Reset obstacles
        if(x_ob < -20)  {x_ob = 1000;}
        if(x_ob1 < -20) {x_ob1 = 980;}

        // If you press the play button, obstacles will appear on screen
        if(checkPlay){
            ob.Render(renderer, nullptr);
            ob1.Render(renderer, nullptr);
            //ob.Free();
           // ob1.Free();
        }

        if (isJumping && checkLose){
            
                //SDL_Rect destRect = dino.getRect();
                dino.SetTexture(jump);
                //dino.Render(renderer, nullptr);
                dino_y += vy;
                vy += ay;
                dino.SetRect(dino_x, dino_y);
                //
                if (dino_y >= 325) {
                    dino_y = 325;
                    vy = -10;
                    
                    isJumping = false;
                }
            }
        if(checkPlay ){
            dino.Render(renderer, nullptr);
        }
        
        if(checkPlay ){

       // int num = rect_bg.x;
        /*if(checkLose && !isJumping){
            inputTexture(renderer);
            animateCharacter(renderer, runTextures, 4, destRect, num, isJumping);
        }*/
            SDL_Rect rect_bg = g_background.getRect();
            if(checkLose && !isJumping){
                if(fmod(-rect_bg.x/30,4) == 1){

                    dino.SetTexture(run1);
                    dino.Render(renderer, nullptr);
                }
                else if((fmod(-rect_bg.x/30,4) == 2)){

                    dino.SetTexture(run2);
                    dino.Render(renderer, nullptr);
                }
                else if((fmod(-rect_bg.x/30,4) == 3)){
                     dino.SetTexture(run3);
                    dino.Render(renderer, nullptr);
                }

              
                else{
                    dino.SetTexture(run4);
                    dino.Render(renderer, nullptr);
                }
                    
                }

    }

          //Check collision
        if(checkCollision(dino.getRect(), ob.getRect()) || checkCollision(dino.getRect(), ob1.getRect())){

           // if(checkLose) playSoundLose();
            if(checkLose){
                Mix_PlayChannel(-1 , soundLose, 0);
                Mix_VolumeChunk(soundLose, 100);
            }
            dino.SetRect(80, 325);// To prevent the main character from becoming suspended ,if game lose.
            dino.SetTexture(dead);
            dino.Render(renderer, nullptr);
            //SDL_RenderCopy(renderer, dead, nullptr, &destRect);
            //Display lose screen
            int num =  pointText.getPoint();
            gameover.RenderGameOver(renderer, font, num);
            

            checkLose = 0;

            // Reset all to Start screen
            while(SDL_PollEvent(&event)) {
                if(event.type == SDL_QUIT){
                        running = 0;

                    }
                    // startRect  = {410 ,370, 200, 40};

                    if(event.type == SDL_MOUSEMOTION) {

                        int x, y;
                        SDL_GetMouseState(&x, &y);

                        if((x >= 310 && x <= 510)&&( y >= 370  && y <= 410)){
                        color = {249,113,247};
                        }
                        //exitRect = {550,370, 110,38};
                        else if((x >= 590 && x <= 700)&&( y >= 370  && y <= 408))

                            color1 = {239,0,23};

                        else{
                            color = color1 = white;
                        }
                        //exitGame(renderer,x,y);
                    }

                   if(event.type == SDL_MOUSEBUTTONDOWN){

                       if(event.button.button == SDL_BUTTON_LEFT){
                        int x, y;
                        SDL_GetMouseState(&x, &y);
                        if((x >= 590 && x <= 700)&&( y >= 370  && y <= 408)){ running = 0; }

                        //{310 ,370, 200, 40}
                        if((x >= 310 && x <= 510)&&( y >= 370  && y <= 410)){
                        //Add a feature to reset the game to its initial state once the player loses and chooses to restart.
                            pointText.setPoint(0)  ;     
                            bg_speed    = 15;
                            countBg     = 0;
                            checkPlay   = 0;
                            checkMap    = 100;
                            checkLose   = 1;
                            p = 0;
                            
                            g_background.LoadImg("assets/background.png" ,renderer) ;
                            g_background.SetSizeRect(bg_w, bg_h);

                            if(!ob.LoadImg("assets/fire.png",renderer))
                              cout<<"Error to load this image!...\n";
                            ob.SetEntireRect(800, y_ob , ob_w ,ob_h);

                            ob1.LoadImg("assets/fire.png",renderer);
                            ob1.SetEntireRect(1280 , y_ob , ob_w ,ob_h);

                            g_background.SetRect(0, 0);
                            // ob.SetRect(800, y_ob);
                            // ob1.SetRect(1280, y_ob);
                            x_ob = 800;
                            x_ob1 = 1280;
                            bg_x = 0;

                            


                            checkStart = true;
                            
                        }

                        mute = muteSound(renderer, mute, x, y,Music);
                    }
                }
            }
            gameover.RenderOpt(renderer,font, color, color1);


        }
        // Reset countBg
        if(countBg > 502) countBg = 0;

         if(pointText.getPoint() > checkMap ){
                //point+=30;
            
            Mix_PlayChannel(-1, soundNext, 0);
            Mix_VolumeChunk(soundNext, 100);
            //playSoundNext();


            g_background.SetRect(0, 0);
            ob.SetRect(800, y_ob);
            ob1.SetRect(1280, y_ob);
            x_ob = 800;
            x_ob1 = 1280;
            bg_x = 0;


            bg_speed  += 2;
          
            
            
            g_background.SetTexture(updateBackground(renderer, countBg));
            ob.SetTexture(updateObject(renderer, countBg));
            ob1.SetTexture(updateObject(renderer, countBg));
          
            checkMap  += 100;
            checkStart = 0;
        }

        // Render start screen    
        if( checkStart && !checkPlay && !checkIntro ){
        startScreen.renderStart(renderer, font, pointText.getHightPoint(), colorPlay);
        }
        if(checkIntro)
             startScreen.introduceGame(renderer);
        
        
        SDL_RenderPresent(renderer);

    }


    //Quit game
    waitUntilKeyPressed();
    quitSDL(window, renderer);

	return 0;
}
bool checkCollision(SDL_Rect rect1, SDL_Rect rect2){
    if((rect1.x > rect2.x - 80&& rect1.x < rect2.x + rect2.w - 20  )&&( rect1.y >= rect2.y ))
       return true;
    return 0;
}

