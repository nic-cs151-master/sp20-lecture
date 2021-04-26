/**
 * @file game.h
 * @author Gabe de la Cruz (gvdelacruz@nic.edu)
 * @date 2021-04-12
 * 
 */
#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"
#include "snake.h"
#include "world.h"

// Set game to run at 30 frames per second
const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 10.f);

class Game
{
public:
    Game();
    ~Game();

    void run();

    void handleInput();
    void update();
    void render();

    bool isDone() const;

private:
    sf::RenderWindow mWindow;

    World mWorld;
    Snake mSnake;

    bool mIsDone;
    sf::Clock mClock;
    sf::Time mPrevious;
    sf::Time mLag;

    sf::Vector2i mIncrement;
};

#endif