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
    tamanhoPosicao();
}
Submarino::~Submarino(){
}

int Submarino::afundaEmbarcacao(int coordenadaLinha, int coordenadaColuna, vector<vector<string>> mapa){
    if(mapa[coordenadaLinha][coordenadaColuna] == "Submarino") return -1;//atingido
    else if(mapa[coordenadaLinha][coordenadaColuna] == "atingido") {
        printf("\tVocê acabou de atingir o submarino inimigo!!\n");
        return 0;//destruído
    }
    return 1;
}
