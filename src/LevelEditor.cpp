
#include "LevelEditor.h"
#include <iostream>

void LevelEditor::init() {
    // Implémentation spécifique à un niveau de jeu
    // Exemple: chargement des ressources, initialisation des entités, etc.
    std::cout << "Initialisation de " << name << std::endl;
}

void LevelEditor::update(float deltaTime) {
    // Implémentation spécifique à un niveau de jeu
    // Exemple: gestion des entités, collisions, etc.
}

void LevelEditor::handleEvent(SDL_Event& event) {
    // Implémentation spécifique à un niveau de jeu
    // Exemple: gestion des événements clavier/souris, etc.
}

void LevelEditor::draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    for (int i = 0; i < 800; i += 32) {
        SDL_RenderDrawLine(renderer, i, 0, i, 600);
    }
    for (int i = 0; i < 600; i += 32) {
        SDL_RenderDrawLine(renderer, 0, i, 800, i);
    }
    // draw entities
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