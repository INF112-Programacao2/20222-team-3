#pragma once

#include <iostream>
#include <fstream>
#include <exception>
#include "Obra.h"

class Artista
{
private:
    static int _id_geral; // id geral dos artistas
    int _id;              // id de artista
    int _numero_obras;    // numero de obras do artista
    std::string _nome;    // nome do artista
    Obra **_obras;        // vetor de obras

public:
    Artista(std::string nome, int numero_obras);
    ~Artista();
    void carregar_sistema(std::ifstream &fin); // metodo para carregar o sistema com as obras do artista
    int get_numero_obras();                    // retorna o numero de obras do artista
    int get_id();                              // retorna o id do artista
    Obra **get_obras();                        // retorna o ponteiro do vetor de obras
    std::string get_nome();                    // retorna o nome do artista
    void ver_obras();                          // exibe as obras do artista
};
