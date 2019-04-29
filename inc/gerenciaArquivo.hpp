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
    GerenciaArquivo(string arquivo);    
    ~GerenciaArquivo();
    
    string get_arquivo();
    void set_arquivo(string arquivo);
    void leituraLixo(int linhas);
    int leituraCoordenadaLinha();
    int leituraCoordenadaColuna();
    string leituraEmbarcacao();
    string leituraDirecao();
};

#endif
