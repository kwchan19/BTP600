/*********************************************/
/*                                           */
/*  BTP600                                   */
/*  a3 tester                                */
/*                                           */
/*********************************************/

#include "adapter.h"
#include <iostream>
using namespace std;

int main(void){
	
	Stack* s=new ObjectAdapter();
	if(s->isEmpty() && s->numItems()==0){
		cout << "test 1 passed" << endl;
	}
	else{
		cout << "test 1 failed " << endl;
	}

	s->push(5);
	s->push(10);
	s->push(11);
	if(!s->isEmpty() && s->numItems()==3 && s->top() == 11){
		cout << "test 2 passed" << endl;
	}
	else{
		cout << "test 2 failed " << endl;
	}


	s->pop();
	if(!s->isEmpty() && s->numItems()==2 && s->top() == 10){
		cout << "test 3 passed" << endl;
	}
	else{
		cout << "test 3 failed " << endl;
	}

	s->push(15);
	if(!s->isEmpty() && s->numItems()==3 && s->top() == 15){
		cout << "test 4 passed" << endl;
	}
	else{
		cout << "test 4 failed " << endl;
	}

	s->pop();
	if(!s->isEmpty() && s->numItems()==2 && s->top() == 10){
		cout << "test 5 passed" << endl;
	}
	else{
		cout << "test 5 failed " << endl;
	}


	s->pop();
	if(!s->isEmpty() && s->numItems()==1 && s->top() == 5){
		cout << "test 6 passed" << endl;
	}
	else{
		cout << "test 6 failed " << endl;
	}

	s->pop();
	if(s->isEmpty() && s->numItems()==0){
		cout << "test 7 passed" << endl;
	}
	else{
		cout << "test 7 failed " << endl;
	}
	delete s;
	s=new ClassAdapter();
	if(s->isEmpty() && s->numItems()==0){
		cout << "test 8 passed" << endl;
	}
	else{
		cout << "test 8 failed " << endl;
	}

	s->push(5);
	s->push(10);
	s->push(11);
	if(!s->isEmpty() && s->numItems()==3 && s->top() == 11){
		cout << "test 9 passed" << endl;
	}
	else{
		cout << "test 9 failed " << endl;
	}


	s->pop();
	if(!s->isEmpty() && s->numItems()==2 && s->top() == 10){
		cout << "test 10 passed" << endl;
	}
	else{
		cout << "test 10 failed " << endl;
	}

	s->push(15);
	if(!s->isEmpty() && s->numItems()==3 && s->top() == 15){
		cout << "test 11 passed" << endl;
	}
	else{
		cout << "test 11 failed " << endl;
	}

	s->pop();
	if(!s->isEmpty() && s->numItems()==2 && s->top() == 10){
		cout << "test 12 passed" << endl;
	}
	else{
		cout << "test 12 failed " << endl;
	}


	s->pop();
	if(!s->isEmpty() && s->numItems()==1 && s->top() == 5){
		cout << "test 13 passed" << endl;
	}
	else{
		cout << "test 13 failed " << endl;
	}

	s->pop();
	if(s->isEmpty() && s->numItems()==0){
		cout << "test 14 passed" << endl;
	}
	else{
		cout << "test 14 failed " << endl;
	}
	delete s;	

}