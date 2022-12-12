#pragma once
#include <string>
#include "Movimento.h"

class Exposicao : public Movimento
{
private:
    int _semana;
    bool _acessibilidade;
    int _visitantes;
    int **_vigilancia;  //IDs dos funcionarios
    int **_vigilancia_noturna;  //IDs dos funcionarios
    
public:
    Exposicao(std::string nome,int numero_artistas,int popularidade,int semana,bool acessibilidade,int visitantes);
    ~Exposicao();
    
    void ver_vigilancia();
    void ver_vigilancia_noturna();
    int** get_vigilancia();  
    int** get_vigilancia_noturna();
    int get_semana();
    bool get_acessibilidade();
    int get_visitantes();
    int calcular_preco();
};