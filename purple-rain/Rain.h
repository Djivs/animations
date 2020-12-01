//
// Created by dmitriy on 18.08.2020.
//

#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>

#ifndef ANIMATIONS_RAIN_H
#define ANIMATIONS_RAIN_H

//window size
#define SIZE 800

class Rain {
public:
    Rain()
    {
        //set up for random numbers using
        std::random_device rd;
        std::mt19937 e2(rd());
        std::uniform_real_distribution<> dist(0, SIZE);
        std::uniform_real_distribution<> dist1(-SIZE/2, SIZE/2);
        std::uniform_real_distribution<> dist2(2, 7);
        std::uniform_real_distribution<> dist3(0.5, 2);

        //set up random x, y, z and speed
        x = dist(e2);
        y = dist1(e2);
        z = dist2(e2);
        speed = dist3(e2);

    }
    void update()
    {
        //move line down
        y += speed*0.05;

        //if line is out of window, make new one out of it
        //similar to constructor
        if(y >= SIZE)
        {
            std::random_device rd;
            std::mt19937 e2(rd());
            std::uniform_real_distribution<> dist(0, SIZE);
            std::uniform_real_distribution<> dist1(-SIZE/2, SIZE/2);
            std::uniform_real_distribution<> dist2(2, 7);
            std::uniform_real_distribution<> dist3(0.5, 2);
            x = dist(e2);
            y = 0;
            z = dist2(e2);
            speed = dist3(e2);
        }
    }
    void draw(sf::RenderWindow &window) const
    {
        //create rect for raindrop
        sf::RectangleShape shape(sf::Vector2f(z, z*5));

        //select color(based on how far this line is)
        //part of 3d simulation
        sf::Color rectColor;
        if(z > 6)
            rectColor = sf::Color(255, 10, 255);
        else if( z > 5)
            rectColor = sf::Color(226, 0, 226);
        else if(z > 4)
            rectColor = sf::Color(187, 0, 187);
        else if(z > 3)
            rectColor = sf::Color(148, 0, 148);
        else
            rectColor = sf::Color(128, 0, 128);

        shape.setFillColor(rectColor);
        shape.setPosition(x, y);
        window.draw(shape);
    }

    float getZ() const {return z;};


private:
    float x, y, z;
    float speed;

};

#endif //ANIMATIONS_RAIN_H
