// Lab 1 Problem B by Knox Crichton 
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
int main(int argc, char* argv[]){
	bool sent = true;
	vector<int> v; //vector holding all entries
	string r; // stdin reads as string
	while(getline(cin, r)){
		stringstream st(r); // converting string to int with stringstream
		int n =0;
		st >> n;
		v.push_back(n);
	}
	int s =0; // Sum
	int mi =v[0]; // Minimum, start with first value
	int ma =v[0]; // Maximum, start with first value
	for(int i=0;i<v.size();i++){
		s+=v[i]; // Add value to sum
		if(v[i] < mi){
			mi = v[i]; // if lower become new min
		}
		if(v[i] > ma){
			ma = v[i]; // if higher become new max
		}
	}	
	cout << "N   = " << v.size() << "\nsum = " << s << "\nmin = " << mi << "\nmax = " << ma << "\n";
	// i forgot how to use printf over the summer and didn't bother looking it up so this gonna be in cout 
}

