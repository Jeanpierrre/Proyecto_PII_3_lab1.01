//
// Created by sotom on 07/07/2022.
//

#ifndef ALLEGO_BALA_H
#define ALLEGO_BALA_H
#include "Enemigo.h"
#include "Objeto.h"
#include <array>
#include <chrono>
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
class Bala{
private:
    sf::Texture textura;
    sf::Texture textura_ovni;
    bool pare=true;

public:
    sf::Sprite sprite;

    Bala(){
//        textura.loadFromFile("C:\\\\Users\\\\sotom\\\\CLionProjects\\\\Allego\\\\Source\\\\balas.png");
//        sprite.setTexture(textura);
//        sprite.setScale(0.15,0.5);

        //sprite.setPosition(200,200);
    }
    void setup(){
        textura.loadFromFile("C:\\\\Users\\\\sotom\\\\CLionProjects\\\\Allego\\\\Source\\\\balas.png");
        sprite.setTexture(textura);
        sprite.setScale(0.15,0.15);
    }
    void setup_ovni(){
        textura_ovni.loadFromFile("C:\\\\Users\\\\sotom\\\\CLionProjects\\\\Allego\\\\Source\\\\balas.png");
        sprite.setTexture(textura_ovni);
        sprite.setScale(0.15,0.15);
    }

};



#endif //ALLEGO_BALA_H
