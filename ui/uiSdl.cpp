#include <stdlib.h>
#include <time.h>

#include "uiSdl.hpp"


void UiSdl::drawRect(Rect *rect){

    unsigned int seed = time(0);
    int cr = rand_r(&seed) % 255;
    seed++;
    int cg = rand_r(&seed) % 255;
    seed++;
    int cb = rand_r(&seed) % 255;

    SDL_SetRenderDrawColor(this->renderer, 0, cr, cg, cb);
    SDL_Rect r={
        (int) (rect->getX() + rect->parent->getX()),
        (int) (rect->getY() + rect->parent->getY()),
        (int) rect->getW(),
        (int) rect->getH()
    };
    SDL_RenderFillRect(this->renderer, &r);
}

void UiSdl::drawText(){}

