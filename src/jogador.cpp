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
bool Jogador::condicaoVitoria(int embarcacoesRestantesInimigo){
	if(embarcacoesRestantesInimigo == 0){
		cout << "Parabéns " << nome << ", você GANHOUUUUUU!!!\n\n\n";
		return true;
	}
	else return false;
}

int Jogador::rodada(Jogador *defesa, Submarino *submarino, PortaAviao *portaAviao, Canoa *canoa){
	defesa->desenhaMapa();
	cout << get_nome() << " esse é o mapa do seu oponente!!" << endl;
	cout << "Vida " << get_nome() << ": " << get_embarcacoesRestantes() << endl;
	cout << "Vida " << defesa->get_nome() << ": " << defesa->get_embarcacoesRestantes() << endl;
	cout << "Digite 2 coordenadas(linha e coluna, respectivamente) para destruir a embarcação inimiga: ";
	int linha,coluna;
	cin >> linha >> coluna;
	//testando se a entrada é válida ou não
	while(linha>=13 || linha<0 || coluna>=13 || coluna<0){
		cout << "As coordenadas só podem ser de 0 até 12, por favor digite entradas válidas: ";
		cin >> linha >> coluna;
	}
	afundaEmbarcacao(linha, coluna, defesa->get_mapa(), defesa, submarino, portaAviao, canoa);
	if(condicaoVitoria(defesa->get_embarcacoesRestantes())){
		cout << "Deseja voltar ao MENU[S/N]: ";
		string entrada;
		cin >> entrada;
		if(entrada == "S" || entrada == "s") {
			return 1;
		}	
		else {
			cout << "\033[2J\033[1;1H";
			return 0;
		}
		return 0;
	}
	return -1;
}
