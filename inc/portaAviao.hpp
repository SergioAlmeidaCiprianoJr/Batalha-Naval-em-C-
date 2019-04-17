#ifndef PORTAAVIAO_HPP
#define PORTAAVIAO_HPP

#include "embarcacoes.hpp"
#include <iostream>

using namespace std;

class PortaAviao: public Embarcacoes {

private:

	int habilidade;

public:
    PortaAviao();    
    ~PortaAviao();
    
    int get_habilidade();
    void set_habilidade(int rodada);
    
};

#endif
