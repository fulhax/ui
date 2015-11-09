#include "window.hpp"
#include <list>

void Window::draw()
{
    Rect::draw();
    /*
    for(auto element : this->getElements()) {
        element.second->draw();
    }
    */
}

void Window::addElement(Rect *rect)
{
    //this->elements.push_back(rect);
}

std::list<Rect> Window::getElements()
{
    return this->elements;
}
