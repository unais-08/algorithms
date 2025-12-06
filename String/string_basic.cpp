#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string college = "IIT Bombay";

  cout << college.size() << endl;    // number of characters
  cout << college.length() << endl;  // same as size()

  cout << college.substr(4) << endl;  // substring from index 4 → "Bombay"

  cout << college.find("I") << endl;   // first occurrence of 'I' → 0
  cout << college.rfind("I") << endl;  // last occurrence of 'I' → 2

  cout << college.erase(0, 4) << endl;  // erase first 4 chars → "Bombay"

  college.push_back('s');                  // append single char → "Bombays"
  college.insert(college.size(), "tate");  // insert at end → "Bombaystate"

  reverse(college.begin(), college.end());  // reverse string

  cout << college << endl;  // final reversed output

  return 0;
}
