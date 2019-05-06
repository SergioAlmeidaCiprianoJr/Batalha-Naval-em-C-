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

int rodada(Jogador *ataque, Jogador *defesa, Submarino *submarino, PortaAviao *portaAviao, Canoa *canoa, Menu *menu);

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

		//turnos
		int turno = 0;
		//fim
		int fim = -1; // se for 1 -> reinicia e se for 0 -> sai do jogo

		while(1){
			if(turno%2==0){
				//turno do jogador1
				fim = rodada(&jogador1, &jogador2, &submarino, &portaAviao, &canoa, &menu);
				if(fim ==-1) sleep(2.5);
			}
			else{
				//turno do jogador2
				fim = rodada(&jogador2, &jogador1, &submarino, &portaAviao, &canoa, &menu);
				if(fim ==-1) sleep(2.5);
			}
			if(fim!=-1) break;
			turno++;
		}
		if(fim == 0) break;
	}

    return 0;
}

int rodada(Jogador *ataque, Jogador *defesa, Submarino *submarino, PortaAviao *portaAviao, Canoa *canoa, Menu *menu){
	defesa->desenhaMapa();
	cout << ataque->get_nome() << " esse é o mapa do seu oponente!!" << endl;
	cout << "Vida " << ataque->get_nome() << ": " << ataque->get_embarcacoesRestantes() << endl;
	cout << "Vida " << defesa->get_nome() << ": " << defesa->get_embarcacoesRestantes() << endl;
	cout << "Digite 2 coordenadas(linha e coluna, respectivamente) para destruir a embarcação inimiga: ";
	int linha,coluna;
	cin >> linha >> coluna;
	//testando se a entrada é válida ou não
	while(linha>=13 || linha<0 || coluna>=13 || coluna<0){
		cout << "As coordenadas só podem ser de 0 até 12, por favor digite entradas válidas: ";
		cin >> linha >> coluna;
	}
	ataque->afundaEmbarcacao(linha, coluna, defesa->get_mapa(), defesa, submarino, portaAviao, canoa);
	if(ataque->condicaoVitoria(defesa->get_embarcacoesRestantes())){
		cout << "Deseja voltar ao MENU[S/N]: ";
		string entrada;
		cin >> entrada;
		if(entrada == "S" || entrada == "s") {
			return 1;
		}	
		else {
			menu->limpaTela();
			return 0;
		}
		return 0;
	}
	return -1;
}