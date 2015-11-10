#include <stdlib.h>
#include <time.h>

#include "uiSdl.hpp"

void UiSdl::drawWindow(Window *window)
{
    SDL_Texture *texture = SDL_CreateTexture(
                               renderer,
                               SDL_PIXELFORMAT_RGBA8888,
                               SDL_TEXTUREACCESS_TARGET,
                               (int) 500,
                               (int) 500
                           );
    SDL_SetRenderTarget(this->renderer, texture);
    SDL_SetRenderDrawColor(this->renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    SDL_Rect r = {
        (int) window->getX(),
        (int) window->getY(),
        (int) window->getW(),
        (int) window->getH()
    };
    
    SDL_SetRenderDrawColor(this->renderer, 0xFF, 0x55, 0x55, 0x55);
    SDL_RenderDrawRect(this->renderer, &r);
    SDL_RenderFillRect(this->renderer, &r);
    printf("hit\n");
    this->drawRect(window);
    /*for(auto el : window->getElements()){
        el->draw();
    }*/

    SDL_SetRenderTarget(this->renderer, NULL);
    SDL_RenderCopy(this->renderer, texture, NULL, NULL);
}

void UiSdl::drawRect(Rect *rect)
{

    if(this->seed == 0) {
        this->seed = time(0);
    }

    int cr = rand_r(&this->seed) % 255;
    int cg = rand_r(&this->seed) % 255;
    int cb = rand_r(&this->seed) % 255;

    if(rect->parent != nullptr) {

    } else {
        SDL_SetRenderDrawColor(this->renderer, 0, cr, cg, cb);
        SDL_Rect r = {
            (int) rect->getX(),
            (int) rect->getY(),
            (int) rect->getW(),
            (int) rect->getH()
        };
        SDL_RenderFillRect(this->renderer, &r);
    }
}

void UiSdl::drawText() {}
