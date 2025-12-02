/**
 * @file System.cpp
 * @brief Implementação da classe System.
 *
 * Implementa os métodos responsáveis por guardar e alterar o valor interno
 * de um System no simulador baseado na Teoria Geral de Sistemas. Essa classe
 * é usada pelo Model e pelos Flows para formar a dinâmica da simulação.
 *
 * @author Thiago Zanete
 * @date 2025
 */


#include "systemImpl.h"

using namespace std;

SystemImpl::SystemImpl() : value(0.0) {}

SystemImpl::SystemImpl(double value) : value(value) {}

SystemImpl::SystemImpl(const System& other) : value(other.getValue()) {}

SystemImpl& SystemImpl::operator=(const System& other) {
    if (this == &other) 
        return *this;
    value = other.getValue();
    return *this;
}

SystemImpl::~SystemImpl() {}

double SystemImpl::getValue() const {
    return value;
}

bool SystemImpl::setValue(double value){
    this->value = value;
    return true;
}