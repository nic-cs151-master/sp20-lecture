/**
 * @file world.cpp
 * @author Gabe de la Cruz (gvdelacruz@nic.edu)
 * @version 0.1
 * @date 2021-04-12
 * 
 */
#include "world.h"

World::World(sf::Vector2u windowSize)
{
    mBlockSize = 16;

    mWindowSize = windowSize;
    respawnApple();
    mAppleShape.setFillColor(sf::Color::Red);
    mAppleShape.setRadius(mBlockSize / 2);

    for (int i = 0; i < 4; ++i)
    {
        mBounds[i].setFillColor(sf::Color(150, 0, 0));
        if (!(i + 1) % 2)
        {
            mBounds[i].setSize(sf::Vector2f(mWindowSize.x, mBlockSize));
        }
        else
        {
            mBounds[i].setSize(sf::Vector2f(mBlockSize, mWindowSize.y));
        }

        if (i < 2)
        {
            mBounds[i].setPosition(0, 0);
        }
        else
        {
            mBounds[i].setOrigin(mBounds[i].getSize());
            mBounds[i].setPosition(sf::Vector2f(mWindowSize));
        }
    }

    mFontArial.loadFromFile("assets/arial.ttf");
    mScoreText.setFont(mFontArial);
    mScoreText.setString("SCORE: 0");
    mScoreText.setCharacterSize(15);
    mScoreText.setPosition(mBlockSize, 0);
    mScoreText.setFillColor(sf::Color::Red);
}

World::~World()
{}

int World::getBlockSize() const
{
    return mBlockSize;
}

void World::respawnApple()
{
    int maxX = (mWindowSize.x / mBlockSize) - 2;
    int maxY = (mWindowSize.y / mBlockSize) - 2;
    mItem = sf::Vector2i(rand() % maxX + 1, rand() % maxY + 1);
    mAppleShape.setPosition(mItem.x * mBlockSize,
                             mItem.y * mBlockSize);
}

void World::update(Snake &player)
{
    if (player.getPosition() == mItem)
    {
        player.extend();
        player.increaseScore();
        respawnApple();
    }

    int gridSizeX = mWindowSize.x / mBlockSize;
    int gridSizeY = mWindowSize.y / mBlockSize;

    if (player.getPosition().x <= 0 ||
        player.getPosition().y <= 0 ||
        player.getPosition().x >= gridSizeX - 1 ||
        player.getPosition().y >= gridSizeY - 1)
    {
        player.lose();
    }

    string score = "SCORE: " + to_string(player.getScore());
    mScoreText.setString(score);
}

void World::render(sf::RenderWindow &window)
{
    for (int i = 0; i < 4; ++i)
    {
        window.draw(mBounds[i]);
    }
    window.draw(mAppleShape);
    window.draw(mScoreText);
}
