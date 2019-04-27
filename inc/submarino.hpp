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
    Submarino(int coordenadaColuna, int coordenadaLinha, string direcao);
    ~Submarino();

    int afundaSubmarino(int coordenadaLinha, int coordenadaColuna, vector<vector<string>> mapa);
    
};

#endif
