#include "Allegro/A5HitBox.h"
#include "Allegro/Missile.h"

#include "allegro5/allegro.h"
#include "allegro5/allegro_primitives.h"

namespace etsai {
namespace seekingmissile {
namespace allegro {

Missile::Missile(float xPos, float yPos) : Actor(xPos, yPos), halfW(10), halfH(10) {
    hitbox= new A5HitBox(xPos, yPos);
    hitbox->addBoundaryPoint(-halfW, -halfH);
    hitbox->addBoundaryPoint(-halfW, halfH);
    hitbox->addBoundaryPoint(halfW, halfH);
    hitbox->addBoundaryPoint(halfW, -halfH);

}

Missile::~Missile() {
    delete hitbox;
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
    al_draw_filled_rectangle(objPos.vx - halfW, objPos.vy - halfH, objPos.vx + halfW, objPos.vy + halfH, al_map_rgb(255, 0, 0));
}

void Missile::touch(Actor* actor) {
}

core::Vector2D Missile::calcAcceleration(float time) {
    return acceleration;
}

}
}
}
