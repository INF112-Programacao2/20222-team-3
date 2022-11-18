#include "Exposicao.h"
#include "Usuario"

class Gerente : public Usuario
{
private:
    Exposicao **_exposicoes;
public:
    Gerente(int ID, double salario, Exposicao *exposicoes);
    ~Gerente();
    void verExposicoes();
    void arquivarObra();
    void atribuirFuncionario();
    virtual void calcularSalario();
    void get_ID();
    void get_salario();
    void get_exposicoes();
};
