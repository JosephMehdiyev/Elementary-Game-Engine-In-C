#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include "../include/constants.h"

int program_is_running = FALSE;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;


int initialize_window(void) {
    if (SDL_Init(SDL_INIT_EVERYTHING) !=0){
        fprintf(stderr, "Error initializing SDL.\n");
        return FALSE;
    }
    window = SDL_CreateWindow(
        "Cormat",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1024,
        576,
        SDL_WINDOW_SHOWN
    );
    if (!window) {
        fprintf(stderr, "Error creating the SDL Window. \n");
        return FALSE;
    }
    
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer){
        fprintf(stderr,"Error creating the SDL Render");
        return FALSE;
    }

    return TRUE;
}

void process_input(void) {
    SDL_Event event;
    SDL_PollEvent(&event);



    switch (event.type){
        case SDL_QUIT:
            program_is_running = FALSE;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
                program_is_running = FALSE;
            break;
        case SDL_WINDOWEVENT:
            if (event.window.event == SDL_WINDOWEVENT_CLOSE)
                program_is_running = FALSE;
            break;
    }
}

void update(void) {

}

void render(void) {

}

void quit_window(void) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void setup(void) {

}



int main(void) {
    program_is_running = initialize_window();

    setup();

    while (program_is_running) {
        process_input();
        update();
        render();
    }

    quit_window();

    return 0    ;
}       