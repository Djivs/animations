//
// Created by djivs on 17.08.2020.
//

//file with Star class,
//headers and global variables
#include "Star.h"

//main function
int main(){
    //create window
    sf::RenderWindow window(sf::VideoMode((int)SIZE, (int)SIZE), "Star field");

    //create array with stars
    Star stars[800];

    //time control setup
    sf::Clock clock;
    double frame = 0;

    //main cycle
    while (window.isOpen())
    {
        //elapsed time control
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 8000;
        frame += 0.25*time;

        //to close the window
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //to control animation speed with mouse
        if(event.type == sf::Event::MouseMoved)
            speed = (float)event.mouseMove.x / (SIZE / 25);

        //draw and update stars (when frame is >1)
        if(frame >= 1) {
            //clear window
            window.clear();
            //update and draw each star
            for (auto &i : stars) {
                i.update();
                i.draw(window);
            }
            //refresh frame
            frame -= 1;
        }
        //show star field
        window.display();
    }

    //end
    return 0;
}