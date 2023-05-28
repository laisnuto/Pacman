#pragma once
#include <iostream>
#include <fstream>
#include "labirinto.h"
#include "fantasma.h"

using namespace std;


/*! \class Arquivo
* \brief Essa classe é responsável pela leitura do arquivo passado na linha de comando e contar os elementos para contruir o tabuleiro do jogo
*/



class Arquivo {
   
    private:
        fstream file_stream;
        Labirinto *labirinto_lido;
        Fantasma* fantasmas_lidos;
        int contador_pacdots;
        int contador_fantasmas;
        Fantasma** vetor_fantasmas;


    public:

        /*! Função Arquivo
        * \brief Esse construtor cria um mebro da classe arquivo a partir do txt lido, além resgatar o labirinto do arquivo,
        * essa função também conta os elementos para construir o retso do jogo como os pacdots e os fantasmas
        * \param filename o parametro que indica o nome do arquivo que vai ser lido
        */
        Arquivo(char* filename);


        /*! Função ~Arquivo
        * \brief Esse é destrutor do arquivo 
        */
        ~Arquivo();



        /*! Função getLabirinto
        * \brief função que a partir do arquivo lido, resgata da classe arquivo o labirinto do jogo
        * \return A função retorna um item da classe labirinto que representa o labirinto contido no arquivo lido
        */
        Labirinto* getLabirinto();

  


        /*! Função getFantasmas
        * \brief função que a partir do arquivo lido, resgata da classe arquivo cada Fantasma que estava no labirinto
        * \return A função retorna um vetor de Fantasmas lidos no arquivo
        */
        Fantasma** getFantasmas(); 

        
        /*! Função getPacdots
        * \brief função que a partir do arquivo lido, conta o número de pacdots
        * \return A função retorna um númnero inteiro que representa o número de pacdots lidos no arquivo
        */
        int getPacdots();
        
        /*! Função conta_fantasmas
        * \brief função que a partir do arquivo lido, conta o número de fantasmas
        * \return A função retorna um númnero inteiro que representa o número de fantasmas lidos no arquivo
        */
        int conta_fantasmas();




};