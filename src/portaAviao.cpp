#include "embarcacoes.hpp"
#include "portaAviao.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <vector>

using namespace std;

PortaAviao::PortaAviao(){
    set_casas(4);
    set_resistencia(1);
    set_coordenadaColuna(0);
    set_coordenadaLinha(0);
    set_direcao("");
    set_tipo("PortaAviao");
}

PortaAviao::PortaAviao(int coordenadaColuna, int coordenadaLinha, string direcao){
    set_casas(4);
    set_resistencia(1);
    set_coordenadaColuna(coordenadaColuna);
    set_coordenadaLinha(coordenadaLinha);
    set_direcao(direcao);
    set_tipo("PortaAviao");
    tamanhoPosicao();
    set_posicao(coordenadaColuna, coordenadaLinha, direcao);
}

PortaAviao::~PortaAviao(){
}
