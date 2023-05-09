#include"Game.h"

Game::Game(int speed) {

	window = new RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "MarioGame");
	/*
    bgTexture.loadFromFile("../assets/bg.png");
	bgTexture.setRepeated(true);
	bgSprite.setTexture(bgTexture);
	bgSprite.setTextureRect(IntRect(0, 0, window->getSize().x, window->getSize().y));
    */
    this->speed = speed;
    
}

void Game::update(void){

    while(window->isOpen())
    {
         // check all the window's events that were triggered since the last iteration of the loop
         sf::Event event;

         while (window->pollEvent(event))
         {
             // "close requested" event: we close the window
             if (event.type == sf::Event::Closed)
                 window->close();
         }

         window->clear();

         //window->draw(bgSprite);
         window->draw(floorSprite);
         window->draw(pipeLeftSprite);
         window->draw(pipeRightSprite);
         window->draw(pipeSLeftSprite); 
         window->draw(pipeSRightSprite);


         window->display();

         sf::sleep(sf::milliseconds(1000/speed));
     }
}
void Game::drawBackground() {
    floorTexture.loadFromFile("../assets/floor.png");
    floorSprite.setTexture(floorTexture);
    floorSprite.setPosition(Vector2f(0, (window->getSize().y)*0.87));
    
    pipeLeftTexture.loadFromFile("../assets/pipe.png");
    pipeLeftSprite.setTexture(pipeLeftTexture);
    pipeLeftSprite.setScale(-1.f, 1.f);
    pipeLeftSprite.setPosition(Vector2f(pipeLeftTexture.getSize().x, ((window->getSize().y) * 0.78)));

    pipeRightTexture.loadFromFile("../assets/pipe.png");
    pipeRightSprite.setTexture(pipeRightTexture);
    pipeRightSprite.setPosition(Vector2f((window->getSize().x - pipeRightTexture.getSize().x), (window->getSize().y) * 0.78));

    pipeSLeftTexture.loadFromFile("../assets/pipeS.png");
    pipeSLeftSprite.setTexture(pipeSLeftTexture);
    pipeSLeftSprite.setPosition(Vector2f(0, ((window->getSize().y) * 0.14)));

    pipeSRightTexture.loadFromFile("../assets/pipeS.png");
    pipeSRightSprite.setTexture(pipeSRightTexture);
    pipeSRightSprite.setScale(-1.f, 1.f);
    pipeSRightSprite.setPosition(Vector2f((window->getSize().x), (window->getSize().y) * 0.14));
}