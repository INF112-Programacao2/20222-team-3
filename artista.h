#ifndef INF112_ARTISTA_H
#define INF112_ARTISTA_H
#include <iostream>

class Artista {
public:
int id;
std::string nome;


Artista();
~Artista();
int get_obras();

};
#endif