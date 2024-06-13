// Window.cpp
#include "Window.h"
#include "Level.h"
#include "LevelEditor.h"
#include "KeyboardManager.h"
#include "MouseManager.h"
#include <algorithm>

Window* Window::selfInstance = nullptr;

Window::Window(const char* title, int width, int height)
    : width(width), height(height), currentScene(nullptr) {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    lastFrameTime = SDL_GetTicks();
}


Window::~Window() {
    delete currentScene;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Window::init() {
    changeScene(1);
    mouseManager = MouseManager();
}

void Window::changeScene(int sceneIndex) {
    delete currentScene;
    switch (sceneIndex) {
    case 0:
        currentScene = new Level("LevelScene");
        currentScene->init();
        break;
    case 1:
        currentScene = new LevelEditor("LevelEditorScene");
        currentScene->init();
        break;
    }
}

void Window::update(float deltaTime) {
    if (currentScene == nullptr) { 
        return; 
    }
    currentScene->update(deltaTime);
    draw();
}
void Window::draw() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    currentScene->draw(renderer);
    SDL_RenderPresent(renderer);
}

// getRenderer
SDL_Renderer* Window::getRenderer() {
    return renderer;
}


Window *Window::getInstance() {
    if (!selfInstance) {
        selfInstance = new Window("Game", 800, 600);
    }
    return selfInstance;
}

MouseManager* Window::getMouseListener() {
    if (currentScene == nullptr) {
        return nullptr;
    }
    return &mouseManager;
}

KeyboardManager* Window::getKeyboardListener() {
    if (currentScene == nullptr) {
        return nullptr;
    }
    return &keyboardManager;
}


void Window::mainLoop() {
    running = true;
    const float maxFrameTime = 0.25f;

    Uint64 performanceFrequency = SDL_GetPerformanceFrequency();
    Uint64 lastFrameCounter = SDL_GetPerformanceCounter();
    SDL_Event event;

    while (running) {
        Uint64 currentFrameCounter = SDL_GetPerformanceCounter();
        float deltaTime = float(currentFrameCounter - lastFrameCounter) / performanceFrequency;
        lastFrameCounter = currentFrameCounter;

        deltaTime = std::min(deltaTime, maxFrameTime);
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            } else {
                currentScene->handleEvent(event);
            }
        }
        update(deltaTime);
    }
}