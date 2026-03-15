#ifndef ANIMATION_H
#define ANIMATION_H

#include <Arduboy2.h>
#include "vertex.h"
#include "assetHandler.h"
extern Arduboy2 arduboy;

class Animation {
  public:
    uint8_t numFrames;
    const Asset* asset;
    uint8_t framesRest;
    Animation() : numFrames(0), asset(nullptr), framesRest(0), currentFrame(0), rest(0) {};
    Animation(uint8_t numFrames, const Asset* asset, uint8_t framesRest) : numFrames(numFrames), asset(asset), framesRest(framesRest), currentFrame(0), rest(0) {};
    void update(position pos) {
        if (rest > 0) {
            rest--;
        } else if (rest == 0) {
            draw(pos);
            currentFrame = (currentFrame + 1) % numFrames;
            rest = framesRest;
        }
    };
    void draw(position pos) {
        drawFrame(pos, currentFrame);
        
    }; 

  private:
    void drawFrame(position p, uint8_t frame) {
        uint8_t frameWidth = asset->width();
        uint8_t frameHeight = asset->height();
        const uint8_t* frameData = asset->data();
        arduboy.drawBitmap(p.x, p.y, frameData + frame * frameWidth * frameHeight / 8, frameWidth, frameHeight, WHITE);
    }
    uint8_t currentFrame;
    uint8_t rest;
};

#endif // ANIMATION_H