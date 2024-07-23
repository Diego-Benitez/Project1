#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;


class Player2 : public sf::Drawable
{
public:
	Player2(sf::Texture& texture);
	void movement();
	sf::FloatRect getGlobalBounds() const;
	bool contains(float x, float y) const;
	sf::Vector2f getPosition();
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
private:
	sf::Texture player2T;
	sf::Sprite player2S;
};

