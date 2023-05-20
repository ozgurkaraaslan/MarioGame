#include"Game.h"

Game::Game(int speed) {

    this->speed = speed;
	window = new RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "MarioGame");
    window->clear();
    mainMenu.draw(*window);

    sf::Event event;
    while (window->isOpen() && mainMenu.startGame) {
        while (window->pollEvent(event) && mainMenu.startGame) {

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Enter) {
                    window->clear();
                    mainMenu.startGame = false;
                }
            }

            else if (event.type == sf::Event::Closed) {
                window->close();

            }
        }

    }

    elapsedTime = clock.getElapsedTime().asSeconds();
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
             else if (event.type == sf::Event::KeyPressed) {

                 if (rebornFlag) {
                     if (event.key.code == sf::Keyboard::Up && jumpFlag == false) {
                        
                         mario.vy = -20.f;
                         jumpFlag = true;
                         
                     }
                     else if (event.key.code == sf::Keyboard::Right) {

                         mario.move(Mario::MoveDirection::Rigth);
                     }
                     else if (event.key.code == sf::Keyboard::Left) {

                         mario.move(Mario::MoveDirection::Left);
                     }
                 }
                 if (event.key.code == sf::Keyboard::Enter) {

                     rebornFlag = true;
                 }
                 mario.edgeHit(); //checks if mario is at the edge
             }
             else if (event.type == sf::Event::KeyReleased) {
                 mario.move(Mario::MoveDirection::Idle);
             }
         }

         int side_ = 1;
         if (checkCollusion(side_)) {

             rebornFlag = false;
             checkCollusionFlag = true;
         }

         if (checkCollusionFlag) {
             mario.fall();

             if (mario.sprite.getPosition().y > WINDOW_HEIGHT - 90) {
                 checkCollusionFlag = false;
                 mario.setPosition(Vector2f(490.f, 50.f));
                 mario.move(Mario::MoveDirection::Idle);
             }
         }
         else if (rebornFlag == true){

             if (not jumpFlag) { //idle position
                 if (onFLoor(mario)) { //mario is on the floor
                     mario.vy = 0;
                 }
                 else { //mario is not on the floor so make mario fall of the edge
                     mario.jump(true);
                 }

             }
             else { //jump
                 mario.jump(false);
                 if (underFloor(mario)) {   //checks if mario is hitting under floors to push him back
                     mario.vy = 0;
                     mario.jump(true);


                 }
                 if (onFLoor(mario)) { //checks if  mario reached  a floor to cancel movement
                     mario.vy = 0;
                     jumpFlag = false;
                     
                     mario.move(Mario::MoveDirection::Idle);
                 }
                
             }
            
             mario.edgeHit(); //checks if mario is at the edge
         }
         
         
         if (turtleNumber < MAX_TURTLE_NUMBER) {    //turtle spawn
             if (clock.getElapsedTime().asSeconds() - elapsedTime > 15) {
                 if (turtleNumber % 2 == 0) {
                     turtles[turtleNumber].setPosition(Vector2f(138.f, 105.f));
                 }
                 else {
                     turtles[turtleNumber].setPosition(Vector2f(862.f, 105.f));
                 }
                 turtleNumber += 1;
                 elapsedTime = clock.getElapsedTime().asSeconds();
             }
         }
         
         for (int i = 0; i < turtleNumber; i++) { //all methods concerning movement of  turtles is here 
             if (i % 2 == 0) {  //moves the turtles
                 turtles[i].move(Turtle::MoveDirection::Rigth);
             }
             else {
                 turtles[i].move(Turtle::MoveDirection::Left);
             }
             turtles[i].pipeTeleport();
             turtles[i].edgeHit();  //checks if turtles hit boundary of window

             if (!(onFLoor(turtles[i]))) {  //checks if turtles are on the floor
                 turtles[i].jump(true);
             }
         }

         window->clear();

         for (int i = 0; i < NUM_BRICKS; i++) {
             bricks[i].draw(window);
         }
         floor->draw(window);

         for(int i = 0; i < turtleNumber; i++) {    //draws the turtles
             turtles[i].draw(*window);
         }
         
         pipeSs[0].draw(window);
         pipeSs[1].draw(window);
         pipes[0].draw(window);
         pipes[1].draw(window);

         mario.draw(*window);
        
         window->display();

         sf::sleep(sf::milliseconds(1000/speed));
     }
}
void Game::drawBackground() {

    floor = new Floor;  //setting the positions of background objects
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

    bricks = new Brick[NUM_BRICKS]; //setting the positions of all the bricks
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

    mario.setPosition(Vector2f(467.f, 220.f));  

    turtles = new Turtle[MAX_TURTLE_NUMBER];
    turtles[0].setPosition(Vector2f(138.f, 105.f));

}

bool Game::onFLoor(Object &obj){

    obj.boundingBox({ float(obj.sprite.getGlobalBounds().left) , float(obj.sprite.getGlobalBounds().top + obj.sprite.getGlobalBounds().height * 0.95 ) ,float(obj.sprite.getGlobalBounds().width) , float(obj.sprite.getGlobalBounds().height * 0.05)  });

    for(int i = 0; i < NUM_BRICKS; i++){
        if (obj.m_hitbox.intersects(bricks[i].sprite.getGlobalBounds()))
            return true;
    }
    if (obj.sprite.getGlobalBounds().intersects(floor->sprite.getGlobalBounds()))
        return true;

    for (int i = 0; i < 2; i++) {
        if (obj.sprite.getGlobalBounds().intersects(pipeSs[i].sprite.getGlobalBounds()))
            return true;
        
    }

    return false;
    
}
bool Game::underFloor(Mario& mario) {

    mario.boundingBox({ float(mario.sprite.getGlobalBounds().left) , float(mario.sprite.getGlobalBounds().top + mario.sprite.getGlobalBounds().height * 0.05) ,float(mario.sprite.getGlobalBounds().width) , float(mario.sprite.getGlobalBounds().height * 0.05) });
    for (int i = 0; i < NUM_BRICKS; i++) {
        if (mario.m_hitbox.intersects(bricks[i].sprite.getGlobalBounds()))
            return true;
    }
   
    return false;

}

bool Game::checkCollusion(int& side) {

    if (side == 0) {    // top

    }
    else if (side == 1) {  // left or right

        for (int i = 0; i < turtleNumber; i++) {
            
            turtles[i].boundingBox({ float(turtles[i].sprite.getGlobalBounds().left) , float(turtles[i].sprite.getGlobalBounds().top + turtles[i].sprite.getGlobalBounds().height * 0.1) ,float(turtles[i].sprite.getGlobalBounds().width) , float(turtles[i].sprite.getGlobalBounds().height * 0.9) });
            if (turtles[i].m_hitbox.intersects(mario.sprite.getGlobalBounds())) {
                return true;
            }
        }
    }

    return false;
}
