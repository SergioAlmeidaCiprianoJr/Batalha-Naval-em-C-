#ifndef MAPA_HPP
#define MAPA_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include "embarcacoes.hpp"
#include "portaAviao.hpp"
#include "submarino.hpp"
#include "canoa.hpp"

using namespace std;

class Mapa {

private:
    int embarcacoesRestantes;
	vector<vector<string>> mapa;

public:
    Mapa();    
    ~Mapa();
    
    void tamanhoMapa(int coluna, int linha);
    vector<vector<string>> get_mapa();
    void set_mapa(int coluna, int linha, string tipo);
    void desenhaMapa();
    int get_embarcacoesRestantes();
    void set_embarcacoesRestantes(int embarcacoesRestantes);
    void posicionaPortaAviao(vector<vector<int>> posicao);
	void posicionaSubmarino(vector<vector<int>> posicao);
	void posicionaCanoa(int coordenadaLinha, int coordenadaColuna);
    void afundaEmbarcacao(int coordenadaLinha, int coordenadaColuna, vector<vector<string>> mapa, Mapa *alvo, Submarino *submarino, PortaAviao *portaAviao, Canoa *canoa);

    
};

#endif