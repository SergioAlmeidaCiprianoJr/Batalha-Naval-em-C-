#include "mapa.hpp"
#include "embarcacoes.hpp"
#include "portaAviao.hpp"
#include "submarino.hpp"
#include "canoa.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

Mapa::Mapa(){
    //tamanho[linha][coluna]
    embarcacoesRestantes = 0;
    tamanhoMapa(13, 13);
    //cout << "Mapa criado com sucesso!!!!\n";
}

Mapa::~Mapa(){
    //cout << "Mapa deletado com sucesso!!!!\n";
}

void Mapa::tamanhoMapa(int coluna, int linha){
    mapa.resize(coluna);
    for(int i = 0 ; i < coluna ; ++i)
    {
        mapa[i].resize(linha);
    }
}

vector<vector<string>> Mapa::get_mapa(){
    return mapa;
}

void Mapa::set_mapa(int coluna, int linha, string tipo){
    this->mapa[coluna][linha] = tipo;
}

int Mapa::get_embarcacoesRestantes(){
    return embarcacoesRestantes;
}

void Mapa::set_embarcacoesRestantes(int embarcacoesRestantes){
    this->embarcacoesRestantes += embarcacoesRestantes; 
}

void Mapa::desenhaMapa(){
	
	cout << "\033[2J\033[1;1H";//limpando terminal	
    int colunaAtual = 0;
	printf("\n\t00  01  02  03  04  05  06  07  08  09  10  11  12\n    00  ");
	
    for(int linha = 0; linha<13; linha++){
        for(int coluna = 0; coluna<13; coluna++){
            if(mapa[linha][coluna] == "atingido") printf("øøø "); //atingido       
            else if(mapa[linha][coluna] == "destruido") printf("*** "); //destruído
            else printf("~~~ ");
        }
        cout << endl;
        colunaAtual++;
        if(linha!=12) printf("    %02d  ", colunaAtual);
        else cout << endl;
    }
    
}
