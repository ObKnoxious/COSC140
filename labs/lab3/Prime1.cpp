// Prime 1 Lab 3 by Knox Crichton
#include <iostream>
using namespace std;

bool isprime(int number) {
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

int main()
{
	int number;

	while (cin >> number) {
	  if (isprime(number))
	    cout << number << " is a prime number\n";
	}
}
