#include "timer.h"

void Timer::start(){
    this->started = SDL_GetTicks();
}

Uint32 Timer::getTicks(){
    return SDL_GetTicks() - this->started;
}
