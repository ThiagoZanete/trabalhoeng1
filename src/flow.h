#ifndef FLOW_H_
#define FLOW_H_

#include "system.h"
#include <string> 

using namespace std;

class Flow{
    // Atributos conforme UML
    System *source;
    System *target;

    public:
        Flow(System* source = nullptr, System* target = nullptr);
        
        virtual ~Flow();
        Flow(const Flow&) = delete;


        Flow& operator=(const Flow&) = delete;

        // Métodos Get/Set conforme UML
        System* getSource() const;
        bool setSource(System*);

        System* getTarget() const;
        bool setTarget(System*);
        
        virtual double execute() = 0;
};

#endif



/*
#ifndef FLOW_H_
#define FLOW_H_

#include "system.h"

using namespace std;

class Flow{
    // Atributos conforme UML
    System *source;
    System *target;

    public:
        // Construtores
        Flow(System* source = nullptr, System* target = nullptr);
        virtual ~Flow();

        // Métodos Get/Set conforme UML
        System* getSource() const;
        bool setSource(System*);

        System* getTarget() const;
        bool setTarget(System*);
        
        // Método principal
        virtual double execute() = 0;//método virtual puro para tornar a classe abstrata
};

#endif
*/