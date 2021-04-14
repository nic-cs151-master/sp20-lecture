/**
 * @file snake.h
 * @author Gabe de la Cruz (gvdelacruz@nic.edu)
 * @date 2021-04-12
 * 
 */
#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SFML/Graphics.hpp"
using namespace std;

struct SnakeSegment
{
    sf::Vector2i position; // sf::Vector2<int> position
    SnakeSegment(int x, int y)
    {
        position.x = x;
        position.y = y;
    }
};

enum class Input
{
    None, 
    PRESS_UP, 
    PRESS_DOWN, 
    PRESS_LEFT, 
    PRESS_RIGHT
};

class Snake
{
public:
    Snake(int blockSize);
    ~Snake();

    // main functions
    void handleInput(Input direction);
    void update(); // update method
    void render(sf::RenderWindow &window);

    void move(); // movement method
    void extend(); // grow the snake
    void reset(); // reset to starting position

    Input getDirection() const;
    int getSpeed() const;
    sf::Vector2i getPosition() const;
    int getScore() const;
    void increaseScore();
    bool hasLost() const;

    void lose(); // handle losing here
    void toggleLost();

private:
    void checkCollision(); // checking for collision

    vector<SnakeSegment> mSnakeBody;  // segment vector
    sf::RectangleShape mBodyRect;  // shape used in rendering
    
    int mSize; // size of the grpahics
    Input mDirection; // current direction
    int mSpeed; // speed of snake

    int mScore;
    bool mLost;
    
};

#endif