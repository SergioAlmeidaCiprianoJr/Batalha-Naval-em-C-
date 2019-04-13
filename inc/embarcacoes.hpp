#ifndef EMBARCACOES_HPP
#define EMBARCACOES_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <utility>

using namespace std;

class Embarcacoes {

private:
    int tamanho;
    int resistencia;
    pair<int, int> coordenadas;
    string direcaoDoBarco;

public:
    Embarcacoes();    
    ~Embarcacoes();
    
    int get_tamanho();
    void set_tamanho(int tamanho);
    int get_resistencia();
    void set_resistencia(int resistencia);
    pair<int, int> get_coordenadas();
    void set_coordenadas(int x, int y);
    string get_direcaoDoBarco();
    void set_direcaoDoBarco(string direcaoDoBarco);
    
};

#endif
