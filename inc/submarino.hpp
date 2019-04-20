#ifndef SUBMARINO_HPP
#define SUBMARINO_HPP

#include "embarcacoes.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;

class Submarino: public Embarcacoes {

private:
	int posicao[2][2];

public:
    Submarino();    
    ~Submarino();
    
    void resisteMissil(int coordenadaColuna, int coordenadaLinha);
    int* get_posicao();
    void set_posicao(int coordenadaColuna, int coordenadaLinha, string direcao);
    
};

#endif
