#include "game.hh"

// == Event polling for gWindow
void game::engine::gWindowPollEvents() {
    sf::Event ev;

    if (!this->gWindow.pollEvent(ev)) return;
    
    switch (ev.type) {
        case sf::Event::Closed: {
            gWindow.close();        
            break;
        }

        case sf::Event::KeyPressed: {
            // Quit on shift+esc
            if (ev.key.code == sf::Keyboard::Escape && ev.key.shift)
                gWindow.close();
            
            break;
        }

        default: {
            break;
        }
    }
}