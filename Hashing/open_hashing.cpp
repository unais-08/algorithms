#include <bits/stdc++.h>
using namespace std;

class HashTable {
 private:
  vector<list<int>> hashTable;
  int size;

 public:
  // Constructor: create 'size' buckets.
  HashTable(int size) {
    this->size = size;
    hashTable.resize(size);
  }

  // Hash function
  int hash_function(int x) { return x % size; }

  // Insert key
  void push_key(int x) {
    int h = hash_function(x);
    hashTable[h].push_back(x);
  }

  // Search key: return iterator to found key OR bucket.end()
  list<int>::iterator search(int x) {
    int h = hash_function(x);
    for (auto it = hashTable[h].begin(); it != hashTable[h].end(); it++) {
      if (*it == x) return it;
    }
    return hashTable[h].end();  // not found
  }

  // Delete key
  void pop_key(int x) {
    int h = hash_function(x);
    auto it = search(x);

    if (it != hashTable[h].end()) {
      hashTable[h].erase(it);
      cout << "Key " << x << " removed\n";
    } else {
      cout << "Key " << x << " not found\n";
    }
  }

  // Print table (for debugging)
  void print() {
    for (int i = 0; i < size; i++) {
      cout << i << ": ";
      for (int x : hashTable[i]) cout << x << " ";
      cout << "\n";
    }
  }
};

int main() {
  HashTable ht(5);

  ht.push_key(10);

  ht.push_key(15);

  ht.push_key(20);

  ht.push_key(7);

  ht.push_key(32);

  ht.print();

  ht.pop_key(15);

  ht.pop_key(100);

  ht.print();

  return 0;
}