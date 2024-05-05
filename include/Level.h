// Level.h
#ifndef LEVEL_H
#define LEVEL_H

#include "Scene.h"
#include <iostream>
#include "MouseManager.h"
#include "KeyboardManager.h"
#include "Window.h"
#include <SDL2/SDL.h>

class Level : public Scene {
public:
    Level(const std::string& name) : Scene(name) {}
    void init() override;
    void update(float deltaTime) override;
    void handleEvent(SDL_Event& event) override;
    void draw(SDL_Renderer* renderer) override;
private:
    MouseManager* mouseManager;
    KeyboardManager* keyboardManager;
};

#endif
