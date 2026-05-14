#include <bits/stdc++.h>
using namespace std;

int main() {
  int n = 15;
  string xyz = "AbCDEkjdJDJLKjdfkzZ";
  transform(xyz.begin(), xyz.end(), xyz.begin(), ::toupper);
  transform(xyz.begin(), xyz.end(), xyz.begin(), ::tolower);

  cout << xyz;
  // vector<string> ans(n + 1);
  // for (int i = 1; i < n; i++) {
  //   if (i % 3 == 0 && i % 5 == 0) {
  //     ans[i] = "FizzBuzz";
  //   } else if (i % 3 == 0) {
  //     ans[i] = "Fizz";
  //   } else if (i % 5 == 0) {
  //     ans[i] = "Buzz";
  //   } else {
  //     ans[i] = std::to_string(i);
  //   }
  // }
  // for (auto& it : ans) cout << it << " ";

  cout << endl;
  return 0;
}