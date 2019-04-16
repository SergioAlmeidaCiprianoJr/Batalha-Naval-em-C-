#include "mapa.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <utility>

using namespace std;

Mapa::Mapa(){
    tamanho[13][13] = {};
    embarcacoesRestantes = 0;
    cout << "Mapa criado com sucesso!!!!\n";
}

Mapa::~Mapa(){
    cout << "Mapa deletado com sucesso!!!!\n";
}

int Mapa::get_embarcacoesRestantes(){
    return embarcacoesRestantes;
}
void Mapa::set_embarcacoesRestantes(int embarcacoesRestantes){
    this->embarcacoesRestantes = embarcacoesRestantes; 
}
void Mapa::desenhaMapa(){
	printf("\t~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~\n\t");
    for(int linha = 0; linha<13; linha++){
        for(int coluna = 0; coluna<13; coluna++){
            if(tamanho[linha][coluna] == -1) printf("***");
            else printf("    ");
        }
        printf("\n");
        printf("\t~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~\n");
        if(linha!=12) printf("\t");
    }
}
void Mapa::posicionaEmbarcacao(int coordenadaX, int coordenadaY, int tamanhoEmbarcacao, string direcao){

}
void Mapa::afundaEmbarcacao(int coordenadaX, int coordenadaY, int tamanhoEmbarcacao, string direcao){
    
}
