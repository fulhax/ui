#include "vector2.h"

Vec2::Vec2(float x, float y){
    this->Set(x, y);
}

void Vec2::Set(float x, float y){
    this->x = x;
    this->y = y;
}

void Vec2::up(){
    this->Set(0,-1);
}

void Vec2::down(){
    this->Set(0,1);
}

void Vec2::right(){
    this->Set(1,0);
}

void Vec2::left(){
    this->Set(-1, 0);
}
