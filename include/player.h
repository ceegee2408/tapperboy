#ifndef PLAYER_H
#define PLAYER_H
#include "entity.h"
#include "animation.h"
#include "bitmaps.h"
#include "assetHandler.h"

class Player : public Entity
{
public:
    uint8_t positionIndex;
    bool filling = false;
    Animation animations[4] = {
        Animation(AssetHandler::get(PLAYER_STANDING), uint8_t(0)), // None
        Animation(AssetHandler::get(PLAYER_STANDING), uint8_t(0)), // Idle
        Animation(AssetHandler::get(PLAYER_FILLING), uint8_t(0)),  // Filling
        Animation()   // Running
    };
    Player() : Entity(), positionIndex(0) {}

    void update(byte input)
    {
        // Update player logic here
        if (arduboy.justPressed(UP_BUTTON))
        {
            positionIndex = (positionIndex - 1 + 4) % 4;
            //filling = false;
        }
        else if (arduboy.justPressed(DOWN_BUTTON))
        {
            positionIndex = (positionIndex + 1) % 4;
            //filling = false;
        }
        else if (input & A_BUTTON)
        {
            state = FILLING;
            animState = ANIMFILLING;
            //filling = true;
        }
        else
        {
            state = STANDING;
            animState = NONE;
            //filling = false;
        }
    }

    void draw()
    {
        // Draw player based on current state (standing or filling)
        position pos = {
            pgm_read_byte(&playerBarPositions[positionIndex].x),
            pgm_read_byte(&playerBarPositions[positionIndex].y)};
        animations[animState].update(pos);
    }

private:
    enum PlayerState
    {
        STANDING,
        FILLING,
        RUNNING
    } state = STANDING;
    enum AnimState
    {
        NONE,
        IDLE,
        ANIMFILLING,
        ANIMRUNNING
    } animState = NONE;
};

#endif // PLAYER_H
