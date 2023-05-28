#pragma once
#include <iostream>
#include "personagem.h"
#include "random"



/*! \class Fantasma
* \brief Essa classe é responsável por controlar um dos personagens do jogo: o fantasma
*/

class Fantasma:public Personagem {
	


	public:

                /*! Função Fantasma
                * \brief Esse construtor herda as características da classe personagem para caracterizar o fantasma
                * \param x o parametro que indica a linha que o personagem está
                * \param y o parametro que indica a coluna que o personagem está
                * \param labirinto_atual o parametro que indica o labirinto do jogo
                */
                Fantasma (int x, int y, Labirinto* labirinto_atual);

               
                /*! Função ~Fantasma
                * \brief Esse destrutor indica que o fantasma morreu
                */
                ~Fantasma();


                /*! Função mov_aleatorio
                * \brief Essa função tem o objetivo de gerar um char aleatório dentre os caracteres que indicam a 
                * a direção do movimento do personagem para movimentar o fantasma
                * \return Esa função retorna um dos caracteres do vetor [a,s,w,d] de forma pseudo-aleatória 
                */
		char mov_aleatorio();
                
};
