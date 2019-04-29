#include "embarcacoes.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <vector>

using namespace std;

Embarcacoes::Embarcacoes(){
    casas = 0;
    resistencia = 0;
    coordenadaColuna = 0;
    coordenadaLinha = 0;
    direcao = "";
    tipo = "";
    //cout << "Embarcacao criada com sucesso!!!!\n";
}

Embarcacoes::~Embarcacoes(){
    //cout << "Embarcacao destruída com sucesso!!!!\n";
}

int Embarcacoes::get_casas(){
    return casas;
}
void Embarcacoes::set_casas(int casas){
    this->casas = casas;
}
int Embarcacoes::get_resistencia(){
    return resistencia;
}
void Embarcacoes::set_resistencia(int resistencia){
    this->resistencia = resistencia;
}
int Embarcacoes::get_coordenadaColuna(){
    return coordenadaColuna;
}
void Embarcacoes::set_coordenadaColuna(int coordenadaColuna){
    this->coordenadaColuna = coordenadaColuna;
}
int Embarcacoes::get_coordenadaLinha(){
    return coordenadaLinha;
}
void Embarcacoes::set_coordenadaLinha(int coordenadaLinha){
    this->coordenadaLinha = coordenadaLinha;
}
string Embarcacoes::get_tipo(){
    return tipo;
}
void Embarcacoes::set_tipo(string tipo){
    this->tipo = tipo;
}
string Embarcacoes::get_direcao(){
    return direcao;
}
void Embarcacoes::set_direcao(string direcao){
    this->direcao = direcao;
}
void Embarcacoes::tamanhoPosicao(){
    posicao.resize(2);
    for(int i = 0 ; i < 2 ; ++i)
    {
        posicao[i].resize(get_casas());
    }
    //posicao[abscissas][coordenadas]
}
vector<vector<int>> Embarcacoes::get_posicao(){
    return posicao;
}
void Embarcacoes::set_posicao(int coordenadaColuna, int coordenadaLinha, string direcao){
    for(int eixoCoordenada = 0; eixoCoordenada<2; eixoCoordenada++){
        for(int coordenada = 0; coordenada<get_casas(); coordenada++){
             if(eixoCoordenada == 0){
                 if(direcao == "baixo"){
                    posicao[eixoCoordenada][coordenada] = coordenadaLinha;
                    coordenadaLinha++;
                 }
                 else if(direcao == "cima"){
                    posicao[eixoCoordenada][coordenada] = coordenadaLinha;
                    coordenadaLinha--;
                 }
                 else if(direcao == "direita" || direcao == "esquerda"){
                    posicao[eixoCoordenada][coordenada] = coordenadaLinha;
                 }
             }    
             else if(eixoCoordenada == 1){
                 if(direcao == "direita"){
                    posicao[eixoCoordenada][coordenada] = coordenadaColuna;
                    coordenadaColuna++;
                 }
                 else if(direcao == "esquerda"){
                    posicao[eixoCoordenada][coordenada] = coordenadaColuna;
                    coordenadaColuna--;
                 }
                 else if(direcao == "cima" || direcao == "baixo"){
                    posicao[eixoCoordenada][coordenada] = coordenadaColuna;
                 }
             }
        }
    }
}    

int Embarcacoes::afundaEmbarcacao(int coordenadaLinha, int coordenadaColuna, vector<vector<string>> mapa){
    if(mapa[coordenadaLinha][coordenadaColuna] == "Embarcacao"){
		printf("\tVocê acabou de destruir a Embarcacao inimiga!!\n");
        return 0;//atingiu
	}
    return 1;
}
