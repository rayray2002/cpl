#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>

int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Surface *surface = NULL;
    SDL_Texture *texture = NULL;
    SDL_Event event;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
        return 3;
    }

    // load support for the JPG and PNG image formats
    int iflags = IMG_INIT_JPG|IMG_INIT_PNG;
    if( (IMG_Init(iflags)&iflags) != iflags ) {
        std::cout << "IMG_Init: Failed to init required jpg and png support!\n";
        std::cout << "IMG_Init: " << IMG_GetError() << std::endl;
        return 3;
    }
    // load support for the MP3 sample/music formats
    int mflags = MIX_INIT_MP3;
    if( (Mix_Init(mflags) & mflags) != mflags ) {
        std::cout << "Mix_Init: Failed to init required ogg and mod support!\n";
        std::cout << "Mix_Init: %s\n" << Mix_GetError() << std::endl;
        return 3;
    }

    if(Mix_OpenAudio(128000, MIX_DEFAULT_FORMAT, 2, 2048)==-1) {
        std::cout << "Mix_OpenAudio: %s\n" << Mix_GetError() << std::endl;
        return 3;
    }


    // load the MP3 file "music.mp3" to play as music
    Mix_Music *music;
    music = Mix_LoadMUS("../mp3/song1.mp3");
    if(!music) {
        std::cout << "Mix_LoadMUS(\"song1.mp3\"): %s\n" << Mix_GetError();
        return 3;
    }

    window = SDL_CreateWindow("Hello World", 50, 50, 1280, 720, SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);
    if (!window) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window: %s", SDL_GetError());
        return 3;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create renderer: %s", SDL_GetError());
        return 3;
    }

    surface = IMG_Load("../img/cover.png");
    if (!surface) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create surface from image: %s", SDL_GetError());
        return 3;
    }
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture from surface: %s", SDL_GetError());
        return 3;
    }
    SDL_FreeSurface(surface);

    Mix_PlayMusic( music, -1 );
    while (1) {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT) {
            break;
        }
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();

    return 0;
}

