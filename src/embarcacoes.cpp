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
