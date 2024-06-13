// LevelEditor.h
#ifndef LEVEL_EDITOR_H
#define LEVEL_EDITOR_H

#include "Scene.h"
#include <vector>
#include <SDL2/SDL.h>

class LevelEditor : public Scene {
public:
    LevelEditor(const std::string& name);
    void init() override;
    void update(float deltaTime) override;
    void handleEvent(SDL_Event& event) override;
    void draw(SDL_Renderer* renderer) override;

private:
    std::vector<SDL_Color> colors;
    int currentColorIndex;
    std::vector<SDL_Rect> rectangles;
    std::vector<SDL_Color> rectangleColors;
    int rows;
    int cols;
    int rectWidth;
    int rectHeight;

    void changeRectangleColor(int index);
};

#endif
