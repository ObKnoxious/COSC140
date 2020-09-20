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
		void insert(int v);
		void printList();
		void remove(Node *n);
		Node* ghead(){
			return head;
		}
	private:
		Node* head;
};

void List::insert(int v){
	Node* nNode = new Node();
	nNode->data =v;
	nNode->next = NULL;
	if(head == NULL){
		head =nNode;
	}else{
		Node* tmp = head; 
		while(tmp->next != NULL){
			tmp = tmp->next;
		}
		tmp->next = nNode;
	}
}
void List::printList(){
	if(head == NULL){
		cout << "No values in list\n";
	} else {
		Node* tmp = head;
		while(tmp != NULL){
			if(tmp->data == 1){
				cout << "Ace ";
			}else if(tmp->data == 11){
				cout << "Jack ";
			}else if(tmp->data == 12){
				cout << "Queen ";
			}else if(tmp->data == 13){
				cout << "King ";
			}else{
				cout << tmp->data << " ";
			}
			tmp = tmp->next;
		}
		cout << "\n";
	}
}
void List::remove(Node *n){
	if(n == head){
		head->data = head->next->data;
		n = head->next;
		head->next = head->next->next;
		free(n);
		return;
	}
	Node *prev = head;
	while(prev->next != NULL && prev->next !=n)
		prev = prev->next;
	if(prev->next == NULL){
		cout << "\n Bade node to delete";
		return;
	}
	prev->next = prev->next->next;
	free(n);
	return;
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
		bool sent = true;
		srand(seedvalue);
		List* hearts = new List();
		List* clubs = new List();
		List* spades = new List();
		List* diamonds = new List();
		int fn =0;
		while(fn < 10){
			int v = -1;
			string c = random_card(verbose);
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
				default:
					v=int(c[0])-48;
					break;
			}
			if(c.find("Hearts") != string::npos){
				Node* tmp = hearts->ghead();
				while(tmp != NULL){
					if(tmp->data = v){

				hearts->insert(v);
			}else if(c.find("Clubs") != string::npos){
				clubs->insert(v);
			}else if(c.find("Spades") != string::npos){
				spades->insert(v);
			}else if(c.find("Diamonds") != string::npos){
				diamonds->insert(v);
			}
			sent = false;
			fn++;
		}
		cout <<"   Clubs : ";
		clubs ->printList();
		cout <<"Diamonds : ";
		diamonds->printList();
		cout <<"  Hearts : ";		
		hearts->printList();
		cout <<"  Spades : ";
		spades->printList();
		return 0;
}
