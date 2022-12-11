#pragma once
#include <iostream>

class Obra
{
private:
    static int _id_geral;
    int _id;           // id da obra
    bool _arquivada;   // arquivada ou nao
    std::string _nome; // nome da obra
public:
    Obra(std::string nome);             /// metodo construtor que passa nome da obra como parametro
    ~Obra();                            // metodo destrutor
    int get_id();                       // retorna o id da obra
    bool get_arquivada();               // retorna se a obra esta arquivada ou nao
    std::string get_nome();             // retorna o nome da obra
    void set_arquivada(bool arquivada); // altera arquivada
};
