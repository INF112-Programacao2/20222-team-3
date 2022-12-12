#pragma once

#include <string>
#include <fstream>
#include<exception>
#include "Artista.h"

class Movimento
{
    private:
        static int _id_geral; //próximo id a ser definido para o prox objeto do tipo movimento, variavel compartilhada entre todos os objetos
        int _id; //id que será utilizado para reconhecer o objeto
        std::string _nome; //nome do movimento
        int _numero_artistas; // quantidade de artistas daquele movimento
        int _popularidade;
        Artista** _artistas; //ponteiro de ponteiro de artistas para alocar dinamicamente os artistas que fazem parte do movimento
    public:
        Movimento(std::string nome, int numero_artistas, int popularidade); //₢osntrutor que recebe nome, e numero de artistas 
        void carregar_sistema(std::ifstream &fin);  //para preencher o acervo de artistas e obras
        void descarregar_sistema(); // descarregar o acervo de artistas e obras
        virtual ~Movimento(); // destrutor da classe
        int get_numero_artistas(); //retorna o numero de artistas
        Artista** get_artistas();
        int get_id();
        std::string get_nome();
        int get_popularidade();
        void ver_obras(); //imprime as obras do movimento
        void ver_artistas();//imprime os artistas do movimentp

};