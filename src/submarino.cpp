#include "embarcacoes.hpp"
#include "submarino.hpp"
#include "mapa.hpp"	
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;

Submarino::Submarino(){
    set_casas(2);
    set_resistencia(2);
    set_coordenadaColuna(0);
    set_coordenadaLinha(0);
    set_direcao("");
    set_tipo('s');
    //cout << "portaAviao criada com sucesso!!!!\n";
}

Submarino::~Submarino(){
    //cout << "portaAviao destruída com sucesso!!!!\n";
}

void Submarino::resisteMissil(int coordenadaColuna, int coordenadaLinha){
    if(tamanho[coordenadaLinha][coordenadaColuna] == 's') tamanho[coordenadaLinha][coordenadaColuna] = 'a';
    else if(tamanho[coordenadaLinha][coordenadaColuna] == 'a') tamanho[coordenadaLinha][coordenadaColuna] = 'd';    
}

int* Submarino::get_posicao(){
    return *posicao;
}
void Submarino::set_posicao(int coordenadaColuna, int coordenadaLinha, string direcao){
    for(int eixoCoordenada = 0; eixoCoordenada<2; eixoCoordenada++){
        for(int coordenada = 0; coordenada<2; coordenada++){
             if(eixoCoordenada == 0){
                 if(direcao == "direita"){
                    posicao[eixoCoordenada][coordenada] = coordenadaLinha;
                    coordenadaLinha++;
                 }
                 else if(direcao == "esquerda"){
                    posicao[eixoCoordenada][coordenada] = coordenadaLinha;
                    coordenadaLinha--;
                 }
                 else if(direcao == "cima" || direcao == "baixo"){
                    posicao[eixoCoordenada][coordenada] = coordenadaLinha;
                 }
             }    
             else if(eixoCoordenada == 1){
                 if(direcao == "baixo"){
                    posicao[eixoCoordenada][coordenada] = coordenadaColuna;
                    coordenadaColuna++;
                 }
                 else if(direcao == "cima"){
                    posicao[eixoCoordenada][coordenada] = coordenadaColuna;
                    coordenadaColuna--;
                 }
                 else if(direcao == "direita" || direcao == "esquerda"){
                    posicao[eixoCoordenada][coordenada] = coordenadaColuna;
                 }
             }
        }
    }
}
