#include "partida.h"
#include <iostream>
#include <gtest/gtest.h>



/*! \class Make_teste
* \brief Essa classe é responsável por realizar os testes das classes do jogo
*/
class Make_test : public ::testing::Test
{

protected:
    Pacman *pacman_teste;
    Arquivo *arquivo_teste;
    Labirinto *labirinto_teste;
    Fantasma **fantasmas_teste;
    Partida* partida_teste;
    Personagem* personagem_teste;
    char *arquivo_nome;


    Make_test()
    {
        arquivo_nome = (char *)"teste.txt";
        arquivo_teste = new Arquivo(arquivo_nome);
        partida_teste = new Partida();
        labirinto_teste = arquivo_teste->getLabirinto();
        fantasmas_teste = arquivo_teste->getFantasmas();
        pacman_teste = new Pacman(labirinto_teste->getLinhas() / 2, labirinto_teste->getColunas() / 2, labirinto_teste);
        delete arquivo_teste;
    }

    ~Make_test()
    {
        int i;

        for (i = 0; i < arquivo_teste->conta_fantasmas(); i++)
        {
            free(fantasmas_teste[i]);
        }
        free(fantasmas_teste);
    }
};

TEST_F(Make_test, FantasmaAndaCerto)
{

    int movimento_valido;
    int xAntes;
    int yAntes;
    int xDepois;
    int yDepois;

    xAntes = fantasmas_teste[0]->getX();
    yAntes = fantasmas_teste[0]->getY();
    movimento_valido = fantasmas_teste[0]->proximo_movimento('d');
    xDepois = fantasmas_teste[0]->getX();
    yDepois = fantasmas_teste[0]->getY();
    if (movimento_valido == 1){
        xDepois = fantasmas_teste[0]->getX();
        yDepois = fantasmas_teste[0]->getY();
        EXPECT_EQ(xDepois - xAntes, 0);
        EXPECT_EQ((yDepois - yAntes + labirinto_teste->getColunas())%labirinto_teste->getColunas() , 1);
    }
    else{
        EXPECT_EQ(xAntes - xDepois, 0);
        EXPECT_EQ(yAntes - yDepois, 0);
    }

    xAntes = fantasmas_teste[0]->getX();
    yAntes = fantasmas_teste[0]->getY();
    movimento_valido = fantasmas_teste[0]->proximo_movimento('a');
    xDepois = fantasmas_teste[0]->getX();
    yDepois = fantasmas_teste[0]->getY();     
    if (movimento_valido == 1){
        xDepois = fantasmas_teste[0]->getX();
        yDepois = fantasmas_teste[0]->getY();
        EXPECT_EQ(xDepois - xAntes, 0);
        EXPECT_EQ((yDepois - yAntes + labirinto_teste->getColunas())%labirinto_teste->getColunas() , labirinto_teste->getColunas()-1);
    }
    else{
        EXPECT_EQ(xAntes - xDepois, 0);
        EXPECT_EQ(yAntes - yDepois, 0);
    }
 
    xAntes = fantasmas_teste[0]->getX();
    yAntes = fantasmas_teste[0]->getY();
    movimento_valido = fantasmas_teste[0]->proximo_movimento('s');
    xDepois = fantasmas_teste[0]->getX();
    yDepois = fantasmas_teste[0]->getY(); 
    if (movimento_valido == 1){
        xDepois = fantasmas_teste[0]->getX();
        yDepois = fantasmas_teste[0]->getY();
        EXPECT_EQ((xDepois - xAntes + labirinto_teste->getLinhas())%labirinto_teste->getLinhas() , 1);
        EXPECT_EQ(yDepois - yAntes, 0);

    }
    else{
        EXPECT_EQ(xAntes - xDepois, 0);
        EXPECT_EQ(yAntes - yDepois, 0);

    }

    xAntes = fantasmas_teste[0]->getX();
    yAntes = fantasmas_teste[0]->getY();
    movimento_valido = fantasmas_teste[0]->proximo_movimento('w');
    xDepois = fantasmas_teste[0]->getX();
    yDepois = fantasmas_teste[0]->getY(); 
    if (movimento_valido == 1){
        xDepois = fantasmas_teste[0]->getX();
        yDepois = fantasmas_teste[0]->getY();
        EXPECT_EQ((xDepois - xAntes + labirinto_teste->getLinhas())%labirinto_teste->getLinhas() , labirinto_teste->getLinhas()-1);
        EXPECT_EQ(yDepois - yAntes, 0);

    }
    else{
        EXPECT_EQ(xAntes - xDepois, 0);
        EXPECT_EQ(yAntes - yDepois, 0);

    }

}



TEST_F(Make_test, PacmanAndaCerto)
{
    int movimento_valido;
    int xAntes;
    int yAntes;
    int xDepois;
    int yDepois;

    xAntes = pacman_teste->getX();
    yAntes = pacman_teste->getY();
    movimento_valido = pacman_teste->proximo_movimento('d');
    xDepois = pacman_teste->getX();
    yDepois = pacman_teste->getY();
    if (movimento_valido == 1){
        xDepois = pacman_teste->getX();
        yDepois = pacman_teste->getY();
        EXPECT_EQ(xDepois - xAntes, 0);
        EXPECT_EQ((yDepois - yAntes + labirinto_teste->getColunas())%labirinto_teste->getColunas() , 1);
    }
    else{
        EXPECT_EQ(xAntes - xDepois, 0);
        EXPECT_EQ(yAntes - yDepois, 0);
    }

    xAntes = pacman_teste->getX();
    yAntes = pacman_teste->getY();
    movimento_valido =  pacman_teste->proximo_movimento('a');
    xDepois = pacman_teste->getX();
    yDepois = pacman_teste->getY();     
    if (movimento_valido == 1){
        xDepois = pacman_teste->getX();
        yDepois = pacman_teste->getY();
        EXPECT_EQ(xDepois - xAntes, 0);
        EXPECT_EQ((yDepois - yAntes + labirinto_teste->getColunas())%labirinto_teste->getColunas() , labirinto_teste->getColunas()-1);
    }
    else{
        EXPECT_EQ(xAntes - xDepois, 0);
        EXPECT_EQ(yAntes - yDepois, 0);
    }
 
    xAntes = pacman_teste->getX();
    yAntes = pacman_teste->getY();
    movimento_valido = pacman_teste->proximo_movimento('s');
    xDepois = pacman_teste->getX();
    yDepois = pacman_teste->getY(); 
    if (movimento_valido == 1){
        xDepois = pacman_teste->getX();
        yDepois = pacman_teste->getY();
        EXPECT_EQ((xDepois - xAntes + labirinto_teste->getLinhas())%labirinto_teste->getLinhas() , 1);
        EXPECT_EQ(yDepois - yAntes, 0);

    }
    else{
        EXPECT_EQ(xAntes - xDepois, 0);
        EXPECT_EQ(yAntes - yDepois, 0);

    }

    xAntes = pacman_teste->getX();
    yAntes = pacman_teste->getY();
    movimento_valido = pacman_teste->proximo_movimento('w');
    xDepois = pacman_teste->getX();
    yDepois = pacman_teste->getY(); 
    if (movimento_valido == 1){
        xDepois = pacman_teste->getX();
        yDepois = pacman_teste->getY();
        EXPECT_EQ((xDepois - xAntes + labirinto_teste->getLinhas())%labirinto_teste->getLinhas() , labirinto_teste->getLinhas()-1);
        EXPECT_EQ(yDepois - yAntes, 0);

    }
    else{
        EXPECT_EQ(xAntes - xDepois, 0);
        EXPECT_EQ(yAntes - yDepois, 0);

    }

}



TEST_F(Make_test, LabirintoFuncionaCerto)
{
    int i,j;
    char elemento_setado;
    char elemento_matriz;

    elemento_setado = '.';
    labirinto_teste->setElemento(0,0,elemento_setado);
    elemento_matriz = labirinto_teste->getElemento(0,0);
    EXPECT_EQ(elemento_setado - elemento_matriz, 0);

    elemento_setado = ' ';
    labirinto_teste->setElemento(0,0,elemento_setado);
    elemento_matriz = labirinto_teste->getElemento(0,0);
    EXPECT_EQ(elemento_setado - elemento_matriz, 0);


    for (i=0; labirinto_teste->getElemento(i,0) != '\0'; i++);
    EXPECT_EQ(labirinto_teste->getLinhas() - i, 0);

    for (j=0; labirinto_teste->getElemento(0,j) != '\0'; j++);
    EXPECT_EQ(labirinto_teste->getColunas() - j, 0);
    
}


TEST_F(Make_test, ArquivoPropriedadesCertas)
{
    int i,j ;
    int pacdots, fantasmas;

    pacdots = 0;
    fantasmas = 0;

    for (i = 0; i < labirinto_teste->getLinhas(); i++){
        for (j = 0; j < labirinto_teste->getColunas(); j++){

            if (labirinto_teste->getElemento(i,j)== '.'){
                pacdots++;
            }

            if (labirinto_teste->getElemento(i,j)== 'F'){
                fantasmas++;
            }


        }
    }

    EXPECT_EQ(pacdots - arquivo_teste->getPacdots(), 0);
    EXPECT_EQ(fantasmas - arquivo_teste->conta_fantasmas(), 0);
    

}


TEST_F(Make_test, PersonagemPropriedadesCertas)
{

    int movimento_valido;
    int xAntes;
    int yAntes;
    int xDepois;
    int yDepois;
    char sprite;
    char elemento;

    sprite = 'T';

    personagem_teste = new Personagem(0, 0, sprite, labirinto_teste);

    xAntes = personagem_teste->getX();
    yAntes = personagem_teste->getY();
    movimento_valido = personagem_teste->proximo_movimento('d');
    xDepois = personagem_teste->getX();
    yDepois = personagem_teste->getY();
    if (movimento_valido == 1){
        xDepois = personagem_teste->getX();
        yDepois = personagem_teste->getY();
        labirinto_teste->setElemento (personagem_teste->getX(), personagem_teste->getY(), sprite);
        EXPECT_EQ(xDepois - xAntes, 0);
        EXPECT_EQ((yDepois - yAntes + labirinto_teste->getColunas())%labirinto_teste->getColunas() , 1);
    }
    else{
        labirinto_teste->setElemento (personagem_teste->getX(), personagem_teste->getY(), sprite);
        EXPECT_EQ(xAntes - xDepois, 0);
        EXPECT_EQ(yAntes - yDepois, 0);
    }


    elemento = labirinto_teste->getElemento(personagem_teste->getX(), personagem_teste->getY());

    EXPECT_EQ(sprite - elemento, 0);


    personagem_teste->~Personagem();

    EXPECT_EQ(personagem_teste->getStatus(), 0);  

}

TEST_F(Make_test, PartidaPropriedadesCertas)
{
    EXPECT_EQ(partida_teste->getStatus(), 0);

    partida_teste->~Partida();

    EXPECT_EQ(partida_teste->getStatus(), 1 );



}



int main(int argc, char **argv)
{

#ifdef TESTS
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
#endif

    Partida *atual;

    atual = new Partida();

    atual->comeca_jogo(argv[1]);

    exit(0);
}
