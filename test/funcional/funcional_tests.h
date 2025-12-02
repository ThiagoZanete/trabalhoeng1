/**
 * @file funcional_tests.h
 * @brief Declaração das classes de fluxo usadas nos testes e dos protótipos dos testes funcionais.
 *
 * Este arquivo define duas implementações simples de Flow (ExponentialFlow e LogisticFlow),
 * usadas exclusivamente para testes funcionais do simulador, além dos protótipos dos testes.
 *
 * As classes aqui definidas servem apenas como utilitários de teste e não fazem parte
 * da API pública. O objetivo delas é validar a integração entre Model, System e Flow.
 *
 * @author Thiago Zanete
 * @date 2025
 */

#ifndef _FUNCTIONAL_TESTS_H_
#define _FUNCTIONAL_TESTS_H_

#include "../../src/modelImpl.h"
#include "../../src/flowImpl.h"
#include "../../src/systemImpl.h"

/**
 * @class ExponentialFlow
 * @brief Flow simples proporcional ao valor do sistema de origem.
 *
 * Calcula um fluxo diretamente proporcional ao valor do source,
 * útil para testar transferências lineares entre Systems.
 *
 * Fórmula (execute):
 *    value = 0.01 * source->getValue()
 */
class ExponentialFlow : public FlowImpl {
public:
    /** @brief Construtor padrão. */
    ExponentialFlow(): FlowImpl() {}

    /**
     * @brief Construtor parametrizado.
     * @param source System de origem.
     * @param target System de destino.
     */
    ExponentialFlow(System *source, System *target): FlowImpl(source, target) {}

    /**
     * @brief Retorna o valor do fluxo proporcional ao source.
     * @return Valor calculado.
     */
    double execute() {
        return 0.01 * getSource()->getValue();
    }
};

/**
 * @class LogisticFlow
 * @brief Flow baseado em crescimento logístico no sistema de destino.
 *
 * Implementa uma taxa dependente exclusivamente do valor do target,
 * seguindo uma forma logística simplificada.
 *
 * Fórmula (execute):
 *    value = 0.01 * target->getValue() * (1 - target->getValue() / 70.0)
 */
class LogisticFlow : public FlowImpl {
public:
    /** @brief Construtor padrão. */
    LogisticFlow(): FlowImpl() {}

    /**
     * @brief Construtor parametrizado.
     * @param source System de origem.
     * @param target System de destino.
     */
    LogisticFlow(System *source, System *target): FlowImpl(source, target) {}

    /**
     * @brief Calcula a taxa logística baseada no target.
     * @return Valor do fluxo.
     */
    double execute() {
        return 0.01 * getTarget()->getValue() * (1 - (getTarget()->getValue() / 70.0));
    }
};

/**
 * @brief Teste funcional do fluxo exponencial.
 */
void exponentialFuncionalTest();

/**
 * @brief Teste funcional do fluxo logístico.
 */
void logisticalFuncionalTest();

/**
 * @brief Teste funcional com vários Systems e Flows para validar interações complexas.
 */
void complexFuncionalTest();

#endif // _FUNCTIONAL_TESTS_H_
