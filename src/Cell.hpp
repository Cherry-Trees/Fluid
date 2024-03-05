#pragma once
#include <SFML/Graphics.hpp>
#include "globals.hpp"
#include "Cell.h"

void Cell::update(sf::RenderWindow &window)
{
    sprite.setFillColor(sf::Color(std::max(std::min(q, 255.f), 10.f), 
                                        std::max(std::min(q/6, 255.f), 10.f), 
                                        std::max(std::min(q/3, 255.f), 10.f)));
    window.draw(sprite);
}
