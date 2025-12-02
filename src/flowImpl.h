/**
 * @file Flow.h
 * @brief Declaração da classe abstrata Flow, que representa um fluxo entre dois Systems.
 *
 * A classe Flow indica uma transferência de valor entre um System de origem
 * (source) e um de destino (target). Ela serve como base para os diferentes
 * tipos de fluxos usados no simulador (como fluxo linear, logístico etc.).
 * As subclasses precisam implementar o método execute(), que calcula o valor
 * transferido em cada passo da simulação.
 *
 * @author Thiago Zanete
 * @date 2025
 */

#ifndef FLOWIMPL_H_
#define FLOWIMPL_H_

#include "flow.h"

/**
 * @class Flow
 * @brief Classe base abstrata que define um fluxo entre dois Systems.
 *
 * Um Flow armazena ponteiros para o sistema de origem e para o de destino.
 * O Model usa esses objetos para calcular e aplicar transferências entre
 * Systems a cada iteração.
 */
class FlowImpl : public Flow {
protected:
    /** @brief Ponteiro para o System de origem. */
    System* source;

    /** @brief Ponteiro para o System de destino. */
    System* target;

public:
    /**
     * @brief Construtor padrão.
     *
     * Inicializa source e target como nullptr.
     */
    FlowImpl();

    /**
     * @brief Construtor com parâmetros.
     *
     * @param source Ponteiro para o System de origem (pode ser nullptr).
     * @param target Ponteiro para o System de destino (pode ser nullptr).
     */
    FlowImpl(System* source, System* target);

    /**
     * @brief Construtor de cópia.
     *
     * Copia os ponteiros source e target (cópia superficial).
     * Caso seja necessária cópia profunda, isso deve ser feito pela subclasse.
     *
     * @param flow Objeto Flow a ser copiado.
     */
    FlowImpl(const Flow& flow);

    /**
     * @brief Operador de atribuição.
     *
     * Copia os ponteiros source e target de forma segura.
     *
     * @param other Objeto a ser atribuído.
     * @return Referência para *this.
     */
    Flow& operator=(const Flow& other);

    /**
     * @brief Destrutor virtual.
     *
     * Mantido virtual para permitir destruição correta em herança.
     * Flow não é responsável por liberar os Systems apontados.
     */
    virtual ~FlowImpl();

    /**
     * @brief Define o sistema de origem do fluxo.
     *
     * @param s Ponteiro para o System de origem (pode ser nullptr).
     * @return true se a operação foi bem-sucedida.
     */
    bool setSource(System* s);

    /**
     * @brief Retorna o System de origem.
     *
     * @return Ponteiro para o System de origem (pode ser nullptr).
     */
    System* getSource() const;

    /**
     * @brief Define o sistema de destino do fluxo.
     *
     * @param t Ponteiro para o System de destino (pode ser nullptr).
     * @return true se a operação foi bem-sucedida.
     */
    bool setTarget(System* t);

    /**
     * @brief Retorna o System de destino.
     *
     * @return Ponteiro para o System de destino (pode ser nullptr).
     */
    System* getTarget() const;

    /**
     * @brief Calcula o valor do fluxo no passo atual.
     *
     * Deve ser implementado nas subclasses para definir a lógica da transferência.
     *
     * @return Valor calculado do fluxo (double).
     */
    virtual double execute() = 0;
};

#endif // FLOWIMPL_H_
