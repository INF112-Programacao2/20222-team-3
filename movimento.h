#ifndef INF112_MOVIMENTO_H
#define INF112_MOVIMENTO_H

#include <string>
#include "artista.h"
class movimento
{
private:
    int _ID;
    string _nome;
    int _nArtista; //numero de artistas
    artista::artista** artistas;
    
public:
    void ver_obras();
    void ver_artistas();
    int calcular_popilaridade();
    movimento(int ID, string nome, int _nArtistas);
    ~movimento();

};

#endif

