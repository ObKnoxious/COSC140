// Prime 3 Lab 3 By Knox Crichton
#include <stdlib.h>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class isprime {
	public:
		isprime() {addPrime(2);}
		bool operator()(int);

		void addPrime(int n){
			pn.push_back(n);
		}
	private:
    		vector<int> pn {};
};

bool isprime::operator()(int number)
{
	if(binary_search(pn.begin(), pn.end(), number)){
		return true;
	}else if(number <=1){
		return false;
	}else if(number > 2){
		for(int i =2; i < number; i++){
			if(number % i == 0){
				return false;
			}
		}
	}

	//cout << "Adding prime to vect\n";
	addPrime(number);
	return true;
}

int random_number()
{	
	return 1+(rand() % (140-1+1));
}
void generate(int n, vector<int> &v){
	for(int i =0; i < n; i++){
		v.push_back(random_number());
	}
}
void transform(vector<int> v1, vector<bool> &v2){
	isprime pc;
	for(int i =0; i < v1.size(); i++){
		if(pc(v1.at(i))){
			v2.push_back(true);
		}else{
			v2.push_back(false);
		}
	}
}
int count(vector<bool> v){
	int r =0;
	for(int i =0; i <v.size(); i++){
		if(v.at(i)){
			r++;
		}
	}
	return r;
}


void extract_prime(vector<int> &n, vector<bool> &b, vector<int> &p)
{
	for(int i =0; i < n.size(); i++){
	     if(b.at(i)){
			p.push_back(n.at(i));
	     }
	}
}

void print(vector<int> v)
{
	// So the setw the first out is 4 and all others 5 in sprime?
	cout << setw(4) << v.at(0);
	for(int i = 1; i < v.size(); i++){
		cout << setw(5) << v.at(i);
		if((i+1) % 20 == 0 && i != 0){
			cout << "\n";
		}
	}
	cout << "\n";



}

int main(int argc, char *argv[])
{
	int N = 140;
	if(argc > 1){
		N = atoi(argv[1]);
	}


	srand(N);

	vector<int > genNum;
	vector<bool> arePrimes;

	generate(N, genNum);
	transform(genNum, arePrimes);

	int c = count(arePrimes);
	
	cout << "Sequence contains " << c << " prime numbers.\n";

	vector<int> thePrimes;
	extract_prime(genNum, arePrimes, thePrimes);

	cout << "All numbers in order appearance:\n";

	print(thePrimes);

	sort(thePrimes.begin(), thePrimes.end());
	vector<int>::iterator it;
	it = unique(thePrimes.begin(), thePrimes.end());
	thePrimes.resize(distance(thePrimes.begin(), it));

	cout << "Unique values in numerical order:\n";

	print(thePrimes);
}
