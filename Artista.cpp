#include "Artista.h"
#include "Obra.h"

int Artista::_id_geral=200;

Artista::Artista(int numero_obras, std::string nome, int popularidade)
{
    _id = _id_geral++;
    _numero_obras = numero_obras;
    _nome = nome;
    _popularidade = popularidade;
    _carregado = false;
};

void Artista::carregar_sistema()
{
    _obras = new Obra *[_numero_obras];
    std::string nome;
    for (int i = 0; i < _numero_obras; i++)
    {
        std::cin >> nome;
        _obras[i] = new Obra(nome);
    }
    _carregado=true;
}

void Artista::descarregar_sistema()
{
    if(!_carregado)
        return;
    for(int i = 0; i < _numero_obras; i++)
    {
        delete _obras[i];
    }
    delete _obras;
    _carregado=false;
}

Artista::~Artista()
{
    if (_carregado)
        descarregar_sistema();    
};

void Artista::ver_obras()
{
    for (int i = 0; i < _numero_obras; i++)
    {
        std::cout << _obras[i]->get_nome() << std::endl;
    }
};

int Artista::get_popularidade()
{
    return _popularidade;
};

int Artista::get_numero_obras()
{
    return _numero_obras;
};

int Artista::get_id()
{
    return _id;
};

std::string Artista::get_nome()
{
    return _nome;
};

bool Artista::get_carregado()
{
    return _carregado;
};
