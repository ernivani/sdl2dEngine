// MouseManager.h
#ifndef MOUSE_MANAGER_H
#define MOUSE_MANAGER_H

#include <SDL2/SDL.h>

class MouseManager {
public:
    void handleEvent(SDL_Event& event);
};

#endif
