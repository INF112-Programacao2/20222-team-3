#ifndef INF112_OBRA_H
#define INF112_OBRA_H
#include <iostream>

class Obra {
private:
int id_obra;
bool arquivada = false;
std::string nome_obra;
public:
Obra();
~Obra();
int get_id_obra();
bool get_arquivada();
std::string get_nome_obra();


};
#endif