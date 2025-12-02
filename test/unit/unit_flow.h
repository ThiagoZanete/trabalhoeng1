#ifndef _UNIT_FLOW_H_
#define _UNIT_FLOW_H_

#include "../../src/flowImpl.h"

/**
 * @brief Teste unitário para verificar o construtor padrão de FlowImpl.
 */
void unit_Flow_constructor_default();

/**
 * @brief Teste unitário para verificar o construtor de FlowImpl com parâmetros source e target.
 */
void unit_Flow_constructor_with_source_target();

/**
 * @brief Teste unitário para verificar o construtor de cópia de FlowImpl.
 */
void unit_Flow_copy_constructor();

/**
 * @brief Teste unitário para verificar o destrutor de FlowImpl.
 */
void unit_Flow_destructor();

/**
 * @brief Teste unitário para verificar o método getValue().
 */
void unit_Flow_getValue();

/**
 * @brief Teste unitário para verificar o método setValue().
 */
void unit_Flow_setValue();

/**
 * @brief Teste unitário para verificar o método getSource().
 */
void unit_Flow_getSource();

/**
 * @brief Teste unitário para verificar o método setSource().
 */
void unit_Flow_setSource();

/**
 * @brief Teste unitário para verificar o método getTarget().
 */
void unit_Flow_getTarget();

/**
 * @brief Teste unitário para verificar o método setTarget().
 */
void unit_Flow_setTarget();

/**
 * @brief Teste unitário para verificar a sobrecarga do operador de atribuição (=).
 */
void unit_Flow_assignOverload();

#endif
