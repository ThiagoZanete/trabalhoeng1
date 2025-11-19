#include "system.h"

using namespace std;


// construtor e destrutor
System::System() : value(0.0) {}
System::System(double value) : value(value) {}
System::System(const string& name, double value): name(name), value(value){}
System::System(const System& system) : name(system.name), value(system.value) {}

System::~System(){}

// operador de atribuiçaõ
System& System::operator= (const System &system){
    if(this == &system)
        return *this;
    name = system.getName();
    value = system.getValue();
    return *this;
}

// getters e setters
const string System::getName() const{
    return name;
}
bool System::setName(string name){
    this->name = name;
    return true;
}
const double System::getValue() const{
    return value;
}
bool System::setValue(double value){
    this->value = value;
    return true;
}









