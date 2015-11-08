#include "game.h"
#include "ui/elements.hpp"
#include "ui/event.hpp"

void Game::init()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL init error: %s", SDL_GetError());
        return;
    }

    if(!this->createWindow()) {
        return;
    }

    if(!this->createRenderer()) {
        return;
    }

    this->running = 1;
    this->time = SDL_GetTicks();
    this->delta = 0.f;

    this->fps = 0;
    this->fpsTimer.start();

    this->ui.initSDL(this->renderer);
    this->ui.elements["knark"] = new Rect(
        666, 90.f, 90.f, 50.f, 150, 150,
        true, true,
        &this->ui
    );
    /*  this->ui.elements["1knark"] = new Rect(90.f, 500.f, 50.f, 50, 150,
                                           this->ui.getRenderer());
        this->ui.elements["2knark"] = new Rect(90.f, 900.f, 50.f, 250, 150,
                                           this->ui.getRenderer());
    */

    unsigned int framesCount = 0;

    while(this->running) {
        Uint32 oldtime = this->time;
        this->time = SDL_GetTicks();
        this->delta = (float)(this->time - oldtime) / 1000.f;

        if(this->fpsTimer.getTicks() > 1000.f) {
            this->fpsTimer.start();
            framesCount = 0;
        } else {
            this->fps = framesCount / (this->fpsTimer.getTicks() / 1000.f);
        }

        this->handleEvents();
        this->update();
        this->render();
        //printf("Fps:%d\n", this->fps);
        framesCount++;
    }

}

bool Game::createRenderer()
{
    this->renderer = SDL_CreateRenderer(this->window, -1,
                                        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(this->renderer == NULL) {
        printf("SDL Window init error:%s", SDL_GetError());
        return false;
    }

    SDL_RenderSetLogicalSize(this->renderer, 1920, 1080);
    SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);

    return true;
}

bool Game::createWindow()
{
    this->window = SDL_CreateWindow(
                       "Snakefan",
                       SDL_WINDOWPOS_UNDEFINED,
                       SDL_WINDOWPOS_UNDEFINED,
                       1920,
                       1080,
                       SDL_WINDOW_SHOWN
                   );

    if(this->window == NULL) {
        printf("SDL Window init error:%s", SDL_GetError());
        return false;
    }

    return true;
}

void Game::handleEvents()
{
    while(SDL_PollEvent(&this->event)) {
        switch(this->event.type) {
            case SDL_QUIT:
                this->running = 0;
                break;

            // Keypress
            case SDL_KEYDOWN:
                if(SDLK_q == this->event.key.keysym.sym) {
                    this->running = 0;
                }

                break;
        }

        this->passEventToUi(&this->event);

    }
}

void Game::passEventToUi(SDL_Event *event)
{
    if(this->event.type == SDL_TEXTINPUT) {
        EventTextInput e(event->text.text);
        this->ui.handleInputEvent(e);
    } else if(this->event.type == SDL_MOUSEBUTTONDOWN ||
              this->event.type == SDL_MOUSEBUTTONUP) {
        MouseButtonState state;
        MouseButton button;

        if(event->button.button == SDL_BUTTON_LEFT) {
            button = MouseButton::BUTTON_LEFT;
        } else if(event->button.button == SDL_BUTTON_RIGHT) {
            button = MouseButton::BUTTON_RIGHT;
        }

        if(this->event.type == SDL_MOUSEBUTTONDOWN) {
            state = MouseButtonState::BUTTON_DOWN;
        } else if(this->event.type == SDL_MOUSEBUTTONUP) {
            state = MouseButtonState::BUTTON_UP;
        }

        EventMouseButton e(
            (float) event->button.x,
            (float) event->button.y,
            button,
            state
        );
        this->ui.handleInputEvent(e);
    } else if(this->event.type == SDL_MOUSEMOTION) {
        EventMouseMotion e(
            (float)event->motion.x,
            (float)event->motion.y,
            (float)event->motion.xrel,
            (float)event->motion.yrel
        );

        if(SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
            e.button = MouseButton::BUTTON_LEFT;
            e.state = MouseButtonState::BUTTON_DOWN;
        } else if(SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT)) {
            e.button = MouseButton::BUTTON_RIGHT;
            e.state = MouseButtonState::BUTTON_DOWN;
        }

        this->ui.handleInputEvent(e);
    }
}

void Game::render()
{
    SDL_RenderClear(this->renderer);
    this->ui.render();

    SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);
    SDL_RenderPresent(this->renderer);
}

void Game::update()
{
}

Game::~Game()
{
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}
