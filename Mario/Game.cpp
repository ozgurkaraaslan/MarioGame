#include"Game.h"

Game::Game(int speed) {

    this->speed = speed;
	window = new RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "MarioGame");
    window->clear();
    mainMenu.draw(*window);

    sf::Event event;
    while (window->isOpen() && mainMenu.startGame) {
        while (window->pollEvent(event) && mainMenu.startGame) {        // start menu 

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

    elapsedTime = clock.getElapsedTime().asSeconds();   // holds initial time of the game for turtle spawning
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
                     if (event.key.code == sf::Keyboard::Up && jumpFlag == false && onFLoor(mario)) {
                        
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
                 if (event.key.code == sf::Keyboard::Enter) {   // checks reborn of Mario

                     rebornFlag = true;
                 }
                 mario.edgeHit(); //checks if mario is at the edge
             }
             else if (event.type == sf::Event::KeyReleased && jumpFlag == false) {
                 mario.move(Mario::MoveDirection::Idle);
             }
         }


         int side_ = 1;
         if (checkCollusion(side_)) {      // checks if Mario has hit a turtle from lateral side
             
             if (mario.remainingLives == 0) {
                 gameOver(false);
             }

             mario.sprite.move(0, 88);
             checkCollusionFlag = true;
             rebornFlag = false;
         }

         if (checkCollusionFlag) {      // organizes dead Mario operations
             mario.fall();

             if (mario.sprite.getPosition().y > WINDOW_HEIGHT - 90) {
                 checkCollusionFlag = false;
                 mario.setPosition(Vector2f(490.f, 50.f));
                 mario.move(Mario::MoveDirection::Idle);
             }
         }
         else if (rebornFlag == true){  // checks if Mario is alive 

             if (not jumpFlag) {    // no jump directive 
                 if (onFLoor(mario)) {     // checks if Mario is on the floor
                     mario.vy = 0;
                 }
                 else {     //mario is not on the floor so make mario fall of the edge
                     mario.jump(true);
                 }

             }
             else{    //jump
                 mario.jump(false);
                 if (underFloor(mario)) {   //checks if Mario is hitting under floors to push him back
                     mario.vy = 0;
                     mario.jump(true);

                 }
                 if (onFLoor(mario)) { //checks if Mario reached  a floor to cancel movement
                     mario.vy = 0;
                     jumpFlag = false;
                     
                     mario.move(Mario::MoveDirection::Idle);
                 }
                
             }
            
              mario.edgeHit(); //checks if Mario is at the edge
         }
         
         side_ = 0;
         if (checkCollusion(side_) && not checkCollusionFlag) {     // checks if Mario has hit a turtle from top side
             if (scoreboard.score >= 500) {
                 gameOver(true);
             }
             turtles[deadTurtleIndice].sprite.move(0.f, 50.f);
             turtleDeadFlag = true;
         }
         if (turtleDeadFlag) {      // organizes dead turtle operations
             turtles[deadTurtleIndice].fall();

             if (turtles[deadTurtleIndice].sprite.getPosition().y > WINDOW_HEIGHT + 200) {
                 turtleDeadFlag = false;
                 
                 /*
                 for (int i = deadTurtleIndice; i < turtleNumber - 1; i++)
                 {
                     turtles[i] = turtles[i + 1];
                 }
                 turtleNumber -= 1;*/

             }
         }


         if (turtleNumber < maxTurtleNumber) {    // checks max turtle spawn
             if (clock.getElapsedTime().asSeconds() - elapsedTime > TURTLE_SPAWN_FREQUENCY) {  // manages turtle spawn timing
                 if (turtleNumber % 2 == 0) {
                     turtles[turtleNumber].setPosition(Vector2f(138.f, 105.f));
                 }
                 else {
                     turtles[turtleNumber].setPosition(Vector2f(862.f, 105.f));
                 }
                 turtleNumber += 1;
                 elapsedTime = clock.getElapsedTime().asSeconds();     // holds time to manage spawning 
             }
         }
         
         for (int i = 0; i < turtleNumber; i++) { // movement methods of turtles 
             if (i != deadTurtleIndice) {

                 turtles[i].move(turtles[i].dir);
                 
                 turtles[i].pipeTeleport();
                 turtles[i].edgeHit();  //checks if turtles hit boundary of window

                 if (!(onFLoor(turtles[i]))) {  //checks if turtles are on the floor
                     turtles[i].jump(true);
                 }
                 else {
                     turtleCollusion(i);
                 }
                 
             } 
         }
         

         window->clear();  // clears window just before new drawings

         for (int i = 0; i < NUM_BRICKS; i++) {  // draws bricks
             bricks[i].draw(window);
         }
         floor->draw(window);

         for(int i = 0; i < turtleNumber; i++) {    //draws the turtles
             turtles[i].draw(*window);
         }
         
         for (int i = 0; i < mario.remainingLives; i++) {    //draws the turtles
             heads[i].draw(*window);
         }

         pipeSs[0].draw(window);    // draws pipeS
         pipeSs[1].draw(window);
         pipes[0].draw(window);     // draws pipe
         pipes[1].draw(window);

         mario.draw(*window);       // draws Mario

         scoreboard.draw(*window);  //draws scoreboard
         window->draw(textOver);
         window->display();         // shows all the drawings

         sf::sleep(sf::milliseconds(1000/speed));   // delay before next the loop
     }
}
void Game::drawBackground() {

    font.loadFromFile("../assets/font.ttf");
    textOver.setFont(font);
    textOver.setString("Press Enter to be Reborn");
    textOver.setCharacterSize(14);
    textOver.setFillColor(Color::White);
    textOver.setPosition(WINDOW_WIDTH * 0.38, 15);

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

    turtles = new Turtle[maxTurtleNumber];
    turtles[0].setPosition(Vector2f(138.f, 105.f));
    turtles[0].dir = Turtle::MoveDirection::Rigth;
    turtles[1].dir = Turtle::MoveDirection::Left;
    turtles[2].dir = Turtle::MoveDirection::Rigth;
    turtles[3].dir = Turtle::MoveDirection::Left;
    turtles[4].dir = Turtle::MoveDirection::Rigth;

    heads = new Heads[3];
    heads[0].setPosition(Vector2f(120.f, 60.f));
    heads[1].setPosition(Vector2f(160.f, 60.f));
    heads[2].setPosition(Vector2f(200.f, 60.f));

}

bool Game::onFLoor(Object &obj){     //checks if the obj is on top of the floors  
    
    obj.boundingBox({ float(obj.sprite.getGlobalBounds().left), float(obj.sprite.getGlobalBounds().top + obj.sprite.getGlobalBounds().height * 0.95 ) ,float(obj.sprite.getGlobalBounds().width) , float(obj.sprite.getGlobalBounds().height * 0.05)  });
    //creates a small bounding box at obj feet
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
    //creating a bounding box at mario's head to check if mario hit his on the bricks
    mario.boundingBox({ float(mario.sprite.getGlobalBounds().left) , float(mario.sprite.getGlobalBounds().top + mario.sprite.getGlobalBounds().height * 0.05) ,float(mario.sprite.getGlobalBounds().width) , float(mario.sprite.getGlobalBounds().height * 0.05) });
    for (int i = 0; i < NUM_BRICKS; i++) {
        if (mario.m_hitbox.intersects(bricks[i].sprite.getGlobalBounds()))
            return true;    //mario hit his head
    }
   
    return false;   //mario didnt hit his head

}

void Game::turtleCollusion(int j) {        // collision check for turtles
        
        for (int i = 0; i < turtleNumber-1; i++) {
            
            if (i != j) {
                turtles[i].boundingBox({ float(turtles[i].sprite.getGlobalBounds().left) , float(turtles[i].sprite.getGlobalBounds().top + turtles[i].sprite.getGlobalBounds().height * 0.8) ,float(turtles[i].sprite.getGlobalBounds().width) , float(turtles[i].sprite.getGlobalBounds().height * 0.2) });

                if (turtles[i].m_hitbox.intersects(turtles[j].sprite.getGlobalBounds()) && turtles[i].dir != turtles[j].dir) {
                    
                        if (turtles[i].dir == Turtle::MoveDirection::Rigth) {
                               turtles[i].dir = Turtle::MoveDirection::Left;
                               turtles[i].sprite.move(-60, 0);
                               turtles[j].dir = Turtle::MoveDirection::Rigth;
                               turtles[j].sprite.move(60, 0);
                               return;
                        }
                        else if(turtles[i].dir == Turtle::MoveDirection::Left) {
                            turtles[j].dir = Turtle::MoveDirection::Left;
                            turtles[j].sprite.move(-60, 0);
                            turtles[i].dir = Turtle::MoveDirection::Rigth;
                            turtles[i].sprite.move(60, 0);
                            return;
                        }
                }
            }
        }
    
    return;
}

bool Game::checkCollusion(int& side) {

    if (side == 0) {    // checks if Mario has hit a turtle from top side

        for (int i = 0; i < turtleNumber; i++) {
            //sets a bounding box at the head of turtle
            turtles[i].boundingBox({ float(turtles[i].sprite.getGlobalBounds().left) , float(turtles[i].sprite.getGlobalBounds().top) ,float(turtles[i].sprite.getGlobalBounds().width) , float(turtles[i].sprite.getGlobalBounds().height * 0.1) });
            //checks if the bounding box intersected mario if so kills turtle
            if (turtles[i].m_hitbox.intersects(mario.sprite.getGlobalBounds())) {
                deadTurtleIndice = i;
                scoreboard.scoreSetter();
                return true;
            }
        }
    }
    else if (side == 1) {  // checks if Mario has hit a turtle from lateral side

        for (int i = 0; i < turtleNumber; i++) {
            
            turtles[i].boundingBox({ float(turtles[i].sprite.getGlobalBounds().left) , float(turtles[i].sprite.getGlobalBounds().top + turtles[i].sprite.getGlobalBounds().height * 0.2) ,float(turtles[i].sprite.getGlobalBounds().width) , float(turtles[i].sprite.getGlobalBounds().height * 0.8) });
            if (turtles[i].m_hitbox.intersects(mario.sprite.getGlobalBounds())) {
                mario.remainingLives -= 1;
                return true;
            }
        }
    }

    return false;
}
void Game::gameOver(bool finishType) { // ends the game
    Text textOver;
    Font font;
    if (!font.loadFromFile("../assets/font.ttf"))
    {
        cout << "Couldn't load font";
    }
    if (finishType) {       //SCORE REACHED 500
        window->clear();
        //set font for text
        textOver.setFont(font);
        //textOver name
        textOver.setString("GAME OVER\n\tYOU WIN");
        //set size
        textOver.setCharacterSize(75);
        //set color
        textOver.setFillColor(Color::Red);
        //set pos.
        textOver.setPosition(WINDOW_WIDTH * 0.25, WINDOW_HEIGHT * 0.4);
        window->draw(textOver);
        window->display();
        sf::sleep(sf::milliseconds(200000 / speed));
        window->close();
    }
    else {          //MARIO DIES
        window->clear();
        //set font for text
        textOver.setFont(font);
        //textOver name
        textOver.setString("GAME OVER\n  YOU LOST");
        //set size
        textOver.setCharacterSize(75);
        //set color
        textOver.setFillColor(Color::Red);
        //set pos.
        textOver.setPosition(WINDOW_WIDTH * 0.25, WINDOW_HEIGHT * 0.4);
        window->draw(textOver);
        window->display();
        sf::sleep(sf::milliseconds(200000 / speed));
        window->close();
    }
}