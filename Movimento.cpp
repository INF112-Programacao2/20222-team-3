#include <iostream>
#include "Movimento.h"
#include "Artista.h"
#include "Funcoes.h"

//inicializa a variavel estatica
int Movimento::_id_geral=300;

Movimento::Movimento(std::string nome, int numero_artistas, int popularidade){
    _id=_id_geral++; //incrementa o contador da variavel estatistica e define como ID do movimento
    _nome = nome;
    _numero_artistas = numero_artistas;
    _popularidade=popularidade;
}

void Movimento::carregar_sistema(std::ifstream &fin){
    Funcoes f;
    _artistas=new Artista*[_numero_artistas]; //aloca dinamicamente um vetor de artistas
        for(int i=0;i<_numero_artistas;i++){
            std::string nome;
            std::string numero_obras;
            std::getline(fin,nome);
            //verifica se os valores inseridos sao validos
            fin>>numero_obras;
            if(f.ler_int(numero_obras)==-1){
                std::cout<<"Em "<<nome<< std::endl;
                throw std::invalid_argument("Numero de obras invalido.");
            }
            fin.ignore(); //necessario para a entrada de dados ocorrer corretamente
            //aloca um objeto Artista em cada posicao e chama a funcao carregar sistema para esse artista
            _artistas[i]=new Artista(nome,f.ler_int(numero_obras)); // cada posicao do vetor estará sendo alocado um artista
            _artistas[i]->carregar_sistema(fin); // carregando as obras em cada artista do vetor
        }
}

Movimento::~Movimento(){
    for(int i=0;i<_numero_artistas;i++)
        delete _artistas[i];
    delete _artistas;
}

int Movimento::get_numero_artistas()
{
    return _numero_artistas; //retorna o numero de artistas
}

void Movimento::ver_artistas(){
    for(int i = 0; i<_numero_artistas; i++){
        std::cout << _artistas[i]->get_nome() << std::endl; //exibe o nome de cada artista
    }
}

void Movimento::ver_obras(){
    for(int i = 0; i<_numero_artistas; i++){
        _artistas[i]->ver_obras(); //exibe as obras associadas a cada artista do movimento por meio da funcao ver obras
    }
}

int Movimento::get_id(){
    return _id; //retorna o id
}

std::string Movimento::get_nome(){
    return _nome; //retorna o nome
}

Artista** Movimento::get_artistas(){
    return _artistas; //retorna o ponteiro do vetor de artistas
}

int Movimento::get_popularidade(){
    return _popularidade; //retorna a popularidade
}