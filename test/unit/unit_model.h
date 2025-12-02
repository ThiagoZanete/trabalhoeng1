#ifndef _UNIT_MODEL_H_
#define _UNIT_MODEL_H_

#include "../../src/flowImpl.h"

/**
 * @brief Teste unitário para verificar o construtor padrão de Model.
 */
void unit_Model_constructor_default();

/**
 * @brief Teste unitário para verificar o destrutor de Model.
 */
void unit_Model_destructor();

/**
 * @brief Teste unitário para verificar o método getClock().
 */
void unit_Model_getClock();

/**
 * @brief Teste unitário para verificar o método add() com System*.
 */
void unit_Model_add_System();

/**
 * @brief Teste unitário para verificar o método add() com Flow*.
 */
void unit_Model_add_Flow();

/**
 * @brief Teste unitário para verificar o método removeSystem().
 */
void unit_Model_removeSystem();

/**
 * @brief Teste unitário para verificar o método removeFlow().
 */
void unit_Model_removeFlow();

/**
 * @brief Teste unitário para verificar o método run().
 */
void unit_Model_run();

/**
 * @brief Teste unitário para verificar o método systemsBegin().
 */
void unit_Model_systemsBegin();

/**
 * @brief Teste unitário para verificar o método systemsEnd().
 */
void unit_Model_systemsEnd();

/**
 * @brief Teste unitário para verificar o método systemsSize().
 */
void unit_Model_systemsSize();

/**
 * @brief Teste unitário para verificar o método flowsBegin().
 */
void unit_Model_flowsBegin();

/**
 * @brief Teste unitário para verificar o método flowsEnd().
 */
void unit_Model_flowsEnd();

/**
 * @brief Teste unitário para verificar o método flowsSize().
 */
void unit_Model_flowsSize();

/**
 * @brief Teste unitário para verificar a sobrecarga do operador de atribuição (=).
 */
void unit_Model_assignOverload();

#endif
