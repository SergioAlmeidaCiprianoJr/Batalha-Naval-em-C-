#include "embarcacoes.hpp"
#include "portaAviao.hpp"
#include <iostream>

using namespace std;

PortaAviao::PortaAviao(){
    set_tamanho(0);
    set_resistencia(0);
    set_coordenadaColuna(0);
    set_coordenadaLinha(0);
    set_direcao("");
    //cout << "portaAviao criada com sucesso!!!!\n";
}

PortaAviao::~PortaAviao(){
    //cout << "portaAviao destruída com sucesso!!!!\n";
}

int PortaAviao::get_habilidade(){
    return habilidade;
}
void PortaAviao::set_habilidade(int rodada){
    if(!(rodada%4))    this->habilidade = 1;
    else this->habilidade = 0;
}
