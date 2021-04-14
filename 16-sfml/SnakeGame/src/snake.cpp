/**
 * @file snake.cpp
 * @author Gabe de la Cruz (gvdelacruz@nic.edu)
 * @date 2021-04-12
 * 
 */
#include "snake.h"

Snake::Snake(int blockSize)
{
    mSize = blockSize;
    // minus 1 to make it visually look slightly separated
    mBodyRect.setSize(sf::Vector2f(mSize - 1, mSize - 1));
    reset();
}

Snake::~Snake()
{}

// main functions
void Snake::move() // movement method
{
    for (int i = mSnakeBody.size() - 1; i > 0; --i)
    {
        mSnakeBody[i].position = mSnakeBody[i - 1].position;
    }

    if (mDirection == Input::PRESS_LEFT)
    {
        --mSnakeBody[0].position.x;
    }
    else if (mDirection == Input::PRESS_RIGHT)
    {
        ++mSnakeBody[0].position.x;
    }
    else if (mDirection == Input::PRESS_UP)
    {
        --mSnakeBody[0].position.y;
    }
    else if (mDirection == Input::PRESS_DOWN)
    {
        ++mSnakeBody[0].position.y;
    }
}

void Snake::update() // update method
{
    if (mSnakeBody.empty()) 
    {
        return;
    }

    if (mDirection == Input::None)
    {
        return;
    }

    move();
    checkCollision();
}

void Snake::render(sf::RenderWindow& window)
{
    if (mSnakeBody.empty())
    {
        return;
    }

    SnakeSegment& head = mSnakeBody[0];
    mBodyRect.setFillColor(sf::Color::Yellow);
    mBodyRect.setPosition(head.position.x * mSize, head.position.y * mSize);
    window.draw(mBodyRect);

    mBodyRect.setFillColor(sf::Color::Green);
    for (size_t i = 1; i < mSnakeBody.size(); ++i)
    {
        SnakeSegment& body = mSnakeBody[i];
        mBodyRect.setPosition(body.position.x * mSize, body.position.y * mSize);
        window.draw(mBodyRect);
    }
}

void Snake::extend() // grow the snake
{
    if (mSnakeBody.empty()) 
    { 
        return; 
    }

    SnakeSegment& tailHead = mSnakeBody[mSnakeBody.size() - 1];
    if (mSnakeBody.size() > 1)
    {
        SnakeSegment& tailBone = mSnakeBody[mSnakeBody.size() - 2];

        if (tailHead.position.x == tailBone.position.x)
        {
            if (tailHead.position.y > tailBone.position.y)
            {
                SnakeSegment seg(tailHead.position.x, tailHead.position.y + 1);
                mSnakeBody.push_back(seg);
            }
            else
            {
                SnakeSegment seg(tailHead.position.x, tailHead.position.y - 1);
                mSnakeBody.push_back(seg);
            }
        }
        else if (tailHead.position.y == tailBone.position.y)
        {
            if (tailHead.position.x > tailBone.position.x)
            {
                SnakeSegment seg(tailHead.position.x + 1, tailHead.position.y);
                mSnakeBody.push_back(seg);
            }
            else
            {
                SnakeSegment seg(tailHead.position.x - 1, tailHead.position.y);
                mSnakeBody.push_back(seg);
            }
        }
    }
    else
    {
        if (mDirection == Input::PRESS_UP)
        {
            SnakeSegment seg(tailHead.position.x, tailHead.position.y + 1);
            mSnakeBody.push_back(seg);
        }
        else if (mDirection == Input::PRESS_DOWN)
        {
            SnakeSegment seg(tailHead.position.x, tailHead.position.y - 1);
            mSnakeBody.push_back(seg);
        }
        else if (mDirection == Input::PRESS_LEFT)
        {
            SnakeSegment seg(tailHead.position.x + 1, tailHead.position.y);
            mSnakeBody.push_back(seg);
        }
        else if (mDirection == Input::PRESS_RIGHT)
        {
            SnakeSegment seg(tailHead.position.x - 1, tailHead.position.y);
            mSnakeBody.push_back(seg);
        }
    }
}

void Snake::reset() // reset to starting position
{
    mSnakeBody.clear();

    mSnakeBody.push_back(SnakeSegment(5, 7));
    mSnakeBody.push_back(SnakeSegment(5, 6));
    mSnakeBody.push_back(SnakeSegment(5, 5));

    handleInput(Input::None);  // Start off not moving
    mSpeed = 15;
    mScore = 0;
    mLost = false;
}

// helper functions
void Snake::handleInput(Input direction)
{
    mDirection = direction;
}

Input Snake::getDirection() const
{
    return mDirection;
}

int Snake::getSpeed() const
{
    return mSpeed;
}

sf::Vector2i Snake::getPosition() const
{
    if (mSnakeBody.empty())
    {
        return sf::Vector2i(1, 1);
    }
    
    return mSnakeBody.front().position;
}

int Snake::getScore() const
{
    return mScore;
}

void Snake::increaseScore()
{
    mScore += 10;
}

bool Snake::hasLost() const
{
    return mLost;
}


void Snake::lose() // handle losing here
{
    mLost = true;
}

void Snake::toggleLost()
{
    mLost = !mLost;
}

void Snake::checkCollision() // checking for collision
{
    // Impossible to collide
    if (mSnakeBody.size() < 5)
    {
        return;
    }

    SnakeSegment& head = mSnakeBody.front();
    for (size_t i = 1; i < mSnakeBody.size(); ++i)
    {
        if (head.position == mSnakeBody[i].position)
        {
            lose();
            return;
        }
    }
}