// KeyboardManager.cpp
#include "KeyboardManager.h"
#include <iostream>

void KeyboardManager::handleEvent(SDL_Event& event) {
    std::cout << "KeyboardManager::handleEvent" << std::endl;
    if (event.type == SDL_KEYDOWN) {
        std::cout << "Key press detected" << std::endl;
    } else if (event.type == SDL_KEYUP) {
        std::cout << "Key release detected" << std::endl;
    }

    if (event.key.keysym.sym == SDLK_ESCAPE) {
        std::cout << "Escape key pressed" << std::endl;
        SDL_Quit();
        exit(0);
        
    }
}
