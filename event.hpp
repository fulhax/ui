#ifndef EVENT_HPP 
#define EVENT_HPP

enum class EventType {
    Keyboard,
    MouseMotion,
    MouseButton,
    MouseWheel,
    // JoyAxis,
    // JoyBall,
    // JoyHat,
    // JoyButton,
    // JoyDevice,
    // ControllerAxis,
    // ControllerButton,
    // ControllerDevice
};



struct Event {
    EventType type;
    uint32_t time;
    EventData data;
};

class Event;

class EventKeyboard : public EventData {
    uint32_t keycode;
}

class EventMouseMotion : public EventData {
    int x;
    int y;
    uint32_t state; // state of the button
}

class EventMouseButton : public EventMouseMotion {
    uint8_t button;
}

#endif /* ifndef EVENT_HPP */
