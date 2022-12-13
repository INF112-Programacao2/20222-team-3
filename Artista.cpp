#include "Artista.h"
#include "Obra.h"

//inicializa a variavel estatica
int Artista::_id_geral = 200;

Artista::Artista(std::string nome,int numero_obras)
{
    _id = _id_geral++; //incrementa o contador da variavel estatistica e define como ID do artista
    _numero_obras = numero_obras;
    _nome = nome;
};

void Artista::carregar_sistema(std::ifstream &fin)
{                                       
    _obras = new Obra *[_numero_obras]; //aloca dinamicamente um vetor de obras
    std::string nome;
    for (int i = 0; i < _numero_obras; i++)
    {
        std::getline(fin, nome);
        _obras[i] = new Obra(nome); //preenche da posicao do vetor com um objeto Obra
    }
}

Artista::~Artista()
{
    for (int i = 0; i < _numero_obras; i++)
    {
        delete _obras[i];
    }
    delete _obras;
};

void Artista::ver_obras()
{
    for (int i = 0; i < _numero_obras; i++)
    {
        if(!_obras[i]->get_arquivada()) //se a obra nao estiver arquivda
            std::cout << _obras[i]->get_id() << " " << _obras[i]->get_nome() << std::endl; //exibir o id e o nome
    }
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

Obra** Artista::get_obras(){
    return _obras;
};