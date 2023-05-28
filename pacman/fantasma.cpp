
#include "fantasma.h"

#define MORTO 0
#define VIVO 1


using namespace std;



    Fantasma::Fantasma(int x, int y, Labirinto* labirinto_atual) : Personagem(x, y, 'F', labirinto_atual){

    }

    Fantasma::~Fantasma(){
        status = MORTO;
    }

    char Fantasma::mov_aleatorio (){
        int i;
        char movimento;
        char caractere_aleatorio [4];


    
        random_device aleatorio;
        unsigned seed = aleatorio();
        default_random_engine gerador(seed);

        uniform_int_distribution<int> distrI(0, 3);
        i = distrI(gerador);

       
        
       caractere_aleatorio [0]='a';
       caractere_aleatorio [1]='d';
       caractere_aleatorio [2]='w';
       caractere_aleatorio [3]='s';


        movimento = caractere_aleatorio[i];

        return movimento;

    }    




