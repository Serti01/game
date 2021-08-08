#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <thread>
#include <sstream>
#include <chrono>
#include <unistd.h>
#include <cstdlib>
#include <climits>

namespace game {
    class state {
        public:
        sf::Vector2i mouse;
        state();
        ~state();
    };
    class graphics {
        public:
        sf::Font font;
        sf::RenderWindow *Window;
        sf::Text displayText;
        void update();
        void render();
        graphics();
        ~graphics();
    };
    class engine {
        private:
        char *env_user;
        char env_host[HOST_NAME_MAX];
        public:
        sf::Event ev;
        game::state *state;
        game::graphics *graphics;
        void pollEvents();
        void updateState();
        void update();
        void render();
        engine();
        ~engine();
    };
}