#ifndef ETSAI_SEEKINGMISSILE_ALLEGRO_MISSILE
#define ETSAI_SEEKINGMISSILE_ALLEGRO_MISSILE

#include "Cpp2DGameEngine/Engine/Actor.h"

namespace etsai {
namespace seekingmissile {
namespace allegro {

using namespace cpp2dgameengine;

class Missile : public engine::Actor {
public:
    Missile(float xPos, float yPos);
    ~Missile();

    void setAcceleration(float xComp, float yComp);    
protected:
    core::Vector2D acceleration;

    virtual bool tick(float delta);
    virtual void draw();
    virtual void touch(Actor* actor);
    virtual core::Vector2D calcAcceleration(float time);
};

}
}
}

#endif
