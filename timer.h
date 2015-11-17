#ifndef TIMER_H
#define TIMER_H
#include <SDL2/SDL.h>

class Timer
{
public:
    void start();
    Uint32 getTicks();
private:
    Uint32 started;

};

#endif /* ifndef TIMER_H */
