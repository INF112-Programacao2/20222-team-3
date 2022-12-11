#include "Funcionario.h"

Funcionario::Funcionario(std::string carga_horaria,float salario) : Pessoa(salario)
{

   _carga_horaria = carga_horaria;
}

Funcionario::~Funcionario(){

};

std::string Funcionario::get_carga_horaria()
{

   return _carga_horaria;
}