#ifndef MODEL_H_
#define MODEL_H_

#include <iostream>
#include <list> 
#include "flow.h"
#include "system.h"

using namespace std;

class Model{
    protected:
        std:: string name;
        list<System*> systems;
        list<Flow*> flows;

    public:
        Model();
        Model(const std::string& name);
        Model(const Model& m);

        ~Model(); 
        Model& operator= (const Model&);
        
        const std::list<System*>& getSystems() const;
        const std::list<Flow*>& getFlows() const;

        const std::string& getName() const;   
        void setName(const std::string& n); 
        
        bool add(System*);
        bool add(Flow*);

        bool remove(System* s);
        bool remove(Flow* f);

        void run(int, int);
};

#endif
