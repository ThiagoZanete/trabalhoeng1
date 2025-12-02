/**
 * @file Flow.cpp
 * @brief Implementação da classe Flow.
 *
 * Fornece a estrutura básica para representar um fluxo entre dois Systems.
 * As subclasses devem sobrescrever execute() para definir como o fluxo será calculado.
 *
 * O Model utiliza os Flows para simular a troca de valores entre Systems em um
 * ambiente baseado na Teoria Geral de Sistemas.
 *
 * @author Thiago Zanete
 * @date 2025
 */

#include "flowImpl.h"

using namespace std;

FlowImpl::FlowImpl() : source(nullptr), target(nullptr) {}

FlowImpl::FlowImpl(System* source, System* target)
    : source(source), target(target) {}

FlowImpl::~FlowImpl() {}

FlowImpl::FlowImpl(const Flow &flow) {
    if (this == &flow) return;
    source = flow.getSource();
    target = flow.getTarget();
}

// Source / Target
bool FlowImpl::setSource(System* s) {
    source = s;
    return true;
}

System* FlowImpl::getSource() const {
    return source;
}

bool FlowImpl::setTarget(System* t) {
    target = t;
    return true;
}

System* FlowImpl::getTarget() const {
    return target;
}

Flow& FlowImpl::operator=(const Flow &flow) {

    if (this == &flow)
        return *this;

    source = flow.getSource();
    target = flow.getTarget();

    return *this;
}
