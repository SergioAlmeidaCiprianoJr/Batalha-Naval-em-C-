#ifndef MAPA_HPP
#define MAPA_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <utility>

using namespace std;

class Mapa {

private:
    int tamanho[13][13];
    int embarcacoesRestantes;

public:
    Mapa();    
    ~Mapa();
    
    int get_embarcacoesRestantes();
    void set_embarcacoesRestantes(int embarcacoesRestantes);
    void desenhaMapa();
    void posicionaEmbarcacao(int coordenadaX, int coordenadaY, int tamanho, string direcao);
    void afundaEmbarcacao(int coordenadaX, int coordenadaY, int tamanho, string direcao);
    
};

#endif
