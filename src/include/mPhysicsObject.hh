#ifndef __MPHYSICSOBJECT__
#define __MPHYSICSOBJECT__

// == SFML includes
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

// == Includes
#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <cstddef>

#define cGravity 0.2f

enum dControlEnum {left,right,up,down};

class mPhysicsObject {
    // == Common data
    protected:
        sf::FloatRect   dBounds;
        sf::Vector2f    dPosition;
        sf::Vector2f    dVelocity;
        sf::Vector2f    dMaxVelocity;
        bool            dOnGround = true;
                                    //  left   right  up     down
        bool            dControls[4] = {false, false, false, false};

    // == Common functions
    public:
        void update();

        // == Setters
        void setBounds(sf::FloatRect aBounds)           { this->dBounds = aBounds; }
        void setPosition(sf::Vector2f aPosition)        { this->dPosition = aPosition; }
        void setVelocity(sf::Vector2f aVelocity)        { this->dVelocity = aVelocity; }
        void setMaxVelocity(sf::Vector2f aMaxVelocity)  { this->dMaxVelocity = aMaxVelocity; }
        void setOnGround(bool aOnGround)                { this->dOnGround = aOnGround; }
        void setControlIndex(bool aControlValue, size_t aControlIndex) { this->dControls[aControlIndex] = aControlValue; }

        // == Getters
        sf::FloatRect getBounds()           { return dBounds; }
        sf::Vector2f getPosition()          { return dPosition; }
        sf::Vector2f getVelocity()          { return dVelocity; }
        sf::Vector2f getMaxVelocity()       { return dMaxVelocity; }
        bool getOnGround()                  { return dOnGround; }
        bool getControlIndex(size_t aIndex) { return dControls[aIndex]; }

    // == Con/Destructors
    public:
        mPhysicsObject();
        explicit mPhysicsObject(sf::FloatRect aBounds);
        ~mPhysicsObject();
};


#endif