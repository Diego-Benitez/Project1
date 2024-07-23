#include "player2.h"
#include "ball.h"


Player2::Player2(sf::Texture& texture)
{
    if (!player2T.loadFromFile("kolo.png")) {
        cout << "Error al cargar textura Kolo" << endl;
    }

    player2S.setTexture(player2T);
    player2S.setOrigin(player2T.getSize().x / 2, player2T.getSize().y / 2);
    player2S.setPosition(30, 250);
    player2S.setScale(0.2, 0.2);
}
void Player2::movement()
{
    //player2 movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && player2S.getPosition().y > 0)
    {
        player2S.move(0, -10);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)&& player2S.getPosition().y < 500)
    {
        player2S.move(0, 10);
    }
}

sf::FloatRect Player2::getGlobalBounds() const
{
    return player2S.getGlobalBounds();
}

bool Player2::contains(float x, float y) const
{
    return player2S.getGlobalBounds().contains(x, y);
}


sf::Vector2f Player2::getPosition()
{
    return player2S.getPosition();
}

void Player2::draw(sf::RenderTarget &rt, sf::RenderStates rs) const
{
    rt.draw(player2S, rs);
}


