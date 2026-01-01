#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>

int main() {
    std::cerr << "[INITIALIZATION] Starting SDL3 initialization\n";
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << "[DEBUG] SDL Init failed :" << SDL_GetError() << "\n";
        return 1;
    }

    std::cerr << "[INITIALIZATION] Starting SDL3_ttf initialization\n";
    if (!TTF_Init()) {
        std::cerr << "[DEBUG] TTF Init failed :" << SDL_GetError() << "\n";
        SDL_Quit();
        return 1;
    }

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    if (!SDL_CreateWindowAndRenderer(
        "AeroBlade",
        1280,
        720,
        SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIGH_PIXEL_DENSITY,
        &window,
        &renderer)) {
        std::cerr << "[ERROR] SDL_CreateWindowAndRenderer failed: " << SDL_GetError() << "\n";
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    if (!SDL_SetRenderVSync(renderer, 1)) {
        std::cerr << "[WARNING] VSync failed: " << SDL_GetError() << "\n";
    }

    int windowWidth = 0, windowHeight = 0;
    if (!SDL_GetWindowSize(window, &windowWidth, &windowHeight)) {
        std::cerr << "[ERROR] Failed to get window size: " << SDL_GetError() << "\n";
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }
    std::cout << "[INFO] Window size: " << windowWidth << "x" << windowHeight << "\n";

    int screenWidth = windowWidth;
    int screenHeight = windowHeight;
    std::cout << "[INFO] Game configured for resolution: "
        << screenWidth << "x" << screenHeight << "\n";

    bool running = true;
    SDL_Event e;
    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return 0;
}
