#ifndef INF112_ARTISTA_H
#define INF112_ARTISTA_H
#include <iostream>
#include "obra.h"

class Artista {
private:
int id_artista;
int numero_obras;
std::string nome_artista;
Obra **obras;//duvida
int _popularidade;

public:
Artista(int id_artista_, int numero_obras_, std:: string nome_artista_, int popularidade);
~Artista();
int get_popularidade();
int get_numero_obras();
int get_id_artista();
std::string get_nome_artista();
void ver_obras();
};
#endif