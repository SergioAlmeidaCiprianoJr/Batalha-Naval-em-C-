#ifndef MAPA_HPP
#define MAPA_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;

class Mapa {

private:
    int embarcacoesRestantes;

public:
    char tamanho[13][13];
    
    Mapa();    
    ~Mapa();
    
    int get_embarcacoesRestantes();
    void set_embarcacoesRestantes(int embarcacoesRestantes);
    void desenhaMapa();
    void posicionaEmbarcacao(int *posicao, int resistencia);
    void afundaEmbarcacao(int *posicao, int resistencia);
    
};

#endif
