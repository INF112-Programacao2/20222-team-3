#pragma once
#include <cstring>
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
    bool _carregado;
public:
    Gerente(float salario,int numero_exposicoes,int numero_segurancas,int numero_guias);
    void carregar_sistema();  //para preencher o acervo de movimentos, artistas e obras
    void descarregar_sistema();
    ~Gerente();
    Exposicao** get_exposicoes();
    Seguranca** get_segurancas();
    Guia** get_guias();
    int get_numero_exposicoes();
    int get_numero_segurancas();
    int get_numero_guias();
    bool get_carregado();
    
    void ver_exposicoes();
    void ver_segurancas();
    void ver_guias();
    void arquivar_obra(int ID_obra);
    void atribuir_funcionarios(int ID_exposicao);
    float calcular_lucro();
    virtual float calcular_salario() override;
};
