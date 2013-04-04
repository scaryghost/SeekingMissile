#include "Allegro/A5HitBox.h"
#include "allegro5/allegro_primitives.h"

A5HitBox::A5HitBox(float xPos, float yPos) : HitBox(xPos, yPos)  {
}

void A5HitBox::draw() {
    auto prev= boundaryOffsets.end() - 1;
    for(auto it= boundaryOffsets.begin(); it != boundaryOffsets.end(); it++) {
        al_draw_line(objPos.vx + prev->first, objPos.vy + prev->second, objPos.vx + it->first, objPos.vy + it->second, al_map_rgb(0, 255, 0), 2.0);
        prev= it;
    }
    al_draw_circle(objPos.vx, objPos.vy, getRadius(), al_map_rgb(0, 0, 255), 2.0);
}
