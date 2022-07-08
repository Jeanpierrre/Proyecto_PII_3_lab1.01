//
// Created by sotom on 08/07/2022.
//
#include "menu.h"
#include <iostream>
#include <array>
#include <chrono>
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "Menu.h"
#include <SFML/Audio.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>
#include<iostream>
#include "unistd.h"
#include<stdio.h>
#include<stdlib.h>
#include "Windows.h"
#include <iostream>
#include <chrono>
#include <thread>
#include<ctime>
using namespace sf;

void menu(){

}


int play=0;
int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Menu");

    Menu menu(window.getSize().x, window.getSize().y);

    sf::SoundBuffer buffer;
    sf::Sound sound;
    if(!buffer.loadFromFile("C:\\Users\\sotom\\CLionProjects\\Allego\\Source\\menu.wav")){
        cout<<"No carga"<<endl;
    }

    sound.setBuffer(buffer);
    sound.play();
    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::KeyReleased:
                    switch (event.key.code)
                    {
                        case sf::Keyboard::Up:
                            menu.MoveUp();
                            break;

                        case sf::Keyboard::Down:
                            menu.MoveDown();
                            break;

                        case sf::Keyboard::Return:
                            switch (menu.GetPressedItem())
                            {
                                case 0:
                                    std::cout << "Play button has been pressed" << std::endl;
                                    play++;
                                    break;
                                case 1:
                                    window.close();
                                    break;
//                                    std::cout << "Option button has been pressed" << std::endl;
//                                    break;
//                                case 2:
//                                    window.close();
//                                    break;
                            }

                            break;
                    }

                    break;
                case sf::Event::Closed:
                    window.close();

                    break;

            }
        }

        if(play==1){
            window.close();
        }
        window.clear();

        menu.draw(window);

        window.display();
    }

    if(play==1){
        cout<<"Hola"<<endl;
    }
}