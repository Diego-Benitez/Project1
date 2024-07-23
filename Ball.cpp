#include "Ball.h"
#include "player1.h"
#include "player2.h"

Ball::Ball(sf::Texture& texture)
{
	if (!ballT.loadFromFile("ball.png")) {
		cout << "Error al cargar textura ball.png" << endl;
	}
	
	ballS.setTexture(ballT);
	ballS.setOrigin(ballT.getSize().x / 2, ballT.getSize().y / 2);
	ballS.setPosition(425, 250);
	ballS.setScale(0.02, 0.02);
}

void Ball::movement(int velX, int velY)
{
	ballS.move(velX, velY);

}


sf::Vector2f Ball::getPosition()
{
	return ballS.getPosition();
}

void Ball::draw(sf::RenderTarget &rt, sf::RenderStates rs) const
{
	rt.draw(ballS, rs);
}
