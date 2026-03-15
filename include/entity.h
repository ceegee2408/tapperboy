#ifndef ENTITY_H
#define ENTITY_H

#include "vertex.h"
#include "animation.h"

class Entity {
  public:
    position pos;
    velocity vel;
    Entity() : pos(), vel() {}
    Entity(position p, velocity v) : pos(p), vel(v) {}
};
#endif // ENTITY_H