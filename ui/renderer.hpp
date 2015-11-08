#ifndef RENDERER_HPP
#define RENDERER_HPP
#include "rectangle.hpp"

class Renderer {
    public:
        virtual void drawRect(Rectangle rect);
        virtual void drawText();
        virtual void onInputEvent();
};
#endif /* ifndef RENDERER_HPP */
