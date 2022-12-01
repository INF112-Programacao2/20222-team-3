#ifndef INF112_MOVIMENTO_H
#define INF112_MOVIMENTO_H

#include <string>
#include "artista.h"
class movimento
{
private:
    int _ID;
    std::string _nome;
    int _nArtista; //numero de artistas
    Artista** artistas;
    
public:
    void get_nArtista();
    void ver_obras();
    Artista ver_artistas();
    int calcular_popularidade();
    movimento(int ID, std::string nome, int _nArtistas);
    ~movimento();

};

#endif

