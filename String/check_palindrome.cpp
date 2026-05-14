#include <bits/stdc++.h>
using namespace std;

bool isPalindromeBetter(string s) {
  if (s == " ") return true;

  string temp = "";
  // Step 1: filter + lowercase
  for (auto& ch : s) {
    if (isalnum(ch)) {
      temp += tolower(ch);
    }
  }
  // Step 2: reverse copy
  string rev = temp;
  reverse(rev.begin(), rev.end());

  // Step 3: compare
  return temp == rev;
}

bool isPalindrome(string s) {
  int l = 0, r = s.size() - 1;

  while (l < r) {
    if (!isalnum(s[l])) {
      l++;
    } else if (!isalnum(s[r])) {
      r--;
    } else {
      if (tolower(s[l]) != tolower(s[r])) return false;
      l++;
      r--;
    }
  }
  return true;
}

int main() {
  string s = "A man, a plan, a canal: Panama";
  cout << isPalindrome(s);
  cout << endl;
  cout << isPalindromeBetter(s);
  return 0;
}