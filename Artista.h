#pragma once

#include <iostream>
#include "Obra.h"

class Artista
{
private:
    static int _id_geral;
    int _id;           // id de artista
    int _numero_obras; // numero de obras do artista
    std::string _nome; // nome do artista
    Obra **_obras;     // vetor de obras
    int _popularidade; // popularidade do artista

public:
    Artista(int numero_obras, std::string nome, int popularidade); // metodo construtor
    void carregar_sistema();                                       // metodo para carregar o sistema com as obras do artista
    void descarregar_sistema();                                    // metodo destrutor para descarregar o sistema
    ~Artista();                                                    // metodo destrutor
    int get_popularidade();                                        // retorna a popularidade do artista
    int get_numero_obras();                                        // retorna o numero de obras do artista
    int get_id();                                                  // retorna o id do artista
    std::string get_nome();                                        // rerorna o nome do artista
    void ver_obras();                                              // exibe as obras, por meio de um array com numero de obras e os nomes
};
