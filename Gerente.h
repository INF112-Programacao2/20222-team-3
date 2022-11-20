#pragma once
#include <cstring>
#include "Seguranca.h" //nao precisa incluir Pessoa.h nem Funcionario.h pois Seguranca.h e Guia.h ja incluem
#include "Guia.h"
#include "Exposicao.h"

class Gerente : public Pessoa
{
private:
    Exposicao *_exposicoes;
    Seguranca *_segurancas;
    Guia *_guias;
    int _numero_exposicoes;
    int _numero_segurancas;
    int _numero_guias;
public:
    Gerente(std::string entrada);
    ~Gerente();
    int get_numero_exposicoes();
    int get_numero_segurancas();
    int get_numero_guias();
    void ver_exposicoes();
    void ver_segurancas();
    void ver_guias();
    void arquivar_obra(int id_obra);
    void atribuir_funcionarios(int id_exposicao);
    float calcular_lucro();
    virtual float calcular_salario() override;
};
