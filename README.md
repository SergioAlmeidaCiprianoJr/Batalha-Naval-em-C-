# Batalha Naval

Este projeto consiste em criar um jogo em C++ similar ao game Battleship (ou batalha naval), onde todas suas instruções, dicas e requisitos para a avaliação estão sendo descritos na [wiki](https://gitlab.com/oofga/eps/eps_2019_1/ep1/wikis/home) do repositório.

## Descrição do Projeto

O projeto teve como objetivo construir um jogo de batalha naval para 2 jogadores. O jogo possui dois tabuleiros e as jogadas serão por turno (alternadas). Além disso, o jogo tem 3 tipos de barcos (Submarino, Porta Aviões e Canoa) e as localizações de cada barco serão definidas pelos próprios jogadores antes de começar a partida. O objetivo do jogo é que um dos jogadores destrua todas as embarcações do oponente. Assim, todo turno cada jogador pode lançar um míssil no campo inimigo. 

## Como jogar

* Cada jogador define seu nome e a posição de cada embarcação
* Um navio só pode ser posicionado na vertical ou horizontal
* Ao começo de cada turno o jogador deverá definir a posição no mapa em que deseja lançar o míssil (posição x e y)
* Cada embarcação possui tamanhos e habilidades diferentes

## Embarcações 

As embarcações, diferente do jogo tradicional possuem algumas habilidades especiais.

### Porta Aviões

Um porta-aviões é um navio de guerra cujo papel principal é servir de base aérea móvel. Permite, portanto, que uma força naval possa projetar o seu poder aéreo a grandes distâncias, sem a necessidade de depender de aeroportos para os seus aviões. É uma grande embarcação, ocupa 4 casas no tabuleiro, e com toda a sua tecnologia, consegue abater alguns mísseis antes deles atingirem o navio.

* Quantidade de Casas no Tabuleiro: 4
* Habilidade: Probabilidade de abater mísseis em sua direção, mas mesmo abatendo sua localização será exposta 

### Submarino

Submarino é uma embarcação especializada para operar submersa. Sendo assim, o submarino tem que ser muito resistente, e por isso é necessário 2 mísseis para atingi-lo.

* Quantidade de Casas no Tabuleiro: 2
* Habilidade: Cada casa precisa ser atingida duas vezes para ser abatida

### Canoa

O barco mais frágil, feito de madeira e contendo poucos passageiros, é destruído fácilmente, apenas um míssil em sua localização. Mesmo sendo frágil pode garantir uma vantagem ao ser de difícil localização, já que ocupa apenas uma casa.

* Quantidade de Casas: 1
* Habilidade: Nenhuma

## Instruções para execução do jogo

Após clonar o repositório:

Para compilar:
```
$ make
```

Para rodar:
```
$ make run
```

## Créditos e Contatos

* Sérgio de Almeida Cipriano Júnior (sergiosacj@hotmail.com.br): principal e único programador
* Conceito e regras do projeto [wiki](https://gitlab.com/oofga/eps/eps_2019_1/ep1/wikis/home)





