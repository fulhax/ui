#ifndef UISDL_HPP
#define UISDL_HPP
#include "SDL2/SDL.h"
#include "renderer.hpp"
#include "rectangle.hpp"
#include "ui.hpp"

class Ui;
class UiSdl : public Renderer {
    public:
        void drawRect(Rectangle rect); 
        void drawText(); 
        SDL_Renderer* renderer;
};
#endif
