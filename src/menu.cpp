#include "menu.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <unistd.h>

using namespace std;

Menu::Menu(){}  
Menu::~Menu(){}

string entrada;

void Menu::limpaTela(){
    cout << "\033[2J\033[1;1H";//limpando terminal 
}

void Menu::desenhaTitulo(){
    limpaTela();
    cout << endl;
    cout<<"                                 @@@  @@@                                                      @@@@"<<endl;
    cout<<"@@@@@@@                          @@   @@                     @@@   @@@                         @@@ "<<endl;
    cout<<"@@@  @@              @           @@   @@                     @@@   @@                          @@  "<<endl;
    cout<<"@@  @@@             @            @@   @@                     @@@   @@                          @@ "<<endl;
    cout<<"@@   @@             @            @@   @@                     @@@   @@                          @@  "<<endl;
    cout<<"@@   @@            @@            @@   @@                     @@@@  @@                          @@  "<<endl;
    cout<<"@@   @@    @@@@   @@@@@  @@@@    @@   @@@@@     @@@@         @ @@  @@   @@@@ @@@@@@@@  @@@@    @@  "<<endl;
    cout<<"@@  @@@   @@  @@   @@   @@  @@   @@   @@  @@   @@  @@        @ @@  @@  @  @@  @@@  @@ @@  @@   @@   "<<endl;
    cout<<"@@@@@@    @@  @@   @@   @@  @@   @@   @@  @@@  @@  @@        @ @@  @@ @@@  @@ @@@  @  @@@ @@   @@  "<<endl;
    cout<<"@@   @@@  @@  @@   @@   @@  @@   @@   @@  @@@  @@  @@        @  @@ @@ @@@  @@  @@  @  @@@ @@   @@   "<<endl;
    cout<<"@@    @@  @@ @@@   @@   @@ @@@   @@   @@  @@@  @@ @@@        @  @@ @@  @ @@@@  @@ @@   @ @@@   @@ "<<endl;
    cout<<"@@    @@@  @@ @@   @@    @@ @@   @@   @@  @@@   @@ @@        @  @@ @@  @@@ @@  @@ @    @@@@@   @@"<<endl;
    cout<<"@@    @@@@@@  @@   @@  @@@  @@   @@   @@  @@@ @@@  @@        @  @@@@@ @@@  @@   @@@   @@  @@   @@"<<endl;
    cout<<"@@    @@@@@   @@   @@  @@   @@   @@   @@  @@@ @@   @@        @   @@@@ @@   @@   @@@  @@@  @@   @@ "<<endl;
    cout<<"@@    @@@@@   @@ @ @@  @@   @@ @ @@  @@@  @@@ @@   @@ @      @   @@@@ @@  @@@@  @@@  @@@  @@@@ @@@"<<endl;
    cout<<"@@    @@@@@   @@ @ @@  @@   @@ @ @@  @@@  @@@ @@   @@ @      @   @@@@ @@  @@@@  @@@  @@@  @@@@ @@@ " <<endl;
    cout<<"@@    @@@ @@@@ @@@ @@   @@@@ @@@@@@@ @@@@@@@@@ @@@@ @@@      @   @@@@ @@@@@@@@  @@    @@@@@@@@@@@@ "<<endl;
    cout<<"@@    @@           @@  @                                     @    @@@ "<<endl;
    cout<<"@@@    @@            @@@@                                    @    @@@   "<<endl;
    cout<<"@@@   @@                                                     @@   @@@ "<<endl;
    cout<<"@@@@@@@                                                      @@@   @@@   "<<endl<<endl<<endl;
             
}   

bool Menu::desenhaMenu(){

    desenhaTitulo();
    cout << "MENU:" << endl << endl;
    cout << "1. Jogar" << endl;
    cout << "2. Regras" << endl;
    cout << "3. Sair" << endl<<endl; 

    cout << "Escolha: ";
    cin >> entrada;
    regras(entrada);
    //esse if serve para sair após entrar em regras
    if(entrada == "2. Regras" || entrada == "2" || entrada == "Regras" || entrada == "regras") return 1;
    cout << entrada << endl;
    if(iniciaJogo(entrada)) return 0;
    else if(encerraJogo(entrada)) return 1;
    else {
        cout << "Entrada Inválida!!!! Tente novamente" << endl;
        sleep(1.5);
        desenhaMenu();
    }
    return 0;
}
bool Menu::iniciaJogo(string entrada){
    if(entrada == "1. Jogar" || entrada == "1" ||entrada == "Jogar" || entrada == "jogar") {
        limpaTela();
        return 1;
    }    
    else return 0;
}
void Menu::regras(string entrada){
    if(entrada == "2. Regras" || entrada == "2" || entrada == "Regras" || entrada == "regras"){
        limpaTela();
        cout << "REGRAS:" << endl << endl;
        cout << "1.Cada jogador define seu nome e a posição de cada embarcação" << endl;
        cout << "2.Para definir a posição das embarcações basta alterar os arquivos na pasta 'doc', ou inserir um novo" << endl;
        cout << "3.Um navio só pode ser posicionado na vertical ou horizontal" << endl;
        cout << "4.Ao começo de cada turno o jogador deverá definir a posição no mapa em que deseja lançar o míssil(linha e coluna)" << endl;
        cout << "5.Cada embarcação possui tamanhos e habilidades diferentes" << endl; 
        cout << "6.O símbolo '~~~' refere-se às ondas, o 'øøø' significa atingido e '***' significa destruído" << endl << endl;
        cout << "Deseja voltar ao MENU[S/N]: ";
        cin >> entrada;
        if(entrada == "S" || entrada == "s") {
            limpaTela();
            desenhaMenu();
        }
        else{
            limpaTela();  
        }
    }
}
bool Menu::encerraJogo(string entrada){
    if(entrada == "3. Sair" || entrada == "3" || entrada == "Sair" || entrada == "sair") {
        limpaTela(); 
        return 1;
    }    
    else return 0;
}