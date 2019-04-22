#ifndef SUBMARINO_HPP
#define SUBMARINO_HPP

#include "embarcacoes.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <vector>

using namespace std;

class Submarino: public Embarcacoes {

private:
	vector<vector<int>> posicao;

public:
    Submarino();    
    Submarino(int coordenadaColuna, int coordenadaLinha, string direcao);
    ~Submarino();
    
    void tamanhoSubmarino(int tamanho);
    void resisteMissil(int coordenadaColuna, int coordenadaLinha, vector<vector<char>> tamanho, Mapa *submarino);
    vector<vector<int>> get_posicao();
    void set_posicao(int coordenadaColuna, int coordenadaLinha, string direcao);
};

#endif
