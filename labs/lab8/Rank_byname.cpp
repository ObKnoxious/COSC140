#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <numeric>
#include <map>
#include <vector>
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



int main(int argc, char *argv[]) {
//mmandli
    //argv[1]: W (width of name field)
    	int w = atoi(argv[1]);
    //argv[2]: filename.txt
//:wq

  //open filename.txt
	ifstream f;
    	f.open(argv[2]);
	
	int cs;
	string fn, ln;
  //map<name_t,scores_t> NS;
	map<name_t,scores_t> NS;
	map<name_t, scores_t>::iterator it;
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
		if(NS.find(nm) == NS.end()){
			NS.insert(make_pair(nm, sc));
		}
	}
  //close filename.txt
	f.close();
	//cout << NS.size();
	for(it = NS.begin(); it != NS.end(); it++){
		it->first.print(w);
		it->second.print();
	}
  
	//while (NP map iterator loop) {
    //print name
	//print scores
  //}
}
