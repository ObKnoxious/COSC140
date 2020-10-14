#include <vector>
#include <string>
#include <iostream>
#include <ctype.h>
#include <algorithm> 
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

typedef unsigned int uint;

class hash_table{

	private:

		struct key_line{
			string key;
			vector<int> ln;
			bool inuse(){
				return !key.empty();
			}
			bool operator== (const string &s) const{
				return !s.compare(key);
			}
		};

	public:
		hash_table(int x);
		~hash_table();
		void insert(const string &k, int ln);
		const vector<int>& find(string &s);
		void set_showstats(){
			showstats = true;
		};
		void insert_done(){
			if(showstats){
				showload();
			}
		}
	private:
		void showload(){
			cout << "**N = " << table.size() << " load = " << fixed << setprecision(2) <<  ((float)num_inuse/(float)table.size()) << "\n";
		}	
		bool showstats;
		int hash(const string &k);
		int nextprime(int);
		int qprobe(const string &k, bool c);
		void resize();
		int collisions;
		int num_inuse;
		int max_inuse;
		vector<key_line> table;

};

hash_table::hash_table(int x){
	int N = nextprime(x);
	showstats = false;
	collisions = 0;
	table.assign(N, key_line());
	num_inuse =0;
	max_inuse = N/2;
}

hash_table::~hash_table(){
	if(showstats){
		cout << "Run stats ...\nNumber of slots used: " <<
		num_inuse << "\nMax number of slots:  " << max_inuse <<
		"\nNumber of collisions: " << collisions << "\n";
	};
}
const vector<int>& hash_table::find(string &s){
	return table[qprobe(s, false)].ln;
}
void hash_table::insert(const string &s, int l){
	int index = qprobe(s, true);
	if(!table[index].inuse()){
		table[index].key = s;
		num_inuse++;
	}
	if(std::find(table[index].ln.begin(), table[index].ln.end(), l) == table[index].ln.end()){
		table[index].ln.push_back(l);
	}
	if(num_inuse >= max_inuse){
		insert_done();
		resize();

	}
}

int hash_table::hash(const string &key){
	uint index =0;
	const char *c = key.c_str();
	while(*c){
		index = ((index << 5) | (index >> 27)) + *c++;
	}
	return index % table.size();
}

int hash_table::nextprime(int N) {
	N = N*2 +1;	
       	int i = 2;
	 while (i*i <= N) {
		 if (N%i == 0) {
			 N+=2;
			 i = 1;
		 }
		 i++;
	}
	return max(3,N);
}

int hash_table::qprobe(const string &s, bool c){
	int index = hash(s);
	int k = 0;
	while (table[index].inuse() && table[index].key != s) {
		index += 2*(++k) - 1;
		index = index % table.size();
		if(c){
			collisions++;
		}
	}
		return index;
}
void hash_table::resize() {
	 vector<key_line> tmp_table;
	 for (int i=0; i<(int)table.size(); i++) {
		 if (table[i].inuse())
		 tmp_table.push_back(table[i]);
	 }
	 int N = nextprime(table.size());
	 table.assign(N, key_line());
	 num_inuse = 0;
	 max_inuse = N/2;
	 for (int i=0; i<(int)tmp_table.size(); i++) {
		 key_line &k1 = tmp_table[i];
		 table[ qprobe(k1.key, false) ] = k1;
		 num_inuse++;
	 }
}

char rPunct(char c){
	if(ispunct(c)){
		return ' ';
	}else{
		return c;
	}
}

int main(int argc, char *argv[]){
	int N =23;
	string p;
	bool s=false;
	string an = "-N";
	string as = "-showstats";
	string ai = "-f";
	for(int i =1; i < argc; i++){
		if(argv[i]==an){
			N = atoi(argv[++i]);
		}
		if(argv[i]==as){
			s = true;
		}
		if(argv[i]==ai){
			p = argv[++i];
		}
	}
	int lnum =1;
	ifstream f; 
	f.open(p.c_str());
	string lin;
	vector<string> orig;
	hash_table h(N);
	if(s){
		h.set_showstats();
	}
	while(getline(f, lin)){
		orig.push_back(lin);
		transform(lin.begin(), lin.end(), lin.begin(), rPunct);
		istringstream lis(lin);
		string word;
		while(lis >> word){
			h.insert(word, lnum);
		}
		lnum++;
	}
	h.insert_done();
	string uin;
	cout <<  "find> ";
	while(cin >> uin){
		vector<int> tp;
		tp = h.find(uin);	
		for(uint i =0; i < tp.size(); i++){
			cout << tp.at(i) << ": " << orig.at(tp.at(i)-1) << "\n";
		}
		cout << "find> ";
	}
	cout << "\n";	
	//	hash_table H;

//	string key;
//	while(cin >> key)
//		H.insert(key);
}
