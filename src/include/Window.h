#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <iostream>
#include "Scene.h"
#include "MouseManager.h"
#include "KeyboardManager.h"

class Window {
public:
    Window(const char* title, int width, int height);
    ~Window();
    void mainLoop();
    void update(float dt);
    void draw();
    void init();
    void changeScene(int sceneIndex);
    MouseManager* getMouseListener();
    KeyboardManager* getKeyboardListener();
    static Window* getInstance();
    SDL_Renderer* getRenderer();
    

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    int width;
    int height;
    Uint32 lastUpdate;
    int lastFrameTime;
    bool running;
    Scene* currentScene;
    MouseManager mouseManager;
    KeyboardManager keyboardManager;
    static Window* selfInstance;
};

#endif