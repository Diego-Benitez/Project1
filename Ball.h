#include <iostream>
#include<SFML/Graphics.hpp>

using namespace std;

class Ball : public sf::Drawable
{
public:
	Ball(sf::Texture& texture);
	void movement(int, int);
	sf::Vector2f getPosition();
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
private:
	
	sf::Texture ballT;
	sf::Sprite ballS;
};

