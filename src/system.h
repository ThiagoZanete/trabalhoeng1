#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <iostream>
#include <string>

using namespace std;

class System {
    string name;
    double value;

    public:
        System(string = "", double = 0.);
        System(const System& system);
        virtual ~System();

        System& operator=(const System& system);
        
        const string getName() const;
        bool setName(string name);
        
        const double getValue() const;
        bool setValue(double value);
};

#endif




