#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;

class Player1 : public sf::Drawable
{
public:
	Player1 (sf::Texture& texture);
	void movement();
	void play();
	sf::FloatRect getGlobalBounds() const;
	bool contains(float x, float y) const;
	sf::Vector2f getPosition();
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
private:
	bool flag = false;
	float move;

	sf::Texture player1T;
	sf::Sprite player1S;
	sf::SoundBuffer dibuSoundB;
	sf::Sound dibuSound;
};

