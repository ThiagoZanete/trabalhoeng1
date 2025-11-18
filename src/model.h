#ifndef MODEL_H_
#define MODEL_H_

#include <iostream>
#include <list> 
#include "flow.h"
#include "system.h"

using namespace std;

class Model{
    list<System*> systems;
    list<Flow*> flows;

    private:
        Model& operator= (const Model&);
        Model(const Model&);

    public:
        Model();
        virtual ~Model(); 
        
        bool add(System*);
        bool add(Flow*);

        void run(int, int);
};

#endif
