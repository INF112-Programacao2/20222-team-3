#include "Artista.h"
#include "Obra.h"

int Artista::_id_geral = 200;

Artista::Artista(int numero_obras, std::string nome, int popularidade)
{ // metodo construtor
    _id = _id_geral++;
    _numero_obras = numero_obras;
    _nome = nome;
    _popularidade = popularidade;
};

void Artista::carregar_sistema()
{                                       // carregando sistema em conjunto com a classe obras
    _obras = new Obra *[_numero_obras]; // construtor para obras
    std::string nome;
    for (int i = 0; i < _numero_obras; i++)
    {
        std::getline(std::fin, nome);
        _obras[i] = new Obra(nome);
    }
}

void Artista::descarregar_sistema()
{ // descarregando sistema com metodo destrutor para obras integrado com artista

    for (int i = 0; i < _numero_obras; i++)
    {
        delete _obras[i];
    }
    delete _obras;
}

Artista::~Artista()
{ // metodo destrutor

    descarregar_sistema();
};

void Artista::ver_obras()
{ // exibir obras do artista
    for (int i = 0; i < _numero_obras; i++)
    {
        std::cout << _obras[i]->get_nome() << std::endl;
    }
};

int Artista::get_popularidade()
{ // retorno da popularidade do artista
    return _popularidade;
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
