#include"Game.h"

Game::Game(int speed) {

    this->speed = speed;
	window = new RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "MarioGame");

    /*
    bgTexture.loadFromFile("../assets/bg.png");
    bgTexture.setRepeated(true);
    bgSprite.setTexture(bgTexture);
    bgSprite.setTextureRect(IntRect(0, 0, window->getSize().x, window->getSize().y));
    */
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
         
         floor->draw(window);
         pipeSs[0].draw(window);
         pipeSs[1].draw(window);
         pipes[0].draw(window);
         pipes[1].draw(window);

         for (int i = 0; i < NUM_BRICKS; i++) {
             bricks[i].draw(window);
         }

         mario.draw(*window);
         turtles[0].draw(*window);
         turtles[1].draw(*window);

         window->display();
         sf::sleep(sf::milliseconds(1000/speed));
     }
}
void Game::drawBackground() {


    floor = new Floor;
    floor->setPosition(Vector2f(0, (window->getSize().y) * 0.87));
    
    pipeSs = new PipeS[2];
    pipeSs[0].setPosition(Vector2f(0, ((window->getSize().y) * 0.1)));
    pipeSs[1].setScale(-1.f, 1.f);
    pipeSs[1].setPosition(Vector2f((window->getSize().x), (window->getSize().y) * 0.1));

    pipes = new Pipe[2];
    pipes[0].setScale(-1.f, 1.f);
    pipes[0].setPosition(Vector2f(pipes[0].texture.getSize().x, ((window->getSize().y) * 0.8)));
    pipes[1].setPosition(Vector2f((window->getSize().x - pipes[1].texture.getSize().x), (window->getSize().y) * 0.8));

    float row = 0;
    float column = 0;

    bricks = new Brick[NUM_BRICKS];
    int k = 0, m = 0;

    for (int j = 0; j < (sizeof(brick_rows) / sizeof(float)); j++) {
        row = brick_rows[j];

        if (j == 1)
            column = 260;

        for (m = 0; m < brick_nums[j]; m += 2) {

            bricks[k + m].setPosition(Vector2f(float(column), float(row)));
            bricks[k + m + 1].setPosition(Vector2f(float(window->getSize().x - column - bricks[k + m].texture.getSize().x), float(row)));
            column += bricks[k + m].texture.getSize().x;
        }
        k += m;
        column = 0;
    }

    mario.setPosition(Vector2f(450.f, 420.f));

    turtles = new Turtle[2];
    turtles[0].setPosition(Vector2f(250.f, 220.f));
    turtles[1].setPosition(Vector2f(350.f, 320.f));

}