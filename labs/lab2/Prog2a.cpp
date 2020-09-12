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
	int table[4][13] ={0};
	while (1) {
	  string card = random_card(verbose);
	 	// I use hard tabs for everything and I'm not going to bother
		// fixing this. It really do be that way tho
		cout << card << " "; 
	  // reverse engineer card suit and face (value)
	  // update accordingly: table[suit][value]++

      // break out of loop if stopping criteria met
		break;
	}
	for(int i =0; i < 4; i++){
		for(int j =0; j < 13; j++){
			cout << table[i][j] << "\t";
		}
		cout << "\n";
	}
	// print formatted table contents to stdout 
}
