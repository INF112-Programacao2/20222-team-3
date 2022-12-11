#include <iostream>
#include "Movimento.h"
#include "Artista.h"

int Movimento::_id_geral=300;

Movimento::Movimento(std::string nome, int numero_artistas){
    _id=_id_geral++; // +1 ao id geral e definindo esse numero como o _id do objeto
    _nome = nome; //_nome igual a string nome recebida como parametro
    _numero_artistas = numero_artistas; //o _numero_artistas é igual o numero inteiro de numero de artistas recebido como parametro
    _carregado=false; // carregado começa como falso, afinal nao foram carregados os artistas e as respectivas obras ainda
}

void Movimento::carregar_sistema(){
    _artistas=new Artista*[_numero_artistas]; //ponteiro de ponteiro de artistas aponta para um ponteiro de tamanho _numero_artistas
        for(int i=0;i<_numero_artistas;i++){ 
            int popularidade; //inserindo a popularidade do artista
            int numero_obras; //inseridondo o numero de obras, que será usado para alocar as obras nos artistas 
            std::cin>>nome>>popularidade>>numero_obras; 
            _artistas[i]=new Artista(nome,popularidade,numero_obras); // cada posicao do vetor estará sendo alocado um artista
            _artistas[i]->carregar_sistema(); // carregando as obras em cada artista do vetor
        }
    _carregado=true; //definindo como true carregado
}



void Movimento::descarregar_sistema(){
    if(!_carregado)//se carregado for falso, nao precisa descarregar nada, entao retorna
        return;
    for(int i=0;i<_numero_artistas;i++)
        _artistas[i]->descarregar_sistema();//descarregando as obras de artista
    delete _artistas;//descarregando os artistas do vetor
    _carregado=false; // ao descarregar define carregado como falso
}


Movimento::~Movimento(){
    if(_carregado)
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
    
    int media; //onnde vai ser guardado a soma das popularidades dos artistas

    for(int i = 0; i < _numero_artistas; i++){

        media += _artistas[i]->get_popularidade();

    }

    return media/_numero_artistas; //retornando a popularidade os artistas somados / pelo numero de artistas, assim retornando a popularidade do movimento

}

void Movimento::ver_obras(){

    for(int i = 0; i<_numero_artistas; i++){

        _artistas[i]->ver_obras(); //utilizando o metodo ver_obras de artistas para acesar e imprimir o nome das obras de cada artista de cada posição do vetor
    }
}

bool get_carregado(){
    return _carregado; // retorna se foi carregado ou nao
}