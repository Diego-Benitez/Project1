#include "player1.h"



Player1::Player1(sf::Texture& texture) {

	if (!player1T.loadFromFile("dibu.png")) {
		cout << "Error al cargar la textura dibu.png" << endl;
	}
	if (!dibuSoundB.loadFromFile("tecomo.ogg")) {
		cout << "Error al cargar la textura dibu.png" << endl;
	}
	
	player1S.setTexture(player1T);
	player1S.setOrigin(player1T.getSize().x / 2, player1T.getSize().y / 2);
	player1S.setPosition(805, 250);
	player1S.setScale(0.2, 0.2);
	dibuSound.setBuffer(dibuSoundB);
}

void Player1::movement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && player1S.getPosition().y > 0)
	{
		//pressed = true;
		player1S.move(0, -10);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && player1S.getPosition().y < 500)
	{
		//pressed = true;
		player1S.move(0, 10);
	}
	
	}

void Player1::play()
{	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) && !flag) {
		flag = true;
		dibuSound.play();
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
		flag = false;
	}
}

sf::FloatRect Player1::getGlobalBounds() const {
	return player1S.getGlobalBounds();
}
bool Player1::contains(float x, float y) const {
	return player1S.getGlobalBounds().contains(x, y);
}

sf::Vector2f Player1::getPosition()
{
	return player1S.getPosition();
}

void Player1::draw(sf::RenderTarget &rt, sf::RenderStates rs) const
{
	rt.draw(player1S, rs);
}
