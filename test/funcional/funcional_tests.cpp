#include "funcional_tests.h"
#include "../../src/model.h"

#include <math.h>
#include <assert.h>
#include <iostream> 

using namespace std;

// Classe conforme Caso de Uso (Fig 13) e UML
class Exponencial : public Flow {
    public:
        Exponencial(): Flow() {}
        Exponencial(System *source, System *target): 
            Flow(name, source, target){}
            
        // Método 'execute' conforme UML
        double execute(){
            return 0.01 * getSource()->getValue();
        }
};

void exponentialTest(){
    Model model;

    System* pop1 = new System("pop1",100);
    System* pop2 = new System("pop2",0);

    Exponencial* flow = new Exponencial();
    flow->setSource(pop1);
    flow->setTarget(pop2);


    model.add(pop1);
    model.add(pop2);
    model.add(flow);

    cout << "iniciando teste exponencial" << endl;

    model.run(0, 100);
    
    assert(round(pop1->getValue() - 36.6032) < 0.0001);
    assert(round(pop2->getValue() - 63.3968) < 0.0001);

    cout << "teste exponencial: ok" << endl;
    cout << "\n";


}


// Classe conforme Caso de Uso (Fig 14) e UML
class FluxoLogistica : public Flow {
    public:
        FluxoLogistica(): Flow() {}
        FluxoLogistica(string& name, System *source, System *target): 
            Flow(name, source, target){}
            
        // Método 'execute' conforme UML
        double execute(){
            return 0.01 * getTarget()->getValue() * (1 - (getTarget()->getValue()/70.0));
        }
};

void logisticTest(){
    Model model;

    System* p1 = new System("p1", 100);
    System* p2 = new System("p2", 10);

    Flow* flow = new FluxoLogistica();
    flow->setSource(p1);
    flow->setTarget(p2);

    model.add(p1);
    model.add(p2);
    model.add(flow);
    cout << "iniciando teste logistico" << endl;

    model.run(0, 100);
    
    // Testes usam '->'
    assert(fabs(p1->getValue() - 88.2167) < 0.0001);
    assert(fabs(p2->getValue() - 21.7833) < 0.0001);

    cout << "teste logistico: ok" << endl; 
    cout << "\n";
}


void complexTest(){
    Model model;

    System* Q1 = new System("Q1",100);
    System* Q2 = new System("Q2",0);
    System* Q3 = new System("Q3",100);
    System* Q4 = new System("Q4",0);
    System* Q5 = new System("Q5",0);

    Flow* f = new Exponencial(Q1, Q2);
    Flow* g = new Exponencial(Q1, Q3);
    Flow* r = new Exponencial(Q2, Q5);
    Flow* t = new Exponencial(Q2, Q3);
    Flow* u = new Exponencial(Q3, Q4);
    Flow* v = new Exponencial(Q4, Q1);

    model.add(Q1);
    model.add(Q2);
    model.add(Q3);
    model.add(Q4);
    model.add(Q5);
    model.add(f);
    model.add(g);
    model.add(r);
    model.add(t);
    model.add(u);
    model.add(v);
    cout << "iniciando teste complexo" << endl;


    model.run(0, 100);


    assert(round(Q1->getValue() - 31.8513) < 0.0001);
    assert(round(Q2->getValue() - 18.4003) < 0.0001); 
    assert(round(Q3->getValue() - 77.1143) < 0.0001);
    assert(round(Q4->getValue() - 56.1728) < 0.0001);
    assert(round(Q5->getValue() - 16.4612) < 0.0001);

    cout << "teste complexo: ok" << endl;
}
