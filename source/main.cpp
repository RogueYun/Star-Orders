//include the SDL libary

//include SDL and iostream replace the SDL include path in windows
#include <SDL2/SDL.h>
#include <iostream>

//Define the screen width and height
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

int main(int argc, char** argv){

    //Create the main
    SDL_Window* mainWindow = nullptr;
    SDL_Renderer* mainRenderer = nullptr;

    //Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0){

        std::cout<<"SDL could not intialize!"<<std::endl;

    }

    else{


        //Create the maín window
        mainWindow = SDL_CreateWindow("Star Orders developement version", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if(mainWindow==nullptr){

            std::cout<<"Window could not be created!"<<std::endl;

        }

        else{

            //Create the main renderer
            mainRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

            if(mainRenderer==nullptr){

                std::cout<<"Renderer could not be created!"<<std::endl;

            }

            else{

                    bool quitPollEvent = false;
                    SDL_Event pollEvent;

                    //Repeat as long as quitPollEvent = false
                    while(quitPollEvent == false){

                        while( SDL_PollEvent(&pollEvent) != 0){

                            //If the windows will be closed quitpollevent = true
                            if(pollEvent.type == SDL_QUIT){

                                quitPollEvent=true;

                            }

                            else{

                                SDL_SetRenderDrawColor(mainRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

                                SDL_RenderClear(mainRenderer);

                                SDL_RenderPresent(mainRenderer);

                            }
                        }
                    }

                }

            }

    }

    //Free the memory
    SDL_DestroyRenderer(mainRenderer);
    SDL_DestroyWindow(mainWindow);
    SDL_Quit();

    return 0;
}
