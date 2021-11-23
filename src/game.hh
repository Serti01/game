#ifndef __GAMEHH__
#define __GAMEHH__

// == SFML Includes
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

// == Standard C++ includes
#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <cstddef>
#include <thread>
#include <chrono>

// == Main namespace
namespace game {
    // == Typedefs
    typedef uint8_t stage_t;
    
    class engine {

        // == Window handling
        private:
            sf::RenderWindow gWindow;
            void gWindowPollEvents();

        public:
            engine();
            ~engine();

        // == Engine
        public:
            void eRun();
            void eUpdate();
            void eRender();

        protected:
            void dLoadStage(stage_t stage);


    };
}

#endif