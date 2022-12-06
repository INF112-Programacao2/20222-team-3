#include <iostream>
#include "Movimento.h"
#include "Artista.h"

int Movimento::_id_geral=300;

Movimento::Movimento(std::string nome, int numero_artistas){
    _id=_id_geral++;
    _nome = nome;
    _numero_artistas = numero_artistas;
    _carregado=false;
}

void Movimento::carregar_sistema(){
    _artistas=new Artista*[_numero_artistas];
        for(int i=0;i<_numero_artistas;i++){
            int popularidade;
            int numero_obras;
            std::cin>>nome>>popularidade>>numero_obras;
            _artistas[i]=new Artista(nome,popularidade,numero_obras);
            _artistas[i]->carregar_sistema();
        }
    _carregado=true;
}
void Movimento::descarregar_sistema(){
    if(!_carregado)
        return;
    for(int i=0;i<_numero_artistas;i++)
        _artistas[i]->descarregar_sistema();
    delete _artistas;
    _carregado=false;
}
Movimento::~Movimento(){
    if(_carregado)
        descarregar_sistema();

}

int Movimento::get_numero_artistas(){
    return _numero_artistas;
}

void Movimento::ver_artistas(){
    for(int i = 0; i<_numero_artistas; i++){

        std::cout << _artistas[i]->get_nome() << std::endl;

    }
}

int Movimento::calcular_popularidade(){
    
    int media;

    for(int i = 0; i < _numero_artistas; i++){

        media += _artistas[i]->get_popularidade();

    }

    return media/_numero_artistas;

}

void Movimento::ver_obras(){

    for(int i = 0; i<_numero_artistas; i++){

        _artistas[i]->ver_obras();
    }
}

bool get_carregado(){
    return _carregado;
}