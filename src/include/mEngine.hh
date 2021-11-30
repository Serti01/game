#ifndef __ENGINEHH__
#define __ENGINEHH__

// == SFML Includes
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
#include "mPlayer.hh"

// == Typedefs
typedef uint8_t stage_t;

class mEngine {

    // == Window handling
    private:
        sf::RenderWindow gWindow;
        void gWindowPollEvents();

    // == Con/Destructor
    public:
        mEngine();
        ~mEngine();

    // == Engine
    public:
        void eRun();
        void eUpdate();
        void eRender();

    protected:
        mPlayer dPlayer;
        void dLoadStage(stage_t stage);
};


#endif