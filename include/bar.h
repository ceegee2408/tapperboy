#ifndef BAR_H
#define BAR_H
#include <Arduboy2.h>
#include "customer.h"
#include "beer.h"

class Bar {
  public:
    Customer customers[10];
    byte numCustomers = 0;
    Beer beers[10];
    byte numBeers = 0;
    bool filling = false;
    Bar() {};
    void update(byte input) {
        for (int i = 0; i < numCustomers; i++) {
            customers[i].update(input);
        }
        for (int i = 0; i < numBeers; i++) {
            //beers[i].update();
        }
    }

    void beginFill() {
        filling = true;
        // Logic to start filling the beer
    }

    void stopFill() {
        filling = false;
        // Logic to stop filling the beer
    }

    void removeBeer(int index) {
        beers[index] = beers[numBeers - 1];
        numBeers--;
    }

    void draw() {
        for (int i = 0; i < numCustomers; i++) {
            //customers[i].draw();
        }
        for (int i = 0; i < numBeers; i++) {
            //beers[i].draw();
        }
    }
};

#endif // BAR_H