#include "model.h"
#include "flow.h"
#include <vector>

using namespace std;

// Construtor
Model::Model(){}

// Destrutor
Model::~Model(){
    // Deleta todos os flows alocados
    for (Flow* f : flows) {
        delete f;
    }
    // Deleta todos os systems alocados
    for (System* s : systems) {
        delete s;
    }
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
