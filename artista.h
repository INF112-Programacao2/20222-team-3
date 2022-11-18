#ifndef INF112_ARTISTA_H
#define INF112_ARTISTA_H
#include <iostream>

class Artista {
private:
int id_artista;
int numero_obras;
std::string nome_artista;
int **obras;//duvida

public:
Artista();
~Artista();
int get_numero_obras();
int get_id_artista();
std::string get_nome_artista();

};
#endif