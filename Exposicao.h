#pragma once 
#include <cstring>

class Exposicao
{
private:
    int _semana;
    int _ID;
    bool _acessibilidade;
public:
    Exposicao(int semana, int ID, bool acessibilidade);
    ~Exposicao();
    void vigilancia();
    void calcularPreco();
    void get_semana();
    void get_ID();
    void get_acessiblidade();
    };
