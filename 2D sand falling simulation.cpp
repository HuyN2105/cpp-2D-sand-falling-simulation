#include <SDL/SDL.h>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_Event e;

    bool running = true;

    while(running)
    {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) 
                running = false;
            else if (e.type == SDL_KEYDOWN)
            {
                switch (e.key.keysym.sym) {
                    case SDLK_RIGHT:
                        cout << "RIGHT\n";
                }
            }
            else if (e.type == SDL_KEYUP) {
                switch (e.key.keysym.sym) {
                    case SDLK_RIGHT:
                        cout << "RIGHT RELEASED\n";
                    }
            }
           
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawPoint(renderer, 640 / 2, 480 / 2);

        SDL_RenderPresent(renderer);
    }

    cout << "Hello World!\n";
    return 0;
}
