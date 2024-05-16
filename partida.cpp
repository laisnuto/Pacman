#include "partida.h"



Partida::Partida (){
    this->acabou = nao;
    this->ganhou = nao;
}

Partida::~Partida (){
    this->acabou = sim;
}


int  Partida:: getStatus() {
    return acabou;
}


void Partida::comeca_jogo(char* arquivo_nome){
    char movimento_pacman;
    char* elemento_anterior;
    int i,j, k;
    int pontos;
    int numero_pacdots;
    int numero_fantasmas;
    Labirinto* labirinto_mapa;
    Fantasma** fantasmas;
    int coordenada_x, coordenada_y;
    Arquivo* arquivo_entrada;
    char mov_ale;
    

    arquivo_entrada = new Arquivo(arquivo_nome);

    labirinto_mapa = arquivo_entrada->getLabirinto();
    numero_fantasmas = arquivo_entrada->conta_fantasmas();
    fantasmas = arquivo_entrada->getFantasmas();
    numero_pacdots= arquivo_entrada->getPacdots();


    coordenada_x= (labirinto_mapa->getLinhas())/2;
    coordenada_y= (labirinto_mapa->getColunas())/2;

  

    Pacman *jogador = new Pacman( coordenada_x, coordenada_y, labirinto_mapa);


    labirinto_mapa->setElemento (jogador->getX(), jogador->getY(), 'C');

    for (i=0; i < labirinto_mapa->getLinhas(); i++){
        for (j=0; j < labirinto_mapa->getColunas(); j++){

            cout << labirinto_mapa->getElemento(i,j) << " ";
        }

        cout << endl;

    }

    elemento_anterior= (char*)malloc(sizeof(char)*numero_fantasmas);

    for (k=0; k< numero_fantasmas; k++){
        elemento_anterior[k]= ' ';
    }


    pontos = 0;

    while(1){

 

        cout << "Direção (a - esquerda, d - direita, w - cima, s - baixo): " << " ";

        cin >> movimento_pacman;

        cout << endl;


        labirinto_mapa->setElemento (jogador->getX(), jogador->getY(), ' ');

       



        for (i=0; i<numero_fantasmas; i++){

            if (elemento_anterior[i]== ' '){
                labirinto_mapa->setElemento (fantasmas[i]->getX(), fantasmas[i]->getY(), ' ');
            }
            else if (elemento_anterior[i]== '.'){
                labirinto_mapa->setElemento (fantasmas[i]->getX(), fantasmas[i]->getY(), '.');
            }


            elemento_anterior[i] = labirinto_mapa->getElemento (fantasmas[i]->getX(), fantasmas[i]->getY());
            mov_ale = fantasmas[i]->mov_aleatorio();
            fantasmas[i]->proximo_movimento(mov_ale);
            elemento_anterior[i] = labirinto_mapa->getElemento (fantasmas[i]->getX(), fantasmas[i]->getY());
            labirinto_mapa->setElemento (fantasmas[i]->getX(), fantasmas[i]->getY(), 'F');
            
        }


        if (labirinto_mapa->getElemento(jogador->getX(), jogador->getY())=='F'){
            labirinto_mapa->setElemento(jogador->getX(), jogador->getY(), 'X');
            jogador->~Pacman();
            break;
        }
        



        jogador->proximo_movimento(movimento_pacman);


        if (labirinto_mapa->getElemento(jogador->getX(), jogador->getY())=='F'){
            labirinto_mapa->setElemento(jogador->getX(), jogador->getY(), 'X');
            jogador->~Pacman();
            break;
        }



        if (labirinto_mapa->getElemento(jogador->getX(), jogador->getY())=='.'){
            labirinto_mapa->setElemento (jogador->getX(), jogador->getY(), 'C');  
            pontos++; 
        }

        if (labirinto_mapa->getElemento(jogador->getX(), jogador->getY())== ' ' ){
            labirinto_mapa->setElemento (jogador->getX(), jogador->getY(), 'C');  

        }




        if (pontos == numero_pacdots){
            this->ganhou = sim;
            break;
        }



        for (i=0; i < labirinto_mapa->getLinhas(); i++){
            for (j=0; j < labirinto_mapa->getColunas(); j++){

            cout << labirinto_mapa->getElemento(i,j) << ' ';
             }

            cout << endl;

        }
        
        cout << endl;




    }



    for (i=0; i < labirinto_mapa->getLinhas(); i++){
        for (j=0; j < labirinto_mapa->getColunas(); j++){

        cout << labirinto_mapa->getElemento(i,j) << ' ';
            }

        cout << endl;

    }
    
    cout << endl;


    

    
    if (pontos == numero_pacdots){
        cout << "Congratulations! Pontos: " << pontos <<endl;
    }


    if (jogador->getStatus()== MORTO){
        cout << "Game over! Pontos: " << pontos << endl;
    }

    labirinto_mapa->~Labirinto();

}

