// MouseManager.cpp
#include "MouseManager.h"
#include <iostream>

void MouseManager::handleEvent(SDL_Event& event) {
    if (event.type == SDL_MOUSEBUTTONDOWN) {
        std::cout << "Mouse button " << (int)event.button.button << " pressed at (" 
                  << event.button.x << ", " << event.button.y << ")" << std::endl;
    }
}
