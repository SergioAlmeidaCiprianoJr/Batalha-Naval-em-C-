#ifndef MAPA_HPP
#define MAPA_HPP

#include <iostream>
#include <string>
#include <fstream>

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
    void posicionaEmbarcacao(int coordenadaLinha, int coordenadaColuna, int tamanho, string direcao);
    void afundaEmbarcacao(int coordenadaLinha, int coordenadaColuna, int tamanho, string direcao);
    
};

#endif
