#include "window.hpp"
#include "../renderer.hpp"


void Window::draw()
{

    this->renderer->drawWindow(this);
    /*  for(auto element : this->getElements()) {
        element->draw();
        }
    */
}

void Window::handleEvent(const Event &event)
{
    Rect::handleEvent(event);

    for(auto element : this->getElements()) {
        element->handleEvent(event);
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
