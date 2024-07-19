#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;


int main()
{
 
    sf::Texture ballT;
    sf::Texture player1T;
    sf::Texture player2T;
    sf::Texture backgroundT;

     
    sf::Sprite ballS;
    sf::Sprite player1S;
    sf::Sprite player2S;
    sf::Sprite backgroundS;
    

    sf::SoundBuffer dibuSoundB;
    sf::Sound dibuSound;

    bool flag = false;
    float velX = 5;
    float velY = 5;


    if (!backgroundT.loadFromFile("campo.png")) {
        cout << "Error al cargar textura campo" << endl;
    }
    if (!ballT.loadFromFile("ball.png")) {
        cout << "Error al cargar textura ball" << endl;
    }

    if (!player1T.loadFromFile("dibu.png")) {
        cout << "Error al cargar textura Dibu" << endl;
    }
    if (!player2T.loadFromFile("kolo.png")) {
        cout << "Error al cargar textura Kolo" << endl;
    }
    if (!dibuSoundB.loadFromFile("tecomo.ogg")) {
        cout << "Error al cargar el sonido tecomo.ogg" <<endl;
    }

    //background texture
    backgroundS.setTexture(backgroundT);
    backgroundS.setOrigin(backgroundT.getSize().x / 2, backgroundT.getSize().y / 2);
    backgroundS.setPosition(425, 250);
    backgroundS.setScale(5, 5);
    backgroundS.setScale(1, 1);

    //ball texture
    ballS.setTexture(ballT);
    ballS.setOrigin(ballT.getSize().x/2, ballT.getSize().y/2);
    ballS.setPosition(425, 250);
    ballS.setScale(0.02, 0.02);

    //dibu texture & sound
    player1S.setTexture(player1T);
    player1S.setOrigin(player1T.getSize().x / 2, player1T.getSize().y / 2);
    player1S.setPosition(805, 250);
    player1S.setScale(0.2, 0.2);
    dibuSound.setBuffer(dibuSoundB);

    //kolo texture
    player2S.setTexture(player2T);
    player2S.setOrigin(player2T.getSize().x / 2, player2T.getSize().y / 2);
    player2S.setPosition(30, 250);
    player2S.setScale(0.2, 0.2);

    

    sf::RenderWindow window(sf::VideoMode(850, 500), "Kolo Muani vs Dibu!");
    window.setFramerateLimit(60);
    
    
 
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

        //player1 movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            player1S.move(0, -10);
            
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            player1S.move(0, 10);
        }
        //player2 movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            player2S.move(0, -10);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            player2S.move(0, 10);
        }

        //sound player1
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)&& !flag) {
            flag = true;
            dibuSound.play();
            
        }
        else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
            flag = false;
        }
       
        window.clear();
        window.draw(backgroundS);
        window.draw(ballS);
        window.draw(player1S);
        window.draw(player2S);
        window.display();
    }

    return 0;
}