#pragma once 
#include <cstring>

class Exposicao
{
private:
    std::string periodo;
    int ID;
    bool acessibilidade;
public:
    Exposicao(/* args */);
    ~Exposicao();
    void vigilancia();
    void calcularPreco();
    };
