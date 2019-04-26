#include "embarcacoes.hpp"
#include "submarino.hpp"
#include "mapa.hpp"	
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <vector>

using namespace std;

Submarino::Submarino(){
    set_casas(2);
    set_resistencia(2);
    set_coordenadaColuna(0);
    set_coordenadaLinha(0);
    set_direcao("");
    set_tipo("Submarino");
}

Submarino::Submarino(int coordenadaColuna, int coordenadaLinha, string direcao){
    set_casas(4);
    set_resistencia(2);
    set_coordenadaColuna(coordenadaColuna);
    set_coordenadaLinha(coordenadaLinha);
    set_direcao(direcao);
    set_tipo("Submarino");
    tamanhoPosicao();
    set_posicao(coordenadaColuna, coordenadaLinha, direcao);
}
Submarino::~Submarino(){
}
