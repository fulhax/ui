#ifndef UI_HPP
#define UI_HPP

#include <string>
#include <map>
#include <stdint.h>
#include "SDL2/SDL.h"
#include "elements.hpp"

struct Rectangle {
    float x;
    float y;
    float z;

    unsigned int h;
    unsigned int w;
};

class Renderer {
    public:
        virtual void drawRect(Rectangle rect);
        virtual void drawText();
};

class UiSdl : public Renderer {
    public:
        void drawRect(Rectangle rect); 
        void drawText(); 
        SDL_Renderer* renderer;
};

class Rect;
class Ui {
    public:
        void initSDL(SDL_Renderer* renderer);
        void addElement();
        void render();
        Renderer* getRenderer();
        std::map <std::string, Rect *> elements;
        ~Ui();

    private:
        Renderer *renderer;
};
#endif
