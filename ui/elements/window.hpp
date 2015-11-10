#ifndef UI_WINDOW_HPP
#define UI_WINDOW_HPP

#include "rect.hpp"

class Window : public Rect
{
public:
    using Rect::Rect; 
    virtual void draw();
    virtual void addElement(Rect *rect);
    virtual void handleEvent(const Event &event);
    virtual std::list<Rect *> getElements();
    ~Window();
private:
    std::list<Rect *> elements;
};

#endif /* ifndef UI_WINDOW_HPP */
