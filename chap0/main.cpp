// a small C++ program

#include <iostream>


#include "single.h"

// even though this funciton isn't incluced into header file, but make file
// will make every file into one exe file
extern int otherPrint();


int main()
{
	std::cout << "Hello World" << std::endl;
	otherPrint();
	
	Singleton *sc1,*sc2;
    sc1 = Singleton::getInstance();
    sc1->testMethod();
    sc2 = Singleton::getInstance();
    sc2->testMethod();
    
    //Singleton s3(*sc1); //copy constructor
    //s3.testMethod();
	
	return 0;
}
