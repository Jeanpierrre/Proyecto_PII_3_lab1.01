//
// Created by sotom on 08/07/2022.
//

#ifndef ALLEGO_ENEMIGO_H
#define ALLEGO_ENEMIGO_H
#include <iostream>
#include <array>
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <SFML/Audio.hpp>
#include<stdio.h>
#include<stdlib.h>
#include "Windows.h"
#include<ctime>
#include "Bala.h"
#include "Objeto.h"
using namespace std;
//
//class Enemigo{
//private:
//    Bala bala_nave;
//    sf::Texture textura;
//public:
//    sf::Sprite sprite;
//    bool muerte_enemigo=true;
//    bool error;
//    Enemigo(){
//        textura.loadFromFile("C:\\\\Users\\\\sotom\\\\CLionProjects\\\\Allego\\\\Source\\\\ovni.png");
//        sprite.setTexture(textura);
//        sprite.setScale(0.2,0.2);
//
//    }
//
//    int limites(){
//        if(sprite.getPosition().x<=202){
//            return 1;
//        }
//        else if(sprite.getPosition().x>=740){
//            return 2;
//        }
//        else{
//            return 0;
//        }
//    }
//
//    bool muerte_ovni_bala(Bala& bala_nave){
//        if(bala_nave.sprite.getGlobalBounds().intersects(sprite.getGlobalBounds())){
//            muerte_enemigo=false;
//
//            return 1;
//            cout<<"Enemigo muerto"<<endl;
//        }
//        return 0;
//    }
//
//};
//





#endif //ALLEGO_ENEMIGO_H
