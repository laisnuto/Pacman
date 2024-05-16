# Pacman em C++
Uma versão simplificada do jogo pacman usando orientação a objetos em c++


## AUTOR:
Laís Nuto Rossman, NºUSP 12547274, laisnuto@usp.br


## DESCRIÇÃO:
O programa realizado nesse trabalho é uma versão mais simples do jogo pacman. Com orientação a objetos, foi possível 
construir os diferentes elementos do jogo e combiná-los para funcionar da seguinte forma: a cada interação, o usuário 
pode mover o Pac-Man, enquanto os fantasmas se movem de forma pseudo-aleatória, além disso, para ganhar o usuário
deve se movimentar no tabuleiro para comer os pacdots enquanto evita ser morto pelos fantasmas. Para implementação do jogo 
foi criada uma classe Personagem que é responsável pelas propriedades gerais de movimentação e manutenção dos personagens do 
jogo que são o Pacman e os Fantasmas. Foi criada uma classe também para o Pacman para as especificidades desse personagem, e
outra classe para os Fantasmas, que por exemplo era responsável por realizar seu movimento pseudo-aleatório. Além disso foi
criado uma classe Labirinto que controlava as probriedades do labirinto em que o jogo está acontecendo. Ta,bém foi criada uma 
Arquivo, responsável pela leitura do arquivo txt na linha de comando que contém o labirinto do jogo e por guardar os elementos 
importantes lidos nesse arquivo (como pacdots, fantasmas e o próprio labirinto). Por fim foi implementada uma classe Partida
que contém todas as outras classes e executa o jogo em si, verificando quando o pacman come um pacdot, quando morre ou quando 
ganha o jogo. 

Para garantir o funcionamento das classes e do jogo como um todo, nesse EP foram feitos comentários no código-fonte explicando
as classes e o programa principal que geram uma documentação que possa ser lida em um navegador web através da ferramenta doxygen.
Além disso, o programa contém algum testes para conferir se os métodos das classes estão corretamente implementados usando GoogleTest3.


## COMO EXECUTAR:
O primeiro passo para executar o programa compilar o makefile com a instrução de acordo com o que o usuáriorio quer compilar.

*Um comentário importante é destacar que no makefile os comandos de compilação foram feitos usando -pthread -lgtest (e não -lpthread).
Isso por causa de alguma particularidade da arquitetura e da versão do compilador que foi testado o programa (nas dependências
estão todas as informações dessa máquina em que foi testado). Por isso é preciso se atentar a esse detalhe na hora de compilar.

Segue as instruções de compilação e execução para cada tipo de alvo

1. Para compilar o jogo em si e poder jogá-lo sem os testes ativados, o usuário deve inserir o terminal: make all
Depois para executar o jogo, o usuário deve ter um arquivo txt com um labirinto que o nome deve ser passado 
como um dos argumentos na linha de comando após o ./ep4. Ou seja, supondo que o usuário tenha o labirinto num arquivo teste.txt, 
ele deve executar o seguinte comando: ./ep4 teste.txt

2. Para compilar o programa e ativar os testes feitos usando o GoogleTeste, o usuário precisa ter um arquivo com o labirinto
nomeado de "teste.txt" obrigatoriamente, no mesmo diretório em que está os arquivos do programa. As classes serão 
testadas a partir do labirinto que estiver no arquivo "teste.txt. Para fazer os testes é preciso colocar o 
seguinte comando no terminal: make tests
e depois colocar esse comando: ./ep4

3. Para gerar a documentação do programa que possa ser lida num navegador web, depois de executar o comando, o usuário deve entrar na 
pasta html gerada e procurar o arquivo index.html para acessar a documentação. Além disso é preciso ter um arquivo Doxyfile no mesmo diretório 
do programa com as devidas modificações para gerar a documentação necessária (assim como no EP3 com a alteração na sessão OPTIMIZE_OUTPUT_FOR_C = NO
e na sessão INPUT = ep4.cpp arquivo.h fantasma.h labirinto.h pacman.h partida.h personagem.h).
O comando no terminal para gerar a documentação é: make doc

4. Para limpar todos os arquivos gerados na compilação e na documentação, basta colocar o seguinte 
comando no terminal: make clean


## TESTES:
vc tem q ter um arquivo teste.txt
No arquivo ep4.cpp é onde tem todos os testes que serão feitos. é importante destacar a necessidade de um arquivo nomeado "teste.txt" com 
um labirinto do jogo para que as classes sejam testadas.

Primeiramente é criada uma classe de teste nomeada como Make_teste em que todas as outras classes são instanciadas para auxiliar na hora de fazer
os testes.

Começamos testando a classe Fantasma em FantasmaAndaCerto em que verificamos se um fantasma se movimenta da forma esperada nas 4 possíveis direções

Depois fazemos o mesmo com a classe Pacman no PacmanAndaCerto em que testamos o movimento do pacman nas 4 possíveis direções

O próximo teste é o da classe Labirinto no LabirintoFuncionaCerto foram testasdas as funções getElemento e setElemento, já que elas são usadas 
para modificar o labirinto na hora que um pacman come um pacdot, ou que um fantasma passa por cima de um pacdot e até mesmo para colocar os fantasmas 
e o pacman no labirinto. Além disso, esse teste verifica se as funções getColunas e getLinhas também estão funcionando corretamente

O próximo teste é o da classe Arquivo no ArquivoPropriedadesCertas, no qual verifica se as funções getPacdots e conta_fantasmas devolvem o número 
certo de pacdots e fantasmas, respectivamente, que foi lido no arquivo de entrada para a classe Labirinto.

O próximo teste é da classe Personagem no Personagem propriedades certas, em que foi criado um personagem representado pelo caracter 'T' que  é 
testado o movimento em uma das direções possíveis. A função getStatus também foi testada usando o destructor

O último teste é da classe Partida, da forma como foi implementada, não tinha tantas funções que pudessem ser testadas se forma automatizada. Portanto 
foi testada a função getStatus que informa se a partida acabou (quando retirna 1) ou não (quando retorna 0)

Todos os testes foram feitos de acordo com que o EP estava implementado, levando em consideração o fazia sentido ou não testar.



## DEPENDÊNCIAS:
< Processador: i5-1135G7 2.40GHz x86_64
  Versão do gcc: gcc 9.4.0
  Sistema Operacional: Ubuntu 20.04.4 LTS 
  Memory: 4471MiB / 7672MiB
  Shell: bash 5.0.17 
  Versão do doxygen: 1.8.17

  
  Bibliotecas padrão: iostream, fstream, random, gtest/gtest.h
  
  *Para gerar uma documentação automática é preciso instalar o Doxygen, se não foi feito, 
  executar o seguinte comando no terminal: sudo apt install doxygen
 *Para gerar os teste é preciso ter o a ferramenta do GoogleTest instalada no seu computador
  
>

