#include "embarcacoes.hpp"
#include "canoa.hpp"
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

Canoa::~Canoa(){
    //cout << "Canoa destruída com sucesso!!!!\n";
}

int Canoa::afundaCanoa(int coordenadaLinha, int coordenadaColuna, vector<vector<string>> mapa){
    if(mapa[coordenadaLinha][coordenadaColuna] == "Canoa"){
		printf("\tVocê acabou de destruir a Canoa inimiga!!\n");
        return 0;//atingiu
	}
    return 1;
}
