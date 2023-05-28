CPPFLAGS = -Wall

all: ep4.cpp arquivo.o pacman.o fantasma.o personagem.o partida.o labirinto.o
	g++ -Wall -o ep4 ep4.cpp arquivo.o pacman.o fantasma.o personagem.o partida.o labirinto.o -pthread -lgtest
	
	
tests: ep4.cpp arquivo.o pacman.o fantasma.o personagem.o partida.o labirinto.o
	g++ -Wall -o ep4 ep4.cpp arquivo.o pacman.o fantasma.o personagem.o partida.o labirinto.o -pthread -lgtest -DTESTS
	
doc:
	doxygen Doxyfile
	


arquivo.o: arquivo.cpp arquivo.h
	g++ -Wall -c -o arquivo.o arquivo.cpp
	
pacman.o: pacman.cpp pacman.h
	g++ -Wall -c -o pacman.o pacman.cpp

fantasma.o: fantasma.cpp fantasma.h
	g++ -Wall -c -o fantasma.o fantasma.cpp

personagem.o: personagem.cpp personagem.h
	g++ -Wall -c -o personagem.o personagem.cpp

partida.o: partida.cpp partida.h
	g++ -Wall -c -o partida.o partida.cpp

labirinto.o: labirinto.cpp labirinto.h
	g++ -Wall -c -o labirinto.o labirinto.cpp
	
clean: 
	rm *.o
	rm ep4
	rm -rf html
