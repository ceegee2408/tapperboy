#ifndef BEER_H
#define BEER_H
#include "entity.h"
#include "animation.h"
#include "assetHandler.h"

class Beer : public Entity {
  public:
  bool ready = false;
    Animation animation = {};
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
        animation.update(pos);
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
    
    void setState(BeerState newState) {
        state = newState;
        switch (state) {
            case NONE:
                animation = Animation(AssetHandler::get(BEER_EMPTY));
                break;
            case EMPTY:
                animation = Animation(AssetHandler::get(BEER_EMPTY));
                break;
            case FILLING:
                animation = Animation(AssetHandler::get(BEER_FILL));
                break;
            case FILLED:
                animation = Animation(AssetHandler::get(BEER_FILLED));
                break;
            case TUMBLING:
                animation = Animation(AssetHandler::get(BEER_TUMBLE));
                break;
        }
    }
};

#endif // BEER_H