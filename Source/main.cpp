#include <iostream>
#include <array>
#include <chrono>
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;

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

class Enemigo{
private:
    Bala bala_nave;
    sf::Texture textura;
    enum direccion{
        RIGHT,DOWN,LEFT
    };
    direccion dir;
public:
    sf::Sprite sprite;
    bool error;
    Enemigo(){
        textura.loadFromFile("C:\\\\Users\\\\sotom\\\\CLionProjects\\\\Allego\\\\Source\\\\ovni.png");
        sprite.setTexture(textura);
        sprite.setScale(0.2,0.2);

    }
    void movimiento(short n){
        dir = static_cast<direccion>(n);
        switch (dir) {
            case RIGHT:
                sprite.move(0.1,0);
            case DOWN:
                sprite.move(0,0.1);
            case LEFT:
                sprite.move(-0.1,0);
                break;
        }
    }
    int limites(){
        //1=izq
        //2=dere
        //cout<<"Limites: "<<sprite.getPosition().x<<endl;
        if(sprite.getPosition().x<=202){
            //cout<<"entro"<<1<<endl;
            return 1;
        }
        else if(sprite.getPosition().x>=740){
            //cout<<"entro"<<2<<endl;
            return 2;
        }
        else{
            //cout<<"entro"<<0<<endl;
            return 0;
        }
    }

    bool choque_ovni_bala(Bala bala_nave){
        //posicion x e y de la nave//generar colicion
        if(bala_nave.sprite.getPosition().x== sprite.getPosition().x && bala_nave.sprite.getPosition().y== sprite.getPosition().y){
            return true;
        }
        return false;
    }

};

class Enemigo;
class Objeto{
private:
    sf::Texture textura;
public:
    Bala bala_ovni;
    Enemigo enemigo;
    bool muerte=false;
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

    void muerte_jugador(Bala& bala_ovni){
        if(bala_ovni.sprite.getGlobalBounds().intersects(sprite.getGlobalBounds())){
            muerte=true;
            cout<<"Jugador muerto"<<endl;
        }
    }

    void muerte_tocar(Enemigo& enemigo){
        if(enemigo.sprite.getGlobalBounds().intersects(sprite.getGlobalBounds())){
            muerte=true;
            cout<<"Jugador muerto al tocar ovni"<<endl;
        }
    }



};





Objeto nave;
//vector<Bala> balas;
//vector<bool> balas_pare;
bool disparo=false;
Bala *bala;
bool disparo_ovni=false;
Bala *bala_ovni;
Enemigo *enemy;
bool derecha=true;
bool libre=true;
//vector<Enemigo> enemigos;
void gameplay();
void crear_balas();
void crear_enemigos();
int enemigos_maximos=30;
int velocidad=0.01;
void iniciar_enemigos();

int main() {
    srand (time(NULL));
    iniciar_enemigos();

//    for(int i=0;i<enemigos_maximos;i++){
//        if(i==(valor-1)){
//            enemy[i].sprite.move(10,0);
//
//        }
//        else if(i==(valor+valor-1)){
//
//        }
//        else{
//            enemy[i].sprite.move(10,0);
//
//        }
//    }

    sf::RenderWindow Ventana(sf::VideoMode(800,600),"Juego",sf::Style::Default);
    //limite
    Ventana.setFramerateLimit(30);

    //texturaDA
    sf::Texture textura;
    textura.loadFromFile("C:\\Users\\sotom\\CLionProjects\\Allego\\Source\\fondo.jpg");
    sf::Sprite background_sprite;
    background_sprite.setTexture(textura);

    sf::Text text;
    text.setString("Perdiste");
    text.setCharacterSize(42);
    text.setColor(sf::Color::Red);
    //text.setStyle(sf::Text::Bold);
    text.setPosition(Ventana.getPosition().x/2,Ventana.getPosition().y/2);

    //sf::Texture textura;
//
//    textura.loadFromFile("C:\\\\Users\\\\sotom\\\\CLionProjects\\\\Allego\\\\Source\\\\ovni.png");
//    sf::Sprite sprite;
//    sprite.setTexture(textura);
//    sprite.setScale(0.2,0.2);
    //textura;

    while(Ventana.isOpen()){
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
            Ventana.draw(enemy[i].sprite);
        }
        //Ventana.draw(enemy.sprite);

        if(nave.muerte){
            cout<<"Entro"<<endl;
            Ventana.draw(text);
        }
        Ventana.display();
    }
//    do{
//        Ventana.clear();
//        Ventana.draw(background_sprite);
//        Ventana.draw(sprite);
//        Ventana.display();
//
//        sf::Event _event;
//        //ventana funcional,
//        if(Ventana.pollEvent(_event)){
//            switch (_event.type) {
//                case sf::Event::Closed:
//                    Ventana.close();
//                default:
//                    break;
//            }
//        }
//    }while(Ventana.isOpen());
}
void crear_balas(){
    bala=new Bala[1];
}
void crear_balas_ovni(){
    bala_ovni=new Bala[1];
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
void gameplay(){
    //cout<<"x: "<<nave.sprite.getPosition().x<<" Y: "<<nave.sprite.getPosition().y<<endl;
//moverse
    //nave.posicion();
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::J)){//disparo
//        //cout<<balas.size()<<endl;
//        Bala bal;
//        balas.push_back(bal);
//        for(int i=0;i<balas.size();i++){
//            balas[i].sprite.setPosition(nave.sprite.getPosition().x-10,nave.sprite.getPosition().y);
//            balas_pare.push_back(0);
//        }
//    }
//    if(!balas_pare.empty()){
//        for(int i=0;i<balas_pare.size();i++){
//            if(balas_pare[i]){
//                balas[i].sprite.move(0,2);
//            }
//        }
//    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::J)){//disparo
        disparo=true;
        crear_balas();
        bala[0].setup();
        bala[0].sprite.setPosition(nave.sprite.getPosition().x+10,nave.sprite.getPosition().y);
    }
    if(disparo){
        bala[0].sprite.move(0,-4);
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
    }
    //disparar enemigos

    if(libre){
        disparo_ovni=true;
        int random=rand()%30;
        //cout<<random<<endl;
        crear_balas_ovni();
        bala_ovni[0].setup_ovni();
        bala_ovni[0].sprite.setPosition(enemy[random].sprite.getPosition().x,enemy[random].sprite.getPosition().y+10);

        libre=false;
    }
    //cout<<bala_ovni[0].sprite.getPosition().y<<endl;
    if(disparo_ovni){
        bala_ovni[0].sprite.move(0,4);
        if(bala_ovni[0].sprite.getPosition().y>=600){
            delete[] bala_ovni;
            //cout<<"bala muerta"<<endl;
//            cout<<bala_ovni[0].sprite.getPosition().y<<endl;
            disparo_ovni=false;
            libre=true;
        }

    }
    /// choque
    for(int i=0;i<enemigos_maximos;i++){
        if(enemy[i].choque_ovni_bala(bala[0])){
            cout<<"Choca"<<endl;
           // delete[ enemy[i];
        }
    }
    //verificar muerte juagdor

    nave.muerte_jugador(bala_ovni[0]);




    //mover ovni
//    for(int i=0;i<enemigos_maximos;i++){
//        if(enemy[i].limites()==1){
//            for(int j=0;j<enemigos_maximos;j++){
//                enemy[i].sprite.move(0.005,40);
//            }
//            derecha=false;
//            break;
//        }
//        else if(enemy[i].limites()){
//            for(int j=0;j<enemigos_maximos;j++)
//                enemy[i].sprite.move(-0.005,40);
//            derecha=false;
//            break;
//        }
//    }
//
//    for(int i=0;i<enemigos_maximos;i++){
//        if(derecha)
//            enemy[i].sprite.move(-0.005,0);
//        else
//            enemy[i].sprite.move(0.005,0);
//    }
//

    //enemy.movimiento(1);
//    for(int i=0;i<enemigos_maximos;i++){
//        enemy[i].sprite.setPosition();
//    }

};