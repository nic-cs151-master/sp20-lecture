/**
 * @file main.cpp
 * @author Gabe de la Cruz (gvdelacruz@nic.edu)
 * @brief Compile program:
 *          g++ -std=c++11 -Wall main.cpp -lsfml-graphics -lsfml-system -lsfml-window
 * @date 2021-04-12
 * 
 */
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), 
                            "Rendering the rectangle.");
    window.setKeyRepeatEnabled(false);

    sf::Font font;
    font.loadFromFile("assets/fonts/arial.ttf");
    sf::Text prompt;
    prompt.setFont(font);
    prompt.setFillColor(sf::Color::Red);

    // Creating the shape
    sf::RectangleShape rectangle(sf::Vector2f(128.0f, 128.0f));
    rectangle.setFillColor(sf::Color::Red);
    rectangle.setPosition(320, 240);
    rectangle.setOrigin(rectangle.getSize().x / 2, 
                        rectangle.getSize().y / 2);

    unsigned int fontSize = 12;
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                // Close window button clicked.
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::W)
                {
                    std::cout << "W key WAS pressed\n";
                }
            }
            else if(event.type == sf::Event::KeyReleased)
            {
                fontSize = 24;
            }
        }

        prompt.setString("");
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            prompt.setString("Hello");
            fontSize += 1;
            prompt.setCharacterSize(fontSize);
            sf::FloatRect textRect = prompt.getLocalBounds();
            prompt.setOrigin(textRect.left + textRect.width/2, 
                             textRect.top + textRect.height/2);
            prompt.setPosition(320, 240);
            
            // std::cout << "W pressed!\n";
        }

        window.clear(sf::Color::Black);
        window.draw(prompt);  // Drawing the shape.
        window.display();
    }

    return 0;
}