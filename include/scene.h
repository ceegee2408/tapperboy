#ifndef SCENE_H
#define SCENE_H

#include <Arduboy2.h>

class Scene {
    public:
        Scene() {}
        virtual void update(byte input) = 0; // Pure virtual function for updating the scene
        virtual void draw() = 0;   // Pure virtual function for drawing the scene
};

#endif // SCENE_H 