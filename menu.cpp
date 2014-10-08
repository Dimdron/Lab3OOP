#include "menu.h"
#include <iostream>

Menu::Menu()
    : mainWindow(0, 0, "Main", MainWindow::minWidth, MainWindow::minHeight)
{
}

Menu::~Menu()
{
}

void Menu::start()
{
    bool continueExecution = true;
    while (continueExecution)
    {
        mainWindow.draw();
        std::cout << std::endl;
        std::cout << "Choose operation:" << std::endl;
        std::cout << "1. Choose window" << std::endl;
        std::cout << "2. Add the subwindow" << std::endl;
        std::cout << "3. Change the window position" << std::endl;
        std::cout << "4. Change the widow size" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Type the item number: ";

        unsigned int item = recognizeInteger(getString());

        switch (item) {
        case 1:
            chooseWindow();
            break;
        case 2:
            addWindow();
            break;
        case 3:
            changePosition();
            break;
        case 4:
            changeSize();
            break;
        case 5:
            continueExecution = false;
            break;
        default:
            std::cout << "Can't recognize input! Please, repeat" << std::endl;
            break;
        }
    }
}

void Menu::addWindow()
{
    std::cout << "Adding subwindow " << std::endl;
    std::cout << "Enter name: " << std::endl;
    std::string name;
    std::cin >> name;
    std::cout << "Enter position (format: x y):" << std::endl;
    int x = 0, y = 0;
    std::cin >> x >> y;
    std::cout << "Enter size (format: w h):" << std::endl;
    int h = 0, w = 0;
    std::cin >> w >> h;
    ResizableWindow* newWindow = new ResizableWindow(x, y, name, w, h);
    mainWindow << newWindow;
    std::cout << "Successful adding" << std::endl;
}

void Menu::changePosition()
{
    ResizableWindow* selectedWindow = chooseWindow();
    std::cout << "Enter the dx and dy: ";
    int dx = 0, dy = 0;
    std::cin >> dx >> dy;
    selectedWindow->move(dx, dy);
}


void Menu::changeSize()
{
    ResizableWindow* selectedWindow = chooseWindow();
    std::cout << "Enter the dw and dh: ";
    int dw, dh;
    std::cin >> dw >> dh;
    selectedWindow->changeSize(dw, dh);
}

ResizableWindow* Menu::findWindow(const std::string &name)
{
    if (name.empty())
        return static_cast<ResizableWindow*>(&mainWindow);
    else
    {
        auto children = mainWindow.getChildren();
        for (auto childWindow = children.cbegin(); childWindow != children.cend(); ++childWindow)
        {
            if ((*childWindow)->getName() == name)
                return *childWindow;
        }
        return nullptr;
    }
}

ResizableWindow* Menu::chooseWindow()
{
    std::string name;
    int item;
    std::cout << "Choose item:" << std::endl;
    std::cout << "1. Main window" << std::endl;
    std::cout << "2. Find by name" << std::endl;
    std::cout << "Item: ";
    std::cin >> item;
    switch (item) {
    case 1:
        break;
    case 2:
        std::cout << "Name: ";
        std::cin >> name;
        break;
    default:
        return nullptr;
    }
    return findWindow(name);
}

const std::string &Menu::getString()
{
    std::string userInput;
    std::cin >> userInput;
    return userInput;
}

unsigned int Menu::recognizeInteger(const std::string &input)
{
    unsigned int item;
    try
    {
        item  = std::stoi(input);
    }
    catch(std::exception &)
    {
        std::cout << "Can't recognize input. Please, repeat" << std::endl;
    }
    return item;
}
