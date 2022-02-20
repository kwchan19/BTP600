#include "a5.h"

//Set state
void FSMachine::state(State* s){
    name_ = s;
}
void State::state(FSMachine * f, State * s){
    f->state(s);
}

//FSMachine
void FSMachine::actionOne(){
    name_->actionOne(this);
}
void FSMachine::actionTwo(){
    name_->actionTwo(this);
}
void FSMachine::actionThree(){
    name_->actionThree(this);
}
int FSMachine::doOperation(int a, int b){
    return name_->doOperation(a,b);
}
statename FSMachine::stateName(){
    return name_->stateName();
}
FSMachine::FSMachine(){
    name_ = stateA::getState();
}

//State A
stateA* stateA::temporary = nullptr;
stateA* stateA::getState(){
    if (temporary == nullptr) {
        temporary = new stateA();
    }
    return temporary;
}

statename stateA::stateName(){
    return A;
}

int stateA::doOperation(int a, int b){
    return a+b;
}

void stateA::actionOne(FSMachine * v){
    state(v, stateB::getState());
}

void stateA::actionTwo(FSMachine * v){
    state(v, stateA::getState());
}

void stateA::actionThree(FSMachine * v){
    state(v, stateD::getState());
}

//State B
stateB* stateB::temporary = nullptr;
stateB* stateB::getState(){
    if (temporary == nullptr) {
        temporary = new stateB();
    }
    return temporary;
}

statename stateB::stateName(){
    return B;
}

int stateB::doOperation(int a, int b){
    return a - b;
}

void stateB::actionOne(FSMachine * v){
    state(v, stateC::getState());
}

void stateB::actionTwo(FSMachine * v){
    state(v, stateA::getState());
}

void stateB::actionThree(FSMachine * v){
    state(v, stateD::getState());
}

//Class C
stateC* stateC::temporary = nullptr;
stateC* stateC::getState(){
    if (temporary == nullptr) {
        temporary = new stateC();
    }
    return temporary;
}

statename stateC::stateName(){
    return C;
}

int stateC::doOperation(int a, int b){
    return a * b;
}

void stateC::actionOne(FSMachine * v){
    state(v, stateB::getState());
}

void stateC::actionTwo(FSMachine * v){
    state(v, stateA::getState());
}

void stateC::actionThree(FSMachine * v){
    state(v, stateD::getState());
}

//State D
stateD* stateD::temporary = nullptr;
stateD* stateD::getState(){
    if (temporary == nullptr){
        temporary = new stateD();
    }
    return temporary;
}

statename stateD::stateName(){
    return D;
}

int stateD::doOperation(int a, int b){
    int total = 0;
    if (b > 0) {
        total = a / b;
    }
    return total;
}

void stateD::actionOne(FSMachine * v){
    state(v, stateA::getState());
}

void stateD::actionTwo(FSMachine * v){
    state(v, stateC::getState());
}

void stateD::actionThree(FSMachine * v){
    state(v, stateD::getState());
}
