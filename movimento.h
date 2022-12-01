#ifndef INF112_MOVIMENTO_H
#define INF112_MOVIMENTO_H

#include <string>
#include "artista.h"
class Movimento
{
private:
    int _ID;
    std::string _nome;
    int _nArtista; //numero de artistas
    Artista** _artistas;
    
public:
    int get_nArtista();
    void ver_obras();
    void ver_artistas();
    int calcular_popularidade();
    Movimento(int ID, std::string nome, int _nArtistas);
    ~Movimento();

};

#endif

