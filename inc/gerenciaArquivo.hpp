#ifndef GERENCIAARQUIVO_HPP
#define GERENCIAARQUIVO_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <vector>

using namespace std;

class GerenciaArquivo {

private:
	string arquivo;

public:
    GerenciaArquivo();
    GerenciaArquivo(string arquivo);    
    ~GerenciaArquivo();
    
    string get_arquivo();
    void set_arquivo(string arquivo);
    void leituraLixo(int numerolinhas);//ignora algumas linhas do arquivo inuteis para criar o mapa
    void leitura(Jogador *jogador, Submarino *submarino, PortaAviao *portaAviao);

};

#endif
