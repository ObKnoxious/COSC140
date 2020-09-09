// Lab 1 Problem D by Knox Crichton
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <cctype>
using namespace std;
int main (int argc, const char* argv[]){
	// Error checking to make sure input matches
	if(argc <= 2){
		printf("Usage: ./Prog1d -decode|encode 0-9\n");
		return -1;
	}
	if(!(strcmp(argv[1], "-encode")==0 || strcmp(argv[1], "-decode")==0)){
		printf("Usage: ./Prog1d -decode|encode 0-9\n");
		return -1;
	}
	int r = stoi(argv[2]);
	if(r > 9 || r < 0){
		printf("Usage: ./Prog1d -decode|encode 0-9\n");
		return -1;
	}
	
	//HAHA SO FUNNY STORY I thought you put the input just in argv for
	//some reason and wrote this whole entire thing that took me like
	//20 minutes to do to make it one char array even tho it was all
	//useless but i left it in as comments as a mark of shame and to
	//remind me to just read the instructions and not be an idiot

	//Combining all needed argv values into one char array for ease of use
	//int t =0;
	//for(int i = 3; i < argc; i++){
		// This loop figures out how long the array needs to be
		// I am confident there is a better way to solve this problem
		// but I'm tryna do this quickly And this is the first thing
		// that came to my head
	//	t+= strlen(argv[i]);
	//}
	//char fullText[t];
	//cout << t;	
	//for(char o : fullText){
	//	cout << o << " ";
	//}
	//
	//string arr[argc -3];
	//for(int i=3;i<argc;i++){
	//	arr[i-3]=argv[i];
	//}
	//int l = sizeof(arr)/sizeof(arr[0]);
	if(strcmp(argv[1], "-encode")==0){
		while(true){
			string inp; 
			getline(cin, inp); // Get input into inp
			int linp = inp.length();
			char arr[linp +1]; // create char array of inp
			strcpy(arr, inp.c_str());
			int a = 0; // For adjusting upper vs lower
			for(int i =0; i < sizeof(arr)/sizeof(arr[0]); i++){
				// These two ifs convert value to 0-25 for 
				// letters and save if to revert back to
				// upper or lower
				if(isalpha(arr[i])){
					if(isupper(arr[i])){
						arr[i] = int(arr[i]) -65;
						a = 65;
					}else if(islower(arr[i])){
						arr[i] =arr[i] - 97;
						a =97;
					}
					// Actual "encoding"
					arr[i] = arr[i] + r;
					// Convert back to ascii standard
					if(arr[i] < 0){
						arr[i] = arr[i] + 26;
					}else if(arr[i] > 25){
						arr[i] =arr[i] -26;
					}
					arr[i] = arr[i] + a;
				}
			}
			// This makes the output string. I chop off the last
			// letter because there is always an extra one and
			// I don't really know why
			string o ="";
			for(int i=0; i < sizeof(arr)/sizeof(arr[0])-1; i++){
				o += arr[i];
			}
			cout << o << "\n";
			//TO USE LIKE SPROG COMMENT OUT THE LINE BENEATH THIS
			return 0;
		}
	}else if(strcmp(argv[1], "-decode")==0){
		while(true){
			string inp; 
			getline(cin, inp); // Get input into inp
			int linp = inp.length();
			char arr[linp +1]; // create char array of inp
			strcpy(arr, inp.c_str());
			int a = 0; // For adjusting upper vs lower
			for(int i =0; i < sizeof(arr)/sizeof(arr[0]); i++){
				// These two ifs convert value to 0-25 for 
				// letters and save if to revert back to
				// upper or lower
				if(isalpha(arr[i])){
					if(isupper(arr[i])){
						arr[i] = int(arr[i]) -65;
						a = 65;
					}else if(islower(arr[i])){
						arr[i] =arr[i] - 97;
						a =97;
					}
					// Actual "encoding"
					arr[i] = arr[i] - r;
					// Convert back to ascii standard
					if(arr[i] < 0){
						arr[i] = arr[i] + 26;
					}else if(arr[i] > 25){
						arr[i] =arr[i] -26;
					}
					arr[i] = arr[i] + a;
				}
			}
			// This makes the output string. I chop off the last
			// letter because there is always an extra one and
			// I don't really know why
			string o ="";
			for(int i=0; i < sizeof(arr)/sizeof(arr[0])-1; i++){
				o += arr[i];
			}
			cout << o << "\n";
			// TO USE LIKE SPROG COMMENT OUT THE LINE BENEATHT THIS
			return 0;
		}
	}

}
