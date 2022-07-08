//
// Created by sotom on 07/07/2022.
//

#ifndef ALLEGO_OBJETO_H
#define ALLEGO_OBJETO_H
#include <array>
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>

#include <SFML/Audio.hpp>
#include<stdio.h>
#include "Windows.h"
#include<ctime>

#include "Enemigo.h"
#include "Bala.h"

using namespace std;
//
//class Objeto{
//private:
//    sf::Texture textura;
//public:
//    int vida=50;
//    bool muerte=false;
//    sf::Sprite sprite;
//    int quita=25;
//    Objeto(){
//        textura.loadFromFile("C:\\\\Users\\\\sotom\\\\CLionProjects\\\\Allego\\\\Source\\\\nave.png");
//        sprite.setTexture(textura);
//        sprite.setScale(0.2,0.2);
//
//        sprite.setPosition(400,520);
//
//
//    }
//    bool posicion(){
//
//
//
//        if(sprite.getPosition().x>=4 && sprite.getPosition().x<=560){
//
//            return true;
//
//        }
//        else if(sprite.getPosition().x<100){
//            sprite.move(-0.05,0);
//        }
//        else if(sprite.getPosition().x>100){
//            sprite.move(0.05,0);
//        }
//
//
//    }
//
//
//    void muerte_jugador(Bala& bala_ovni){
//        if(bala_ovni.sprite.getGlobalBounds().intersects(sprite.getGlobalBounds())){
//
//            //cout<<"vida: "<<vida<<endl;
//
//            vida=vida-quita;
//            //cout<<"vida: "<<vida<<endl;
//            if(vida<=0){
//                muerte=true;
//                //cout<<"Jugador muerto"<<endl;
//            }
//        }
//    }
//
//    void muerte_tocar(Enemigo& enemigo){
//        if(enemigo.sprite.getGlobalBounds().intersects(sprite.getGlobalBounds())){
//            vida=vida-quita;
//            if(vida<=0){
//                muerte=true;
//                //cout<<"Jugador muerto al tocar ovni"<<endl;
//            }
//        }
//    }
//
//
//
//};
//
//
//


#endif //ALLEGO_OBJETO_H
