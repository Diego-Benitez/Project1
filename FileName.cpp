#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;

#include "player1.h"
#include "player2.h"
#include "Ball.h"

int main()
{
   
    sf::Texture ballT;
    sf::Texture player1T;
    sf::Texture player2T;
    sf::Texture backgroundT;

    sf::SoundBuffer golB;

    sf::Sound golSound;

    sf::Sprite backgroundS;

    sf::Font fuente;
    sf::Text pts1;
    sf::Text pts2;

    float velX = 5 ;
    float velY = 5;
    int contP1 = 0;
    int contP2 = 0;

    if (!backgroundT.loadFromFile("campo.png")) {
        cout << "Error al cargar textura campo" << endl;
    }
    if (!ballT.loadFromFile("ball.png")) {
        cout << "Error al cargar textura ball" << endl;
    }
    if (!golB.loadFromFile("gol.wav")) {
        cout << "Error al cargar sonido gol" << endl;
    }
    if (!fuente.loadFromFile("pixel.ttf")){
        cout << "Error al cargar fuente pixel.ttf" << endl;
    }
    

    //background texture
    backgroundS.setTexture(backgroundT);
    backgroundS.setOrigin(backgroundT.getSize().x / 2, backgroundT.getSize().y / 2);
    backgroundS.setPosition(425, 250);
    backgroundS.setScale(5, 5);
    backgroundS.setScale(1, 1);
    
    golSound.setBuffer(golB);

    pts1.setFont(fuente);
    pts1.setCharacterSize(40);
    pts1.setPosition((850 / 2) + (850 / 2) / 2, 25);
    pts1.setString(to_string(contP1));

    pts2.setFont(fuente);
    pts2.setCharacterSize(40);
    pts2.setPosition((850 / 2) / 2, 25);
    pts2.setString(to_string(contP2));



    sf::RenderWindow window(sf::VideoMode(850, 500), "Kolo Muani vs Dibu!");
    window.setFramerateLimit(60);
    
    
    Player1 dibu (player1T);
    Player2 kolo (player2T);
    Ball ball(ballT);
    //Game Loop
    while (window.isOpen())
    { 
        sf::Event event;

        //Event polling
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //--------------------------------Update------------------------------------------
       
        //player1 movement
        dibu.movement();

        //player2 movement
        kolo.movement();

        //ball movement;
        ball.movement(velX, velY);

        //collision
        if (dibu.contains((float)ball.getPosition().x, ball.getPosition().y)) {
            velX *= -1;
        }
        if (kolo.contains((float)ball.getPosition().x, ball.getPosition().y)) {
            velX *= -1;
        }
        if (ball.getPosition().x > 850 ){
            contP2++;
            velX *= -1;
            pts2.setString(to_string(contP2));
            golSound.play();
        }
        else if (ball.getPosition().x < 0) {
            contP1++;
            velX *= -1;
            pts1.setString(to_string(contP1));
            golSound.play();
        }
        if (ball.getPosition().y > 500 || ball.getPosition().y < 0) {
            velY *= -1;
          
        }
          

        //--------------------------------Draw------------------------------------------
        window.clear();
        window.draw(backgroundS);
        window.draw(ball);
        window.draw(dibu);
        window.draw(kolo);
        window.draw(pts1);
        window.draw(pts2);
        window.display();

        //Liberamos memoria 
        
    }

    return 0;
}