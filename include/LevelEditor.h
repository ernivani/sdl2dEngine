// Level.h
#ifndef LEVELEdITOR_H
#define LEVELEdITOR_H

#include "Scene.h"

class LevelEditor : public Scene {
public:

    LevelEditor(const std::string& name) : Scene(name) {}
    void init() override;
    void update(float deltaTime) override;
    void handleEvent(SDL_Event& event) override;
    void draw(SDL_Renderer* renderer) override;
};

#endif