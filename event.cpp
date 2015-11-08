#include "event.hpp"

EventTextInput::EventTextInput(char *key)
{
    this->key = key;
    this->type = EventType::TextInput;
}

EventMouseMotion::EventMouseMotion(
    float x,
    float y,
    float rx,
    float ry
)
{
    this->type = EventType::MouseMotion;
    this->x = x;
    this->y = y;
    this->rx = rx;
    this->ry = ry;
    this->button = MouseButton::NONE;
    this->state = MouseButtonState::NONE;
}

EventMouseMotion::EventMouseMotion(
    float x,
    float y,
    float rx,
    float ry,
    MouseButton button,
    MouseButtonState state
) : EventMouseMotion::EventMouseMotion(x, y, rx, ry)
{
    this->button = button;
    this->state = state;
}

EventMouseButton::EventMouseButton(
    float x,
    float y,
    MouseButton button,
    MouseButtonState state
) : EventMouseMotion::EventMouseMotion(x, y, 0, 0, button, state)
{
    this->type = EventType::MouseButton;
}

OEvent::OEvent(int id, EventType type)
{
    this->id = id;
    this->type = type;
}
