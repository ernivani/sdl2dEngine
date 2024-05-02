#include "Window.h"

int main(int argc, char* args[]) {
    Window* window = Window::getInstance();
    window->init();
    window->mainLoop();
    return 0;
}
