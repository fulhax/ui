#ifndef RECT_H
#define RECT_H
#include <list>
#include <string>
#include <stdint.h>
#include "../event.hpp"

class Ui;
class Renderer;
class Rect
{
public:
    Rect(
        int id,
        float x,
        float y,
        float z,
        unsigned int w,
        unsigned int h,
        bool movable,
        bool resizable,
        Ui *ui
    );
    virtual void attach(Rect *parent);
    virtual void detach();
    virtual bool inBounds(float x, float y);
    virtual void handleEvent(const Event &event);
    virtual void draw();
    virtual void resize(unsigned int w, unsigned int h);
    virtual void move(float x, float y);
    float getX();
    float getY();
    unsigned int getW();
    unsigned int getH();
    Rect *parent;
private:
    unsigned int id;
    bool movable;
    bool resizable;
    float x, y, z;
    unsigned int w, h; // uints?
protected:
    Renderer *renderer;
    Ui *ui;
};


///*
//    class Button : public Rect {
//    public:
//        Button(float x, float y, float z, unsigned int w, unsigned int h, std::string label);
//
//        void draw();
//        uint8_t getState();
//        void setState(uint8_t state);
//
//    private:
//        std::string label;
//        int value;
//
//       //
//       // hmm enum hax istället?
//       // uint8_t state;
//       // const uint8_t STATE_HOVER;
//       // const uint8_t STATE_CLICKED;
//       // const uint8_t STATE_DISABLED;
//       //
//    };
//
//    class Label : public Rect {
//    public:
//        Label(float x, float y, float z, unsigned int w, unsigned int h, std::string label);
//
//    private:
//        std::string label;
//    };
//
//    class Textbox : public Label {
//    public:
//        void draw();
//
//    private:
//        bool scroll;
//        float contentHeight;
//        float contentWidth;
//        float scrollTop;
//        float scrollLeft;
//    };
//*/
#endif
