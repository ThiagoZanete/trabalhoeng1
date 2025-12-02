/**
 * @file funcional_tests.cpp
 * @brief Testes funcionais do simulador.
 *
 * Este arquivo contém três testes que verificam se o simulador funciona
 * corretamente em diferentes cenários:
 *
 * - **ExponentialFuncionalTest:**  
 *   Verifica a transferência proporcional baseada no valor do sistema de origem.
 *
 * - **LogisticalFuncionalTest:**  
 *   Testa o comportamento de um fluxo logístico (crescimento limitado).
 *
 * - **ComplexFuncionalTest:**  
 *   Testa vários sistemas e fluxos ao mesmo tempo para avaliar interações
 *   mais complexas.
 *
 * Em cada teste:
 *  - Cria-se um Model.
 *  - Os Systems e Flows são configurados.
 *  - A simulação é executada com Model::run().
 *  - Os valores finais são verificados com asserts.
 *
 * Esses testes ajudam a garantir que a simulação continue correta após
 * mudanças no código.
 *
 * @author Thiago Zanete
 * @date 2025
 */

#include "funcional_tests.h"

#include <math.h>
#include <assert.h>

using namespace std;

void exponentialFuncionalTest(){
    cout << "===== ExponentialFuncionalTest =====\n";

    ModelImpl *model = new ModelImpl;
    
    /**
     * @brief System iniciado com valor 100.
    */
    System *pop1 = new SystemImpl(100.0);
    pop1->getValue();
    /**
     * @brief System iniciado com valor 0.
    */
    System *pop2 = new SystemImpl(0.0);

    /**
     * @brief Flow usado na transferência.
    */
    ExponentialFlow *flow = new ExponentialFlow();
    flow->setSource(pop1);
    flow->setTarget(pop2);

    model->add(pop1);
    model->add(pop2);
    model->add(flow);

    pop1->setValue(100.0);
    pop2->setValue(0.0);

    /**
     * @brief Executa a simulação de 0 a 100.
    */
    model->run(0, 100);
    
    /**
     * @brief Verifica o valor final do primeiro System.
    */
    assert(round(fabs(pop1->getValue() - 36.6032) < 0.0001));
    /**
     * @brief Verifica o valor final do segundo System.
    */
    assert(round(fabs(pop2->getValue() - 63.3968) < 0.0001));

    cout << "OK\n" << endl;
}


void logisticalFuncionalTest(){
    cout << "===== LogisticalFuncionalTest =====\n";

    Model *model = new ModelImpl;

    /**
     * @brief System iniciado com 100.
    */
    System *pop1 = new SystemImpl(100.0);
    /**
     * @brief System iniciado com 10.
    */
    System *pop2 = new SystemImpl(10.0);

    /**
     * @brief Flow logístico.
    */
    LogisticFlow *flow = new LogisticFlow();
    flow->setSource(pop1);
    flow->setTarget(pop2);

    model->add(pop1);
    model->add(pop2);
    model->add(flow);

    /**
     * @brief Executa a simulação de 0 a 100.
    */
    model->run(0, 100);
    
    /**
     * @brief Verifica o resultado final do primeiro System.
    */
    assert(round(fabs(pop1->getValue() - 88.2167) < 0.0001));
    /**
     * @brief Verifica o resultado final do segundo System.
    */
    assert(round(fabs(pop2->getValue() - 21.7833) < 0.0001));

    cout << "OK\n" << endl;
}


void complexFuncionalTest(){
    cout << "===== ComplexFuncionalTest =====\n";

    ModelImpl *model = new ModelImpl;

    /**
     * @brief Systems usados no teste, com seus valores iniciais.
    */
    SystemImpl *pop1 = new SystemImpl(100.0);
    SystemImpl *pop2 = new SystemImpl(0.0);
    SystemImpl *pop3 = new SystemImpl(100.0);
    SystemImpl *pop4 = new SystemImpl(0.0);
    SystemImpl *pop5 = new SystemImpl(0.0);
    
    /**
     * @brief Fluxos utilizados nas interações.
    */
    ExponentialFlow *flow1 = new ExponentialFlow();
    flow1->setSource(pop1);
    flow1->setTarget(pop2);

    ExponentialFlow *flow2 = new ExponentialFlow();
    flow2->setSource(pop1);
    flow2->setTarget(pop3);
    
    ExponentialFlow *flow3 = new ExponentialFlow();
    flow3->setSource(pop2);
    flow3->setTarget(pop5);

    ExponentialFlow *flow4 = new ExponentialFlow();
    flow4->setSource(pop2);
    flow4->setTarget(pop3);
    
    ExponentialFlow *flow5 = new ExponentialFlow();
    flow5->setSource(pop3);
    flow5->setTarget(pop4);

    ExponentialFlow *flow6 = new ExponentialFlow();
    flow6->setSource(pop4);
    flow6->setTarget(pop1);

    model->add(pop1);
    model->add(pop2);
    model->add(pop3);
    model->add(pop4);
    model->add(pop5);
    model->add(flow1);
    model->add(flow2);
    model->add(flow3);
    model->add(flow4);
    model->add(flow5);
    model->add(flow6);

    /**
     * @brief Executa a simulação de 0 a 100.
    */
    model->run(0, 100);

    /**
     * @brief Verifica os valores finais de cada System.
    */
    assert(round(fabs(pop1->getValue() - 31.8513) < 0.0001));
    assert(round(fabs(pop2->getValue() - 18.4003) < 0.0001));
    assert(round(fabs(pop3->getValue() - 77.1143) < 0.0001));
    assert(round(fabs(pop4->getValue() - 56.1728) < 0.0001));
    assert(round(fabs(pop5->getValue() - 16.4612) < 0.0001));

    cout << "OK\n" << endl;
}
