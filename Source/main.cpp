#include <iostream>
#include <array>
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "Menu.h"
#include <SFML/Audio.hpp>
#include<stdio.h>
#include<stdlib.h>
#include "Windows.h"
#include<ctime>
#include "Clases.cpp"
#include "Funciones.cpp"
using namespace std;


///variables locales

///clases
Objeto nave;
Bala *bala;
Bala *bala_ovni;
Bala *bala_ovni2;
Enemigo *enemy;

///booleanos
bool disparo=false;
bool disparo_ovni=false;
bool derecha=true;
bool libre=true;
bool tiempo=true;
bool validar=true;
bool juego=true;
bool sonido=true;

///funciones que toman las variables globales
void gameplay();
void crear_balas();
void crear_enemigos();
void iniciar_enemigos();
///valores
int valor=0;
int enemigos_maximos=30;
int velocidad=0.01;


///variables-sonido
sf::SoundBuffer buffer;
sf::Sound sound;

sf::SoundBuffer buffer1;
sf::Sound sound1;

int main() {
    int salir=0;
    int play=0;
    sf::RenderWindow window(sf::VideoMode(600, 600), "Menu");
    Menu menu(window.getSize().x, window.getSize().y);
    sf::SoundBuffer buffer;
    sf::Sound sound;
    if(!buffer.loadFromFile("C:\\Users\\sotom\\CLionProjects\\Allego\\Source\\audios\\menu.wav")){
        cout<<"No carga"<<endl;
    }
    sound.setBuffer(buffer);
    sound.play();
    ///fondo
    sf::Texture textura;
    textura.loadFromFile("C:\\Users\\sotom\\CLionProjects\\Allego\\Source\\fotos\\fondo.png");
    sf::Sprite background_sprite;
    background_sprite.setTexture(textura);

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
                                    play++;
                                    break;
                                case 1:
                                    salir++;
                                    window.close();
                                    break;

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
        window.draw(background_sprite);
        menu.draw(window);

        window.display();
    }

    if(play==1){


    if(!buffer.loadFromFile("C:\\Users\\sotom\\CLionProjects\\Allego\\Source\\audios\\bala.wav")){
        sonido=false;
        cout<<"No carga"<<endl;
    }
    if(!buffer1.loadFromFile("C:\\Users\\sotom\\CLionProjects\\Allego\\Source\\audios\\explosion.wav")){
        sonido=false;
        cout<<"No carga"<<endl;
    }
    sound.setBuffer(buffer);

    sound1.setBuffer(buffer1);


    srand (time(NULL));
    iniciar_enemigos();
    sf::Font tipo_letra;
    tipo_letra.loadFromFile("C:\\Users\\sotom\\CLionProjects\\Allego\\Source\\fuente.otf");
    sf::Text score;
    score.setFont(tipo_letra);
    score.setString(to_string(valor));
    score.setCharacterSize(42);
    score.setColor(sf::Color::Black);
    score.setPosition(500,0);
    //tiempo
    sf::Clock clock;
    sf::Time time;



    sf::RenderWindow Ventana(sf::VideoMode(800,600),"Space Invaders",sf::Style::Default);
    //limite
    Ventana.setFramerateLimit(80);

    //texturaDA
    sf::Texture textura;
    textura.loadFromFile("C:\\Users\\sotom\\CLionProjects\\Allego\\Source\\fotos\\fondo.png");
    sf::Sprite background_sprite;
    background_sprite.setTexture(textura);

    sf::Font tipo;
    tipo.loadFromFile("C:\\Users\\sotom\\CLionProjects\\Allego\\Source\\fuente.otf");
    sf::Text text;
    text.setFont(tipo);
    text.setString("Perdiste");
    text.setCharacterSize(42);
    text.setColor(sf::Color::Red);
    text.setPosition(300,300);


    while(Ventana.isOpen() && juego){
        sf::Text score;
        score.setFont(tipo_letra);
        score.setString(to_string(valor));
        if(tiempo){
            time+=clock.getElapsedTime();
        }
        gameplay();
        sf::Event _event;

        while(Ventana.pollEvent(_event)){
            //cerrar ventana
            if(_event.type==sf::Event::Closed){
                Ventana.close();
            }
        }

        Ventana.clear();
        Ventana.draw(background_sprite);
        Ventana.draw(nave.sprite);
        if(disparo){
            Ventana.draw(bala[0].sprite);
        }
        if(disparo_ovni){
            Ventana.draw(bala_ovni[0].sprite);
        }
        for(int i=0;i<enemigos_maximos;i++){
            if(enemy[i].muerte_enemigo)
                Ventana.draw(enemy[i].sprite);
        }
        if(valor==30){
            if(validar){
                text.setString("Ganaste en un tiempo de: "+ to_string(time.asSeconds()));
                text.setPosition(90,300);
                Ventana.draw(text);
                tiempo=false;
//            cout.flush();
//            usleep(20000000000);
//            auto start = std::chrono::high_resolution_clock::now();
//            this_thread::sleep_for(2000ms);
//            auto end = std::chrono::high_resolution_clock::now();
                juego=false;
                cout<<"Ganaste"<<endl;
                cout<<"Tu tiempo fue de "+to_string(round(time.asSeconds()))<<endl;
                validar=true;
            }

        }

        if(nave.muerte){
            //cout<<"Entro"<<endl
            // ;

                Ventana.draw(text);
                juego=false;
                cout<<"Perdiste"<<endl;
                cout<<"Tu tiempo fue de "+to_string(round(time.asSeconds()/60))<<endl;
                cout<<"Quedaron: "<<enemigos_maximos-valor<<" con vida."<<endl;
                validar=false;
        }
        Ventana.draw(score);
        Ventana.display();
    }
    }

}

void crear_balas();
void crear_balas_ovni();
void crear_balas_ovni2();
///funcion que realiza todo
void gameplay(){

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::J)){//disparo

        disparo=true;
        crear_balas();
        sound.play();
        bala[0].setup();
        bala[0].sprite.setPosition(nave.sprite.getPosition().x,nave.sprite.getPosition().y-30);



    }
    if(disparo){
        bala[0].sprite.move(0,-4);

        if(sonido){
            sound1.play();
        }
        if(bala[0].sprite.getPosition().y<=-20){
            delete[] bala;
            cout<<"bala muerta en:"<<endl;
            cout<<bala[0].sprite.getPosition().y<<endl;
            disparo=false;
        }
    }


    if(nave.posicion()){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){//DERECHA
            nave.sprite.move(6,0);

        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){//IZQUIERDA
            nave.sprite.move(-6,0);

        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){//IZQUIERDA
            nave.sprite.move(0,-6);

        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){//IZQUIERDA
            nave.sprite.move(0,6);

        }
    }
    //disparar enemigos

    if(libre){
        disparo_ovni=true;
        int random=rand()%30;
        //cout<<random<<endl;
        crear_balas_ovni();
        bala_ovni[0].setup_ovni();
        bala_ovni[0].sprite.setPosition(enemy[random].sprite.getPosition().x,enemy[random].sprite.getPosition().y+10);
        int random2=rand()%30;
        crear_balas_ovni2();
        bala_ovni[1].setup_ovni();
        bala_ovni[1].sprite.setPosition(enemy[random2].sprite.getPosition().x,enemy[random2].sprite.getPosition().y+10);
        libre=false;
    }

    if(disparo_ovni){
        bala_ovni[0].sprite.move(0,6);
        if(bala_ovni[0].sprite.getPosition().y>=600){
            delete[] bala_ovni;
            disparo_ovni=false;
            libre=true;
        }
        if(bala_ovni2[0].sprite.getPosition().y>=600){
            delete[] bala_ovni2;
            disparo_ovni=false;
            libre=true;
        }
    }
    ///verificar muerte
    nave.muerte_jugador(bala_ovni[0]);
    for(int i=0;i<enemigos_maximos;i++){
        nave.muerte_tocar(enemy[i]);
    }

    ///verificar muerte ovni
    for(int i=0;i<enemigos_maximos;i++){
        if(disparo){
            if(enemy[i].muerte_ovni_bala(bala[0])){
                //enemy[i].sprite.
                enemy[i].sprite.setPosition(-60,-20);
                valor++;
                delete[] bala;
                disparo=false;
            }
        }
        else
            break;
    }

};

void crear_balas(){
    bala=new Bala[1];

}
void crear_balas_ovni(){
    bala_ovni=new Bala[1];
}
void crear_balas_ovni2(){
    bala_ovni2=new Bala[1];
}
void iniciar_enemigos(){
    bala=new Bala[1];
    bala_ovni=new Bala[1];
    enemy=new Enemigo[enemigos_maximos];
    float *xp=new float[enemigos_maximos];
    float *yp=new float[enemigos_maximos];

    yp[0]=30;
    int valor=enemigos_maximos/3;
    //posicionar con x y Y      y
    //80
    for(int  i=0;i<enemigos_maximos;i++){
        if(10==i || 20==i ||30==i )
            yp[i]=yp[i-1]+80;
        else
            yp[i]=yp[i-1];
    }
    //x
    //85
    for(int  i=0;i<enemigos_maximos;i++){
        xp[i]=xp[i-1]+65;
        if(10==i || 20==i ||30==i ){
            xp[i]=65;//para hacer filas
        }
    }
    //enemy move
    for(int i=0;i<enemigos_maximos;i++){
        enemy[i].sprite.move(xp[i],yp[i]);

    }
}