#include <cstdlib>
#include <iostream>
using namespace std;
enum statename {A,B,C,D};

class State;

class FSMachine{
    friend class State;
    State* name_;
    void state(State*s);
public:
    FSMachine();
    statename stateName();
    int doOperation(int a, int b);
    void actionOne();
    void actionTwo();
    void actionThree();
};

class State{
public:
    void state(FSMachine *f, State *s);
    virtual statename stateName() = 0;
    virtual int doOperation(int, int) = 0;
    virtual void actionOne(FSMachine*) = 0;
    virtual void actionTwo(FSMachine*) = 0;
    virtual void actionThree(FSMachine*) = 0;
};

class stateA : public State{
private:
    static stateA* temporary;
public:
    static stateA* getState();
    statename stateName();
    int doOperation(int, int);
    void actionOne(FSMachine*);
    void actionTwo(FSMachine*);
    void actionThree(FSMachine*);
};

class stateB : public State{
private:
    static stateB* temporary;
public:
    static stateB* getState();
    statename stateName();
    int doOperation(int, int);
    void actionOne(FSMachine*);
    void actionTwo(FSMachine*);
    void actionThree(FSMachine*);
};

class stateC : public State{
private:
    static stateC* temporary;
public:
    static stateC* getState();
    statename stateName();
    int doOperation(int, int);
    void actionOne(FSMachine*);
    void actionTwo(FSMachine*);
    void actionThree(FSMachine*);
};

class stateD : public State{
private:
    static stateD* temporary;
public:
    static stateD* getState();
    statename stateName();
    int doOperation(int, int);
    void actionOne(FSMachine*);
    void actionTwo(FSMachine*);
    void actionThree(FSMachine*);
};
