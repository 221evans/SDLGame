#include <SDL2/SDL.h>
#include <iostream>

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Failed to initialize SDL2: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("SDL App", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,0);

    // Renders the screen green
    SDL_SetRenderDrawColor(renderer, 0,255,0,255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    if (!window)
    {
        std::cout << "Failed to create window: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Event event;
    bool running = true;
    while (running)
    {
        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
            // Add code to handle other event types like SDL_KEYDOWN, SDL_MOUSEBUTTONDOWN and so on...
        }

        // Put your game rendering code here...

        SDL_Delay(16); // Delay to limit the loop to ~60 frames per second
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}