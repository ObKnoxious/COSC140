#include <>
using namespace std;

typedef unsigned int uint;

template <typename Tkey>
class hash_table{
	public:
		hash_table();
		void insert(const Tkey &);

	private:
		int hash(const Tkey &);
		int nextprime(int);
		int qprobe(const Tkey &);
		void resize();

		int num_inuse;
		int max_inuse;

		vector<Tkey> table;
};

template <typename Tkey>
hash_table<Tkey>::hash_table(){
	int n = 23;
	table.assign(N, Tkey());

	num_inuse =0;
	max_inuse = N/2;
}

template <typename Tkey>
void hash_table<Tkey>::insert<const Tkey &key){
	int index = qprobe(key);
	if(table[index] == Tkey()){
		table[index] = key;
		if(++num_inuse >= max_inuse)
			resize();
	}
}

template <typename Tkey>
int hash_table<Tkey>::nextprime(int N) {
	 int i = 2;
	 while (i*i <= N) {
	 if (N%i == 0) { N++; i = 1; }
	 i++;
	}
	return max(3,N);
}

template <typename Tkey>
int hash_table<Tkey>::qprobe(const Tkey &key) {
	int index = hash(key);
	int k = 0;
	while (table[index] != Tkey() && table[index] != key) {
		index += 2*(++k) - 1;
		index = index % table.size();
	}
		return index;
}
template <typename Tkey>
void hash_table<Tkey>::resize() {
	 vector<Tkey> tmp_table;
	 for (int i=0; i<(int)table.size(); i++) {
		 if (table[i] != Tkey())
		 tmp_table.push_back(table[i]);
	 }
	 int N = nextprime(2*table.size());
	 table.assign(N, Tkey());
	 num_inuse = 0;
	 max_inuse = N/2;
	 for (int i=0; i<(int)tmp_table.size(); i++) {
		 Tkey &key = tmp_table[i];
		 table[ qprobe(key) ] = key;
		 num_inuse++;
	 }
}
