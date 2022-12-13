#pragma once
#include <string>
#include <fstream>
#include <exception>
#include "Seguranca.h" //nao precisa incluir Pessoa.h nem Funcionario.h pois Seguranca.h e Guia.h ja incluem
#include "Guia.h"
#include "Exposicao.h"

class Gerente : public Pessoa
{
private:
    Exposicao **_exposicoes; // vetor de exposicoes
    Seguranca **_segurancas; // vetor de segurancas
    Guia **_guias;           // vetor de guias
    int _numero_exposicoes;  // numero de exposicoes
    int _numero_segurancas;  // numero de segurancas
    int _numero_guias;       // numero de guias
public:
    Gerente(int salario, int numero_exposicoes, int numero_segurancas, int numero_guias, std::ifstream &fin);
    ~Gerente();
    void carregar_sistema(std::ifstream &fin); // metodo para carregar o sistema com as exposicoes
    Exposicao **get_exposicoes();
    Seguranca **get_segurancas();
    Guia **get_guias();
    int get_numero_exposicoes();
    int get_numero_segurancas();
    int get_numero_guias();

    void ver_exposicoes();                   // exibe as exposicoes com seus artistas e obras associadas
    void ver_segurancas();                   // exibe os IDs dos segurancas cadastrados
    void ver_guias();                        // exibe os IDs dos segurancas cadastrados
    void arquivar_obra(int ID_obra);         // localiza a obra por meio do ID
    void atribuir_funcionarios();            // atribui os funcionarios a cada exposicao
    int calcular_lucro();                    // calcula o lucro
    virtual int calcular_salario() override; // calcula o salario
};
