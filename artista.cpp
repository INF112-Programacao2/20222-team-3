#include "artista.h"
#include "obra.h"



Artista::Artista(int id_artista_, int numero_obras_, std:: string nome_artista_, int popularidade)
{
    id_artista=id_artista_;
    numero_obras=numero_obras_;
    nome_artista=nome_artista_;
    _popularidade = popularidade;
    obras = new Obra*[numero_obras];
}

int Artista::get_popularidade(){
    return _popularidade;
}

int Artista::get_numero_obras(){
    return numero_obras;
}
int Artista::get_id_artista(){
    return id_artista;
}
std::string Artista::get_nome_artista(){
    return nome_artista;
}
Artista::~Artista()
{};

void Artista::ver_obras(){

    for(int i =0; i<numero_obras; i++){

        std::cout << obras[i]->get_nome_obra() << std::endl;

    }

}