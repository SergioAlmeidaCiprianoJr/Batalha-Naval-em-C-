#ifndef CANOA_HPP
#define CANOA_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <vector>

using namespace std;

class Canoa: public Embarcacoes{

public:
    Canoa(); 
    ~Canoa();

    int afundaEmbarcacao(int coordenadaLinha, int coordenadaColuna, vector<vector<string>> mapa);
    
};

#endif
