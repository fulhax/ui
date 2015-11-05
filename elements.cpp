#include "elements.hpp"

Rect::Rect(float x, float y, float z, unsigned int w, unsigned int h, Renderer *r){
    this->x = x;
    this->y = y;
    this->z = z; // z-index

    this->w = w;
    this->h = h;

    this->renderer = r;
}
/*
void Rect::init(float x, float y, float z, unsigned int w, unsigned int h, Ui *ui){
    this->x = x;
    this->y = y;
    this->z = z; // z-index

    this->w = w;
    this->h = h;

    this->ui = ui;
}
*/

void Rect::resize(unsigned int w, unsigned int h){
    this->w = w;
    this->h = h;
}

void Rect::move(float x, float y){
    this->x = x;
    this->y = y;
}

void Rect::draw(){
    Rectangle rect = {this->x, this->y, this->z, this->h, this->w};
    this->renderer->drawRect(rect);
}

/*
Button::Button(float x, float y, float z, unsigned int w, unsigned int h, std::string label)
    : Rect(x, y, z, w, h){
    this->label = label;
}

// Triggers callback and passes value as first argument;
void Button::onClick(void (*callback)(int)){
    callback(this->value);
}

void Button::onHover(void (*callback)()){
    callback();
}

void Button::draw(){

}


Label::Label(float x, float y, float z, unsigned int w, unsigned int h, std::string label)
    : Rect(x, y, z, w, h){
    this->label = label;
}
*/
