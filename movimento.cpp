#include "movimento.h"
#include <iostream>
#include "artista.h"

Movimento::Movimento(int ID, std::string nome, int nArtista){
    _ID = ID;
    _nome = nome;
    _nArtista = nArtista;
    _artistas = new Artista*[_nArtista];
}

Movimento::~Movimento(){
    
    delete[] _artistas;

}

int Movimento::get_nArtista(){
    return _nArtista;
}

void Movimento::ver_artistas(){
    for(int i = 0; i<_nArtista; i++){

        std::cout << _artistas[i]->get_nome_artista() << std::endl;

    }
}

int Movimento::calcular_popularidade(){
    
    int media;

    for(int i = 0; i < _nArtista; i++){

        media += _artistas[i]->get_popularidade();

    }

    return media/_nArtista;

}

void Movimento::ver_obras(){
    //???????
}