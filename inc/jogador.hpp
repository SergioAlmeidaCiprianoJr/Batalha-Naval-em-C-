#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <vector>

using namespace std;

class Jogador: public Mapa {

private:
	string nome;
	
public:
    Jogador(); 
    Jogador(string nome);   
    ~Jogador();
    
	string get_nome();
	void set_nome(string nome);
    bool condicaoVitoria(int embarcacoesRestantesInimigo);
    int rodada(Jogador *defesa, Submarino *submarino, PortaAviao *portaAviao, Canoa *canoa);
    
};

#endif
