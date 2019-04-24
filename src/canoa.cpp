#include "embarcacoes.hpp"
#include "canoa.hpp"
#include "mapa.hpp"	
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <vector>

using namespace std;

Canoa::Canoa(){
    set_casas(2);
    set_resistencia(2);
    set_coordenadaColuna(0);
    set_coordenadaLinha(0);
    set_direcao("");
    set_tipo("Canoa");
    //cout << "Canoa criada com sucesso!!!!\n";
}
Canoa::Canoa(int coordenadaColuna, int coordenadaLinha, string direcao){
    set_casas(1);
    set_resistencia(1);
    set_coordenadaColuna(coordenadaColuna);
    set_coordenadaLinha(coordenadaLinha);
    set_direcao(direcao);
    set_tipo("Canoa");
}

Canoa::~Canoa(){
    //cout << "Canoa destruída com sucesso!!!!\n";
}
