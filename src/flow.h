/**
 * @file Flow.h
 * @brief Declaração da classe abstrata Flow, responsável por representar um fluxo entre dois Systems.
 *
 * A classe Flow indica uma transferência de valor entre um System de origem
 * (source) e outro de destino (target). Ela serve como base para diferentes tipos
 * de fluxos usados no simulador (como linear, logístico etc.). As subclasses
 * devem implementar o método execute(), que calcula o valor transferido em cada
 * passo da simulação.
 *
 * @author Thiago Zanete
 * @date 2025
 */

#ifndef FLOW_H_
#define FLOW_H_

#include "system.h"

/**
 * @class Flow
 * @brief Classe base que define um fluxo entre dois Systems.
 *
 * Um Flow mantém ponteiros para o System de origem e o de destino.
 * O Model usa os Flows para calcular e aplicar transferências entre Systems
 * a cada iteração.
 */
class Flow {
public:

    /**
     * @brief Destrutor virtual.
     *
     * É virtual para permitir herança correta. Flow não é dono dos Systems
     * apontados.
     */
    virtual ~Flow() {};

    /**
     * @brief Operador de atribuição.
     *
     * Copia os ponteiros source e target com segurança.
     *
     * @param other Objeto a ser copiado.
     * @return Referência para *this.
     */
    virtual Flow& operator=(const Flow& other) = 0;

    /**
     * @brief Define o System de origem.
     *
     * @param s Ponteiro para o System de origem. Pode ser nullptr.
     * @return true se definido corretamente.
     */
    virtual bool setSource(System* s) = 0;

    /**
     * @brief Obtém o System de origem.
     *
     * @return Ponteiro para o System de origem (ou nullptr).
     */
    virtual System* getSource() const = 0;

    /**
     * @brief Define o System de destino.
     *
     * @param t Ponteiro para o System de destino. Pode ser nullptr.
     * @return true se definido corretamente.
     */
    virtual bool setTarget(System* t) = 0;

    /**
     * @brief Obtém o System de destino.
     *
     * @return Ponteiro para o System de destino (ou nullptr).
     */
    virtual System* getTarget() const = 0;

    /**
     * @brief Calcula o valor do fluxo neste passo.
     *
     * Deve ser implementado pelas subclasses para definir a lógica de
     * transferência entre origem e destino.
     *
     * @return Valor calculado do fluxo.
     */
    virtual double execute() = 0;
};

#endif // FLOW_H_
