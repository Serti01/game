#ifndef __MENTITYHH__
#define __MENTITYHH__

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

class mEntity : public mPhysicsObject {
    // == Sprite and Texture data
    public:
        sf::Texture dPlayerTexture;
        sf::Sprite dSprite;

    // == Public interface
    public:
        void render(sf::RenderTexture &aCanvas);

    // == Con/Destructor
    public:
        mEntity();
        ~mEntity();
};

#endif