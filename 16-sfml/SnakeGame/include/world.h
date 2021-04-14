#ifndef WORLD_H
#define WORLD_H

#include "SFML/Graphics.hpp"
#include "snake.h"

class World
{
public:
    World(sf::Vector2u windowSize);
    ~World();

    void update(Snake &player);
    void render(sf::RenderWindow &window);

    int getBlockSize() const;
    void respawnApple();

private:
    sf::Vector2u mWindowSize;
    sf::Vector2i mItem; // apple's coordinates
    int mBlockSize;

    sf::CircleShape mAppleShape;
    sf::RectangleShape mBounds[4];
    sf::Font mFontArial;
    sf::Text mScoreText;
};

#endif