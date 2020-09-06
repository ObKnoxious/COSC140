// Lab 1 Problem B by Knox Crichton
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <cctype>
using namespace std;
int main (int argc, const char* argv[]){
	// Error checking to make sure input matches
	if(argc <= 3){
		printf("Usage: ./Prog1d -decode|encode 0-9 catch 1\n");
		return 1;
	}
	if(!(strcmp(argv[1], "-encode")==0 || strcmp(argv[1], "-decode")==0)){
		printf("Usage: ./Prog1d -decode|encode 0-9 catch 2\n");
		return 1;
	}
	int r = stoi(argv[2]);
	if(r > 9 || r < 0){
		printf("Usage: ./Prog1d -decode|encode 0-9 catch 3\n");
		return 1;
	}
	
	//Combining all needed argv values into one char array for ease of use
	//int t =0;
	//for(int i = 3; i < argc; i++){
		// This loop figures out how long the array needs to be
		// I am confident there is a better way to solve this problem but I'm tryna 
		// do this quickly And this is the first thing that came to my head
	//	t+= strlen(argv[i]);
	//}
	//char fullText[t];
	//cout << t;	
	//for(char o : fullText){
	//	cout << o << " ";
	//}
	//
	string arr[argc -3];
	for(int i=3;i<argc;i++){
		arr[i-3]=argv[i];
	}
	int l = sizeof(arr)/sizeof(arr[0]);
	if(strcmp(argv[1], "-encode")==0){

		int a = 0;
		for(int i =0; i < l; i++){
			for(int j=0; j < arr[i].size(); j++){
				if(isupper(arr[i][j])){
					arr[i][j] = int(arr[i][j]) -65;
					a = 65;
				}else if(islower(arr[i][j])){
					arr[i][j] =arr[i][j] - 97;
					a =97;
				}
				arr[i][j] = arr[i][j] - r;
				if(arr[i][j] < 0){
					arr[i][j] = arr[i][j] + 26;
				}else if(arr[i][j] > 26){
					arr[i][j] =arr[i][j] -26;
				}
				arr[i][j] = arr[i][j] + a;
				cout << arr[i][j] << " ";
			}
		}
	}

	for(int i=0; i < l; i++){
		cout << arr[i];
	}
}
