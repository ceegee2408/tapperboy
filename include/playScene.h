#ifndef PLAYSCENE_H 
#define PLAYSCENE_H 

#include "scene.h"
#include "Player.h"
#include "Bar.h"
#include "assetHandler.h"

class PlayScene : public Scene {
public:
    Player player;
    Bar bars[4];
    Animation backgroundAnim = Animation(uint8_t(1), AssetHandler::get(BAR_BACKGROUND), uint8_t(0));
  PlayScene() {};
  void update(byte input) {
    Bar &currentBar = bars[player.positionIndex];
    player.update(input);
    if(player.filling && arduboy.justPressed(A_BUTTON)) {
        currentBar.beginFill();
    } else if (arduboy.justReleased(A_BUTTON)) {
        currentBar.stopFill();
    }
    for (int i = 0; i < 4; i++) {
      bars[i].update(input);
    }
  };
  void draw() {
    backgroundAnim.draw({0, 0});
    player.draw();
    for (int i = 0; i < 4; i++) {
      //bars[i].draw();
    }
    //for (int i = 0; i < 4; i++) {
    //  bars[i].draw();
    //}

  };

private:
  // Private members and methods
};

#endif // PLAYSCENE_H 