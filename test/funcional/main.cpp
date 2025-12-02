/**
 * @file main.cpp
 * @brief Executa os testes funcionais do simulador.
 *
 * Este arquivo contém apenas a função `main()`, responsável por invocar
 * os testes funcionais definidos em `functional_tests.cpp`. Ele atua como
 * ponto de entrada para validar o comportamento integrado do simulador,
 * verificando a interação entre Model, System e Flow por meio de cenários
 * específicos de teste.
 *
 * Os testes executados incluem:
 *  - Teste funcional com fluxo exponencial.
 *  - Teste funcional com fluxo logístico.
 *  - Teste funcional complexo envolvendo múltiplos fluxos.
 *
 * Cada teste utiliza asserções para garantir que o simulador produza
 * resultados consistentes, matematicamente corretos e de acordo com a
 * dinâmica esperada do modelo.
 *
 * @author Thiago Zanete
 * @date 2025
 */


 #include "funcional_tests.h"

#include "../../src/model.h"
#include "../../src/flow.h"
#include <assert.h>

using namespace std;

int main(void){
    exponentialFuncionalTest();
    logisticalFuncionalTest();
    complexFuncionalTest();
}