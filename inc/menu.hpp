#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <vector>

using namespace std;

class Menu {

public:
    Menu();    
    ~Menu();
    
    void desenhaTitulo();
    bool desenhaMenu();
    bool iniciaJogo(string entrada);
    void regras(string entrada);
    bool encerraJogo(string entrada);
    
};

#endif