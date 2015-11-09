#include <stdlib.h>
#include <time.h>

#include "uiSdl.hpp"

void UiSdl::drawRect(Rect *rect){

    if(this->seed == 0) this->seed = time(0);
    int cr = rand_r(&this->seed) % 255;
    int cg = rand_r(&this->seed) % 255;
    int cb = rand_r(&this->seed) % 255;
    
    if(rect->parent != nullptr){

    }

    SDL_SetRenderDrawColor(this->renderer, 0, cr, cg, cb);
    SDL_Rect r={
        (int) rect->getX(),
        (int) rect->getY(),
        (int) rect->getW(),
        (int) rect->getH()
    };
    SDL_RenderFillRect(this->renderer, &r);
}

void UiSdl::drawText(){}

