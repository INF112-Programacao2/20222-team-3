#include <iostream>
#include "Movimento.h"
#include "Artista.h"

int Movimento::_id_geral=300;

Movimento::Movimento(std::string nome, int numero_artistas){
    _id=_id_geral++; // +1 ao id geral e definindo esse numero como o _id do objeto
    _nome = nome; //_nome igual a string nome recebida como parametro
    _numero_artistas = numero_artistas; //o _numero_artistas é igual o numero inteiro de numero de artistas recebido como parametro
}

void Movimento::carregar_sistema(){
    _artistas=new Artista*[_numero_artistas]; //ponteiro de ponteiro de artistas aponta para um ponteiro de tamanho _numero_artistas
        for(int i=0;i<_numero_artistas;i++){
            std::string nome;
            std::string popularidade; //inserindo a popularidade do artista
            std::string numero_obras; //inseridondo o numero de obras, que será usado para alocar as obras nos artistas 
            std::cin.ignore();
            std::getline(std::cin,nome);
            std::cin>>popularidade;
            // popularidade recebe inteiros entre 1 e 5
            if(ler_digito(popularidade)==0)
                throw std::exception("Popularidade de "+nome+" deve ser um inteiro entre 1 e 5.");
            std::cin>>numero_obras;
            if(ler_int(numero_obras)==0)
                throw std::exception("Numero de obras de "+nome+" invalido.");
            _artistas[i]=new Artista(nome,ler_digito(popularidade),ler_int(numero_obras)); // cada posicao do vetor estará sendo alocado um artista
            _artistas[i]->carregar_sistema(); // carregando as obras em cada artista do vetor
        }
}

void Movimento::descarregar_sistema(){
    for(int i=0;i<_numero_artistas;i++)
        _artistas[i]->descarregar_sistema();//descarregando as obras de artista
    delete _artistas;//descarregando os artistas do vetor
}

Movimento::~Movimento(){
    descarregar_sistema(); //utilizando o metodo pra remover da memoria o que foi alocado dinamicamente
}

int Movimento::get_numero_artistas(){
    return _numero_artistas; //retornando o nuemro de aristas
}

void Movimento::ver_artistas(){
    for(int i = 0; i<_numero_artistas; i++){
        std::cout << _artistas[i]->get_nome() << std::endl; //imprimindo cada posição do vetor retornando get_nome
    }
}

int Movimento::calcular_popularidade(){
    int media; //onde vai ser guardado a soma das popularidades dos artistas
    for(int i = 0; i < _numero_artistas; i++){
        media += _artistas[i]->get_popularidade();
    }
    return media/_numero_artistas; //retornando a popularidade os artistas somados / numero de artistas, assim retornando a popularidade do movimento
}

void Movimento::ver_obras(){

    for(int i = 0; i<_numero_artistas; i++){
        _artistas[i]->ver_obras(); //utilizando o metodo ver_obras de artistas para acesar e imprimir o nome das obras de cada artista de cada posição do vetor
    }
}
