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
    PortaAviao(int coordenadaColuna, int coordenadaLinha, string direcao);
    ~PortaAviao();
    
};

#endif
