// Prime 1 Lab 3 by Knox Crichton
#include <iostream>
using namespace std;

class isprime {
	public:
		isprime() {}
		bool operator()(int number){
			if(number == 1 || number <= 0){
				return false;
			}else if(number > 2){
				for(int i =2; i < number; i++){
					if(number % i == 0){
						return false;
					}
				}
			}else{
				return true;
			}
		};
	private:
    
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
