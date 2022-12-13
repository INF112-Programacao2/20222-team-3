#pragma once
#include<string>
class Funcoes{
    public:
        int ler_int(std::string str); //verifica se a string corresponde a um numero
        int ler_digito(std::string str); //verifica se a string corresponde a um valor dentro do intervalo
        int ler_bool(std::string str); //verifica se a string e 0 ou 1
};