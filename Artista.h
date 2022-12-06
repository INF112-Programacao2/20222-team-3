#pragma once

#include <iostream>
#include "Obra.h"

class Artista {
private:
static int _id_geral;
    int _id;
    int _numero_obras;
    std::string _nome;
    Obra **_obras;
    int _popularidade;
    bool _carregado;

public:
    Artista(int numero_obras, std::string nome, int popularidade);
    void carregar_sistema();
    void descarregar_sistema();
    ~Artista();
    int get_popularidade();
    int get_numero_obras();
    int get_id();
    std::string get_nome();
    bool get_carregado();
    void ver_obras();
};
