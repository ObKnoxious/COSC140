
// Lab 7 Knox Crichton
#include <iostream>
#include <vector>
#include <set>
#include <bits/stdc++.h>
using namespace std;
class prime_partition{
	public:
		prime_partition();
		void operator()(int o);

	private:
		void create_pset();
		bool is_prime(int number);
		void compute_partitions(vector<int> & n, const int & t, int s=0);
		void print_partitions();
		set<int> pset;
		int pset_min, pset_max;
		unsigned int max_terms;
		vector<vector<int> > partitions;

};


bool prime_partition::is_prime(int number) {
	if(number <= 1){
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
}

prime_partition::prime_partition(){
	create_pset();
}

void prime_partition::create_pset(){
	for(int i = 2; i < 2000; i++){
		if(is_prime(i)){
			pset.insert(i);
		}
	}
	pset_min = *pset.begin();
	pset_max = *pset.rbegin();

}

void prime_partition::operator()(int o){
	//cout << "in operator()\n";
	if(o < 2 || 0 > 2000){
		return;
	}
	if(o % 2 ==0){
		max_terms =2;
	}else{
		max_terms=3;
	}
	partitions.clear();
	vector<int> temp;
	compute_partitions(temp,o,0);
	print_partitions();
}

void prime_partition::compute_partitions(vector<int> & n, const int & t, int s){
	if(s == t){
		if(n.size() == max_terms){
			partitions.push_back(n);
		}else if(n.size() < max_terms){
			max_terms = n.size();
			partitions.clear();
			partitions.push_back(n);
			return;
		}
	}
	if(s > t || n.size() > max_terms){
	       return;
	}
	set<int>::iterator  start = pset.begin();
	set<int>::iterator end;
	if(n.size() == 0){
		end = pset.upper_bound(t);
	}else{
		end = pset.upper_bound(n.back());
	}
	//vector<int>::iterator ii;
	set<int>::iterator ii; // = start;
	for(ii = start; ii != end; ii++){
		n.push_back(*ii);
		compute_partitions(n, t, s + *ii);
		n.pop_back();
	}

}	

void prime_partition::print_partitions(){
	for(unsigned int i =0; i < partitions.size(); i++){
		for(unsigned int j=0; j < partitions[i].size(); j++){
			cout << partitions[i][j] << " ";
		}
		cout << "\n";
	}
}


int main(int argc, char *argv[])
{
  prime_partition goldbach;

  int number;
  while (1) {
	cout << "number = ";
    cin >> number;
	if (cin.eof())
	  break;
	
	goldbach(number);
  }

  cout << "\n";
}
