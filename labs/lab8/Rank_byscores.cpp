#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;

class name_t{
	public:
		name_t();
		name_t(const string &, const string &);

		bool operator <(const name_t &) const;
		void print(int w=0) const;
		string getName() const;

	private:
		string name;
};

name_t::name_t(){
	name = "";
}
name_t::name_t(const string & fname, const string & lname){
	name = lname + ", " + fname;	       
}
string name_t::getName() const{
	return name;
}
bool name_t::operator <(const name_t & c) const{
	return	name < c.getName();
}
void name_t::print(int w) const{
	cout << setw(w+3) << setfill('.') << left << name + " ";
}



class scores_t{
	public:
		scores_t();
		void insert(int n);
		void insert_done();
		void print();
		float getMean() const;
	private:
		vector<int> scores;
		float mean;
};
scores_t::scores_t(){
	mean = 0.0;
}
void scores_t::insert(int n){
	scores.push_back(n);
}
void scores_t::insert_done(){
	if(scores.empty()){
		cout << "Scores was empty! \n";
		mean = 0.0;
	}
	else{
		mean = (float(accumulate(scores.begin(), scores.end(), float()))/ (scores.size()));
	}
}
void scores_t::print(){
	for(int i=0; i<scores.size();i++){
		cout << right << setfill(' ') << " " << setw(2) << scores[i];
	}
	cout << " : " << setprecision(1) << fixed  << mean << "\n";
}

float scores_t::getMean() const{
	return mean;
}
class namescores_t {
  //public:
	public:  
  //constructor(s);
		namescores_t();
		namescores_t(const name_t & name, const scores_t & score);
		bool operator<(const namescores_t & comp ) const;
		void print_name(int w=0);
		void print_scores();
	
    //bool operator<(...);
    
    //void print_name(int);
    //void print_scores();

  //private:
  	private:
		name_t n;
		scores_t s;
    //name_t name;
    //scores_t scores;
};

namescores_t::namescores_t(){
}
namescores_t::namescores_t(const name_t & name, const scores_t & score){
	n = name;
	s = score;
}
void namescores_t::print_name(int w){
	n.print(w);
}
void namescores_t::print_scores(){
	s.print();
}
bool namescores_t::operator<(const namescores_t & comp ) const{
	if(s.getMean() == comp.s.getMean()){
		return comp.n < this->n;
	}else{
		return s.getMean() < comp.s.getMean();
	}
	//if(comp.getMean != mean){

		//return comp.getMean() < mean;
	//}else{
		//return !(n<comp.getName());
	//}	
}
//int main(...) {
  //commandline parsing
    //argv[1]: W (width of name field)
    //argv[2]: K (number of elements to print)
    //argv[3]: filename.txt

  //open filename.txt
  //vector<namescores_t> NS;

  //while (more data in file) {
    //add first and lastname to name_t object

    //while (more scores) {
      //insert score into scores_t object
    //have insert_done calculate mean score

    //create and insert namescores_t object into NS list //}

  //close filename.txt

  //turn NS list into binary max-heap

  //for (K data elements && heap not empty) {
    //extract top of heap element

    //print name
    //print scores
  //}
int main(int argc, char *argv[]) {
//mmandli
    //argv[1]: W (width of name field)
    	int w = atoi(argv[1]);
    //argv[2]: filename.txt
//:wq
	int p = atoi(argv[2]);
  //open filename.txt
	ifstream f;
    	f.open(argv[3]);
	
	int cs;
	string fn, ln;
  //map<name_t,scores_t> NS;
	vector<namescores_t> nmsc;
	//map<name_t, scores_t>::iterator it;
  //while (more data in file) {
  	string d;
	while(getline(f,d)){
		istringstream line(d);
		//string word;
		line >> fn >> ln;
		name_t nm(fn,ln);
		scores_t sc;
		while(line >> cs){
			sc.insert(cs);
		}	
		//int ct = 0;

		//while(line >> word){
			//if(ct == 0){
				//fn = word;
			//}else if(ct == 1){
				//ln = word;
			//}else{
				//int x =atoi(word.c_str());
				//sc.insert(x);
			//}
			//ct++;
		//}
		sc.insert_done();
		//name_t nm(fn,ln);
		namescores_t ns(nm,sc);
		nmsc.push_back(ns);

	}
  //close filename.txt
	f.close();
	make_heap(nmsc.begin(), nmsc.end());
	for(int i =0; i < p && !nmsc.empty(); i++){
		nmsc.at(0).print_name(w);
		nmsc.at(0).print_scores();
		pop_heap(nmsc.begin(), nmsc.end());
		nmsc.pop_back();

	}
	//cout << NS.size();
	//for(it = NS.begin(); it != NS.end(); it++){
		//it->first.print(w);
		//it->second.print();
	//}
 	 
	//while (NP map iterator loop) {
    //print name
	//print scores
  //}
  	return 0;
}
