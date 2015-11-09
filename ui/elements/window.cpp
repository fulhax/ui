#include "window.hpp"
#include <list>


void Window::draw()
{
    Rect::draw();

    for(auto element : this->getElements()) {
        element->draw();
    }
}

void Window::addElement(Rect *rect)
{
    rect->attach(this);
    this->elements.push_back(rect);
}

std::list<Rect *> Window::getElements()
{
    return this->elements;
}

Window::~Window()
{
    for(auto element : this->getElements()) {
        delete element;
    }
}
