#pragma once

#include <string>
#include "Artista.h"

class Movimento
{
    private:
        int _id;
        std::string _nome;
        int _numero_artistas;
        Artista** _artistas;
        bool _carregado;
    public:
        Movimento(int id, std::string nome, int numero_artistas);
        void carregar_sistema();  //para preencher o acervo de artistas e obras
        void descarregar_sistema();
        ~Movimento();
        int get_numero_artistas();
        bool get_carregado();
        void ver_obras();
        void ver_artistas();
        int calcular_popularidade();

};

