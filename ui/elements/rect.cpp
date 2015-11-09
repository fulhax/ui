#include "rect.hpp"

Rect::Rect(
    int id,
    float x,
    float y,
    float z,
    unsigned int w,
    unsigned int h,
    bool movable,
    bool resizable,
    Ui *ui
)
{
    this->id = id;

    this->x = x;
    this->y = y;
    this->z = z; // z-index

    this->w = w;
    this->h = h;

    this->resizable = resizable;
    this->movable = movable;

    this->ui = ui;
    this->renderer = ui->getRenderer();
    this->detach();
}

float Rect::getX()
{
    if(this->parent != nullptr) {
        return this->parent->x + this->x;
    } else {
        return this->x;
    }
}

float Rect::getY()
{
    if(this->parent != nullptr) {
        return this->parent->y + this->y;
    } else {
        return this->y;
    }
}

unsigned int Rect::getW()
{
    return this->w;
}

unsigned int Rect::getH()
{
    return this->h;
}

void Rect::attach(Rect *parent)
{
    this->parent = parent;
}

void Rect::detach()
{
    this->parent = nullptr;
}

void Rect::handleEvent(const Event &e)
{
    switch(e.type) {
        case EventType::MouseMotion: {
            EventMouseMotion *mm = (EventMouseMotion *) &e;

            if(this->inBounds(mm->x, mm->y)) {
                this->ui->addEvent(OEvent(this->id, EventType::Hover));

                if(mm->state == MouseButtonState::BUTTON_DOWN) {
                    switch(mm->button) {
                        case MouseButton::BUTTON_LEFT:
                            if(this->movable == false) {
                                break;
                            }

                            this->move(this->x += mm->rx, this->y += mm->ry);
                            this->ui->addEvent(
                                OEvent(this->id, EventType::Drag)
                            );
                            break;

                        case MouseButton::BUTTON_RIGHT:
                            if(this->resizable == false) {
                                break;
                            }

                            this->resize(this->w += mm->rx, this->h += mm->ry);
                            this->ui->addEvent(
                                OEvent(this->id, EventType::Resize)
                            );
                            break;


                        default:
                            break;
                    }
                }
            }
        }
        break;

        default:
            break;
            /*
                case EventType::MouseWheel: {
                EventMouseWheel *mm = (EventMouseWheel *) &e;
                printf("Mouse wheel, x:%f y:%f\n", mm->x, mm->y);
                }
                break;
                    case EventType::MouseButton: {
                    EventMouseButton *me = (EventMouseButton *) &e;

                    if(this->inBounds(me->x, me->y)) {
                    printf("Click\n");
                    this->ui->addEvent(OEvent(this->id, EventType::Click));
                    }
                    }
                    break;
                    case EventType::TextInput: {
                    EventTextInput *te = (EventTextInput *) &e;
                    printf("%s\n", te->key);
                    }
                    break;
            */
    }
}

bool Rect::inBounds(float x, float y)
{
    return (
               (x > this->getX() && x < this->getX() + (float)this->getW()) &&
               (y > this->getY() && y < this->getY() + (float)this->getH())
           );
};

void Rect::resize(unsigned int w, unsigned int h)
{
    this->w = w;
    this->h = h;
}

void Rect::move(float x, float y)
{
    this->x = x;
    this->y = y;
}

void Rect::draw()
{
    this->renderer->drawRect(this);
}

/*
    Button::Button(float x, float y, float z, unsigned int w, unsigned int h,
    std::string label)
    : Rect(x, y, z, w, h){
    this->label = label;
    }

    // Triggers callback and passes value as first argument;
    void Button::onClick(void (*callback)(int)){
    callback(this->value);
    }

    void Button::onHover(void (*callback)()){
    callback();
    }

    void Button::draw(){

    }


    Label::Label(float x, float y, float z, unsigned int w, unsigned int h,
    std::string label)
    : Rect(x, y, z, w, h){
    this->label = label;
    }
*/
