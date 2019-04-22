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

Mapa::Mapa(){
    //tamanho[linha][coluna]
    embarcacoesRestantes = 0;
    //cout << "Mapa criado com sucesso!!!!\n";
}

Mapa::~Mapa(){
    //cout << "Mapa deletado com sucesso!!!!\n";
}

void Mapa::tamanhoMapa(int coluna, int linha){
    tamanho.resize(coluna);
    for(int i = 0 ; i < coluna ; ++i)
    {
        tamanho[i].resize(linha);
    }
}

vector<vector<char>> Mapa::get_tamanho(){
    return tamanho;
}

void Mapa::set_tamanho(int coluna, int linha, char tipo){
    this->tamanho[coluna][linha] = tipo;
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
            if(tamanho[linha][coluna] == 'a') printf("øøø "); //atingido       
            if(tamanho[linha][coluna] == 'd') printf("*** "); //destruído
            else printf("~~~ ");
        }
        cout << endl;
        colunaAtual++;
        if(linha!=12) printf("    %02d  ", colunaAtual);
        else cout << endl;
    }
    
}
