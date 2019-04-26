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

GerenciaArquivo::GerenciaArquivo(string arquivo){
	arquivo = arquivo;
	file.open(arquivo);
	if(file.fail()){
		cerr << "Erro ao abrir arquivo\n";
		exit(1);
	}
}
GerenciaArquivo::~GerenciaArquivo(){
	
}

string GerenciaArquivo::get_arquivo(){
	return arquivo;
}
void GerenciaArquivo::set_arquivo(string arquivo){
	this->arquivo = arquivo;
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

