#include <iostream>
#include "add.h"
#include "f1.cpp"
int main(){
	std::cout<<Adder<int>().add(1,2);
	return 0;
}