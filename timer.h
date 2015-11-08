#include <SDL2/SDL.h>
class Timer {

    public:
        void start();
        Uint32 getTicks();
    private:
        Uint32 started;

};
