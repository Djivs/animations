//
// Created by djivs on 17.08.2020.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>

#ifndef ANIMATIONS_STAR_H
#define ANIMATIONS_STAR_H
//size of window variable
const float SIZE = 800.0;

//animation speed
float speed = 10;
class Star {
public:
    //constructor
    Star()
    {
        //setup for getting random number
        std::random_device rd;
        std::mt19937 e2(rd());
        //x and y from -SIZE/2 to make stars fly out of center
        std::uniform_real_distribution<> dist(-SIZE/2, SIZE/2); //for x & y
        std::uniform_real_distribution<> dist2(0, SIZE/2); // for z
        //get random x && y coordinate
        x = dist(e2);
        y = dist(e2);
        z = dist2(e2);
        //pz - previous z coordinate
        pz = z;
    }
    void update()
    {
        //change z by speed
        z = z - speed;

        //refresh star coordinates if star is out of window
        //similar to constructor
        if (z < 1) {
            std::random_device rd;
            std::mt19937 e2(rd());
            z = SIZE/2;
            std::uniform_real_distribution<> dist(-SIZE/2, SIZE/2);
            x = dist(e2);
            y = dist(e2);
            pz = z;
        }
    };
    void draw(sf::RenderWindow &window)
    {
        //calculate current star coordinates by x/z or y/z
        float sx = x/z * (SIZE/2);
        float sy = y/z * (SIZE/2);

        //calculate star radius by z (far => small)
        float r = 4 - z/((SIZE/2) / 4);

        //calculate previous star coordinates
        float px = x/pz * (SIZE/2);
        float py = y/pz * (SIZE/2);

        //save current z to pz
        pz = z;

        //create line from previous star position to current star position
        //adding SIZE/2 to make stars go out of center
        //adding r/2 to make line go out of star center
        sf::VertexArray line(sf::LinesStrip, 2);
        line[0].position = sf::Vector2f(px + SIZE/2 + r/2, py + SIZE/2 + r/2);
        line[1].position = sf::Vector2f(sx+ r / 2 + SIZE/2, sy + r/2 + SIZE/2);

        //create circle for star with star radius
        sf::CircleShape dot(r);
        //set pos in current coordinates
        //adding SIZE/2 to make stars fly out of center
        dot.setPosition(sx + SIZE/2, sy + SIZE/2);

        //draw line and star
        window.draw(dot);
        window.draw(line);
    };
private:
    //coordinates and var to store previous z coordinate
    //(for line drawing)
    float x, y, z;
    float pz;
};
#endif //ANIMATIONS_STAR_H
