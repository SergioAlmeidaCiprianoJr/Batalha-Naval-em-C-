#include "mapa.hpp"
#include "embarcacoes.hpp"
#include "portaAviao.hpp"
#include "submarino.hpp"
#include "canoa.hpp"
#include "jogador.hpp"
#include "colisao.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <time.h> 

using namespace std;

Colisao::Colisao(){}    
Colisao::~Colisao(){}

void Colisao::posicionaPortaAviao(vector<vector<int>> posicao, Jogador *tamanho){
    for(int coordenada = 0; coordenada<4; coordenada++){
    	tamanho->set_tamanho(posicao[0][coordenada], posicao[1][coordenada], "PortaAviao");
    	tamanho->set_embarcacoesRestantes(1);
    }    
}
void Colisao::posicionaSubmarino(vector<vector<int>> posicao, Jogador *tamanho){
	for(int coordenada = 0; coordenada<4; coordenada++){
    	tamanho->set_tamanho(posicao[0][coordenada], posicao[1][coordenada], "Submarino");
    	tamanho->set_embarcacoesRestantes(1);
    }
}
void Colisao::posicionaCanoa(int coordenadaLinha, int coordenadaColuna, Jogador *tamanho){
	tamanho->set_tamanho(coordenadaLinha, coordenadaColuna, "Canoa");
	tamanho->set_embarcacoesRestantes(1);
}
void Colisao::afundaEmbarcacao(int coordenadaLinha, int coordenadaColuna, Jogador *tamanho, vector<vector<string>> mapa){

	if(mapa[coordenadaLinha][coordenadaColuna] == "Submarino" || mapa[coordenadaLinha][coordenadaColuna] == "atingido"){
		if(mapa[coordenadaLinha][coordenadaColuna] == "Submarino") tamanho->set_tamanho(coordenadaLinha, coordenadaColuna, "atingido");
    	else if(mapa[coordenadaLinha][coordenadaColuna] == "atingido") {
    		tamanho->set_tamanho(coordenadaLinha, coordenadaColuna, "destruido");
    		tamanho->set_embarcacoesRestantes(-1);
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
			tamanho->set_embarcacoesRestantes(-1);
			printf("\tVocê acabou de atingir o Porta Aviões inimigo!!\n");
		}	
	}
	
	if(mapa[coordenadaLinha][coordenadaColuna] == "Canoa"){
		tamanho->set_tamanho(coordenadaLinha, coordenadaColuna, "destruido");
		tamanho->set_embarcacoesRestantes(-1);
		printf("\tVocê acabou de atingir a Canoa inimiga!!\n");
	}
}
