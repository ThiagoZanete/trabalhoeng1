/**
 * @file Model.h
 * @brief Definição da classe Model, que gerencia a simulação.
 *
 * A classe Model é o centro do simulador baseado na Teoria Geral de Sistemas.
 * Ela armazena listas de Systems e Flows e controla a evolução do sistema
 * aplicando os fluxos ao longo do tempo.
 *
 * O Model funciona como o "ambiente" onde tudo é coordenado:
 *  - Lista de sistemas
 *  - Lista de fluxos entre os sistemas
 *  - Execução da simulação
 *
 * @author Thiago Zanete
 * @date 2025
 */

#ifndef MODELIMPL_H_
#define MODELIMPL_H_

#include <iostream>
#include <vector>
#include "model.h"

/**
 * @class Model
 * @brief Classe que gerencia sistemas, fluxos e a simulação.
 *
 * O Model mantém:
 *  - Uma lista de Systems, que guardam valores.
 *  - Uma lista de Flows, que transferem valores entre Systems.
 *
 * Seu papel principal é executar a simulação entre dois tempos,
 * aplicando todos os fluxos passo a passo.
 */
class ModelImpl : public Model{
protected:
    /**
     * @brief Lista de sistemas do modelo.
     *
     * Cada ponteiro representa um System usado na simulação.
     */
    std::vector<System*> systems;

    /**
     * @brief Lista de fluxos do modelo.
     *
     * Cada Flow define como o valor passa de um sistema para outro.
     */
    std::vector<Flow*> flows;

    /** @brief Marca o tempo atual da simulação. */
    int clock = 0;

public:
    /**
     * @brief Construtor padrão.
     *
     * Cria um modelo vazio, sem sistemas ou fluxos.
     */
    ModelImpl();

    /**
     * @brief Destrutor.
     *
     * Libera sistemas e fluxos quando necessário.
     */
    ~ModelImpl();

    /**
     * @brief Retorna o valor atual do clock.
     * @return Valor inteiro do clock.
     */
    int getClock();

    /**
     * @brief Retorna um iterator para o início da lista de systems.
     */
    iteratorSystem systemsBegin() const;

    /**
     * @brief Retorna um iterator para o fim da lista de systems.
     */
    iteratorSystem systemsEnd() const;

    /**
     * @brief Retorna um iterator para o início da lista de flows.
     */
    iteratorFlow flowsBegin() const;

    /**
     * @brief Retorna um iterator para o fim da lista de flows.
     */
    iteratorFlow flowsEnd() const;

    /**
     * @brief Adiciona um System ao modelo.
     *
     * @param s Ponteiro para o System.
     * @return true se foi adicionado, false caso contrário.
     */
    bool add(System* s);

    /**
     * @brief Adiciona um Flow ao modelo.
     *
     * @param f Ponteiro para o Flow.
     * @return true se foi adicionado, false caso contrário.
     */
    bool add(Flow* f);

    /**
     * @brief Remove um System do modelo.
     *
     * @param s Ponteiro para o System.
     * @return true se foi removido, false caso contrário.
     */
    bool remove(System* s);

    /**
     * @brief Remove um Flow do modelo.
     *
     * @param f Ponteiro para o Flow.
     * @return true se foi removido, false caso contrário.
     */
    bool remove(Flow* f);

    /**
     * @brief Executa a simulação.
     *
     * Aplica todos os fluxos do modelo entre startTime e endTime.
     * O comportamento depende da implementação de cada Flow.
     *
     * @param startTime Tempo inicial.
     * @param endTime Tempo final.
     * @return true se rodou corretamente, false caso contrário.
     */
    bool run(int startTime, int endTime);

private:
    /**
     * @brief Construtor de cópia.
     *
     * Copia listas de systems e flows de outro Model.
     */
    ModelImpl(const Model& other);

    /**
     * @brief Operador de atribuição.
     *
     * Copia o conteúdo de outro Model para este.
     *
     * @return Referência para o objeto atual.
     */
    ModelImpl& operator=(const Model& other);
};

#endif
