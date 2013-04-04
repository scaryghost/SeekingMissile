#ifndef A5HITBOX_H
#define A5HITBOX_H

#include "Cpp2DGameEngine/Engine/HitBox.h"

class A5HitBox : public etsai::cpp2dgameengine::engine::HitBox {
public:
    A5HitBox(float xPos, float yPos);

    virtual void draw();
};

#endif
