// Scene.h
#ifndef SCENE_H
#define SCENE_H

#include <SDL2/SDL.h>
#include <string>

class Scene {
public:
    Scene(const std::string& name) : name(name) {}
    virtual ~Scene() {}
    virtual void update(float deltaTime) = 0;
    virtual void draw(SDL_Renderer* renderer) = 0;
    virtual void handleEvent(SDL_Event& event) = 0;
    virtual void init() = 0;
protected:
    std::string name;
};

#endif
