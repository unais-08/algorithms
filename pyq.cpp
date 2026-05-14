#include <bits/stdc++.h>
using namespace std;

int solution(vector<int>& v, int n) {
  map<int, int> mpp;
  for (auto& ele : v) {
    mpp[ele]++;
  }
  int freq;
  int productID;

  for (auto& ele : mpp) {
    if (freq < ele.second) {
      freq = ele.second;
      productID = ele.first;
    }
  }
  return productID;
}

int main() {
  int n;
  cin >> n;
  cin.ignore();
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  cout << endl;
  cout << solution(v, n) << endl;
  return 0;
}