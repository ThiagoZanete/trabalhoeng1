#include "model.h"
#include "flow.h"
#include <vector>
#include <algorithm>

using namespace std;

// Construtor
Model::Model() : systems(), flows() {}
Model::Model(const string& name) :  name(name), systems(), flows(){}

// Destrutor
Model::~Model(){
}

Model::Model(const Model& model){
    name = model.name;
    systems = model.systems;
    flows = model.flows;
}

Model& Model::operator= (const Model &model){
    if(this == &model)
        return *this;
    name = model.name;
    systems = model.systems;
    flows = model.flows;

    return *this;
}

//get e seter
const list<System*>& Model::getSystems() const {
    return systems;
}
const list<Flow*>& Model::getFlows() const {
    return flows;
}
const string& Model::getName() const {
    return name;
}
void Model::setName(const string& n) {
    name = n;
}

// add polimórfico para System e Flow
bool Model::add(System *system){
    systems.push_back(system);
    return true;
}
bool Model::add(Flow *flow){
    flows.push_back(flow);
    return true;
}

//remove
bool Model::remove(System* s) {
    auto it = find(systems.begin(), systems.end(), s);
    if (it != systems.end()) {
        systems.erase(it);
        return true;
    }
    return false;
}
bool Model::remove(Flow* f) {
    auto it = find(flows.begin(), flows.end(), f);
    if (it != flows.end()) {
        flows.erase(it);
        return true;
    }
    return false;
}


// Executar
void Model::run(int startTime, int endTime){

    vector<double> results;

    for(int i = startTime; i < endTime; i++){
        
        results.clear();

        for(Flow* f : flows){
            results.push_back(f->execute());
        }

        auto itResult = results.begin(); 
        for(Flow* f : flows){
            
            if(f->getSource() != nullptr) {
                double sourceValue = f->getSource()->getValue();
                f->getSource()->setValue(sourceValue - *itResult);
            }
            
            if(f->getTarget() != nullptr) {
                double targetValue = f->getTarget()->getValue();
                f->getTarget()->setValue(targetValue + *itResult);
            }

            itResult++;
        }
    }
}
