#include "system.h"

using namespace std;


// construtor e destrutor
System::System(string name, double value):
    name(name), value(value){}

System::~System(){}

// construtor de copia
System::System(const System& system){
    name = system.getName();
    value = system.getValue();
}

// getters e setters
const string System::getName() const{
    return name;
}
bool System::setName(string name){
    this->name = name;
    return true;
}
bool System::setValue(double value){
    this->value = value;
    return true;
}
const double System::getValue() const{
    return value;
}

// operador de atribuiçaõ
System& System::operator= (const System &system){
    if(this == &system)
        return *this;

    name = system.getName();
    value = system.getValue();

    return *this;
}







