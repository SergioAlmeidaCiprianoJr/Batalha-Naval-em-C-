#include "mapa.hpp"
#include "embarcacoes.hpp"
#include "portaAviao.hpp"
#include "submarino.hpp"
#include "canoa.hpp"
#include "jogador.hpp"
#include "gerenciaArquivo.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
ifstream file;

GerenciaArquivo::GerenciaArquivo(){
	arquivo = "";
}

GerenciaArquivo::GerenciaArquivo(string arquivo){
	this->arquivo = arquivo;
	file.open(arquivo);
	if(file.fail()){
		cerr << "Erro ao abrir arquivo\n";
		exit(1);
	}
	leituraLixo(13);
}
GerenciaArquivo::~GerenciaArquivo(){
	file.close();
}

string GerenciaArquivo::get_arquivo(){
	return arquivo;
}
void GerenciaArquivo::set_arquivo(string arquivo){
	this->arquivo = arquivo;
}
void GerenciaArquivo::leituraLixo(int numerolinhas){
	string leLinha;
	for(int i = 0; i<numerolinhas; i++) getline(file, leLinha);
}
void GerenciaArquivo::leitura(Jogador *jogador, Submarino *submarino, PortaAviao *portaAviao){	
	for(int i = 0; i<12; i++){

		int linha;
		int coluna;
		string embarcacao; 
		string direcao;
		file >> linha >> coluna >> embarcacao >> direcao;

		if(embarcacao == "canoa" || embarcacao == "Canoa") {
			jogador->posicionaCanoa(linha, coluna);
		}
		if(embarcacao == "submarino" || embarcacao == "Submarino") {
			submarino->set_posicao(coluna, linha, direcao);
			jogador->posicionaSubmarino(submarino->get_posicao());
		}
		if(embarcacao == "porta-avioes" || embarcacao == "PortaAvioes" || embarcacao == "portaAvioes") {
			portaAviao->set_posicao(coluna, linha, direcao);
			jogador->posicionaPortaAviao(portaAviao->get_posicao());
		}
	}
}
