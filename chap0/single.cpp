#include <iostream>

#include "single.h"


//this way we set initial value of static member
bool Singleton::instanceFlag = false;
Singleton* Singleton::single = 0;

Singleton* Singleton::getInstance()
{
	if(instanceFlag){
		return single;
	}
	else{
		single = new Singleton();
		instanceFlag = true;
		return single;
	}
}

void Singleton::testMethod()
{
	//int i;
	std::cout << "test method from singleton " << &i << std::endl;
}

