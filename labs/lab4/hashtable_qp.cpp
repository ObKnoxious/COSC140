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



