#ifndef PORTAAVIAO_HPP
#define PORTAAVIAO_HPP

#include "embarcacoes.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;

class PortaAviao: public Embarcacoes {

private:
    int posicao[2][4];

public:
    PortaAviao(); 
    PortaAviao(int coordenadaColuna, int coordenadaLinha, string direcao);
    ~PortaAviao();
    
    int desviaMissil();
    int* get_posicao();
    void set_posicao(int coordenadaColuna, int coordenadaLinha, string direcao);
};

#endif
