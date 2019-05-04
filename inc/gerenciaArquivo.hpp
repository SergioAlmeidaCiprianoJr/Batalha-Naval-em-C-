#ifndef GERENCIAARQUIVO_HPP
#define GERENCIAARQUIVO_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <vector>

using namespace std;

class GerenciaArquivo {

public:
    GerenciaArquivo();
    GerenciaArquivo(string arquivo);    
    ~GerenciaArquivo();
    
    void leituraLixo(string jogador);//ignora algumas linhas do arquivo inuteis para criar o mapa
    void leitura(Jogador *jogador, Submarino *submarino, PortaAviao *portaAviao);

};

#endif
