// Lab 1 Problem C by Knox Crichton 
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
class Stats{
	// In the lab1.html it says to call this "stats", but I'm going to capitalize my class names because that drives me
	// insane unless it specifically says it has to be lowercase
	private:
		// Why is this private? Because my high school cs teacher had us make stuff like this private and 
		// no one ever told me otherwise
		vector<int> nums; // Equivelant of vector v from Prob B
		int min, max, sum;
	
	public: 
		Stats(){
			min =0;
			max =0;
			sum =0;	
		}

		void push(int p){
			nums.push_back(p);
		}
		void print(){
			// Should this actually print this here or return the string and thing output that seperately? Not sure so i went with the former
			// Also the whole looping and calculating thing should probably be in a different function but theres like 6 variables in this whole
			// thing so who really cares
			min = nums[0];
			max = nums[0];
			for(int i=0;i<nums.size();i++){
				sum+=nums[i];
				if(nums[i] < min){
					min = nums[i];
				}
				if(nums[i] > max){
					max = nums[i];
				}
			}
			cout << "N   = " << nums.size() << "\nsum = " << sum << "\nmin = " <<min << "\nmax = " << max << "\n";
			// i forgot how to use printf over the summer and didn't bother looking it up so this gonna be in cout 
		}
};
int main(int argc, char* argv[]){
	bool sent = true;
	//vector<int> v; //vector holding all entries
	string r; // stdin reads as string
	Stats x;
	while(getline(cin, r)){
		stringstream st(r); // converting string to int with stringstream
		int n =0;
		st >> n;
		x.push(n);
		//v.push_back(n);
	}
	x.print();
	//int s =0; // Sum
	//int mi =v[0]; // Minimum, start with first value
	//int ma =v[0]; // Maximum, start with first value
	//for(int i=0;i<v.size();i++){
	//	s+=v[i]; // Add value to sum
	//	if(v[i] < mi){
	//		mi = v[i]; // if lower become new min
	//	}
	//	if(v[i] > ma){
	//		ma = v[i]; // if higher become new max
	//	}
	//}	
	//cout << "N   = " << v.size() << "\nsum = " << s << "\nmin = " << mi << "\nmax = " << ma << "\n";
	// i forgot how to use printf over the summer and didn't bother looking it up so this gonna be in cout 
}

	
