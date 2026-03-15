#ifndef VERTEX_H
#define VERTEX_H

#include <Arduboy2.h>

struct position {
  uint8_t x, y;
};

struct velocity {
  signed char x, y;
};

const position PROGMEM playerBarPositions[4] = {
    {104, 0},
    {107, 15},
    {110, 30},
    {112, 45}
};

const position PROGMEM beerPositions[4] = {
    {104, 0},
    {107, 15},
    {110, 30},
    {112, 45}
};

const position PROGMEM customerPositions[4] = {
    {0, 0},
    {0, 15},
    {0, 30},
    {0, 45}
};

#endif