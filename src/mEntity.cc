#include "include/mEntity.hh"

mEntity::mEntity() {}
mEntity::~mEntity() {}

mEntity::mEntity(sf::FloatRect aBounds) {
    this->dBounds = aBounds;
}

void mEntity::render(sf::RenderTexture &aCanvas) {
    this->dSprite.setPosition({aCanvas.getSize().x / 2.0f - this->dSprite.getLocalBounds().width / 2.0f - this->dPosition.x,
                               aCanvas.getSize().y / 2.0f - this->dSprite.getLocalBounds().height / 2.0f - this->dPosition.y});

    aCanvas.draw(this->dSprite);
}

void mEntity::loadSpriteFromFile(const std::string &path, const sf::IntRect &area){
    dPlayerTexture.loadFromFile(path, area);
    dSprite.setTexture(dPlayerTexture);
    dBounds = dSprite.getLocalBounds();
}

