#include "game.hh"
#include <cstdio>

// State
game::state::state() {

}
game::state::~state() {

}

// Window
game::graphics::graphics() {
    this->Window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(),"Game",sf::Style::Fullscreen);
    this->Window->setVerticalSyncEnabled(true);
    font.loadFromFile("res/fonts/VT323-Regular.ttf");
    this->displayText.setCharacterSize(28);
    this->displayText.setFont(this->font);
    this->displayText.setFillColor(sf::Color::White);
}
game::graphics::~graphics() {
    delete this->Window;
}
void game::graphics::update() {
    this->Window->clear(sf::Color::Black);
}
void game::graphics::render() {
    this->Window->draw(this->displayText);
    this->Window->display();
}

// Engine
game::engine::engine() {
    this->state = new game::state;
    this->graphics = new game::graphics;
    this->env_user = getlogin();
    gethostname(this->env_host, HOST_NAME_MAX);
}
game::engine::~engine() {
    delete this->state;
    delete this->graphics;
}
void game::engine::pollEvents() {
    this->graphics->Window->pollEvent(this->ev);
    
    switch (this->ev.type) {
        case sf::Event::Closed: {
            this->graphics->Window->close();
            break;
        }
        case sf::Event::KeyPressed: {
            if (this->ev.key.code == sf::Keyboard::Q)
                this->graphics->Window->close();
            break;
        }
        default: {
            break;
        }
    }
}
void game::engine::updateState() {
    // Mouse pos
    this->state->mouse = sf::Mouse::getPosition(*this->graphics->Window);
}
void game::engine::update() {
    this->updateState();
    this->graphics->update();
}
void game::engine::render() {
    this->graphics->render();
}