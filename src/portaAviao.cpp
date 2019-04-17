#include "embarcacoes.hpp"
#include "portaAviao.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;

PortaAviao::PortaAviao(){
    set_tamanho(4);
    set_resistencia(1);
    set_coordenadaColuna(0);
    set_coordenadaLinha(0);
    set_direcao("");
    //cout << "portaAviao criada com sucesso!!!!\n";
}

PortaAviao::~PortaAviao(){
    //cout << "portaAviao destruída com sucesso!!!!\n";
}

int PortaAviao::desviaMissil(){
    if(rand()%2==0) return true;
    else return false;
}
