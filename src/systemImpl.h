/**
 * @file System.h
 * @brief Declaração da classe System, que representa um elemento básico do modelo.
 *
 * A classe System é uma das partes principais do simulador. Ela representa um
 * “estoque”, ou seja, algo que guarda um valor que pode mudar durante a simulação
 * conforme os fluxos atuam sobre ele.
 * 
 * @author Thiago Zanete
 * @date 2025
 */

#ifndef SYSTEMIMPL_H_
#define SYSTEMIMPL_H_

#include "system.h"

/**
 * @class System
 * @brief Representa um valor armazenado dentro do modelo.
 *
 * Um System guarda um único valor numérico que pode representar qualquer tipo
 * de quantidade, como recurso, população ou nível, dependendo do modelo.
 *
 * Ele é alterado durante a simulação pelos objetos Model e Flow.
 */
class SystemImpl : public System {
private:
    /**
     * @brief Valor mantido pelo sistema.
     *
     * Pode ser alterado diretamente pelo Model ou por meio dos Flows.
     */
    double value;

public:
    /**
     * @brief Construtor padrão.
     *
     * Cria um System com valor inicial igual a 0.
     */
    SystemImpl();

    /**
     * @brief Construtor com valor inicial.
     *
     * Cria um System já configurado com um valor específico.
     *
     * @param value Valor inicial.
     */
    SystemImpl(double value);

    /**
     * @brief Construtor de cópia.
     *
     * Copia o valor de outro System.
     *
     * @param other System a ser copiado.
     */
    SystemImpl(const System& other);

    /**
     * @brief Destrutor virtual.
     *
     * Virtual para permitir herança segura.
     */
    virtual ~SystemImpl();

    /**
     * @brief Define um novo valor.
     *
     * @param v Novo valor.
     * @return true se o valor foi atualizado.
     */
    bool setValue(double v);

    /**
     * @brief Retorna o valor atual.
     *
     * @return Valor armazenado.
     */
    double getValue() const;

private:
    /**
     * @brief Operador de atribuição.
     *
     * Copia o valor de outro System.
     *
     * @param other System a ser copiado.
     * @return Referência para o próprio objeto.
     */
    SystemImpl& operator=(const System& other);

};

#endif // SYSTEM_H_
