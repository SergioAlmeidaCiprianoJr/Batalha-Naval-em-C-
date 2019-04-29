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
int GerenciaArquivo::leituraCoordenadaLinha(){
	int linha;
	file >> linha;
	return linha;
}
int GerenciaArquivo::leituraCoordenadaColuna(){
	int coluna;
	file >> coluna;
	return coluna;
}
string GerenciaArquivo::leituraEmbarcacao(){
	string embarcacao;
	file >> embarcacao;
	return embarcacao;
}
string GerenciaArquivo::leituraDirecao(){
	string direcao;
	file >> direcao;
	return direcao;
}
