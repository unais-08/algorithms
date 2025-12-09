/*******************************
 *        SET IN C++ (REVISION)
 *  Sorted + Unique | O(log n)
 ********************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
  // ---------- DECLARATION ----------
  set<int> s;  // sorted, unique

  // ---------- INSERT ----------
  s.insert(10);
  s.insert(5);
  s.insert(10);  // ignored (duplicate)

  // ---------- CHECK EXISTENCE ----------
  if (s.count(5)) {  // 1 = exists, 0 = not exists
    cout << "5 found\n";
  }

  // ---------- FIND ----------
  auto it = s.find(5);
  if (it != s.end()) {
    cout << "5 found via find()\n";
  }

  // ---------- ERASE ----------
  s.erase(5);  // erase by value
  // s.erase(it);      // erase by iterator

  // ---------- SIZE + CLEAR ----------
  cout << "Size = " << s.size() << "\n";
  // s.clear();        // remove all elements

  // ---------- ITERATE (SORTED ORDER) ----------
  s.insert(1);
  s.insert(9);
  s.insert(3);

  for (int x : s) cout << x << " ";  // 1 3 9 10
  cout << "\n";

  // ---------- LOWER_BOUND / UPPER_BOUND ----------
  auto lb = s.lower_bound(3);  // first >= 3
  auto ub = s.upper_bound(3);  // first > 3

  if (lb != s.end()) cout << "lower_bound(3) = " << *lb << "\n";

  if (ub != s.end()) cout << "upper_bound(3) = " << *ub << "\n";

  // ---------- CUSTOM COMPARATOR (DESC ORDER) ----------
  set<int, greater<int>> s2;
  s2.insert(4);
  s2.insert(1);
  s2.insert(7);

  cout << "Descending set: ";
  for (int x : s2) cout << x << " ";  // 7 4 1
  cout << "\n";

  // ---------- SET WITH PAIRS ----------
  set<pair<int, int>> sp;
  sp.insert({3, 10});
  sp.insert({1, 20});
  sp.insert({1, 15});  // allowed (pair differs)

  cout << "Set of pairs: ";
  for (auto& p : sp) cout << "(" << p.first << "," << p.second << ") ";
  cout << "\n";

  return 0;
}

/************* COMPLEXITY *************
insert     -> O(log n)
erase      -> O(log n)
find       -> O(log n)
count      -> O(log n)
iteration  -> O(n)
****************************************/
