#pragma once
#include <string>
#include <fstream>
#include<exception>
#include "Seguranca.h" //nao precisa incluir Pessoa.h nem Funcionario.h pois Seguranca.h e Guia.h ja incluem
#include "Guia.h"
#include "Exposicao.h"

class Gerente : public Pessoa
{
private:
    Exposicao **_exposicoes;
    Seguranca **_segurancas;
    Guia **_guias;
    int _numero_exposicoes;
    int _numero_segurancas;
    int _numero_guias;
public:
    Gerente(int salario,int numero_exposicoes,int numero_segurancas,int numero_guias, std::ifstream &fin);
    void carregar_sistema(std::ifstream &fin);  //para preencher o acervo de movimentos, artistas e obras
    ~Gerente();
    Exposicao** get_exposicoes();
    Seguranca** get_segurancas();
    Guia** get_guias();
    int get_numero_exposicoes();
    int get_numero_segurancas();
    int get_numero_guias();
    
    void ver_exposicoes();
    void ver_segurancas();
    void ver_guias();
    void arquivar_obra(int ID_obra);
    void atribuir_funcionarios();
    int calcular_lucro();
    virtual int calcular_salario() override;
};
