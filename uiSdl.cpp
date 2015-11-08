#include "uiSdl.hpp"

void UiSdl::drawRect(Rectangle rect){
    SDL_SetRenderDrawColor(this->renderer, 0, 200, 200, 200);
    SDL_Rect r={
        (int) rect.x,
        (int) rect.y,
        (int) rect.w,
        (int) rect.h
    };
    SDL_RenderFillRect(this->renderer, &r);
}

void UiSdl::drawText(){}
