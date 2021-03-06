#ifndef UI_HPP
#define UI_HPP

#include <string>
#include <map>
#include <list>
#include <stdint.h>
#include "elements/rect.hpp"
#include "rectangle.hpp"
#include "renderer.hpp"
#include "event.hpp"

class SDL_Renderer;
class Ui
{
public:
    Ui();
    void initSDL(SDL_Renderer *renderer);
    void addElement();
    void render();
    Renderer *getRenderer();

    void handleInputEvent(const Event &event);

    std::list<OEvent> getEvents();
    void addEvent(OEvent e);

    std::list <Rect *> elements;
    ~Ui();

private:
    Renderer *renderer;
    std::list<OEvent> eventList;
    void clearEvents();
};
#endif
