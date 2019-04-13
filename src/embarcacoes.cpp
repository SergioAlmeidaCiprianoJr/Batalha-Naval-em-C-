#include "embarcacoes.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <utility>

using namespace std;

Embarcacoes::Embarcacoes(){
    //cout << "Embarcacao criada com sucesso!!!!\n";
}

Embarcacoes::~Embarcacoes(){
    //cout << "Embarcacao destruída com sucesso!!!!\n";
}

int Embarcacoes::get_tamanho(){
    return tamanho;
}
void Embarcacoes::set_tamanho(int tamanho){
    this->tamanho = tamanho;
}
int Embarcacoes::get_resistencia(){
    return resistencia;
}
void Embarcacoes::set_resistencia(int resistencia){
    this->resistencia = resistencia;
}
pair<int, int> Embarcacoes::get_coordenadas(){
    return coordenadas;
}
void Embarcacoes::set_coordenadas(int x, int y){
    this->coordenadas.first = x;
    this->coordenadas.second = y;
}
string Embarcacoes::get_direcaoDoBarco(){
    return direcaoDoBarco;
}
void Embarcacoes::set_direcaoDoBarco(string direcaoDoBarco){
    this->direcaoDoBarco = direcaoDoBarco;
}
