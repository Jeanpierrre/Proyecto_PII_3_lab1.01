//
// Created by sotom on 08/07/2022.
//

#ifndef ALLEGO_MENU_H
#define ALLEGO_MENU_H
#define MAX_NUMBER_OF_ITEMS 3
#include "SFML/Graphics.hpp"
using namespace std;
class Menu
{
public:
    Menu(float width, float height);
    ~Menu();

    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() { return selectedItemIndex; }

private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];

};


#endif //ALLEGO_MENU_H
