#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
int main(int argc, char* argv[]){
	cout << "Num args = " << argc << "\n";
	for(int i =0; i<argc; i++){
		cout << "argv[" << i <<  "] = " <<  &argv[i] << " " << argv[i] << "\n";
	}
}
