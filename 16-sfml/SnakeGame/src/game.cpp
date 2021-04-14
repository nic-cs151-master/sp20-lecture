/**
 * @file game.cpp
 * @author Gabe de la Cruz (gvdelacruz@nic.edu)
 * @version 0.1
 * @date 2021-04-12
 * 
 */
#include "game.h"

Game::Game() : mWindow(sf::VideoMode(800, 600), "Snake"),
    mWorld(sf::Vector2u(800, 600)), mSnake(mWorld.getBlockSize())
{
    mIncrement = sf::Vector2i(400, 400); // 400px a second
    mIsDone = false;

    mPrevious = mClock.restart();
    mLag = sf::seconds(0);

    // key-repeats are added once to poll
    mWindow.setKeyRepeatEnabled(false);
}

Game::~Game()
{}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (mWindow.isOpen())
    {
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TIME_PER_FRAME)
        {
            timeSinceLastUpdate -= TIME_PER_FRAME;
            handleInput();
            update();
        }
        render();
    }
}

void Game::handleInput()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) 
           && mSnake.getDirection() != Input::PRESS_DOWN)
    {
        mSnake.handleInput(Input::PRESS_UP);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
        && mSnake.getDirection() != Input::PRESS_UP)
    {
        mSnake.handleInput(Input::PRESS_DOWN);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
        && mSnake.getDirection() != Input::PRESS_RIGHT)
    {
        mSnake.handleInput(Input::PRESS_LEFT);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
        && mSnake.getDirection() != Input::PRESS_LEFT)
    {
        mSnake.handleInput(Input::PRESS_RIGHT);
    }

    sf::Event event;
    while(mWindow.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            // Close window button clicked.
            mWindow.close();
        }
    }
}

void Game::update()
{
    mSnake.update();
    mWorld.update(mSnake);

    if (mSnake.hasLost())
    {
        mSnake.reset();
    }
}

void Game::render()
{
    mWindow.clear(sf::Color::Black);

    mWorld.render(mWindow);
    mSnake.render(mWindow);

    mWindow.display();
}

bool Game::isDone() const
{
    return (!mWindow.isOpen() || mIsDone);
}