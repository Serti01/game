#include "include/mPlayer.hh"

mPlayer::mPlayer() {
    loadSprite();
};

mPlayer::~mPlayer() {

};

void mPlayer::loadSprite() {
    this->dTexture.loadFromFile("./res/img/player.png");
    this->dSprite.setTexture(dTexture);
    
    this->dTexture.setSmooth(true);
    
    this->dSprite.setRotation(180);
    this->dSprite.setOrigin(this->dTexture.getSize().x, this->dTexture.getSize().y);
}

void mPlayer::updatePosition() {
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    sf::Vector2u size = {desktopMode.width, desktopMode.height}; 
    this->dSprite.setPosition({size.x / 2.0f - this->dSprite.getLocalBounds().width / 2.0f - this->dPosition.x,
                               size.y / 2.0f - this->dSprite.getLocalBounds().height / 2.0f - this->dPosition.y});
}

void mPlayer::render(sf::RenderTexture &aCanvas) {

    aCanvas.draw(this->dSprite);


    sf::VertexBuffer vBuf(sf::PrimitiveType::Points);

    sf::Vector2f pos = dSprite.getPosition();
    sf::Vector2u size = dTexture.getSize();

    sf::Vertex vertex[4] = {
        sf::Vertex({pos.x           , pos.y         }),
        sf::Vertex({pos.x           , pos.y + size.y}),
        sf::Vertex({pos.x + size.x  , pos.y         }),
        sf::Vertex({pos.x + size.x  , pos.y + size.y})
    };

    vBuf.create(4);
    vBuf.update(vertex);
    aCanvas.draw(vBuf);
}