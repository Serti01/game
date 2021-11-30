#include "include/mEntity.hh"

mEntity::mEntity() {}
mEntity::~mEntity() {}

void mEntity::render(sf::RenderTexture &aCanvas) {
    this->dSprite.setPosition({aCanvas.getSize().x / 2.0f - this->dSprite.getLocalBounds().width / 2.0f - this->dPosition.x,
                               aCanvas.getSize().y / 2.0f - this->dSprite.getLocalBounds().height / 2.0f - this->dPosition.y});

    aCanvas.draw(this->dSprite);

    // sf::Vector2f dSpritePos = dSprite.getPosition();
    // sf::Vector2u dPlayerTextureSize = dPlayerTexture.getSize();

    // sf::VertexBuffer vBuf(sf::PrimitiveType::Quads);
    // sf::Vertex vertices[4] = {
    //     sf::Vertex({dSpritePos.x - (dPlayerTextureSize.x / 2), dSpritePos.y - (dPlayerTextureSize.y / 2)}),
    //     sf::Vertex({dSpritePos.x - (dPlayerTextureSize.x / 2), dSpritePos.y + (dPlayerTextureSize.y / 2)}),
    //     sf::Vertex({dSpritePos.x + (dPlayerTextureSize.x / 2), dSpritePos.y + (dPlayerTextureSize.y / 2)}),
    //     sf::Vertex({dSpritePos.x + (dPlayerTextureSize.x / 2), dSpritePos.y - (dPlayerTextureSize.y / 2)})
    // };

    // std::cout << "dSpritePos.x = " << dSpritePos.x << "\n";
    // std::cout << "dSpritePos.y = " << dSpritePos.y << "\n";
    // std::cout << "dPlayerTextureSize.x = " << dPlayerTextureSize.x << "\n";
    // std::cout << "dPlayerTextureSize.y = " << dPlayerTextureSize.y << "\n";


    // vBuf.create(4);
    // vBuf.update(vertices);


    // aCanvas.draw(vBuf);
}
