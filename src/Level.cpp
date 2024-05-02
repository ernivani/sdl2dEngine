
#include "Level.h"

void Level::init() {
    mouseManager = Window::getInstance()->getMouseListener();
    keyboardManager = Window::getInstance()->getKeyboardListener();
    std::cout << "Initialisation de " << name << std::endl;
}

void Level::update(float deltaTime) {
    
}

void Level::handleEvent(SDL_Event& event) {
    // when click on ar ec we change his color 
}
void Level::draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_Rect rect = { 32, 32, 32, 32 };
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    rect = { 64, 32, 32, 32 };
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    rect = { 96, 32, 32, 32 };
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
}