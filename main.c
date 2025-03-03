#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int SCREEN_WIDTH = 1900;
int SCREEN_HEIGHT = 20;

int main(int argc, char* argv[]) {
    srand(time(NULL));

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL_Init Error: %s", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("HyprBar", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_ALWAYS_ON_TOP | SDL_WINDOW_UTILITY | SDL_WINDOW_BORDERLESS);
    if (window == NULL) {
        SDL_Log("SDL_CreateWindow Error: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == NULL) {
        SDL_Log("SDL_CreateRenderer Error: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Event event;
    int quit = 0;

    while (!quit) {
        float loopStartTime = SDL_GetTicks();

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                quit = 1;
            }
        }

        SDL_SetRenderDrawColor(renderer, 11,10,15, 255);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);

        SDL_Delay(1);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
