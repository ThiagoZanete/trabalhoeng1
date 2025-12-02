/**
 * @file System.h
 * @brief Declaração da classe System, que representa um elemento básico do modelo.
 *
 * A classe System é uma das partes principais do simulador baseado na
 * Teoria Geral de Sistemas. Ela representa um "estoque", ou seja, um valor
 * que pode mudar durante a simulação por meio dos Flows.
 * 
 * @author Thiago Zanete
 * @date 2025
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_

/**
 * @class System
 * @brief Representa um valor armazenado dentro do modelo.
 *
 * Um System guarda um único valor numérico, que pode significar
 * quantidade, população, nível, concentração etc., dependendo do modelo.
 *
 * A classe é usada pelo Model e pelos Flows, que alteram seu valor
 * durante a simulação.
 */
class System {
public:
    /**
     * @brief Destrutor virtual.
     *
     * Mantido virtual para permitir herança de forma segura.
     */
    virtual ~System() {};

    /**
     * @brief Operador de atribuição.
     *
     * Copia o valor de outro System.
     *
     * @param other System a ser copiado.
     * @return Referência para o próprio objeto.
     */
    virtual System& operator=(const System& other) = 0;

    /**
     * @brief Define o valor do System.
     *
     * @param v Novo valor.
     * @return true se o valor foi atualizado.
     */
    virtual bool setValue(double v) = 0;

    /**
     * @brief Retorna o valor atual.
     *
     * @return Valor armazenado no System.
     */
    virtual double getValue() const = 0;
};

#endif // SYSTEM_H_
