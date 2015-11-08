#ifndef UI_HPP
#define UI_HPP

#include <string>
#include <map>
#include <list>
#include <stdint.h>
#include "elements.hpp"
#include "rectangle.hpp"
#include "renderer.hpp"
#include "event.hpp"

class Rect;
class SDL_Renderer;

class Ui {
    public:
        void initSDL(SDL_Renderer* renderer);
        void addElement();
        void render();
        Renderer* getRenderer();

        void handleInputEvent(const Event &event);
        
        std::list<Event> getEvents();
        void addEvent(Event e);

        std::map <std::string, Rect *> elements;
        ~Ui();

    private:
        Renderer *renderer;
        std::list<Event> eventList;
        void clearEvents();
};
#endif
