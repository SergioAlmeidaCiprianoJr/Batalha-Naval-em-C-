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
    tamanhoPosicao();
}

PortaAviao::~PortaAviao(){
}

int PortaAviao::afundaEmbarcacao(int coordenadaLinha, int coordenadaColuna, vector<vector<string>> mapa){
    if(mapa[coordenadaLinha][coordenadaColuna] == "PortaAviao"){
            srand (time(NULL));
            int probabilidadeDesviar = rand() % 2 + 1;
            if(probabilidadeDesviar%2 == 0) {
                printf("\tVocê achou o Porta Aviões, mas ele desviou seu míssil!!\n");
                return -1;//não atingiu
            }	
            else {
                printf("\tVocê acabou de atingir o Porta Aviões inimigo!!\n");
                return 0;//atingiu
            }	
    }
    return 1;
}    