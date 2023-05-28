#include "labirinto.h"




using namespace std;



Labirinto::Labirinto(int linhas, int colunas, char** labirinto_atual){
	this->linhas= linhas;
	this->colunas= colunas;
	this->labirinto_atual = labirinto_atual;
}

Labirinto::~Labirinto(){
	int i;

	for (i=0; i < linhas; i++){
		free(labirinto_atual[i]);
	}

	free(labirinto_atual);
}

char Labirinto::getElemento (int x, int y){
	return labirinto_atual[x][y];
}


int Labirinto::getColunas(){
	return colunas;
}

int Labirinto::getLinhas(){
	return linhas;
}


void Labirinto::setElemento(int x, int y, char novo_elemento){
	labirinto_atual[x][y]= novo_elemento;
}