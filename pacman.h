#pragma once
#include <iostream>
#include "personagem.h"

using namespace std;

#define MORTO 0
#define VIVO 1


/*! \class Pacman
* \brief Essa classe é responsável por controlar o pacman
*/

class Pacman: public Personagem{
    
    private:
    Labirinto* labirinto_atual;


    public:
  

      /*! Função Pacman
      * \brief Esse construtor herda as características da classe personagem para caracterizar o pacman
      * \param x o parametro que indica a linha que o personagem está
      * \param y o parametro que indica a coluna que o personagem está
      * \param labirinto_atual o parametro que indica o labirinto do jogo
      */
      Pacman (int x, int y, Labirinto* labirinto_atual);

      /*! Função ~Pacman
      * \brief Esse destrutor indica que o Pacman morreu
      */
      ~Pacman();

      /*! Função getStatus
      * \brief Essa função tem o objetivo de indicar o status do pacman
      * \return Esta função devolve o número 1 se o personagem está vivo e devolve 0 se estiver morto.
      */
      int getStatus();



};