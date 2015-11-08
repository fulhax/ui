#ifndef EVENT_HPP
#define EVENT_HPP
#include <stdint.h>

enum class EventType {
    Click,
    Hover,
    Drag,
    Resize,
    MouseMotion,
    MouseButton,
    TextInput,
    MouseWheel
    //Keydown,
    // JoyAxis,
    // JoyBall,
    // JoyHat,
    // JoyButton,
    // JoyDevice,
    // ControllerAxis,
    // ControllerButton,
    // ControllerDevice
};

enum class MouseButton {
    NONE,
    BUTTON_LEFT,
    BUTTON_RIGHT,
    BUTTON_MIDDLE
};

enum class MouseButtonState {
    NONE,
    BUTTON_UP,
    BUTTON_DOWN
};


class Event
{
public:
    EventType type;
};

class OEvent : public Event
{
public:
    OEvent(int id, EventType type);
    int id;
};


class EventTextInput : public Event
{
public:
    EventTextInput(char *key);
    char *key;
};

class EventMouseMotion : public Event
{
public:
    EventMouseMotion(
        float x,
        float y,
        float rx,
        float ry
    );
    EventMouseMotion(
        float x,
        float y,
        float rx,
        float ry,
        MouseButton button,
        MouseButtonState state
    );

    float x;
    float y;
    float rx;
    float ry;
    MouseButton button;
    MouseButtonState state; // state of the button
};

class EventMouseButton : public EventMouseMotion
{
public:
    EventMouseButton(
        float x,
        float y,
        MouseButton button,
        MouseButtonState state
    );


};

class EventMouseWheel
{
    float x;
    float y;
};

//class EventKeyboard : public Event {};
#endif /* ifndef EVENT_HPP */
