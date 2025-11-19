#ifndef FLOW_H_
#define FLOW_H_

#include "system.h"
#include <string> 

using namespace std;

class Flow{
    // Atributos conforme UML
    protected:
        std::string name;
        System *source;
        System *target;
        
    public:
        Flow();
        Flow(const std::string& name, System* source = nullptr, System* target = nullptr);
        Flow(const Flow&);

        virtual ~Flow();
        Flow& operator=(const Flow&);

        const std::string& getName() const;   
        bool setName(const std::string& n);

        System* getSource() const;
        bool setSource(System*);

        System* getTarget() const;
        bool setTarget(System*);
        
        virtual double execute() = 0;
};

#endif

