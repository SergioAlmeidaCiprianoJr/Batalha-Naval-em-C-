#include "mapa.hpp"
#include "embarcacoes.hpp"
#include "portaAviao.hpp"
#include "submarino.hpp"
#include "canoa.hpp"
#include "colisao.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <time.h> 

using namespace std;

Colisao::Colisao(){}    
Colisao::~Colisao(){}

void Colisao::posicionaPortaAviao(vector<vector<int>> posicao, Mapa *tamanho){
    for(int coordenada = 0; coordenada<4; coordenada++){
    	tamanho->set_tamanho(posicao[0][coordenada], posicao[1][coordenada], "PortaAviao");
    }    
}
void Colisao::posicionaSubmarino(vector<vector<int>> posicao, Mapa *tamanho){
	for(int coordenada = 0; coordenada<4; coordenada++){
    	tamanho->set_tamanho(posicao[0][coordenada], posicao[1][coordenada], "Submarino");
    }
}
void Colisao::posicionaCanoa(int coordenadaLinha, int coordenadaColuna, Mapa *tamanho){
	tamanho->set_tamanho(coordenadaLinha, coordenadaColuna, "Canoa");
}
void Colisao::afundaEmbarcacao(int coordenadaLinha, int coordenadaColuna, Mapa *tamanho, vector<vector<string>> mapa){

	if(mapa[coordenadaLinha][coordenadaColuna] == "Submarino" || mapa[coordenadaLinha][coordenadaColuna] == "atingido"){
		if(mapa[coordenadaLinha][coordenadaColuna] == "Submarino") tamanho->set_tamanho(coordenadaLinha, coordenadaColuna, "atingido");
    	else if(mapa[coordenadaLinha][coordenadaColuna] == "atingido") {
    		tamanho->set_tamanho(coordenadaLinha, coordenadaColuna, "destruido");
			printf("\tVocê acabou de atingir o submarino inimigo!!\n");
		}
	}
	if(mapa[coordenadaLinha][coordenadaColuna] == "PortaAviao"){
		bool desvia = false;
		srand (time(NULL));
		int probabilidadeDesviar = rand() % 2 + 1;
		if(probabilidadeDesviar%2 == 0) {
			desvia = true;
			printf("\tVocê achou o Porta Aviões, mas ele desviou seu míssil!!\n");
		}	
		else if(!desvia) {
			tamanho->set_tamanho(coordenadaLinha, coordenadaColuna, "destruido");
			printf("\tVocê acabou de atingir o Porta Aviões inimigo!!\n");
		}	
	}
	
	if(mapa[coordenadaLinha][coordenadaColuna] == "Canoa"){
		tamanho->set_tamanho(coordenadaLinha, coordenadaColuna, "destruido");
		printf("\tVocê acabou de destruir completamente a Canoa inimiga!!\n");
	}
}
