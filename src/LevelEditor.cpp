
#include "LevelEditor.h"
#include <iostream>


LevelEditor::LevelEditor(const std::string& name)
    : Scene(name), currentColorIndex(0), rows(10), cols(10), rectWidth(32), rectHeight(32) {
    colors.push_back({255, 0, 0, 255}); // Red
    colors.push_back({0, 255, 0, 255}); // Green
    colors.push_back({0, 0, 255, 255}); // Blue
    colors.push_back({255, 255, 0, 255}); // Yellow
    colors.push_back({139,69,19,255}); // Brown
    colors.push_back({255,165,0,255}); // Orange
    colors.push_back({255,192,203,255}); // Pink
    colors.push_back({128,0,128,255}); // Purple
    colors.push_back({0,255,255,255}); // Cyan
    colors.push_back({255,0,255,255}); // Magenta
    colors.push_back({0,0,0,255}); // Black
    colors.push_back({255,255,255,255}); // White

    // Initialize the grid of rectangles
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            SDL_Rect rect = {j * rectWidth, i * rectHeight, rectWidth, rectHeight};
            rectangles.push_back(rect);
            rectangleColors.push_back(colors[0]); // Initialize all rectangles with the first color
        }
    }
}

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
    // Gérer les événements de la souris
    if (event.type == SDL_MOUSEBUTTONDOWN) {
        std::cout << "Mouse button " << (int)event.button.button << " pressed at (" 
                  << event.button.x << ", " << event.button.y << ")" << std::endl;
        for (size_t i = 0; i < rectangles.size(); ++i) {
            if (SDL_PointInRect(new SDL_Point{event.button.x, event.button.y}, &rectangles[i])) {
                changeRectangleColor(i);
                break;
            }
        }
    }

    // Gérer les événements du clavier
    if (event.type == SDL_KEYDOWN) {
        std::cout << "Key press detected: " << SDL_GetKeyName(event.key.keysym.sym) << std::endl;
        if (event.key.keysym.sym == SDLK_c) {
            std::cout << "Key 'C' pressed - Changing color of all rectangles" << std::endl;
            for (size_t i = 0; i < rectangles.size(); ++i) {
                changeRectangleColor(i);
            }
        }
    } else if (event.type == SDL_KEYUP) {
        std::cout << "Key release detected: " << SDL_GetKeyName(event.key.keysym.sym) << std::endl;
    }
}


void LevelEditor::changeRectangleColor(int index) {
    currentColorIndex = (currentColorIndex + 1) % colors.size();
    rectangleColors[index] = colors[currentColorIndex];
    std::cout << "Rectangle color changed to: (" << (int)colors[currentColorIndex].r << ", " 
              << (int)colors[currentColorIndex].g << ", " 
              << (int)colors[currentColorIndex].b << ")" << std::endl;
}

void LevelEditor::draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    for (size_t i = 0; i < rectangles.size(); ++i) {
        SDL_SetRenderDrawColor(renderer, rectangleColors[i].r, rectangleColors[i].g, rectangleColors[i].b, rectangleColors[i].a);
        SDL_RenderFillRect(renderer, &rectangles[i]);
    }

    SDL_RenderPresent(renderer);
}