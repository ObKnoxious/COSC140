#ifndef BST_H
#define BST_H

#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <class TKey>
class bst {
	struct node {
	    node(int inid = 0){
		    id = inid;
	    }

	    void print();

	    TKey key;
	    //ID parameter
		int id;
	    //c /parent info
	    	node *left = NULL ;
	  	node *right= NULL;
		node *parent = NULL;
	};

  public:
    class iterator {
      public:
        //default constructor (no argument)
        //overloaded operators (++, *, ==, !=)
	iterator();
	iterator & operator ++();
	TKey & operator * ();
	bool operator == (const iterator &) const;
	bool operator != (const iterator &) const;
      private:
        friend class bst<TKey>;
        //constructor (with argument)
	iterator(node *);

        node *p;
    };

    //iterator begin() { ... }
    //iterator end() { ... }

  public:
    bst(){
	    Troot=NULL;
	    id =0;
    }
    ~bst() { clear(Troot); }

    bool empty() { return Troot==NULL; }

    void insert(TKey &);
	iterator begin();
	iterator end();
    //iterator lower_bound(const TKey &);
    //iterator upper_bound(const TKey &);

    void print_bylevel();

  private:
    void clear(node *);
    node *insert(node *, TKey &);
	int id;
    //ID parameter
    node *Troot;
};

//template <class TKey>
//bst::~bst(){
	//clear(Troot);
//}
//bst<TKey>::node constructor goes here

template <class TKey>
bst<TKey>::iterator::iterator(){

}
template <class TKey>
bst<TKey>::iterator::iterator(bst<TKey>::node *ptr){

}
template <class TKey>
typename bst<TKey>::iterator & bst<TKey>::iterator::operator ++(){

}
template <class TKey>
TKey & bst<TKey>::iterator::operator *(){

}
template <class TKey>
TKey & bst<TKey>::iterator::operator ==(){

}
TKey & bst<TKey>::iterator::operator !=(){

}
template <class TKey>
typename bst<TKey>::iterator bst<TKey>::begin(){

}


template <class TKey>
void bst<TKey>::node::print()
{
  cout << setw(3) << id << " " << setw(3) <<  key << " :";

  //output node and parent ID information
  //change below to output subtree ID information

	if(parent) cout << " P=" << setw(3) << parent->id;
	else	cout << " ROOT ";
	if (left)  cout << " L=" << setw(3) << left->id;
	else       cout << "      ";
	if (right) cout << " R=" << setw(3) << right->id;
	else       cout << "      ";
	cout << "\n";
}

//specialized string version of the above goes here

template <>
void bst<string>::node::print()
{
  cout << setw(3) << id << " " << setw(20) <<  key << " :";

  //output node and parent ID information
  //change below to output subtree ID information

	if(parent) cout << " P=" << setw(3) << parent->id;
	else	cout << " ROOT ";
  if (left)  cout << " L=" << setw(3) << left->id;
  else       cout << "      ";
  if (right) cout << " R=" << setw(3) << right->id;
  else       cout << "      ";
  cout << "\n";
}
//bst<TKey>::iterator functions not defined above go here

template <class TKey>
void bst<TKey>::clear(node *T)
{
  if (T) {
    clear(T->left);
    clear(T->right);
    delete T;
    T = NULL;
  }
}

template <class TKey>
void bst<TKey>::insert(TKey &key)
{ 
  Troot = insert(Troot, key);
}

template <class TKey>
class bst<TKey>::node *bst<TKey>::insert(node *T, TKey &key)
{
  //set parent link below
  if (T == NULL) {

      	  //update and set node ID 
    T = new node(++id);
    T->key = key;
  } else if (T->key == key) {
    ;
  } else if (key < T->key) {
    T->left = insert(T->left, key);
  
	T->left->parent =T;
  } else {
    T->right = insert(T->right, key);
	T->right->parent=T;
  }

  return T;
}

//bst<TKey>::lower_bound function goes here

//bst<TKey>::upper_bound function goes here

template <class TKey>
void bst<TKey>::print_bylevel()
{
  if (Troot == NULL)
    return;

  queue<node *> Q;
  node *T;

  Q.push(Troot);
  while (!Q.empty()) {
    T = Q.front();
    Q.pop();

    T->print();
    if (T->left)  Q.push(T->left);
    if (T->right) Q.push(T->right);
  }
}
#endif
