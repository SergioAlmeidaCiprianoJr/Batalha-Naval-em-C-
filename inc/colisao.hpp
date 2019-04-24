#ifndef COLISAO_HPP
#define COLISAO_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <vector>

using namespace std;

class Colisao {

public:
    Colisao();    
    ~Colisao();
    
    void posicionaPortaAviao(vector<vector<int>> posicao, Mapa *tamanho);
	void posicionaSubmarino(vector<vector<int>> posicao, Mapa *tamanho);
	void posicionaCanoa(int coordenadaLinha, int coordenadaColuna, Mapa *tamanho);
	void afundaEmbarcacao(int coordenadaLinha, int coordenadaColuna, Mapa *tamanho, vector<vector<string>> mapa);
    
};

#endif
