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
    
    void posicionaPortaAviao(vector<vector<int>> posicao, Jogador *tamanho);
	void posicionaSubmarino(vector<vector<int>> posicao, Jogador *tamanho);
	void posicionaCanoa(int coordenadaLinha, int coordenadaColuna, Jogador *tamanho);
	void afundaEmbarcacao(int coordenadaLinha, int coordenadaColuna, Jogador *tamanho, vector<vector<string>> mapa);
    
};

#endif
