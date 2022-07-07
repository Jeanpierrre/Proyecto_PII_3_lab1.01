//
// Created by sotom on 07/07/2022.
//

#ifndef ALLEGO_OBJETO_H
#define ALLEGO_OBJETO_H
#include "Enemigo.h"
#include "Bala.h"
#include <array>
#include <chrono>
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
class Objeto{
private:
    sf::Texture textura;
    //Bala *bala_ovni;
public:
    sf::Sprite sprite;

    Objeto(){
        textura.loadFromFile("C:\\\\Users\\\\sotom\\\\CLionProjects\\\\Allego\\\\Source\\\\nave.png");
        sprite.setTexture(textura);
        sprite.setScale(0.2,0.2);

        sprite.setPosition(400,520);

        //limites//  y=560
        //parte izquierda x:4 y y:520
        //parte derecha 712 y 520
    }
    bool posicion(){

//        if(sprite.getPosition().x>=4){
//            sprite.move(-0.05,0);
//        }
//        else if(sprite.getPosition().x<=560){
//            sprite.move(0.05,0);
//
//        }

        if(sprite.getPosition().x>=4 && sprite.getPosition().x<=560){

            return true;

        }
        else if(sprite.getPosition().x<100){
            sprite.move(-0.05,0);
        }
        else if(sprite.getPosition().x>100){
            sprite.move(0.05,0);
        }

        //cout<<"x: "<<sprite.getPosition().x<<" Y: "<<sprite.getPosition().y<<endl;
        //if(sprite.getPosition().x<=)

    }
//    void tocar_enemigo(float& bala, int enemigos_maximos){
//        for(int i=0;i<enemigos_maximos;i++){
//            if()
//        }

//    void muerte_jugador(Bala*& bala_ovni, int max){
//        for(int i=0;i<max;i++){
//            if(bala_ovni[i].spriet){
//
//            }
//
//        }

    //}



};




#endif //ALLEGO_OBJETO_H
