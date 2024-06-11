#include <iostream>
#include "window.h"

#define LOG(X) std::cout << X << std::endl

int main() {
    Window window;
    bool running = true;

    LOG("!Opened a window!");

    while (running) {
        if (!window.ProcessMessages()){
            LOG("!Window closed!");
            running = false;
        }
    }
}