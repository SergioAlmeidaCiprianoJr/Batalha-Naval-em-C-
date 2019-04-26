#ifndef PORTAAVIAO_HPP
#define PORTAAVIAO_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <vector>

using namespace std;

class PortaAviao: public Embarcacoes {

private:
    vector<vector<int>> posicao;

public:
    PortaAviao(); 
    PortaAviao(int coordenadaColuna, int coordenadaLinha, string direcao);
    ~PortaAviao();
    
    void tamanhoPortaAviao(int casas);
    vector<vector<int>> get_posicao();
    void set_posicao(int coordenadaColuna, int coordenadaLinha, string direcao);
};

#endif
