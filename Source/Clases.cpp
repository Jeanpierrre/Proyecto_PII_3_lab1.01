//
// Created by sotom on 08/07/2022.
//

#include <iostream>
#include <array>
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>

#include <SFML/Audio.hpp>
#include<stdio.h>
#include<stdlib.h>
#include<ctime>
using namespace std;

class Bala{
private:
    sf::Texture textura;
    sf::Texture textura_ovni;
    bool pare=true;

public:
    sf::Sprite sprite;

    Bala(){
    }
    void setup(){
        textura.loadFromFile("C:\\Users\\sotom\\CLionProjects\\Allego\\Source\\fotos\\bala.png");
        sprite.setTexture(textura);
        sprite.setScale(3,3);
    }
    void setup_ovni(){
        textura_ovni.loadFromFile("C:\\Users\\sotom\\CLionProjects\\Allego\\Source\\fotos\\bala.png");
        sprite.setTexture(textura_ovni);
        sprite.setScale(3,3);
    }

};



class Enemigo{
private:
    Bala bala_nave;
    sf::Texture textura;
public:
    sf::Sprite sprite;
    bool muerte_enemigo=true;
    bool error;
    Enemigo(){
        textura.loadFromFile("C:\\Users\\sotom\\CLionProjects\\Allego\\Source\\fotos\\ovni.png");
        sprite.setTexture(textura);
        sprite.setScale(0.2,0.2);

    }

    int limites(){
        if(sprite.getPosition().x<=202){
            return 1;
        }
        else if(sprite.getPosition().x>=740){
            return 2;
        }
        else{
            return 0;
        }
    }

    bool muerte_ovni_bala(Bala& bala_nave){
        if(bala_nave.sprite.getGlobalBounds().intersects(sprite.getGlobalBounds())){
            muerte_enemigo=false;

            return 1;
            cout<<"Enemigo muerto"<<endl;
        }
        return 0;
    }

};




class Objeto{
private:
    sf::Texture textura;
public:
    int vida=50;
    bool muerte=false;
    sf::Sprite sprite;
    int quita=25;
    Objeto(){
        textura.loadFromFile("C:\\Users\\sotom\\CLionProjects\\Allego\\Source\\fotos\\nave.png");
        sprite.setTexture(textura);
        sprite.setScale(0.2,0.2);

        sprite.setPosition(400,520);


    }
    bool posicion(){



        if(sprite.getPosition().x>=4 && sprite.getPosition().x<=560){

            return true;

        }
        else if(sprite.getPosition().x<100){
            sprite.move(-0.05,0);
        }
        else if(sprite.getPosition().x>100){
            sprite.move(0.05,0);
        }


    }


    void muerte_jugador(Bala& bala_ovni){
        if(bala_ovni.sprite.getGlobalBounds().intersects(sprite.getGlobalBounds())){

            //cout<<"vida: "<<vida<<endl;
                muerte=true;
                //cout<<"Jugador muerto"<<endl;

        }
    }

    void muerte_tocar(Enemigo& enemigo){
        if(enemigo.sprite.getGlobalBounds().intersects(sprite.getGlobalBounds())){

                muerte=true;
                //cout<<"Jugador muerto al tocar ovni"<<endl;

        }
    }



};
