#ifndef UI_WINDOW_HPP
#define UI_WINDOW_HPP

#include "rect.hpp"

class Window : public Rect
{
public:
    virtual void draw();
    virtual void addElement(Rect *rect);
    virtual std::list<Rect> getElements();
private:
    std::list<Rect> elements;
};

#endif /* ifndef UI_WINDOW_HPP */
