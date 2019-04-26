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

void Colisao::posicionaPortaAviao(vector<vector<int>> posicao, Jogador *MapaJogador){
    for(int coordenada = 0; coordenada<4; coordenada++){
    	MapaJogador->set_mapa(posicao[0][coordenada], posicao[1][coordenada], "PortaAviao");
    	MapaJogador->set_embarcacoesRestantes(1);
    }    
}
void Colisao::posicionaSubmarino(vector<vector<int>> posicao, Jogador *MapaJogador){
	for(int coordenada = 0; coordenada<4; coordenada++){
    	MapaJogador->set_mapa(posicao[0][coordenada], posicao[1][coordenada], "Submarino");
    	MapaJogador->set_embarcacoesRestantes(1);
    }
}
void Colisao::posicionaCanoa(int coordenadaLinha, int coordenadaColuna, Jogador *MapaJogador){
	MapaJogador->set_mapa(coordenadaLinha, coordenadaColuna, "Canoa");
	MapaJogador->set_embarcacoesRestantes(1);
}
void Colisao::afundaEmbarcacao(int coordenadaLinha, int coordenadaColuna, Jogador *MapaJogador, vector<vector<string>> mapa){
	//Afunda submarino
	if(mapa[coordenadaLinha][coordenadaColuna] == "Submarino" || mapa[coordenadaLinha][coordenadaColuna] == "atingido"){
		if(mapa[coordenadaLinha][coordenadaColuna] == "Submarino") MapaJogador->set_mapa(coordenadaLinha, coordenadaColuna, "atingido");
    	else if(mapa[coordenadaLinha][coordenadaColuna] == "atingido") {
    		MapaJogador->set_mapa(coordenadaLinha, coordenadaColuna, "destruido");
    		MapaJogador->set_embarcacoesRestantes(-1);
			printf("\tVocê acabou de atingir o submarino inimigo!!\n");
		}
	}
	//Afunda PortaAviao
	if(mapa[coordenadaLinha][coordenadaColuna] == "PortaAviao"){
		bool desvia = false;
		srand (time(NULL));
		int probabilidadeDesviar = rand() % 2 + 1;
		if(probabilidadeDesviar%2 == 0) {
			desvia = true;
			printf("\tVocê achou o Porta Aviões, mas ele desviou seu míssil!!\n");
		}	
		else if(!desvia) {
			MapaJogador->set_mapa(coordenadaLinha, coordenadaColuna, "destruido");
			MapaJogador->set_embarcacoesRestantes(-1);
			printf("\tVocê acabou de atingir o Porta Aviões inimigo!!\n");
		}	
	}
	//Afunda canoa
	if(mapa[coordenadaLinha][coordenadaColuna] == "Canoa"){
		MapaJogador->set_mapa(coordenadaLinha, coordenadaColuna, "destruido");
		MapaJogador->set_embarcacoesRestantes(-1);
		printf("\tVocê acabou de atingir a Canoa inimiga!!\n");
	}
}
