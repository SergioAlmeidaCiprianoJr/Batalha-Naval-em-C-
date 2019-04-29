#include "mapa.hpp"
#include "menu.hpp"
#include "jogador.hpp"
#include "embarcacoes.hpp"
#include "portaAviao.hpp"
#include "submarino.hpp"
#include "canoa.hpp"
#include "gerenciaArquivo.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main(){
	//Criando Embarcações
	PortaAviao portaAviao;
	Submarino submarino;
	Canoa canoa;

	//desenhando menu
	Menu menu;
	menu.desenhaTitulo();
	if(menu.desenhaMenu()) return 0;
	
	string nomes,entrada;

	//criando jogador1
	cout << "Player1 digite seu nome: ";
	cin >> nomes;
	Jogador jogador1(nomes);
	menu.limpaTela();

	//criando jogador2
	cout << "Player2 digite seu nome: ";
	cin >> nomes;
	Jogador jogador2(nomes);
	menu.limpaTela();

	//criando leitor de arquivo
	cout << "Digite o nome do arquivo do mapa(ele precisa estar na pasta './doc/'): ";
	nomes = "doc/";
	cin >> entrada;
	nomes += entrada;

	//escaneando e posicionando barcos no mapa do jogador1
	GerenciaArquivo arquivo(nomes);
	for(int i = 0; i<12; i++){
		int linha = arquivo.leituraCoordenadaLinha();
		int coluna = arquivo.leituraCoordenadaColuna();
		string embarcacao = arquivo.leituraEmbarcacao();
		string direcao = arquivo.leituraDirecao();
		if(embarcacao == "canoa" || embarcacao == "Canoa") {
			jogador1.posicionaCanoa(linha, coluna);
		}
		if(embarcacao == "submarino" || embarcacao == "Submarino") {
			submarino.set_posicao(coluna, linha, direcao);
			jogador1.posicionaSubmarino(submarino.get_posicao());
		}
		if(embarcacao == "porta-avioes" || embarcacao == "PortaAvioes" || embarcacao == "portaAvioes") {
			portaAviao.set_posicao(coluna, linha, direcao);
			jogador1.posicionaPortaAviao(portaAviao.get_posicao());
		}
	}
	
	//escaneando e posicionando barcos no mapa do jogador2
	arquivo.leituraLixo(5);
	for(int i = 0; i<12; i++){
		int linha = arquivo.leituraCoordenadaLinha();
		int coluna = arquivo.leituraCoordenadaColuna();
		string embarcacao = arquivo.leituraEmbarcacao();
		string direcao = arquivo.leituraDirecao();
		if(embarcacao == "canoa" || embarcacao == "Canoa") {
			jogador2.posicionaCanoa(linha, coluna);
		}
		if(embarcacao == "submarino" || embarcacao == "Submarino") {
			submarino.set_posicao(coluna, linha, direcao);
			jogador2.posicionaSubmarino(submarino.get_posicao());
		}
		if(embarcacao == "porta-avioes" || embarcacao == "PortaAvioes" || embarcacao == "portaAvioes") {
			portaAviao.set_posicao(coluna, linha, direcao);
			jogador2.posicionaPortaAviao(portaAviao.get_posicao());
		}
	}

	while(1){

		break;
	}

    return 0;
}
