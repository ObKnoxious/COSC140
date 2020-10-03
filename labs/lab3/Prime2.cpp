// Prime 1 Lab 3 by Knox Crichton
#include <iostream>
#include <vector>
using namespace std;

class isprime {
	public:
		void addPrime(int n){
			pn.push_back(n);
		}
		isprime() {}
		bool operator()(int number){
			for(int i =0; i<pn.size(); i++){
				if(number == pn.at(i)){
					//cout << "Found in the loop!";
					return true;
				}
			}

			if(number <=1){
				return false;
			}else if(number > 2){
				for(int i =2; i < number; i++){
					if(number % i == 0){
						return false;
					}
				}
			}

//			cout << "Adding prime to vect\n";
			addPrime(number);
			return true;
		
			//cout << "Made is past if?\n";
		};

	private:
    		vector<int> pn{2};
};


int main()
{
	isprime pcheck;
	int number;

	while (cin >> number) {
	  if (pcheck(number))
	    cout << number << " is a prime number\n";
	}
}
