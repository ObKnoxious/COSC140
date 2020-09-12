#include <cstdlib>
#include <iostream>

using namespace std;

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

int main(int argc, char *argv[])
{
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

	srand(seedvalue);

	// declare a table[][] that can keep track of the
	// cards dealt for each suit -- initialize to 0
	// Clubs, Diamonds, Hearts, Spades 
	int table[4][13] ={0};
	int sx = 4; // Stores which suit is the stop
	while (true) {
	  string card = random_card(verbose);
  		// I use hard tabs for everything and I'm not going to bother
		// fixing this. It really do be that way tho
	//	if(verbose){
	//		cout << card << "\n";
	//	}
		// Check if not face card
		// Equivelant to !isAlpha()
		if(int(card[0] < 65 && card[1] != '0')){
			// String format means if not face card suit letter
			// is always at card[5]
			int v = int(card[0]) - 48;
			switch(card[5]){
				case 'C':
					table[0][v-1]=table[0][v-1] +1;
			//		cout << table[0][v-1] << " ";
					break;
				case 'D':
					table[1][v-1]+=1;
			//		cout << table[1][v-1] << " ";
					break;
				case 'H':
					table[2][v-1]+=1;
		//			cout << table[2][v-1] << " ";
			//		break;
				case 'S':
					table[3][v-1]+=1;
			//		cout << table[3][v-1]<< " ";
					break;
				default:
					cout << "Please panic\n";
			}
		}else if(card[0] == '1' && card[1] == '0'){
			// Gotta right this whole other if statement for 10
			// because it's a special little bitch
			
			int v = 10;
			switch(card[6]){
				case 'C':
					table[0][v-1]=table[0][v-1] +1;
				//	cout << table[0][v-1] << " ";
					break;
				case 'D':
					table[1][v-1]+=1;
				//	cout << table[1][v-1] << " ";
					break;
				case 'H':
					table[2][v-1]+=1;
				//	cout << table[2][v-1] << " ";
					break;
				case 'S':
					table[3][v-1]+=1;
				//	cout << table[3][v-1]<< " ";
					break;
				default:
					cout << "Please panic\n";
			}
		}else if(card[0] == 'A'){
			// For aces
			// Ace of X
			int v=1;
			switch(card[7]){
				case 'C':
					table[0][v-1]=table[0][v-1] +1;
				//	cout << table[0][v-1] << " ";
					break;
				case 'D':
					table[1][v-1]+=1;
				//	cout << table[1][v-1] << " ";
					break;
				case 'H':
					table[2][v-1]+=1;
				//	cout << table[2][v-1] << " ";
					break;
				case 'S':
					table[3][v-1]+=1;
				//	cout << table[3][v-1]<< " ";
					break;
				default:
					cout << "Please panic\n";
			}
		}else if(card[0] == 'J'){
			// For Jacks
			// Jack of X
			int v=11;
			switch(card[8]){
				case 'C':
					table[0][v-1]=table[0][v-1] +1;
				//	cout << table[0][v-1] << " ";
					break;
				case 'D':
					table[1][v-1]+=1;
				//	cout << table[1][v-1] << " ";
					break;
				case 'H':
					table[2][v-1]+=1;
				//	cout << table[2][v-1] << " ";
					break;
				case 'S':
					table[3][v-1]+=1;
				//	cout << table[3][v-1]<< " ";
					break;
				default:
					cout << "Please panic\n";
			}
		}else if(card[0] == 'Q'){
			// For queens
			// Queen of X
			
			int v=12;
			switch(card[9]){
				case 'C':
					table[0][v-1]=table[0][v-1] +1;
				//	cout << table[0][v-1] << " ";
					break;
				case 'D':
					table[1][v-1]+=1;
				//	cout << table[1][v-1] << " ";
					break;
				case 'H':
					table[2][v-1]+=1;
				//	cout << table[2][v-1] << " ";
					break;
				case 'S':
					table[3][v-1]+=1;
				//	cout << table[3][v-1]<< " ";
					break;
				default:
					cout << "Please panic\n";
			}
		}else if(card[0] == 'K'){
			// For Kings
			// King of X

			int v=13;
			switch(card[8]){
				case 'C':
					table[0][v-1]=table[0][v-1] +1;
				//	cout << table[0][v-1] << " ";
					break;
				case 'D':
					table[1][v-1]+=1;
				//	cout << table[1][v-1] << " ";
					break;
				case 'H':
					table[2][v-1]+=1;
				//	cout << table[2][v-1] << " ";
					break;
				case 'S':
					table[3][v-1]+=1;
				//	cout << table[3][v-1]<< " ";
					break;
				default:
					cout << "Please panic\n";
			}
		}
				
	  // reverse engineer card suit and face (value)
	  // update accordingly: table[suit][value]++
	
      // break out of loop if stopping criteria meti
      		if((table[0][10] > 0 && table[0][11] > 0 && table[0][12] > 0)){
			sx = 0;
			break;
		}else if(table[1][10] > 0 && table[1][11] > 0 && table[1][12] 
				>0){
			sx =1;
			break;
		}else if(table[2][10] > 0 && table[2][11] > 0 && table[2][12] 
				> 0){
			sx = 2;
			break;
		}else if(table[3][10] > 0 && table[3][11] > 0 && table[3][12]
			       	> 0){
			sx = 3;
			break;
		}
	}// This is the bracket for end of while
	for(int i =0; i < 4; i++){
		switch(i){
			case 0:
				cout << "   Clubs :";
				break;
			case 1:
				cout << "Diamonds :";
				break;
			case 2:
				cout << "  Hearts :";
				break;
			case 3:
				cout << "  Spades :";
				break;
			default:
				cout << "Please Panic\n";
				break;
		}
		for(int j =0; j < 13; j++){
			cout <<"   " << table[i][j];
		}
		if(i == sx){
			cout << " **";
		}
		cout << "\n";
	}
	// print formatted table contents to stdout 
}
