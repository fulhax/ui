#include "ui.hpp"
#include "uiSdl.hpp"

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

void Ui::handleInputEvent(Event const &e){
    for(auto element : this->elements){
        element.second->handleEvent(e);
    }
}

std::list<OEvent> Ui::getEvents(){
    return this->eventList; 
}

void Ui::addEvent(OEvent e){
    this->eventList.push_back(e);
}

void Ui::clearEvents(){
    this->eventList.clear();
}

Ui::~Ui(){
    delete this->renderer;
    this->clearEvents();

    for(auto element : this->elements) {
        delete element.second;
    }
    this->elements.clear();
};
