#include "Common.h"
#include "Game.h"

/*

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Tennis Ball");

    sf::Texture texture;
    if (!texture.loadFromFile("../assets/ball.png"))
    {
        cout << "File could not be found!" << endl;
    }

    sf::Sprite sprite;
    sprite.setTexture(texture);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;

        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        window.draw(sprite);

        window.display();

        sf::sleep(sf::milliseconds(100));
    }

    return 0;
}
*/

int main()
{
    Game game(SPEED);
    game.drawBackground();
    game.update();
    return 0;
}