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

using namespace std;

Colisao::Colisao(){}    
Colisao::~Colisao(){}

void Colisao::posicionaPortaAviao(vector<vector<int>> posicao, Mapa *tamanho){
    for(int coordenada = 0; coordenada<4; coordenada++){
    	tamanho->set_tamanho(posicao[0][coordenada], posicao[1][coordenada], 'p');
    }    
}
void Colisao::posicionaSubmarino(vector<vector<int>> posicao, Mapa *tamanho){
	for(int coordenada = 0; coordenada<4; coordenada++){
    	tamanho->set_tamanho(posicao[0][coordenada], posicao[1][coordenada], 's');
    }
}
void Colisao::posicionaCanoa(int coordenadaLinha, int coordenadaColuna, Mapa *tamanho){
	tamanho->set_tamanho(coordenadaLinha, coordenadaColuna, 'c');
}
void Colisao::afundaEmbarcacao(int coordenadaLinha, int coordenadaColuna, Mapa *tamanho, vector<vector<char>> mapa){

}
