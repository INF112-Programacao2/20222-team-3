#include "Exposicao.h"
#include "Usuario"

class Gerente : public Usuario
{
private:
    Exposicao **exposicoes;
public:
    Gerente(/* args */);
    ~Gerente();
    void verExposicoes();
    void arquivarObra();
    void atribuirFuncionario();
    void calcularSalario()
};
