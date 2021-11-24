#include "include/mEngine.hh"

// == Engine constructor
mEngine::mEngine() {
    // Create window
    this->gWindow.create(sf::VideoMode::getDesktopMode(), "Game", sf::Style::Fullscreen);
    this->gWindow.setVerticalSyncEnabled(true);

    // Create player
    this->dPlayer.loadSpriteFromFile("res/img/player.png", {});
    this->dPlayer = mEntity();
    this->dPlayer.setMaxVelocity({10.0f, 10.0f});

    // Load first stage
    this->dLoadStage(0);
}

// == Engine Destructor
mEngine::~mEngine() {}

// == Entry point into engine
void mEngine::eRun() {
    while (this->gWindow.isOpen()) {
        this->gWindowPollEvents();
        eUpdate();
        eRender();
    }
}

// == Update cycle
void mEngine::eUpdate() {
    this->dPlayer.update();
}

// == Render cycle
void mEngine::eRender() {
    gWindow.clear(sf::Color::Black);

    sf::RenderTexture rTexture;
    sf::Sprite rSprite;

    rTexture.create(gWindow.getSize().x, gWindow.getSize().y);
    
    dPlayer.render(rTexture);
    rSprite.setTexture(rTexture.getTexture());
    
    gWindow.draw(rSprite);

    gWindow.display();
}

// == Load stage
void mEngine::dLoadStage(stage_t stage) {
    switch (stage) {
        default: {
            std::cerr << "[Err] Tried to load an unknown stage (" << (unsigned long)stage << ")" << std::endl;
            break;
        }

        case 1: {
            
            break;
        }
    }
}

// == Event polling for gWindow
void mEngine::gWindowPollEvents() {
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

            switch (ev.key.code) {
                case sf::Keyboard::Left: {
                    dPlayer.setControlIndex(true, dControlEnum::left);
                    break;
                }

                case sf::Keyboard::Right: {
                    dPlayer.setControlIndex(true, dControlEnum::right);
                    break;
                }

                case sf::Keyboard::Up: {
                    dPlayer.setControlIndex(true, dControlEnum::up);
                    break;
                }

                default: {break;}
            }
            
            break;
        }

        case sf::Event::KeyReleased: {
            switch (ev.key.code) {
                case sf::Keyboard::Left: {
                    dPlayer.setControlIndex(false, dControlEnum::left);
                    break;
                }

                case sf::Keyboard::Right: {
                    dPlayer.setControlIndex(false, dControlEnum::right);
                    break;
                }

                case sf::Keyboard::Up: {
                    dPlayer.setControlIndex(false, dControlEnum::up);
                    break;
                }

                default: {break;}
            }

            break;
        }

        default: {
            break;
        }
    }
}