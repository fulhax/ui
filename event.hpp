#ifndef EVENT_HPP 
#define EVENT_HPP
#include <stdint.h>

enum class EventType {
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
    BUTTON_LEFT,
    BUTTON_RIGHT
};

enum class MouseButtonState {
    BUTTON_UP,
    BUTTON_DOWN
};


class Event {
    public:
        EventType type;
};


class EventTextInput : public Event {
    public:
        EventTextInput(char *key);
        char *key;
};

class EventMouseMotion : public Event {
    public:
        EventMouseMotion(float x, float y);
        float x;
        float y;
        //MouseState state; // state of the button
};

class EventMouseButton : public EventMouseMotion {
    public:
        EventMouseButton(
            float x,
            float y,
            MouseButton button,
            MouseButtonState state
        );
        MouseButton button;
        MouseButtonState buttonState;
};

class EventMouseWheel {
    float x;
    float y;
};

//class EventKeyboard : public Event {};
#endif /* ifndef EVENT_HPP */
