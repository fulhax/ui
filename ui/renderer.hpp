#ifndef RENDERER_HPP
#define RENDERER_HPP
#include "elements/rect.hpp"
#include "elements/window.hpp"

class Rect;
class Renderer {
    public:
        virtual void drawRect(Rect *rect);
        virtual void drawWindow(Window *window);
        virtual void drawText();
        virtual void onInputEvent();
};
#endif /* ifndef RENDERER_HPP */
