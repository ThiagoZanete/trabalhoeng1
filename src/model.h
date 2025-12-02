/**
 * @file Model.h
 * @brief Declara a classe Model, responsável por organizar a simulação.
 *
 * O Model é o centro do simulador baseado na Teoria Geral de Sistemas.
 * Ele guarda e controla listas de Systems e Flows, executando a evolução
 * do sistema ao aplicar os fluxos ao longo do tempo.
 *
 * O Model funciona como o "ambiente" onde ocorre a simulação, gerenciando:
 *  - A lista de sistemas do modelo
 *  - A lista de fluxos conectando esses sistemas
 *  - A execução da simulação ao longo do tempo
 *
 * @author Thiago Zanete
 * @date 2025
 */

#ifndef MODEL_H_
#define MODEL_H_

#include <iostream>
#include <vector>
#include "system.h"
#include "flow.h"

/**
 * @class Model
 * @brief Gerencia Systems, Flows e a execução da simulação.
 *
 * O Model mantém:
 *  - Uma lista de Systems, que guardam valores.
 *  - Uma lista de Flows, que transferem valores entre Systems.
 *
 * Sua função principal é rodar a simulação entre dois instantes,
 * aplicando todos os fluxos a cada passo de tempo.
 */
class Model {
public:
    /**
     * @brief Destrutor.
     *
     * Libera os elementos armazenados quando necessário.
     */
    virtual ~Model() {};

    /**
     * @brief Operador de atribuição.
     *
     * Permite copiar outro Model, substituindo o conteúdo atual.
     *
     * @param other Modelo a ser copiado.
     * @return Referência para o próprio objeto.
     */
    virtual Model& operator=(const Model& other) = 0;

    /**
     * @brief Tipo de iterador para percorrer Systems.
     */
    typedef std::vector<System*>::const_iterator iteratorSystem;

    /**
     * @brief Retorna iterador para o início da lista de Systems.
     */
    virtual iteratorSystem systemsBegin() const = 0;

    /**
     * @brief Retorna iterador para o fim da lista de Systems.
     */
    virtual iteratorSystem systemsEnd() const = 0;

    /**
     * @brief Tipo de iterador para percorrer Flows.
     */
    typedef std::vector<Flow*>::const_iterator iteratorFlow;

    /**
     * @brief Retorna iterador para o início da lista de Flows.
     */
    virtual iteratorFlow flowsBegin() const = 0;

    /**
     * @brief Retorna iterador para o fim da lista de Flows.
     */
    virtual iteratorFlow flowsEnd() const = 0;

    /**
     * @brief Adiciona um System ao modelo.
     *
     * @param s Ponteiro para o System.
     * @return true se foi adicionado, false caso contrário.
     */
    virtual bool add(System* s) = 0;

    /**
     * @brief Adiciona um Flow ao modelo.
     *
     * @param f Ponteiro para o Flow.
     * @return true se foi adicionado, false caso contrário.
     */
    virtual bool add(Flow* f) = 0;

    /**
     * @brief Remove um System do modelo.
     *
     * @param s Ponteiro para o System.
     * @return true se foi removido, false caso contrário.
     */
    virtual bool remove(System* s) = 0;

    /**
     * @brief Remove um Flow do modelo.
     *
     * @param f Ponteiro para o Flow.
     * @return true se foi removido, false caso contrário.
     */
    virtual bool remove(Flow* f) = 0;

    /**
     * @brief Executa a simulação.
     *
     * A simulação aplica todos os fluxos entre os tempos informados.
     * O comportamento depende das implementações específicas dos Flows.
     *
     * @param startTime Tempo inicial.
     * @param endTime Tempo final.
     * @return true se a simulação ocorreu sem erros.
     */
    virtual bool run(int startTime, int endTime) = 0;
};

#endif // MODEL_H_
