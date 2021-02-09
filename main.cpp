#include "PlayScreen.h"
#include <chrono>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(nullptr));
    Screen splash, menu;
    PlayScreen play;
    splash.setSplashScreen();
    menu.setMenu();

    bool displaySplash = true;
    bool displayMenu, displayPlay = false;
    auto time1 = chrono::steady_clock::now();

    sf::RenderWindow window(sf::VideoMode(1920, 1080, 32), "Poker");
    window.setFramerateLimit(60);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (displayMenu)
                    {
                        string buttonClicked = menu.getButtonClicked(mousePos);
                        if (buttonClicked == "quit")
                            exit(0);
                        else if (buttonClicked == "play")
                        {
                            displaySplash = false;
                            displayMenu = false;
                            displayPlay = true;
                        }
                    }
                    else if (displayPlay)
                    {
                        if (play.getStateButtonClicked(mousePos))
                            play.playRound();
                        else
                        {
                            Constants::Action action = play.getActionButtonClicked(mousePos);
                            if (action != Constants::NONE)
                                play.playUserAction(action);
                        }
                    }
                    break;
                }
                default: break;
            }
        }
        window.clear();

        if (displaySplash)
        {
            window.draw(splash);
            auto time2 = chrono::steady_clock::now();
            double diff = chrono::duration_cast<chrono::milliseconds>(time2-time1).count()*1.0/1000;
            if (diff > 1)
            {
                displaySplash = false;
                displayMenu = true;
            }
        }
        else if (displayMenu)
        {
            window.draw(menu);
        }
        else if (displayPlay)
        {
            window.draw(play);
            play.updateAnimation();
        }
        window.display();
    }
}