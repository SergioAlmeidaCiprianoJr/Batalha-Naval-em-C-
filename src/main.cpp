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
	arquivo.leitura(&jogador1, &submarino, &portaAviao);
	
	//escaneando e posicionando barcos no mapa do jogador2
	arquivo.leituraLixo(5);
	arquivo.leitura(&jogador2, &submarino, &portaAviao);

	while(1){

		break;
	}

    return 0;
}
