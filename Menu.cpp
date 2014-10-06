#include "Menu.h"
#include <iostream>
#include <list>

Menu::Menu(MainWindow& window)
{
    this->window = &window;
}

bool Menu::show() {
    w->draw();
    std::cout<<std::endl;
    std::cout<<"Choose operation:"<<std::endl;
    std::cout<<"1. Add the window"<<std::endl;
    std::cout<<"2. Change the position"<<std::endl;
    std::cout<<"3. Change the size"<<std::endl;
    std::cout<<"4. Exit"<<std::endl;
    std::cout<<"Type the item number: ";
    int item = 0;
    std::cin>>item;
    switch (item) {
    case 1:
        addWindow();
        break;
    case 2:
        changePosition();
        break;
    case 3:
        changeSize();
        break;
    case 4:
        return false;
    }
    return true;
}

void Menu::addWindow() {
    std::cout<<"Adding subwindow "<<std::endl;
    std::cout<<"Enter name: "<<std::endl;
    string name;
    std::cin>>name;
    std::cout<<"Enter position (format: x y):"<<std::endl;
    int x = 0, y = 0;
    std::cin>>x>>y;
    std::cout<<"Enter size (format: w h):"<<std::endl;
    int h = 0, w = 0;
    std::cin>>w>>h;
    Window* newWindow = new Window(w, h, name);
    newWindow->setPosition(x, y);
    window<<newWindow;
    std::cout<<"Successful adding"<<std::endl;
}

void Menu::changePosition() {
    Window* w = chooseWindow();
    std::cout<<"Enter the dx and dy: ";
    int dx = 0, dy = 0;
    std::cin>>dx>>dy;
    w->move(dx, dy);
}


void Menu::changeSize() {
    Window* w = chooseWindow();
    std::cout<<"Enter the dw and dh: ";
    int dw, dh;
    std::cin>>dw>>dh;
    w->changeSize(dw, dh);
}

Window* Menu::findWindow(string name) {
    if (NULL == name) return window;
    list<Window>* children = window->getChildren();
    list<Window>::iterator i;
    for (i = children->begin(); i != children->end(); i++)
        if ((*i).getName == name)
            return &(*i);
    return NULL;
}

Window* Menu::chooseWindow() {
    string name;
    int item;
    std::cout<<"Choose item:"<<std::endl;
    std::cout<<"1. Main window"<<std::endl;
    std::cout<<"2. Find by name"<<std::endl;
    std::cout<<"Item: ";
    std::cin>>item;
    switch (item) {
    case 1:
        break;
    case 2:
        std::cout<<"Name: ";
        std::cin>>name;
        break;
    default:
        return null;
    }
    return findWindow(name);
}
