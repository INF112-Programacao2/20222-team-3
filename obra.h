#ifndef INF112_OBRA_H
#define INF112_OBRA_H
#include <iostream>

class Obra {
private:
int id_obra;
bool arquivada;
std::string nome_obra;
public:
Obra(int id_obra_, bool arquivada_, std::string nome_obra_);
~Obra();
int get_id_obra();
bool get_arquivada();
std::string get_nome_obra();


};
#endif