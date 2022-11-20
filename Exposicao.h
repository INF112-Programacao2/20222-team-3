#pragma once
#include "Movimento.h"

class Exposicao : public Movimento
{
private:
    int _semana;
    bool _acessibilidade;
    float _preco;
    int _visitantes;
    int **_vigilancia;  //IDs dos funcionarios
    int **_vigilancia_noturna;  //IDs dos funcionarios
    int _id_guia;
public:
    Exposicao(int semana,bool acessibilidade,float preco,int visitantes,int id_guia);
    ~Exposicao();
    void ver_vigilancia();
    void ver_vigilancia_noturna();
    float get_preco();
    int get_semana();
    bool get_acessiblidade();
    int get_visitantes();
    int get_id_guia();
};
