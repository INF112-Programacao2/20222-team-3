#pragma once

#include <string>
#include <fstream>
#include <exception>
#include "Artista.h"

class Movimento
{
private:
    static int _id_geral; // id geral dos movimentos
    int _id;              // id do movimento
    std::string _nome;    // nome do movimento
    int _numero_artistas; // numero artistas do movimento
    int _popularidade;    // popularidade do movimento
    Artista **_artistas;  // vetor de artistas
public:
    Movimento(std::string nome, int numero_artistas, int popularidade);
    virtual ~Movimento();
    void carregar_sistema(std::ifstream &fin); // metodo para carregar o sistema com os artistas do movimento
    int get_numero_artistas();                 // retorna o numero de artistas
    Artista **get_artistas();                  // retorna o ponteiro do vetor de artistas
    int get_id();                              // retorna o id
    std::string get_nome();                    // retorna o nome
    int get_popularidade();                    // retorna a popularidade
    void ver_obras();                          // exibe as obras do movimento
    void ver_artistas();                       // exibe os artistas do movimento
};