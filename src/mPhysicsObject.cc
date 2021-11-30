#include "include/mPhysicsObject.hh"

mPhysicsObject::mPhysicsObject() {}

mPhysicsObject::~mPhysicsObject() {}

void mPhysicsObject::update() {
    if (getControlIndex(dControlEnum::left) && getControlIndex(dControlEnum::right))
        ;
    else if (getControlIndex(dControlEnum::left))
        setVelocity({getVelocity().x - .5f,
                     getVelocity().y});
    else if (getControlIndex(dControlEnum::right))
        setVelocity({getVelocity().x + .5f,
                     getVelocity().y});

    if (getControlIndex(dControlEnum::up) && getOnGround()) {
        setVelocity({getVelocity().x,
                     getVelocity().y + 10.0f});
        setOnGround(false);
    }


    // If character is moving, slow down character
    if (dVelocity.x > 0)
        dVelocity.x -= 0.2f;
    else if (dVelocity.x < 0)
        dVelocity.x += 0.2f;

    if (dVelocity.x > -0.2f && dVelocity.x < 0.2f)
        dVelocity.x = 0.0f;

    // Make sure x velocity doesn't go over the max velocity
    if (dVelocity.x > dMaxVelocity.x) dVelocity.x = dMaxVelocity.x;

    if (dOnGround) dVelocity.y = 0;
    else dVelocity.y -= cGravity;

    // make sure y velocity doesn't go over the max velocity
    if (dVelocity.y > dMaxVelocity.y) dVelocity.y = dMaxVelocity.y;

    dPosition.x -= dVelocity.x;
    dPosition.y -= dVelocity.y;
}
