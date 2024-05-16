#pragma once
#include <iostream>
#include <fstream>
#include "labirinto.h"
#include "arquivo.h"
#include "personagem.h"
#include "fantasma.h"
#include "pacman.h"

#define sim 1
#define nao 0

using namespace std;



/*! \class Partida 
* \brief Essa classe tem o objetivo de começar o jogo em si, incluindo as outras classes dentro dela para ter os elementos necessários para o jogo
*/

class Partida {
   
    private:
        int acabou;
        int ganhou;
        


    public:

        /*! Função Partida
        * \brief Esse construtor tem as instâncias associadas se a partida acabou ou não e se o jogador ganhou ou não
        */
        Partida();
        
        /*! Função ~Partida
        * \brief Esse destrutor indica que a partida acabou
        */
        ~Partida();


        /*! Função getSatatus
        * \brief Esse função informa a situação da partida
        * \return a função retona 1 se a partida já acabou e zero se não acabou
        */
        int  getStatus();


        /*! Função começa_jogo
        * \brief Essa função tem como objetivo executar o jogo propriamente dito
        * Ela é responsável por chamar as funções da classe arquivo, do labirinto, além chamar a função que movimenta o jogadore e os fantasmas da classe perdonagem.
        * A função também conta a pontuação do jogador e indica se ele perdeu ou ganhou o jogo
        * \param arquivo_nome O parãmetro da função é o nome do arquivo passado na linha de comando que tem o labirinto do jogo
        */
        void comeca_jogo(char* arquivo_nome);
   
};
