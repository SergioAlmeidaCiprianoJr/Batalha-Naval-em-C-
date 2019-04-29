#include "mapa.hpp"
#include "embarcacoes.hpp"
#include "portaAviao.hpp"
#include "submarino.hpp"
#include "canoa.hpp"
#include "jogador.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

Jogador::Jogador(){
	nome = "";
    set_embarcacoesRestantes(0);
    tamanhoMapa(13, 13);
}
Jogador::Jogador(string nome){
	set_nome(nome);
    set_embarcacoesRestantes(0);
    tamanhoMapa(13, 13);
}
Jogador::~Jogador(){
}

string Jogador::get_nome(){
	return nome;
}
void Jogador::set_nome(string nome){
	this->nome = nome;
}
bool Jogador::condicaoVitoria(){
	if(get_embarcacoesRestantes() == 0){
		cout << "Parabéns " << nome << ", você GANHOUUUUUU!!!\n";
		return true;
	}
	else return false;
}
