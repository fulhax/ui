#include <string>
#include <stdint.h>

class Rect {
    public:
        virtual void draw(); 
        Rect(float x, float y, float z, unsigned int w, unsigned int h);
        void resize(unsigned int w, unsigned int h);
        void move(float x, float y);
    private:
        float x, y, z;
        unsigned int w, h; // uints?
};

class Button : public Rect {
    public:
        Button(float x, float y, float z, unsigned int w, unsigned int h, std::string label);

        void onClick(void (*callback)(int)); 
        void onHover(void (*callback)());

        void draw();

        uint8_t getState();
        void setState(uint8_t state);

    private:
        std::string label; 
        int value;

        /*
         * hmm enum hax istället?
        uint8_t state;
        const uint8_t STATE_HOVER;
        const uint8_t STATE_CLICKED;
        const uint8_t STATE_DISABLED;
        */
};

class Label : public Rect {
    public:
        Label(float x, float y, float z, unsigned int w, unsigned int h, std::string label);

    private:
        std::string label; 
};

class Textbox : public Label {
    public:
        void draw();

    private:
        bool scroll;
        float contentHeight;
        float contentWidth;
        float scrollTop;
        float scrollLeft;
};
