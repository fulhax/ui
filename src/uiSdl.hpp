#ifndef UISDL_HPP
#define UISDL_HPP
#include <SDL2/SDL.h>
#include "renderer.hpp"
#include "elements/rect.hpp"
#include "elements/window.hpp"

class UiSdl : public Renderer
{
public:
    unsigned int seed;
    void drawRect(Rect *rect);
    void drawWindow(Window *window);
    void drawText();
    SDL_Renderer *renderer;
};
#endif
