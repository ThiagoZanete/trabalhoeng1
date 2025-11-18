#include "flow.h"
#include "system.h"

using namespace std;

// Construtor
Flow::Flow(System* source, System* target):
    source(source), target(target){}

Flow::~Flow(){}

// Getters e Setters
System *Flow::getSource() const{
    return source;
}

bool Flow::setSource(System* system){
    source = system;
    return true;
}

System *Flow::getTarget() const{
    return target;
}

bool Flow::setTarget(System* system){
    target = system;
    return true;
}

