#include <iostream>
#include "personagem.h"
#include "labirinto.h"

using namespace std;

#define MORTO 0
#define VIVO 1


    Personagem::Personagem(int x, int y, char sprite, Labirinto* labirinto_atual){
        this->x = x;
        this->y = y;
        this->sprite = sprite;
        this->status= VIVO;
        this->labirinto_atual=labirinto_atual;

    }


    Personagem:: ~Personagem() {
        status = MORTO; 
    }

    void Personagem:: setPosicao(int x, int y) {
        this->x = x;
        this->y = y;
    }




    int  Personagem:: getStatus() {
        return status;
    }


    int  Personagem:: getX() {
        return x;
    }

    int  Personagem:: getY() {
        return y;
    }


    int Personagem::proximo_movimento (char movimento){

        if (movimento =='a'&& this->labirinto_atual->getElemento(x, (y-1 + labirinto_atual->getColunas()) % labirinto_atual->getColunas()) != '*' ){
            
            this->y = (this->y -1+ labirinto_atual->getColunas()) % (labirinto_atual->getColunas());

            return 1;
        }

        else if (movimento =='d' && this->labirinto_atual->getElemento(x, (y+1)  % labirinto_atual->getColunas()) != '*'){
            this->y = (this->y +1) % (labirinto_atual->getColunas());
            return 1;
        }
        

        else if (movimento =='w' && this->labirinto_atual->getElemento((x -1+ labirinto_atual->getLinhas()) % labirinto_atual->getLinhas(), y)!= '*'){
            
            this->x = (this->x -1+ labirinto_atual->getLinhas()) % (labirinto_atual->getLinhas());
            
            return 1;
        }

        else if (movimento =='s' && this->labirinto_atual->getElemento((x +1) % labirinto_atual->getLinhas(), y) != '*'){
            
            this->x = (this->x +1)   % (labirinto_atual->getLinhas());
            return 1;
        }

        return 0;

    }



