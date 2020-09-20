#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

// Lab 2b by Knox Crichton
const string face[] = { "Ace", "2", "3", "4", "5", "6", "7",
	                        "8", "9", "10", "Jack", "Queen", "King" }; 
const string suit[] = { "Clubs", "Diamonds", "Hearts", "Spades" };
string random_card(bool verbose=false) {
	string card;
	card = face[ rand()%13 ];
	card += " of ";
	card += suit[ rand()%4 ];
	if (verbose)
		cout << card << "\n";
	return card;
}

class Node {
	public:
		int data;
		Node* next;
};
class List{
	public:
		List(){
			head = NULL;
		}
		~List(){};
		void insert(int v, bool &s);
		void printList();
		void remove(Node *n);
		void sort();
		bool check(int v, Node* &t);
	private:
		Node* head;
};


void List::insert(int v, bool &s){
	bool hj = false; // has jack
	bool hq = false; // has queen
	bool hk = false; // has king
	// Create node to be inserted
	Node* nNode = new Node();
	nNode->data =v;
	nNode->next = NULL;
	if(head == NULL){
		// if list is empty this become the head
		head =nNode;
	}else{
		Node* tmp = head; 
		// Loops until end of existing list
		while(tmp->next != NULL){
			// Check for duplicate
			if(tmp->data == v){
//				cout << "Duplicate detected\n";
				remove(tmp);
				return;
			}
			tmp = tmp->next;
		}
		// Check for duplicate after while loop because
		// loop stops at second to last tmp
		if(tmp->data == v){
//			cout << "Duplicate detected\n";
			remove(tmp);
			return;
		}
		// Then inserts
		tmp->next = nNode;
	}
	// Looping thru list to check if all face cards
	if(head != NULL){
		Node* tmpc = head;
		while(tmpc != NULL){
			if(tmpc->data == 11){
				hj = true;
			}
			if(tmpc->data == 12){
				hq = true;
			}
			if(tmpc->data == 13){
				hk = true;
			}
			// S in the sentinal of loop in main
			if(hj && hq && hk){
//				cout << "time to stop\n";
				s = false;
			}
			tmpc = tmpc->next;
		}
	}
//	if(head != NULL){
//		Node* tmpc2 = head;
//		while(tmpc2 != NULL){
//			if(tmpc2->data == v){
//				//cout << "Duplicate found!\n";
//				remove(tmpc2);
//				break;
//			} 
//		}
//	}
}
void List::printList(){
	bool hj = false;
	bool hq = false;
	bool hk = false;
	if(head == NULL){
		// Used on instance 23 when no clubs are dealt
		cout << "\n";
	} else {
		Node* tmp = head;
		// Change output value to face card value
		while(tmp != NULL){
			if(tmp->data == 1){
				cout << "Ace ";
			}else if(tmp->data == 11){
				hj = true;
				cout << "Jack ";
			}else if(tmp->data == 12){
				hq = true;
				cout << "Queen ";
			}else if(tmp->data == 13){
				hk = true;
				cout << "King ";
			}else{
				cout << tmp->data << " ";
			}
			tmp = tmp->next;
		}
		if(hj && hq && hk){
			cout << "**";
		}
		cout << "\n";
	}
}
void List::remove(Node *n){
	//cout << "Inside remove function\n";
	if(n == head){
		//cout << "Inside of first if\n";
		// Have to move next data to head
		if(head->next == NULL){
			head=NULL;
			// Should revert back to blank list
			return;
		}
		head->data = head->next->data;
		n = head->next;
		head->next = head->next->next;
		free(n);
		return;
	}
	//cout << "Made it past first if\n";
	Node *prev = head;
	while(prev->next != NULL && prev->next !=n){
		//cout << "Inside while loop of remove function\n";
		prev = prev->next;
	}
	if(prev->next == NULL){

		// Can't delete null node
		//cout << "\n Bade node to delete";
		return;
	}
	prev->next = prev->next->next;
	free(n);
	return;
}

void List::sort(){
	Node* current = head;
	Node* index = NULL;
	if(head == NULL){
		return;
	}else{
		while(current != NULL){
			index = current->next;
			while(index != NULL){
				if(current->data > index->data){
					int tmp;
					tmp = current->data;
					current->data = index->data;
					index->data = tmp;
				}
				index = index->next;
			}
			current = current->next;
		}
	}
}

int main(int argc, char *argv[]){
	bool verbose = false;
		int seedvalue = 0;
		for (int i=1; i<argc; i++) {
			string option = argv[i];
			if (option.compare(0,6,"-seed=") == 0) {
				seedvalue = atoi(&argv[i][6]);
			} else if (option.compare("-verbose") == 0) {
				verbose = true;
			} else 
				cout << "option " << argv[i] << " ignored\n";
		}
		// Sentinal value for loop
		bool sent = true;
		srand(seedvalue);
		// TODO: Replace this with array of these, causes seg fault
		List* hearts = new List();
		List* clubs = new List();
		List* spades = new List();
		List* diamonds = new List();
		while(sent){
			int v = -1;
			string c = random_card(verbose);
			// Finding value from string, taken from last lab
			switch(c[0]){
				case 'A':
					v=1;
					break;
				case 'J':
					v=11;
					break;
				case 'Q':
					v=12;
					break;
				case 'K':
					v=13;
					break;
				case '1':
					v=10;
					break;
				default:
					v=int(c[0])-48;
					break;
			}
			// Find what suit to put things in
			// The if !sent break was to fix a problem earlier
			// and probably isn't needed but not gonna risk
			// breaking anything at this point
			if(c.find("Hearts") != string::npos){
				hearts->insert(v, sent);
				hearts->sort();
				if(!sent){
					break;
				}
			}else if(c.find("Clubs") != string::npos){
				clubs->insert(v, sent);
				clubs->sort();
				if(!sent){
					break;
				}
			}else if(c.find("Spades") != string::npos){
				spades->insert(v, sent);
				spades->sort();
				if(!sent){
					break;
				}
			}else if(c.find("Diamonds") != string::npos){
				diamonds->insert(v, sent);
				diamonds->sort();
				if(!sent){
					break;
				}
			}
		}
		cout <<"   Clubs : ";
		clubs->sort();
		clubs->printList();
		cout <<"Diamonds : ";
		diamonds->sort();
		diamonds->printList();
		cout <<"  Hearts : ";
		hearts->sort();		
		hearts->printList();
		cout <<"  Spades : ";
		spades->sort();
		spades->printList();
		return 0;
}
