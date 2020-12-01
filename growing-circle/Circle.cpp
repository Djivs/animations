#include <SFML/Graphics.hpp>

#define SIZE 500

using namespace sf;

int main()
{
    //create window
    sf::RenderWindow window(sf::VideoMode(SIZE, SIZE), "Growing Circle");

    double r = 0;

    CircleShape c;
    c.setFillColor(Color::Red);
    //main cycle
    while (window.isOpen())
    {
        //close the window
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        r += 0.001;
        c.setRadius(r);
        c.setPosition(SIZE/2 - r, SIZE /2 - r);
        window.draw(c);
        window.display();
    }

    return 0;
}
