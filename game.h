#include <SDL2/SDL.h>
#include "timer.h"
#include "ui/ui.hpp"

class Game {
    bool running;

    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;

    float delta;
    Timer fpsTimer;
    unsigned int fps;
    Uint32 time;

    Ui ui;

    public:
        Game();
        void render();
        void handleEvents();
        void update();
        bool createWindow();
        bool createRenderer();
        void passEventToUi(SDL_Event *event);
        void init();
        ~Game();

};
