#ifndef EMBARCACOES_HPP
#define EMBARCACOES_HPP

#include "mapa.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <vector>

using namespace std;

class Embarcacoes {

private:
    int casas;
    int resistencia;
    int coordenadaColuna;
    int coordenadaLinha;
    char tipo;
    string direcao;

public:
    Embarcacoes();    
    ~Embarcacoes();
    
    char get_tipo();
    void set_tipo(char tipo);
    int get_casas();
    void set_casas(int casas);
    int get_resistencia();
    void set_resistencia(int resistencia);
    int get_coordenadaColuna();
    void set_coordenadaColuna(int coordenadaColuna);
    int get_coordenadaLinha();
    void set_coordenadaLinha(int coordenadaLinha);
    string get_direcao();
    void set_direcao(string direcao);
      
};

#endif
