#include "menu.h"
#include <iostream>

Menu::Menu(MainWindow &newWindow)
    : window(newWindow)
{
}

Menu::~Menu()
{
}

bool Menu::show()
{
    window.draw();
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

void Menu::addWindow()
{
    std::cout<<"Adding subwindow "<<std::endl;
    std::cout<<"Enter name: "<<std::endl;
    std::string name;
    std::cin>>name;
    std::cout << "Enter position (format: x y):" << std::endl;
    int x = 0, y = 0;
    std::cin >> x >> y;
    std::cout << "Enter size (format: w h):" << std::endl;
    int h = 0, w = 0;
    std::cin >> w >> h;
    ResizableWindow* newWindow = new ResizableWindow(x, y, name, w, h);
    window << newWindow;
    std::cout<<"Successful adding"<<std::endl;
}

void Menu::changePosition()
{
    ResizableWindow* selectedWindow = chooseWindow();
    std::cout<<"Enter the dx and dy: ";
    int dx = 0, dy = 0;
    std::cin >> dx >> dy;
    selectedWindow->move(dx, dy);
}


void Menu::changeSize() {
    ResizableWindow* selectedWindow = chooseWindow();
    std::cout<<"Enter the dw and dh: ";
    int dw, dh;
    std::cin >> dw >> dh;
    selectedWindow->changeSize(dw, dh);
}

ResizableWindow* Menu::findWindow(const std::string &name)
{
//    if (name.empty())
//        return static_cast<ResizableWindow*>(window);
//    else
//    {
//        auto children = window.getChildren();
//        for (auto childWindow = children.begin(); childWindow != children.end(); ++childWindow)
//        {
//            if ((*childWindow)->getName() == name)
//                return *childWindow;
//        }
//        return nullptr;
//    }
}

ResizableWindow* Menu::chooseWindow()
{
    std::string name;
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
        return nullptr;
    }
    return findWindow(name);
}
