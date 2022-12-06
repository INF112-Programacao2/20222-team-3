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
    bool _alocado;
    
public:
    Exposicao(std::string nome,int numero_artistas,int semana,bool acessibilidade,int visitantes);
    ~Exposicao();
    
    void aloca_vigilancia();
    void desaloca_vigilancia();
    void ver_vigilancia();
    void ver_vigilancia_noturna();
    int** get_vigilancia();  
    int** get_vigilancia_noturna();
    int get_semana();
    bool get_acessiblidade();
    int get_visitantes();
    bool get_alocado();
    float calcular_preco();
};