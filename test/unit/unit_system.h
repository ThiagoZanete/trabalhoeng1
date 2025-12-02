#ifndef _UNIT_SYSTEM_H_
#define _UNIT_SYSTEM_H_

#include "../../src/systemImpl.h"

/**
 * @brief Teste unitário para verificar o construtor padrão de SystemImpl.
 */
void unit_System_constructor_default();

/**
 * @brief Teste unitário para verificar o construtor de SystemImpl com valor inicial.
 */
void unit_System_constructor_with_value();

/**
 * @brief Teste unitário para verificar o construtor de cópia de SystemImpl.
 */
void unit_System_copy_constructor();

/**
 * @brief Teste unitário para verificar o destrutor de SystemImpl.
 */
void unit_System_destructor();

/**
 * @brief Teste unitário para verificar o método getValue().
 */
void unit_System_getValue();

/**
 * @brief Teste unitário para verificar o método setValue().
 */
void unit_System_setValue();

/**
 * @brief Teste unitário para verificar a sobrecarga do operador de atribuição (=).
 */
void unit_System_assignOverload();

#endif
