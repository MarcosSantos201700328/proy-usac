#include <iostream>
#include <fstream>
using namespace std;


int main(){
  ifstream infile ("tarea2.cpp");
  while (infile.good())
    cout << (char) infile.get();
  infile.close();
  //  cout << "h" << endl;
  return 0;
}
