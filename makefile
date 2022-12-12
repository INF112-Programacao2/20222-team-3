all:	Artista.o Exposicao.o Funcionario.o Funcoes.o Gerente.o Guia.o Movimento.o Obra.o Pessoa.o Seguranca.o main.o

Artista.o : Artista.cpp Artista.h
	g++ -c Artista.cpp

Exposicao.o : Exposicao.cpp Exposicao.h
	g++ -c Exposicao.cpp

Funcionario.o : Funcionario.cpp Funcionario.h
	g++ -c Funcionario.cpp

Funcoes.o : Funcoes.cpp Funcoes.h
	g++ -c Funcoes.cpp

Gerente.o : Gerente.cpp Gerente.h
	g++ -c Gerente.cpp

Guia.o : Guia.cpp Guia.h
	g++ -c Guia.cpp

Movimento.o : Movimento.cpp Movimento.h
	g++ -c Movimento.cpp

Obra.o : Obra.cpp Obra.h
	g++ -c Obra.cpp

Pessoa.o : Pessoa.cpp Pessoa.h
	g++ -c Pessoa.cpp

Segurança.o : Segurança.cpp Segurança.h
	g++ -c Segurança.cpp

main.o : main.cpp main.h
	g++ -c main.cpp

clean:
	rm -rf *.o 

vai:
	./main