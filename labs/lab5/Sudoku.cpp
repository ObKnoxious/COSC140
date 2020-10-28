// Knox Crichton
// 10/28

#include <sys/time.h>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

const char *units[] = {"sec.", "msec.", "usec." };

class omega {
  public:
	omega();
	float get_sec();

  private:
    long Tinit;
    long Tmark;
};

omega::omega() {
  struct timeval T;
  gettimeofday(&T, NULL);

  Tinit = 1000000*T.tv_sec + T.tv_usec;
}

float omega::get_sec() {
  struct timeval T;
  gettimeofday(&T, NULL);

  Tmark = 1000000*T.tv_sec + T.tv_usec;

  return (float)(Tmark-Tinit)/1000000.0;
}

string elapsed(float d, int i=0) {
 	if(d < 0.1){
		return	elapsed(d*1000, i+1);
	}

		ostringstream rs;
		rs << setprecision(2) << fixed << d << " " << units[i];
		return rs.str();
	
}

class sudoku {
  public:
	sudoku();

	void solve();

    void read(const char *);
    void write(const char *);
    void write(const char *, const char *);

  private:
    bool solve(vector<int> cells, int c);
	
    	vector<int> valid_values(int i, int j);
    // various support functions 
    bool error_check_value(bool zero_valid);
    bool error_check_uniqueness();
	bool check_row(int r, int v);
    	bool check_col(int c, int v);
	bool check_square(int i, int j, int v);
    void display();

    int game[9][9];
};

vector<int> sudoku::valid_values(int i, int j){
	int t = game[i][j];
	vector<int> r;
	for(int v =1; v < 10; v++){
		game[i][j] = v;
		if(!(check_row(i, v)) && !(check_col(j, v)) && !(check_square(i, j , v))){
			r.push_back(v);
		}
//		if(!(check_row(i,v) || check_col(j,v)) || check_square(i,j,v)){
//			r.push_back(v);
//		}
	}
	game[i][j] = t;
       return r;	
}

bool sudoku::check_row(int r, int v){
	bool error = false;
	int f =0;
	for(int i =0; i < 9; i++){
		if(game[r][i] == v){
			f++;
		}
	}

	if(f > 1){
		error = true;
	//	cerr << "CHECK ROW Duplicate value " << v << " in row " << r << " col " << i << "\n";
	}
	return error;
};

bool sudoku::check_col(int c, int v){
	bool error = false;
	int f =0;
	for(int i = 0; i < 9; i++){
		if(game[i][c] == v){
			f++;
		}
	}

	if(f > 1){
		error = true;
	//	cerr << "CHECK COL Duplicate value " << v << " in row " << i << " col " << c << "\n";
	}
	return error;
};

bool sudoku::check_square(int i, int j, int v){
	int sj = (j/3)*3;
	int si = (i/3)*3;
	bool error = false;
	int f = 0;
	for(int r = si; r < si+3; r++){
		for(int c = sj; c < sj+3; c++){
			if(game[r][c] == v){
				f++;
			}
		}
	}

	if(f > 1){
		error = true;
	//	cerr << "CHECK SQUARE Duplicate value " << v << " in row " << i << " col " << j << "\n";
	}
	return error;
};

bool sudoku::error_check_uniqueness(){
	bool error = false;
	for(int r=0; r < 9; r++){
		for(int c =0; c < 9; c++){
			if(game[r][c] != 0){
				if(check_row(r, game[r][c]) || check_col(c, game[r][c]) || check_square(r, c, game[r][c])){
					cerr << "cell " << r << ' ' << c << ": non-unique value " << game[r][c] << "\n";
					error = true;
				}
			}
		}
	}

	return error;
};



sudoku::sudoku() { 
  for (int i=0; i<9; i++) {
    for (int j=0; j<9; j++)
      game[i][j] = 0;
  }
}

void sudoku::solve() {
  	cout << "SOLVE\n";
	bool error = false;
	vector<int> cells;
	for(int i =0; i < 9; i++){
		//cout << "in for 1 i:" << i << "\n";
		for(int j=0; j< 9; j++){
		//	cout << "in for 2 j:" << j << "\n";
			if(game[i][j] == 0){
				cells.push_back((i*9)+j);
			}
		}
	}
	//cout << "Made it passed the for loop!\n";
	if(solve(cells,0)){
		display();
	}
	if(error_check_value(false)){
		error=true;
	}
	if(error_check_uniqueness()){
		error=true;
	}
	if(error){
		exit(0);
	}
}


bool sudoku::solve(vector<int> cells, int c) {
	if(c == cells.size()){
		return true;
	}
	int i = cells[c] /9;
	int j = cells[c] % 9;
	vector<int> values = valid_values(i,j);
	if(values.size() == 0){
		return false;
	}
	for(int v = 0; v < values.size(); v++){
		game[i][j] = values[v];
		if(solve(cells, c+1)){
			return true;
		}	
	}
	game[i][j]=0;
	return false;

}	





void sudoku::read(const char *fname) {
 	bool error = false;
	int line = 1;
	cout << "READ\n";

	ifstream fin(fname);
    
	int i, j, v;

	while (fin >> i >> j >> v) {
		if(i < 0 || i > 8 || j < 0 || j > 8){
			error = true;
			cerr << "line " << line << ": " << i << ' ' << j << ' ' << v << " out-of-bounds grid index\n";
		}	
	    	// error check grid indices
    		game[i][j] = v;
		line++;
	}

	if(error){
		exit(0);
	}
	display();

	if(error_check_value(true)){
		error=true;
	}
	if(error_check_uniqueness()){
		error=true;
	}
	if(error){
		exit(0);
	}
  fin.close();

  // exit if bad grid indices

  // error check data values
  // error check uniqueness
  // exit if errors detected
}

void sudoku::write(const char *fname) {
  ofstream fout(fname);

  for (int i=0; i<9; i++) {
    for (int j=0; j<9; j++) {
      if (0 < game[i][j]) {
        fout << i << " "
			 << j << " "
		     << game[i][j] << "\n";
      }
    }
  }

  fout.close();
}

void sudoku::write(const char *fname, const char *addon) {
  int N1 = strlen(fname);
  int N2 = strlen(addon);

  char *n_fname = new char[N1+N2+2];

  // strip .txt suffix, then concatenate _addon.txt
  strncpy(n_fname, fname, N1-4);
  strcpy(n_fname+N1-4, "_");
  strcpy(n_fname+N1-3, addon);
  strcpy(n_fname+N1-3+N2, ".txt");

  write(n_fname);

  delete [] n_fname;
}

void sudoku::display() {
  cout << "| --------------------------- |\n";
  for (int i=0; i<9; i++) {
    for (int j=0; j<9; j++) {
	  if (j == 0) 
	    cout << "| " << game[i][j];
	  else if (j%3 == 0) 
	    cout << " | " << game[i][j];
	  else
	    cout << "  " << game[i][j];
	}
    cout << " |\n";
	if (i%3 == 2)
      cout << "| --------------------------- |\n";
  }
}

       

	// if solution found, 
  //   return solution-found
  //
  // set cell index (i,j)
  // determine valid values 
  // if no valid values left,
  //   return road-to-nowhere
  //
  // iterate thru valid values 
  //   game[i][j] = next value
  //   if solve(arguments) == solution-found
  //     return solution-found
  //
  // reset: game[i][j] = 0
  // return road-to-nowhere

bool sudoku::error_check_value(bool zero_valid){
	bool error = false;
	for(int i =0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(zero_valid){
				if(game[i][j] < 0 || game[i][j] > 9){
					error=true;
					cerr << "cell " << i << ' ' << j << ": out-of-bounds data value " << game[i][j] << "\n";
				}
			}else{
				if(game[i][j] < 1 || game[i][j] > 9){
					error=true;
					cerr << "cell " << i << ' ' << j << ": out-of-bounds data value " << game[i][j] << "\n";
				}
			}
		}
	}
	return error;
}
				

int main(int argc, char *argv[]) {
  srand(time(NULL));

  if ((argc != 3) ||
      (strcmp(argv[1], "-s") != 0) ||
	  strstr(argv[argc-1], ".txt") == NULL) {
    cerr << "usage: Sudoku -s game.txt\n";
	exit(0);
  }

  omega timer;
  sudoku sudoku_game;

  float T0 = timer.get_sec();
  float T1 = timer.get_sec();

  if (strcmp(argv[1], "-s") == 0) {
    sudoku_game.read(argv[2]);

	T0 = timer.get_sec();
    sudoku_game.solve();
	T1 = timer.get_sec();

    sudoku_game.write(argv[2], "solved");
  }

  string elapsed_time = elapsed(T1-T0);
  cout << elapsed_time << "\n";
  // print string elapsed_time using two decimal places
  // print T1-T0 using six decimal places for comparison
}
