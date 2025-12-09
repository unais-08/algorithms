#include <bits/stdc++.h>
using namespace std;

int main() {
  // =====================================================================
  //                           ORDERED MAP (map)
  // =====================================================================
  cout << "===== ORDERED MAP (map) =====\n";

  map<string, long> orderedPhonebook;

  // Insert
  orderedPhonebook.insert({"unais", 8180013399});
  orderedPhonebook.insert({"home", 8421131930});
  orderedPhonebook["office"] = 9876543210;  // inserts if not exist

  // Traverse (sorted by key)
  cout << "\nOrdered Phonebook:\n";
  for (auto& entry : orderedPhonebook) {
    cout << entry.first << " : " << entry.second << "\n";
  }

  // Search
  cout << "\nSearching for 'home'...\n";
  auto it1 = orderedPhonebook.find("home");
  if (it1 != orderedPhonebook.end())
    cout << "Found: " << it1->first << " : " << it1->second << "\n";
  else
    cout << "Key not found.\n";

  // Erase last element
  cout << "\nErasing last element (in sorted order)...\n";
  orderedPhonebook.erase(--orderedPhonebook.end());

  // After erase
  cout << "\nAfter Deletion:\n";
  for (auto& entry : orderedPhonebook) {
    cout << entry.first << " : " << entry.second << "\n";
  }

  // Check existence
  cout << "\nChecking if 'unais' exists:\n";
  if (orderedPhonebook.count("unais"))
    cout << "'unais' exists.\n";
  else
    cout << "'unais' does NOT exist.\n";

  cout << "Size = " << orderedPhonebook.size() << "\n\n\n";

  // =====================================================================
  //                      UNORDERED MAP (unordered_map)
  // =====================================================================
  cout << "===== UNORDERED MAP (unordered_map) =====\n";

  unordered_map<string, long> unorderedPhonebook;

  // Insert
  unorderedPhonebook.insert({"unais", 8180013399});
  unorderedPhonebook.insert({"home", 8421131930});
  unorderedPhonebook["office"] = 9988776655;

  // Traverse (random order)
  cout << "\nUnordered Phonebook:\n";
  for (auto& entry : unorderedPhonebook) {
    cout << entry.first << " : " << entry.second << "\n";
  }

  // Search
  cout << "\nSearching for 'home'...\n";
  auto it2 = unorderedPhonebook.find("home");
  if (it2 != unorderedPhonebook.end())
    cout << "Found: " << it2->first << " : " << it2->second << "\n";
  else
    cout << "Key not found.\n";

  // Erase by key
  cout << "\nErasing 'office'...\n";
  unorderedPhonebook.erase("office");

  // After erase
  cout << "\nAfter Deletion:\n";
  for (auto& entry : unorderedPhonebook) {
    cout << entry.first << " : " << entry.second << "\n";
  }

  // Check existence
  cout << "\nChecking if 'unais' exists:\n";
  if (unorderedPhonebook.count("unais"))
    cout << "'unais' exists.\n";
  else
    cout << "'unais' does NOT exist.\n";

  cout << "Size = " << unorderedPhonebook.size() << "\n";

  return 0;
}
