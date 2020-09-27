#include <iomanip>
#include <iostream>
using namespace std;
class list {
	 public:
		  list(int Nmax=0);
		   ~list();
		    bool empty() const { return N == 0; }
		     int size() const { return N; }
		      void clear();
		       void insert(int, const int &);
		        void erase(int);
			 void push_back(const int &);
			  void pop_back();
			   const int & back();
			    int & operator[](int);
			     private:
			     int N, Nmax;
			      int *data;
			       void resize(int Nincr=10);
};
list::list(int n_N) {
	 N = 0;
	  Nmax = n_N;
	   data = new int[Nmax];
	    for (int i=0; i<Nmax; i++)
		     data[i] = 0;
}
list::~list() { if (data) delete [] data; }
void printlist(const char *operation, list &v) {
	 cout << setw(14) << operation
		  << " s=" << v.size()
		   << " : ";
	  for (int i=0; i<v.size(); i++)
		   cout << " " << v[i];
	   cout << "\n";
}
int main(int argc, char *argv[]) {
	 cout << left;
	  list v; printlist("list v", v);
	   v.push_back(7); printlist("v.push_back(7)", v);
	    v.push_back(8); printlist("v.push_back(8)", v);
	     v.push_back(9); printlist("v.push_back(9)", v);
	      v.insert(1, 20); printlist("v.insert(1,20)", v);
	       v.erase(2); printlist("v.erase(2)", v);
	        v.insert(0, 11); printlist("v.insert(0,11)", v);
		 v.push_back(2); printlist("push_back(2)", v);
		  v.pop_back(); printlist("pop_back()", v);
		   v.insert(1, 4); printlist("v.insert(1,4)", v);
		    v[1] = 5; printlist("v[1] = 5", v);
		     v.clear(); printlist("clear()", v);
}
