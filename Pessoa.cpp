#include <iostream>
#include "Pessoa.h"

int Pessoa::_id_geral=400;
// Construtor
Pessoa::Pessoa(int id,float salario)
{
    _id = _id_geral++;
    _salario = salario ;
}
// Destrutor
Pessoa::~Pessoa(){};
// Métodos
float Pessoa::get_salario_pessoa()
{
    return _salario;
};
int Pessoa::get_id()
{
    return _id;

};