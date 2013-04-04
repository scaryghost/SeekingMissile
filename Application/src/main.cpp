#include "allegro5/allegro.h"
#include "allegro5/allegro_primitives.h"

#include "Allegro/Missile.h"

#include <iostream>

const double refreshHz= 1.0/30.0;

using etsai::cpp2dgameengine::core::Object;
using std::cerr;
using std::endl;

int main(int argc, char **argv) {
    if(!al_init()) {
        cerr << "failed to initialize allegro!" << endl;
        return -1;
    }
    if(!al_install_keyboard()) {
        cerr << "failed to initialize the keyboard!" << endl;
        return -1;
    }
    if(!al_install_mouse()) {
        cerr << "failed to initialize the mouse!" << endl;
        return -1;
    }
    if (!al_init_primitives_addon()) {
        cerr << "failed to initialize the drawing primitives" << endl;
        return -1;
    }

    ALLEGRO_DISPLAY *display= al_create_display(1680, 1050);
    ALLEGRO_EVENT_QUEUE *event_queue= al_create_event_queue();
    ALLEGRO_TIMER *timer= al_create_timer(refreshHz);
    ALLEGRO_EVENT ev;

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());
    al_start_timer(timer);

    new etsai::seekingmissile::allegro::Missile(840, 525);
    do {
        al_wait_for_event(event_queue, &ev);

        switch(ev.type) {
            case ALLEGRO_EVENT_TIMER:
                Object::tickObjects(refreshHz);
                break;
            case ALLEGRO_EVENT_KEY_DOWN:
                if (ev.keyboard.keycode == ALLEGRO_KEY_W) {
                } else if (ev.keyboard.keycode == ALLEGRO_KEY_A) {
                } else if (ev.keyboard.keycode == ALLEGRO_KEY_S) {
                } else if (ev.keyboard.keycode == ALLEGRO_KEY_D) {
                }
                break;
            case ALLEGRO_EVENT_KEY_UP:
                break;
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                if ((ev.mouse.button & 0x1) == 0x1) {
                    
                }
                break;
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
                if ((ev.mouse.button & 0x1) == 0x1) {
                }
                break;
        }
        al_clear_to_color(al_map_rgb(0,0,0));
        Object::drawObjects();
        al_flip_display();
    } while(ev.type != ALLEGRO_EVENT_DISPLAY_CLOSE);

    al_destroy_display(display);
    return 0;
}
