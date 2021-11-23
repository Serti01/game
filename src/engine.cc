#include "game.hh"

// == Engine constructor
game::engine::engine() {
    // Create window
    this->gWindow.create(sf::VideoMode::getDesktopMode(), "Game", sf::Style::Fullscreen);
    this->gWindow.setVerticalSyncEnabled(true);

    // Load first stage
    dLoadStage(0);
}

// == Engine Destructor
game::engine::~engine() {}

// == Entry point into engine
void game::engine::eRun() {
    while (this->gWindow.isOpen()) {
        this->gWindowPollEvents();
        eUpdate();
        eRender();
    }
}

// == Update cycle
void game::engine::eUpdate() {

}

// == Render cycle
void game::engine::eRender() {
    gWindow.clear(sf::Color::Black);

    gWindow.display();
}


// == Load stage
void game::engine::dLoadStage(game::stage_t stage) {
    switch (stage) {
        default: {
            std::cerr << "[Err] Tried to load an unknown stage (" << (unsigned long)stage << ")" << std::endl;
            break;
        }
    }
}

