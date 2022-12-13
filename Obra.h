#pragma once
#include <iostream>

class Obra
{
private:
    static int _id_geral; // id geral das obras
    int _id;              // id da obra
    bool _arquivada;      // informa se a obra ou nao arquivada
    std::string _nome;    // nome da obra
public:
    Obra(std::string nome);
    ~Obra();
    int get_id();                       // retorna o id da obra
    bool get_arquivada();               // retorna se a obra esta arquivada ou nao
    std::string get_nome();             // retorna o nome da obra
    void set_arquivada(bool arquivada); // altera o estado de _arquivada
};
