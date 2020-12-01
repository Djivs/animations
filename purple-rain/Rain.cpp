#include "Rain.h"

//number of lines
#define RAINAMOUNT 200
int main()
{
    //create window
    sf::RenderWindow window(sf::VideoMode(SIZE, SIZE), "Purple Rain");

    //create lines array
    Rain arr[RAINAMOUNT];

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

        //make window purple
        window.clear(sf::Color(102, 0, 102));

        //sort array by Z to place small lines back (kinda 3d simulation)
        for(int i = 0; i < RAINAMOUNT-1; i++)
        {
            if(arr[i].getZ() > arr[i+1].getZ())
                std::swap(arr[i], arr[i+1]);
        }
        //update and draw each rein drop
        for(Rain & i : arr)
        {
            i.update();
            i.draw(window);
        }
        window.display();
    }

    return 0;
}