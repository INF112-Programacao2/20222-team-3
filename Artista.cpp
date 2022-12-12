#include "Artista.h"
#include "Obra.h"

int Artista::_id_geral = 200;

Artista::Artista(std::string nome,int numero_obras)
{ // metodo construtor
    _id = _id_geral++;
    _numero_obras = numero_obras;
    _nome = nome;
};

void Artista::carregar_sistema(std::ifstream &fin)
{                                       // carregando sistema em conjunto com a classe obras
    _obras = new Obra *[_numero_obras]; // construtor para obras
    std::string nome;
    for (int i = 0; i < _numero_obras; i++)
    {
        std::getline(fin, nome);
        _obras[i] = new Obra(nome);
    }
    
}

Artista::~Artista()
{ // metodo destrutor
    for (int i = 0; i < _numero_obras; i++)
    {
        delete _obras[i];
    }
    delete _obras;
};

void Artista::ver_obras()
{ // exibir obras do artista
    for (int i = 0; i < _numero_obras; i++)
    {
        std::cout << _obras[i]->get_id() << " " << _obras[i]->get_nome() << std::endl;
    }
};

int Artista::get_numero_obras()
{ // retorno do numero de obras
    return _numero_obras;
};

int Artista::get_id()
{ // retorno do id do artista
    return _id;
};

std::string Artista::get_nome()
{ // retorno nome do artista
    return _nome;
};

Obra** Artista::get_obras(){
    return _obras;
}