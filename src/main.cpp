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
#include <unistd.h>

using namespace std;

int main(){
	//loop que reinicia o jogo
	while(1){
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
		getline(cin, nomes);
		Jogador jogador1(nomes);
		menu.limpaTela();

		//criando jogador2
		cout << "Player2 digite seu nome: ";
		getline(cin, nomes);
		Jogador jogador2(nomes);
		menu.limpaTela();

		//criando leitor de arquivo
		cout << "Digite o nome do arquivo do mapa(ele precisa estar na pasta './doc/'): ";
		nomes = "doc/";
		cin >> entrada;
		nomes += entrada;

		//escaneando e posicionando barcos no mapa do jogador1
		GerenciaArquivo arquivo(nomes);
		arquivo.leituraLixo("# player_1");
		arquivo.leitura(&jogador1, &submarino, &portaAviao);
		
		//escaneando e posicionando barcos no mapa do jogador2
		arquivo.leituraLixo("# player_2");
		arquivo.leitura(&jogador2, &submarino, &portaAviao);

		int turno = 0;
		int fim = -1; // se for 1 -> reinicia e se for 0 -> sai do jogo

		while(1){
			if(turno%2==0){
				//turno do jogador1
				fim = jogador1.rodada(&jogador2, &submarino, &portaAviao, &canoa);
				if(fim == -1) sleep(2.5);
			}
			else{
				//turno do jogador2
				fim = jogador2.rodada(&jogador1, &submarino, &portaAviao, &canoa);
				if(fim == -1) sleep(2.5);
			}
			if(fim!=-1) break;
			turno++;
		}
		if(fim == 0) break;
	}

    return 0;
}