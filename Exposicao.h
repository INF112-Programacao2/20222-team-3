#pragma once
#include <string>
#include "Movimento.h"

class Exposicao : public Movimento
{
private:
    int _semana;               // semana do mes
    bool _acessibilidade;      // define se a exposicao requer acessibilidade
    int _visitantes;           // numero de visitantes
    int **_vigilancia;         // IDs dos funcionarios
    int **_vigilancia_noturna; // IDs dos funcionarios

public:
    Exposicao(std::string nome, int numero_artistas, int popularidade, int semana, bool acessibilidade, int visitantes);
    ~Exposicao();

    void ver_vigilancia();          // exibe os IDs dos segurancas associados a cada dia da semana
    void ver_vigilancia_noturna();  // exibe os IDs dos segurancas associados a cada dia da semana
    int calcular_preco();           // calcula preco do ingresso
    int **get_vigilancia();         // retorna o ponteiro do vetor de vigilancia
    int **get_vigilancia_noturna(); // retorna o ponteiro do vetor de vigilancia noturna
    int get_semana();               // retorna a semana da exposicao
    bool get_acessibilidade();      // retorna se requer acessibilidade
    int get_visitantes();           // retorna numero de visitantes
};