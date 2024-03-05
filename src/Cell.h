#pragma once
#include <SFML/Graphics.hpp>
#include "globals.hpp"

struct Cell
{
    float q;
    sf::RectangleShape sprite;

    void update(sf::RenderWindow &window);
};
