#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;


int main()
{
    sf::Texture ballT;
    sf::Texture player1T;
    sf::Texture player2T;

     
    sf::Sprite ballS;
    sf::Sprite player1S;
    sf::Sprite player2S;
    


    float velX = 2;
    float velY = 2;

    if (!ballT.loadFromFile("ball.png")) {
        cout << "Error al cargar textura ball" << endl;
    }

    if (!player1T.loadFromFile("dibu.png")) {
        cout << "Error al cargar textura Dibu" << endl;
    }
    if (!player2T.loadFromFile("kolo.png")) {
        cout << "Error al cargar textura Kolo" << endl;
    }

    //ball texture
    ballS.setTexture(ballT);
    ballS.setOrigin(ballT.getSize().x/2, ballT.getSize().y/2);
    ballS.setPosition(425, 250);
    ballS.setScale(0.02, 0.02);

    //dibu texture
    player1S.setTexture(player1T);
    player1S.setOrigin(player1T.getSize().x / 2, player1T.getSize().y / 2);
    player1S.setPosition(805, 250);
    player1S.setScale(0.2, 0.2);

    //kolo texture
    player2S.setTexture(player2T);
    player2S.setOrigin(player2T.getSize().x / 2, player2T.getSize().y / 2);
    player2S.setPosition(30, 250);
    player2S.setScale(0.2, 0.2);

    sf::RenderWindow window(sf::VideoMode(850, 500), "Kolo Muani vs Dibu!");
    window.setFramerateLimit(120);
    
    
 
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //ball movement
        ballS.move(velX, velY);

        if (ballS.getPosition().x > 850 || ballS.getPosition().x < 0) {
            velX *= -1;
        }
        if (ballS.getPosition().y > 500 || ballS.getPosition().y < 0) {
            velY *= -1;
        }
       
        window.clear();
        window.draw(ballS);
        window.draw(player1S);
        window.draw(player2S);
        window.display();
    }

    return 0;
}