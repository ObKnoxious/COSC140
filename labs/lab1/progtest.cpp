
// Lab 1 Problem B by Knox Crichton 
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
int main(int argc, char* argv[]){
	vector<string> test;
	string r;
	while(getline(cin, r)){
		test.push_back(r);
	}
	for(int i=0;i<test.size();i++){
		cout << test[i] << "\n";
	}
}

