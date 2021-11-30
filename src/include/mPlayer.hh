#ifndef __MPLAYERHH__
#define __MPLAYERHH__

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

// == Local includes
#include "mPhysicsObject.hh"
#include "mEntity.hh"

class mPlayer : public mPhysicsObject {
    // == Sprite and Texture data
    public:
        sf::Texture dTexture;
        sf::Sprite dSprite;

    // == Public interface
    public:
        void loadSprite();
        void updatePosition();
        void render(sf::RenderTexture &aCanvas);

    // == Con/Destructor
    public:
        mPlayer();
        ~mPlayer();
};

#endif