#pragma once

#include <string>
#include "Artista.h"

class Movimento
{
    private:
        static int _id_geral; //próximo id a ser definido para o prox objeto do tipo movimento, variavel compartilhada entre todos os objetos
        int _id; //id que será utilizado para reconhecer o objeto
        std::string _nome; //nome do movimento
        int _numero_artistas; // quantidade de artistas daquele movimento
        Artista** _artistas; //ponteiro de ponteiro de artistas para alocar dinamicamente os artistas que fazem parte do movimento
        bool _carregado; // variavel que serve para conferir se esta carregado o sistema
    public:
        Movimento(std::string nome, int numero_artistas); //₢osntrutor que recebe nome, e numero de artistas 
        void carregar_sistema();  //para preencher o acervo de artistas e obras
        void descarregar_sistema(); // descarregar o acervo de artistas e obras
        ~Movimento(); // destrutor da classe
        int get_numero_artistas(); //retorna o numero de artistas
        bool get_carregado(); //retorna se foi carregado ou nao
        void ver_obras(); //imprime as obras do movimento
        void ver_artistas();//imprime os artistas do movimentp
        int calcular_popularidade();// metoodo que calcula e retorna a popularidade do movimento em relação aos artistas

};

