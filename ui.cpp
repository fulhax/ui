#include "ui.hpp"

void Renderer::drawRect(Rectangle rect){}
void Renderer::drawText(){}

void UiSdl::drawRect(Rectangle rect){
    SDL_SetRenderDrawColor(this->renderer, 0, 200, 200, 200);
    SDL_Rect r={
        rect.x,
        rect.y,
        rect.w,
        rect.h
    };
    SDL_RenderFillRect(this->renderer, &r);
}

void UiSdl::drawText(){}


void Ui::initSDL(SDL_Renderer* renderer){
    UiSdl *r = new UiSdl;
    r->renderer = renderer;
    this->renderer = r; 
}

void Ui::render(){
    for(auto obj : this->elements) {
        obj.second->draw();
    }
}

Renderer* Ui::getRenderer(){
    return this->renderer;
}

Ui::~Ui(){
    delete this->renderer;

    for(auto obj : this->elements) {
        delete obj.second;
    }
    this->elements.clear();
};
