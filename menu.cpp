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
            std::cout << "Unknown menu item! Please, repeat" << std::endl;
            break;
        }
    }
}

void Menu::addWindow()
{
    std::cout << "Adding subwindow " << std::endl;
    std::cout << "Enter name: " << std::endl;
    const std::string name = getString();

    std::cout << "Enter position (format: x<new line>y):" << std::endl;
    unsigned int x = recognizeInteger(getString());
    unsigned int y = recognizeInteger(getString());

    std::cout << "Enter size (format: w<new line>h):" << std::endl;
    unsigned int width = recognizeInteger(getString());
    unsigned int height = recognizeInteger(getString());

    ResizableWindow* newWindow = new ResizableWindow(x, y, name, width, height);
    mainWindow << newWindow;
    std::cout << "Successful adding" << std::endl;
}

void Menu::changePosition()
{
    ResizableWindow* selectedWindow = chooseWindow();
    std::cout << "Enter the dx and dy (format: dx<new line>dy): ";

    unsigned int dx = recognizeInteger(getString());
    unsigned int dy = recognizeInteger(getString());

    selectedWindow->move(dx, dy);
}


void Menu::changeSize()
{
    ResizableWindow* selectedWindow = chooseWindow();
    std::cout << "Enter the dw and dh (format: dw<new line>dh): ";

    unsigned int dw = recognizeInteger(getString());
    unsigned int dh = recognizeInteger(getString());

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
    std::cout << "Choose item:" << std::endl;
    std::cout << "1. Main window" << std::endl;
    std::cout << "2. Find by name" << std::endl;
    std::cout << "Item: ";

    unsigned int item = recognizeInteger(getString());
    std::string name;
    switch (item) {
    case 1:
        break;
    case 2:
        std::cout << "Name: ";
        name = getString();
        break;
    default:
        return nullptr;
    }
    return findWindow(name);
}

const std::string Menu::getString()
{
    std::string userInput;
    std::cin >> userInput;
    return userInput;
}

unsigned int Menu::recognizeInteger(const std::string &input)
{
    unsigned int item = 0;
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
