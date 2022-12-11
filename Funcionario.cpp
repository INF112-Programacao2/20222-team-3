#include "Funcionario.h"
#include <exception>
//Construtor
Funcionario::Funcionario(int salario,std::string carga_horaria): 
   Pessoa(salario), _carga_horaria(carga_horaria){}
//Destrutor
Funcionario::~Funcionario(){
};

std::string Funcionario::get_carga_horaria()
{
   // retorna a string de carga horaria
   return _carga_horaria;
}