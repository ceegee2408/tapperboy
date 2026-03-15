#include <Arduboy2.h>
#include "header.h"
#include "bitmaps.h"
#include "playScene.h"

Arduboy2 arduboy;
PlayScene playScene;

enum GameState {
  START_SCREEN,
  PLAYING,
  GAME_OVER
};
GameState gameState;


void setup() {
  arduboy.boot();
  arduboy.flashlight();
  arduboy.setFrameRate(60);
  gameState = PLAYING;
}

void loop() {
  if(!arduboy.nextFrame()) return;
  arduboy.clear();
  arduboy.pollButtons();
  byte input = arduboy.buttonsState();
  switch (gameState) {
    case START_SCREEN:
      //startScreenScene.update(input);
      //startScreenScene.draw();
      break;
    case PLAYING:
      playScene.update(input);
      playScene.draw();
      break;
    case GAME_OVER:
      //gameOverScene.update(input);
      //gameOverScene.draw();
      break;
  }
  arduboy.display();
}

