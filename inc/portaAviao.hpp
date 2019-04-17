#ifndef PORTAAVIAO_HPP
#define PORTAAVIAO_HPP

#include "embarcacoes.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;

class PortaAviao: public Embarcacoes {

public:
    PortaAviao();    
    ~PortaAviao();
    
    int desviaMissil();
    
};

#endif
