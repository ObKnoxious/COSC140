#include ...

class name_t {
  public:
    constructor(s);

    bool operator<(...);
    void print(int W=0);

  private:
    string name;
};

class scores_t {
  public:
    constructor(s);

    bool operator<(...)

    void insert(int);
    void insert_done();
    void print();

  private:
    vector<int> scores;
    float mean;
};

class namescores_t {
  public:
    constructor(s);

    bool operator<(...);
    
    void print_name(int);
    void print_scores();

  private:
    name_t name;
    scores_t scores;
};

int main(...) {
  commandline parsing
    argv[1]: W (width of name field)
    argv[2]: K (number of elements to print)
    argv[3]: filename.txt

  open filename.txt
  vector<namescores_t> NS;

  while (more data in file) {
    add first and lastname to name_t object

    while (more scores) {
      insert score into scores_t object
    have insert_done calculate mean score

    create and insert namescores_t object into NS list
  }

  close filename.txt

  turn NS list into binary max-heap

  for (K data elements && heap not empty) {
    extract top of heap element

    print name
    print scores
  }
}
