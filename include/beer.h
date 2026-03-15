#ifndef BEER_H
#define BEER_H
#include "entity.h"
#include "animation.h"
#include "assetHandler.h"

class Beer : public Entity {
  public:
  bool ready = false;
    Animation animations[4] = {
        Animation(1, AssetHandler::get(BEER_EMPTY), 0),   // Empty
        Animation(1, AssetHandler::get(BEER_FILLED), 0),  // Filled
        Animation(1, AssetHandler::get(BEER_FILL), 0),    // Filling
        Animation(1, AssetHandler::get(BEER_TUMBLE), 0)   // Tumbling
    };
    Beer() : Entity() {}
    Beer(position pos) : Entity(pos, {0, 0}), ready(false) {}
    
    void update() {
        switch (state) {
            case NONE:
                state = FILLING;
                animState = ANIMFILLING;
                break;
            case EMPTY:
                // Logic for empty beer
                break;
            case FILLING:
                // Logic for filling beer
                break;
            case FILLED:
                // Logic for filled beer
                break;
            case TUMBLING:
                // Logic for tumbling beer
                break;
        }
    }
    
    void draw() {
        position pos = {pos.x, pos.y};
        animations[animState].update(pos);
    }

    private:
    enum BeerState {
        NONE,
        EMPTY,
        FILLING,
        FILLED,
        TUMBLING
    } state = NONE;
    enum AnimState {
        ANIMNONE,
        ANIMEMPTY,
        ANIMFULL,
        ANIMFILLING,
        ANIMTUMBLING
    } animState = ANIMNONE;
};

#endif // BEER_H