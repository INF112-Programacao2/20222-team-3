#include <iostream>
#include "Movimento.h"
#include "Artista.h"
#include "Funcoes.h"

int Movimento::_id_geral=300;

Movimento::Movimento(std::string nome, int numero_artistas, int popularidade){
    _id=_id_geral++; // +1 ao id geral e definindo esse numero como o _id do objeto
    _nome = nome; //_nome igual a string nome recebida como parametro
    _numero_artistas = numero_artistas; //o _numero_artistas é igual o numero inteiro de numero de artistas recebido como parametro
    _popularidade=popularidade;
}

void Movimento::carregar_sistema(std::ifstream &fin){
    Funcoes f;
    _artistas=new Artista*[_numero_artistas]; //ponteiro de ponteiro de artistas aponta para um ponteiro de tamanho _numero_artistas
        for(int i=0;i<_numero_artistas;i++){
            std::string nome;
            std::string numero_obras; //inseridondo o numero de obras, que será usado para alocar as obras nos artistas 
            std::getline(fin,nome);
            fin>>numero_obras;
            if(f.ler_int(numero_obras)==-1){
                std::cout<<"Em "<<nome<< std::endl;
                throw std::invalid_argument("Numero de obras invalido.");
            }
            fin.ignore();
            _artistas[i]=new Artista(nome,f.ler_int(numero_obras)); // cada posicao do vetor estará sendo alocado um artista
            _artistas[i]->carregar_sistema(fin); // carregando as obras em cada artista do vetor
        }
}

Movimento::~Movimento(){
    for(int i=0;i<_numero_artistas;i++)
        delete _artistas[i];
    delete _artistas;//descarregando os artistas do vetor
}

int Movimento::get_numero_artistas(){
    return _numero_artistas; //retornando o nuemro de aristas
}

void Movimento::ver_artistas(){
    for(int i = 0; i<_numero_artistas; i++){
        std::cout << _artistas[i]->get_nome() << std::endl; //imprimindo cada posição do vetor retornando get_nome
    }
}

void Movimento::ver_obras(){

    for(int i = 0; i<_numero_artistas; i++){
        _artistas[i]->ver_obras(); //utilizando o metodo ver_obras de artistas para acesar e imprimir o nome das obras de cada artista de cada posição do vetor
    }
}

int Movimento::get_id(){
    return _id;
}

std::string Movimento::get_nome(){
    return _nome;
}

Artista** Movimento::get_artistas(){
    return _artistas;
}

int Movimento::get_popularidade(){
    return _popularidade;
}