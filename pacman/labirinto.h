#include <iostream>
#pragma once

#define MAX 40

/*! \class Labirinto
* \brief Essa classe é responsável pela montagem do labirinto que corresponde ao tabuleiro do jogo
*/




class Labirinto{
	private:
		int linhas;
		int colunas;
		char** labirinto_atual; 
	
	public:

		/*! Função Labirinto
        * \brief Esse construtor cria um labirinto a partir de uma matriz de caracteres, número de linhas e número de colunas 
        * \param linhas	parametro que representa o número de linhas do labirinto
		* \param colunas parametro que representa o número de colunas do labirinto
		* \param labirinto_atual o parametro que indica uma matriz de caracter que representa o labirinto (com pacdots, paredes e fantasmas)
        */
		Labirinto(int linhas, int colunas, char** labirinto_atual);

  	  	

		/*! Função ~Labirinto
        * \brief Esse destrutor libera o espaço alocado para a matriz de caracter do labirinto
        */
        ~Labirinto();
		


		/*! Função getElemento
        * \brief função que resgata um caracter de uma posição específica da matriz de caracter do labirinto
		* \param x parametro que representa a linha da matriz que o elemento está
		* \param y parametro que representa a coluna da matriz que o elemento está
        * \return A função retorna um char que reprenta o elemnto na linha x e na coluna y da matriz
        */
        char getElemento (int x, int y);


		/*! Função getColunas
        * \brief função que apresenta o número de colunas da matriz de char do labinto
        * \return A função retorna um númnero inteiro que representa o número de colunas do labirinto
        */
        int getColunas();

		/*! Função getLinhas
        * \brief função que apresenta o número de linhas da matriz de char do labinto
        * \return A função retorna um númnero inteiro que representa o número de linhas do labirinto
        */
        int getLinhas();




		/*! Função setElemento
        * \brief função que muda o caracter de uma posição específica da matriz de caracter do labirinto
		* \param x parametro que representa a linha da matriz que o novo elemento vai está
		* \param y parametro que representa a coluna da matriz que o novo elemento vai está
		* \param novo_elemento parametro que representa o novo caracter que vai ficar na posição da linha x e na coluna y
        */
		void setElemento(int x, int y, char novo_elemento);

};
