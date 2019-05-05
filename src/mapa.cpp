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
    embarcacoesRestantes = 0;
    tamanhoMapa(13, 13);
}

Mapa::~Mapa(){
}

void Mapa::tamanhoMapa(int coluna, int linha){
    mapa.resize(coluna);
    for(int i = 0 ; i < coluna ; ++i)
    {
        mapa[i].resize(linha);
    }

    for(int j = 0 ; j < coluna ; ++j)
    {
        for(int i = 0 ; i < linha ; ++i)
        {
            mapa[j][i] = "desconhecido";
        }
    }
}

vector<vector<string>> Mapa::get_mapa(){
    return mapa;
}

void Mapa::set_mapa(int coluna, int linha, string tipo){
    this->mapa[coluna][linha] = tipo;
}

void Mapa::desenhaMapa(){
	
	cout << "\033[2J\033[1;1H";//limpando terminal	
    int colunaAtual = 0;
	printf("\n\t00  01  02  03  04  05  06  07  08  09  10  11  12\n    00  ");
	
    for(int linha = 0; linha<13; linha++){
        for(int coluna = 0; coluna<13; coluna++){
            if(mapa[linha][coluna] == "atingido") printf("øøø "); //atingido       
            else if(mapa[linha][coluna] == "destruido") printf("*** "); //destruído
            else if(mapa[linha][coluna] == "agua") printf("~~~ ");
            else printf("??? ");
        }
        cout << endl;
        colunaAtual++;
        if(linha!=12) printf("    %02d  ", colunaAtual);
        else cout << endl;
    }
    
}

int Mapa::get_embarcacoesRestantes(){
    return embarcacoesRestantes;
}

void Mapa::set_embarcacoesRestantes(int embarcacoesRestantes){
    this->embarcacoesRestantes += embarcacoesRestantes; 
}

void Mapa::posicionaPortaAviao(vector<vector<int>> posicao){
    for(int coordenada = 0; coordenada<4; coordenada++){
        set_mapa(posicao[0][coordenada], posicao[1][coordenada], "PortaAviao");
    	set_embarcacoesRestantes(1);
    }    
}

void Mapa::posicionaSubmarino(vector<vector<int>> posicao){
	for(int coordenada = 0; coordenada<2; coordenada++){
    	set_mapa(posicao[0][coordenada], posicao[1][coordenada], "Submarino");
    	set_embarcacoesRestantes(1);
    }
}

void Mapa::posicionaCanoa(int coordenadaLinha, int coordenadaColuna){
    set_mapa(coordenadaLinha, coordenadaColuna, "Canoa");
	set_embarcacoesRestantes(1);
}

void Mapa::afundaEmbarcacao(int coordenadaLinha, int coordenadaColuna, vector<vector<string>> mapa, Mapa *alvo, Submarino *submarino, PortaAviao *portaAviao, Canoa *canoa){
    int resultado;
    if(mapa[coordenadaLinha][coordenadaColuna] != "desconhecido"){
        if(mapa[coordenadaLinha][coordenadaColuna] == "destruido") cout << "\nVocê já destruiu essa posição!!\n";
        else if(mapa[coordenadaLinha][coordenadaColuna] == "agua") cout << "\nVocê acertou a água!!!\n";
        else if(mapa[coordenadaLinha][coordenadaColuna] == "PortaAviao") {
            resultado = portaAviao->afundaEmbarcacao(coordenadaLinha, coordenadaColuna, mapa);
            if(!resultado) {
                alvo->set_mapa(coordenadaLinha, coordenadaColuna, "destruido");
                alvo->set_embarcacoesRestantes(-1);
            }    
        }
        else if(mapa[coordenadaLinha][coordenadaColuna] == "Submarino" || mapa[coordenadaLinha][coordenadaColuna] == "atingido") {
            resultado = submarino->afundaEmbarcacao(coordenadaLinha, coordenadaColuna, mapa);
            if(!resultado) {
                alvo->set_mapa(coordenadaLinha, coordenadaColuna, "destruido");
                alvo->set_embarcacoesRestantes(-1);
            }    
            else if(resultado == -1){
                alvo->set_mapa(coordenadaLinha, coordenadaColuna, "atingido");
            }
        }
        else if(mapa[coordenadaLinha][coordenadaColuna] == "Canoa"){
            resultado = canoa->afundaEmbarcacao(coordenadaLinha, coordenadaColuna, mapa);
            if(!resultado) {
                alvo->set_mapa(coordenadaLinha, coordenadaColuna, "destruido");
                alvo->set_embarcacoesRestantes(-1);
            } 
        }
    }
    else{
        alvo->set_mapa(coordenadaLinha, coordenadaColuna, "agua");
        cout << "\nVocê acertou a água!!!\n";
    }
}