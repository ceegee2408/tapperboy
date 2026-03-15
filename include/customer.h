#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "entity.h"

class Customer : public Entity {
  public:
    Customer() : Entity() {}
    void update(byte input) {
        // Update customer logic here
    }
    
    void draw() {
        // Draw customer based on current state
    }
    private:
    enum CustomerState {
        WAITING,
        SERVED,
        LEAVING
    } state = WAITING;
    enum AnimState {
        NONE,
        DRINKING,
        ANIMLEAVING
    } animState = NONE;
};

#endif // CUSTOMER_H