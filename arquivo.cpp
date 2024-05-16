#include "arquivo.h"
#define MAX 40







    Arquivo::Arquivo (char* arq){
        int i, j;
        int contador_linhas;
        int contador_colunas;
        fstream arquivoTabuleiro;
        char** tabuleiro;       
        arquivoTabuleiro.open(arq,ios::in);
        



        tabuleiro= (char**)malloc(sizeof(char*)*MAX);
        vetor_fantasmas= (Fantasma**)malloc(sizeof(Fantasma)*MAX*MAX);

        for (i=0; i<MAX; i++){
            tabuleiro[i]=(char*)malloc(sizeof(char)*MAX);
        }
        
        contador_pacdots=0;
        contador_linhas = 0;
        contador_colunas=0;
        contador_fantasmas = 0;

        while (arquivoTabuleiro.getline(tabuleiro[contador_linhas],MAX)){
            
            contador_linhas++;

    
        }
        
        arquivoTabuleiro.close();



        for (contador_colunas= 0; tabuleiro[0][contador_colunas] != '\0'; contador_colunas++);

        


        labirinto_lido = new Labirinto(contador_linhas, contador_colunas, tabuleiro);        

  
   

        for (i= 0; i< contador_linhas ; i++){
            for (j= 0; j< contador_colunas ; j++){

                if (tabuleiro[i][j] == 'F'){

                    vetor_fantasmas[contador_fantasmas] = new Fantasma(i, j, labirinto_lido);
                    contador_fantasmas++;
                }

                if (tabuleiro[i][j] == '.'){
                    contador_pacdots++ ;
                }
            }
        }

        
    }


    Arquivo::~Arquivo(){}


    Labirinto* Arquivo:: getLabirinto(){
        return labirinto_lido;
    }
        

    Fantasma** Arquivo::getFantasmas(){
        return vetor_fantasmas;
    }


            
    int Arquivo::getPacdots(){
        return contador_pacdots;
    }

    int Arquivo::conta_fantasmas(){
        return contador_fantasmas;
    }

    

        





