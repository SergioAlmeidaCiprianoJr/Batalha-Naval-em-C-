#include "mapa.hpp"
#include "portaAviao.hpp"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Mapa::Mapa(){
    tamanho[13][13] = {};
	//tamanho[linha][coluna]
    embarcacoesRestantes = 0;
    //cout << "Mapa criado com sucesso!!!!\n";
}

Mapa::~Mapa(){
    //cout << "Mapa deletado com sucesso!!!!\n";
}

int Mapa::get_embarcacoesRestantes(){
    return embarcacoesRestantes;
}
void Mapa::set_embarcacoesRestantes(int embarcacoesRestantes){
    this->embarcacoesRestantes = embarcacoesRestantes; 
}
void Mapa::desenhaMapa(){

    int colunaAtual = 0;
	printf("\n\t00  01  02  03  04  05  06  07  08  09  10  11  12\n    00  ");
	
    for(int linha = 0; linha<13; linha++){
        for(int coluna = 0; coluna<13; coluna++){
            if(tamanho[linha][coluna] == -1) printf("øøø "); //atingido       
            if(tamanho[linha][coluna] == -2) printf("*** "); //destruído
            else printf("~~~ ");
        }
        cout << endl;
        colunaAtual++;
        if(linha!=12) printf("    %02d  ", colunaAtual);
        else cout << endl;
    }
    
}
void Mapa::posicionaEmbarcacao(int coordenadaLinha, int coordenadaColuna, int tamanhoEmbarcacao, string direcao, int resistencia){

}
void Mapa::afundaEmbarcacao(int coordenadaLinha, int coordenadaColuna, int tamanhoEmbarcacao, string direcao, int resistencia){
    
}
