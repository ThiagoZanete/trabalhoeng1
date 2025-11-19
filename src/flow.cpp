#include "flow.h"
#include "system.h"

using namespace std;


Flow::Flow() : name(""), source(nullptr), target(nullptr) {}

Flow::Flow(const std::string& name, System* source, System* target):
    name(name), source(source), target(target){}

Flow::~Flow(){}

Flow::Flow(const Flow &flow){
    if(this == &flow) return;

    name = flow.getName();
    source = flow.getSource();
    target = flow.getTarget();
}


Flow& Flow::operator= (const Flow &flow){
    if(this == &flow)
        return *this;
    name = flow.getName();
    source = flow.getSource();
    target = flow.getTarget();
    return *this;
}

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

const string& Flow::getName() const{
    return name;
}
bool Flow::setName(const string& n){
    name = n;
    return true;
}