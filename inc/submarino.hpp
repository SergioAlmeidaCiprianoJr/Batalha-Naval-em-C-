#ifndef SUBMARINO_HPP
#define SUBMARINO_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <vector>

using namespace std;

class Submarino: public Embarcacoes {

public:
    Submarino();    
    ~Submarino();
    
    int afundaEmbarcacao(int coordenadaLinha, int coordenadaColuna, vector<vector<string>> mapa);

};

#endif
