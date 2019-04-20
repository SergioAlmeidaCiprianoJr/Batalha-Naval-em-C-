#include "embarcacoes.hpp"
#include "portaAviao.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;

PortaAviao::PortaAviao(){
    set_casas(4);
    set_resistencia(1);
    set_coordenadaColuna(0);
    set_coordenadaLinha(0);
    set_direcao("");
    posicao[2][4] = {};
    set_tipo('p');
    //cout << "portaAviao criada com sucesso!!!!\n";
}

PortaAviao::PortaAviao(int coordenadaColuna, int coordenadaLinha, string direcao){
    set_casas(4);
    set_resistencia(1);
    set_coordenadaColuna(coordenadaColuna);
    set_coordenadaLinha(coordenadaLinha);
    set_direcao(direcao);
    posicao[2][4] = {};
    set_tipo('p');
}

PortaAviao::~PortaAviao(){
    //cout << "portaAviao destruída com sucesso!!!!\n";
}

int PortaAviao::desviaMissil(){
    if(rand()%2==0) return true;
    else return false;
}
int* PortaAviao::get_posicao(){
    return *posicao;
}
void PortaAviao::set_posicao(int coordenadaColuna, int coordenadaLinha, string direcao){
    for(int eixoCoordenada = 0; eixoCoordenada<2; eixoCoordenada++){
        for(int coordenada = 0; coordenada<4; coordenada++){
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
