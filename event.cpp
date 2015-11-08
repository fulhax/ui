#include "event.hpp"

EventTextInput::EventTextInput(char *key){
    this->key = key;
    this->type = EventType::TextInput;
}

EventMouseMotion::EventMouseMotion(float x, float y){
    this->x = x;
    this->y = y;
}

EventMouseButton::EventMouseButton(
    float x,
    float y,
    MouseButton button,
    MouseButtonState state
) : EventMouseMotion::EventMouseMotion(x, y){

    this->button = button;
    this->buttonState = state;
}
