#include <bits/stdc++.h>
#include "Pessoa.h"
// Construtor
Pessoa::Pessoa()
{

    int _id;
    std::cin >> _id;
    Id_Pessoa = _id;
    salario = calcular_salario();
}
// Destrutor
Pessoa::~Pessoa(){};
// Métodos
void Pessoa::get_salario_pessoa()
{
    std::cout << salario << std::endl;
};
void Pessoa::get_Id_pessoa()
{
    std::cout << Id_Pessoa << std::endl;
};