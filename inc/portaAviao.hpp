#ifndef PORTAAVIAO_HPP
#define PORTAAVIAO_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <vector>

using namespace std;

class PortaAviao: public Embarcacoes {

public:
    PortaAviao(); 
    ~PortaAviao();

    int afundaEmbarcacao(int coordenadaLinha, int coordenadaColuna, vector<vector<string>> mapa);

};

#endif
