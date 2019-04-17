#ifndef EMBARCACOES_HPP
#define EMBARCACOES_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;

class Embarcacoes {

private:
    int tamanho;
    int resistencia;
    int coordenadaColuna;
	int coordenadaLinha;
    string direcao;

public:
    Embarcacoes();    
    ~Embarcacoes();
    
    int get_tamanho();
    void set_tamanho(int tamanho);
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
