#include "pacman.h"



using namespace std;

#define MORTO 0
#define VIVO 1



    Pacman::Pacman(int x, int y, Labirinto* labirinto_atual) : Personagem(x, y, 'C', labirinto_atual){

    }

    Pacman::~Pacman(){
        status = MORTO; 
    }

    int Pacman::getStatus() {
        return status;
    }







