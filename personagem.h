#pragma once
#include <iostream>
#include "labirinto.h"


/*! \class Personagem
* \brief Essa classe é responsável por controlar os personagens do jogo: o pacman e os fantasmas
*/

class Personagem  {
    
    protected:
        int x;
        int y;
        int status;
        char sprite;
        Labirinto* labirinto_atual;
    
    public:


        /*! Função Personagem
        * \brief Esse construtor tem as instâncias associadas a posição x,y do personagem, o seu status se ta vivo ou morto,
        * o caracter que representa o personagem na hora de imprimir o tabuleiro e o labirinto do jogo
        * \param x o parametro que indica a linha que o personagem está
        * \param y o parametro que indica a coluna que o personagem está
        * \param sprite o caracter que representa o personagem (C no caso do pacman e F no Fantasma)
        * \param labirinto_atual o parametro que indica o labirinto do jogo
        */
        Personagem(int x, int y, char sprite, Labirinto* labirinto_atual);

        
        /*! Função ~Personagem
        * \brief Esse destrutor indica que o personagem morreu
        */
        ~Personagem();



        /*! Função setPosicao
        * \brief Esse função seta a posição dos personagens de acordo com os parametro
        * \param x o parametro que indica a linha que o personagem está
        * \param y o parametro que indica a coluna que o personagem está
        */
        void setPosicao(int x, int y);
    

        /*! Função getStatus
        * \brief Essa função tem o objetivo de indicar o status do personagem
        * \return Esta função devolve o número 1 se o personagem está vivo e devolve 0 se estiver morto.
        */
        int getStatus();



        /*! Função getX
        * \brief Essa função tem o objetivo de indicar a linha em que o personagem está
        * \return Esta devolve um número inteiro que indica em qual linha o personagem está no tabuleiro
        */
        int getX();


        /*! Função getY
        * \brief Essa função tem o objetivo de indicar a coluna em que o personagem está
        * \return Esta devolve um número inteiro que indica em qual coluna o personagem está no tabuleiro
        */
        int getY();

        /*! Função proximo_movimento
        * \brief Essa função tem o objetivo de relizar o movimento de um personagem.
        *A função verifica se não tem nenhuma parede no próximo movimento e se o movimento for válido, 
        * ela seta nova posição dos personagens
        * \param movimento Esse caracter indica em qual direção o personagem irá se movem
        * \return Esta devolve um 1 se o movimento do parametro é válido e 0 se não for
        */
        int proximo_movimento (char movimento);

};