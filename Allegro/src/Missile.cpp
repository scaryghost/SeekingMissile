#include "Allegro/Missile.h"

#include "allegro5/allegro.h"
#include "allegro5/allegro_primitives.h"

namespace etsai {
namespace seekingmissile {
namespace allegro {

Missile::Missile(float xPos, float yPos) : Actor(xPos, yPos) {
}

Missile::~Missile() {
}

void Missile::setAcceleration(float xComp, float yComp) {
    acceleration= core::Vector2D(xComp, yComp);
}

bool Missile::tick(float delta) {
    ALLEGRO_MOUSE_STATE state;

    al_get_mouse_state(&state);
    core::Vector2D direction= (core::Vector2D(state.x, state.y) - objPos).normalize();
    acceleration= direction * 100;
    return Actor::tick(delta);
}

void Missile::draw() {
    al_draw_filled_rectangle(objPos.vx - 10, objPos.vy - 10, objPos.vx + 10, objPos.vy + 10, al_map_rgb(255, 0, 0));
}

void Missile::touch(Actor* actor) {
}

core::Vector2D Missile::calcAcceleration(float time) {
    return acceleration;
}

}
}
}
