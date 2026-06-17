/*
 * ============================================================================
 *  LinkedList.cpp
 * ============================================================================
 *  A complete singly linked list implementation: the standard operations
 *  (insert/delete/search) plus the classic problems that come up in
 *  technical interviews (reversal, cycle detection, palindrome check,
 *  merging two sorted lists, adding two numbers).
 *
 *  NAMING CONVENTIONS used throughout this file:
 *    - Classes / structs    -> PascalCase          (Node, LinkedList)
 *    - Methods / functions  -> camelCase            (insertAtHead, hasCycle)
 *    - Member variables     -> camelCase, no prefix (head, size)
 *    - Pointer "walkers" use short, INDUSTRY-STANDARD names that any
 *      interviewer instantly recognises: current, prev, next, slow, fast,
 *      lead, trail. These aren't lazy names - they're the names everyone
 *      uses for these exact roles, so anything else (e.g. "temp1", "x")
 *      usually makes the code harder to follow, not easier.
 *
 *  Every non-trivial method is commented with WHY it works, not just what
 *  it does - that's the part interviewers actually probe on.
 * ============================================================================
 */

#include <iostream>
using namespace std;

// ----------------------------------------------------------------------------
// Node
// ----------------------------------------------------------------------------
// A plain data carrier - no behaviour, no invariants to protect, so a
// lightweight struct (not a class) is the right tool here. The LinkedList
// class below is the actual abstraction that enforces correctness.
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// ----------------------------------------------------------------------------
// LinkedList
// ----------------------------------------------------------------------------
class LinkedList {
   private:
    Node* head;
    int size;  // tracked incrementally so getSize() is O(1) instead of a full walk

    // Returns the node at 0-indexed `index`, or nullptr if out of range.
    Node* getNodeAt(int index) const {
        if (index < 0 || index >= size) return nullptr;

        Node* current = head;
        for (int i = 0; i < index; i++) current = current->next;

        return current;
    }

    // Recursive helper for reverseRecursive(). Reverses the sub-list that
    // starts at `node` and returns the new head of that sub-list.
    Node* reverseRecursiveHelper(Node* node) {
        // Base case: empty list, or we've walked off the last node -> it
        // becomes the new head of the reversed sub-list.
        if (node == nullptr || node->next == nullptr) return node;

        Node* newHead = reverseRecursiveHelper(node->next);

        // After the recursive call returns, node->next is the tail of the
        // already-reversed remainder. Point it back at `node`, then cut
        // node's old forward link.
        node->next->next = node;
        node->next = nullptr;

        return newHead;
    }

   public:
    // ------------------------------------------------------------------
    // Construction / Destruction
    // ------------------------------------------------------------------

    LinkedList() : head(nullptr), size(0) {}  // empty list

    LinkedList(int firstValue) : head(new Node(firstValue)), size(1) {}

    // Frees every node so the list never leaks memory when it goes out of scope.
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    // Copying a raw-pointer list naively would let two LinkedLists point at
    // the SAME nodes - whichever destructor runs first frees memory the
    // other still thinks it owns (double free / use-after-free). So we
    // disable copying outright.
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    // Moving is safe and O(1): just steal the other list's pointer instead
    // of touching any nodes. This is what lets mergeSorted()/addTwoNumbers()
    // below return a LinkedList by value.
    LinkedList(LinkedList&& other) noexcept : head(other.head), size(other.size) {
        other.head = nullptr;
        other.size = 0;
    }

    LinkedList& operator=(LinkedList&& other) noexcept {
        if (this != &other) {
            Node* current = head;
            while (current != nullptr) {
                Node* next = current->next;
                delete current;
                current = next;
            }
            head = other.head;
            size = other.size;
            other.head = nullptr;
            other.size = 0;
        }
        return *this;
    }

    // ------------------------------------------------------------------
    // Basic utilities
    // ------------------------------------------------------------------

    bool isEmpty() const {
        return head == nullptr;
    }

    int getSize() const {
        return size;
    }

    void printList() const {
        Node* current = head;
        cout << "[ ";
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) cout << " -> ";
            current = current->next;
        }
        cout << " ]" << endl;
    }

    // ------------------------------------------------------------------
    // Insertion
    // ------------------------------------------------------------------

    void insertAtHead(int value)  // O(1)
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void insertAtTail(int value)  // O(n) - must walk to the last node
    {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            size++;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) current = current->next;

        current->next = newNode;
        size++;
    }

    // Inserts `value` so it becomes the element at 0-indexed `position`.
    // position == 0 behaves like insertAtHead; position == size behaves like insertAtTail.
    void insertAtPosition(int value, int position)  // O(n)
    {
        if (position < 0 || position > size) {
            cout << "Invalid position: " << position << endl;
            return;
        }

        if (position == 0) {
            insertAtHead(value);
            return;
        }

        Node* prevNode = getNodeAt(position - 1);
        Node* newNode = new Node(value);
        newNode->next = prevNode->next;
        prevNode->next = newNode;
        size++;
    }

    // ------------------------------------------------------------------
    // Deletion
    // ------------------------------------------------------------------

    void deleteAtHead()  // O(1)
    {
        if (head == nullptr) {
            cout << "List is empty - nothing to delete." << endl;
            return;
        }

        Node* oldHead = head;
        head = head->next;
        delete oldHead;
        size--;
    }

    void deleteAtTail()  // O(n) - must find the second-last node
    {
        if (head == nullptr) {
            cout << "List is empty - nothing to delete." << endl;
            return;
        }

        if (head->next == nullptr)  // only one node in the list
        {
            delete head;
            head = nullptr;
            size--;
            return;
        }

        Node* secondLast = head;
        while (secondLast->next->next != nullptr) secondLast = secondLast->next;

        delete secondLast->next;
        secondLast->next = nullptr;
        size--;
    }

    void deleteAtPosition(int position)  // O(n)
    {
        if (position < 0 || position >= size) {
            cout << "Invalid position: " << position << endl;
            return;
        }

        if (position == 0) {
            deleteAtHead();
            return;
        }

        Node* prevNode = getNodeAt(position - 1);
        Node* nodeToDelete = prevNode->next;
        prevNode->next = nodeToDelete->next;
        delete nodeToDelete;
        size--;
    }

    // Deletes the FIRST node holding `value`. Returns true if something was deleted.
    bool deleteByValue(int value)  // O(n)
    {
        if (head == nullptr) return false;

        if (head->data == value) {
            deleteAtHead();
            return true;
        }

        Node* prev = head;
        Node* current = head->next;
        while (current != nullptr) {
            if (current->data == value) {
                prev->next = current->next;
                delete current;
                size--;
                return true;
            }
            prev = current;
            current = current->next;
        }
        return false;  // value not found
    }

    // ------------------------------------------------------------------
    // Search
    // ------------------------------------------------------------------

    bool search(int value) const {
        return indexOf(value) != -1;
    }  // O(n)

    int indexOf(int value) const  // O(n)
    {
        Node* current = head;
        int index = 0;
        while (current != nullptr) {
            if (current->data == value) return index;
            current = current->next;
            index++;
        }
        return -1;
    }

    // ------------------------------------------------------------------
    // Classic interview operations
    // ------------------------------------------------------------------

    // Iterative reversal via the three-pointer (prev, current, next) walk.
    // Time O(n), Space O(1).
    void reverseIterative() {
        Node* prev = nullptr;
        Node* current = head;

        while (current != nullptr) {
            Node* next = current->next;  // save before we overwrite it
            current->next = prev;        // flip the arrow
            prev = current;              // advance prev
            current = next;              // advance current
        }

        head = prev;  // prev ends up sitting on the old tail - the new head
    }

    // Same result as reverseIterative(), via recursion instead of a loop.
    // Time O(n), Space O(n) for the call stack.
    void reverseRecursive() {
        head = reverseRecursiveHelper(head);
    }

    // Tortoise & Hare: slow moves 1 step, fast moves 2. When fast falls off
    // the end, slow is sitting exactly on the middle node.
    // Time O(n), Space O(1).
    int findMiddleValue() const {
        if (head == nullptr) {
            cout << "List is empty - no middle exists." << endl;
            return -1;
        }

        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->data;
    }

    // Removes the n-th node counting from the END (1-indexed), in one pass.
    // Technique: send a "lead" pointer n steps ahead first (via a dummy
    // sentinel, so deleting the real head needs no special case). Then move
    // `lead` and `trail` together - the gap between them stays exactly n,
    // so when `lead` falls off the end, `trail` sits right before the node
    // to remove. (We could shortcut with `size - n` since we track size,
    // but this two-pointer version is the technique you're expected to
    // reproduce when you're just handed a head pointer with no size
    // tracking - which is how this problem is usually posed.)
    void removeNthFromEnd(int n)  // O(n)
    {
        if (n <= 0 || n > size) {
            cout << "Invalid n: " << n << endl;
            return;
        }

        Node dummy(0);  // sentinel - means "removing the real head" needs no special case
        dummy.next = head;

        Node* lead = &dummy;
        Node* trail = &dummy;

        for (int i = 0; i < n; i++) lead = lead->next;

        while (lead->next != nullptr) {
            lead = lead->next;
            trail = trail->next;
        }

        Node* nodeToRemove = trail->next;
        trail->next = nodeToRemove->next;
        delete nodeToRemove;
        size--;

        head = dummy.next;  // covers the case where the head itself was removed
    }

    // Checks if the list reads the same forwards and backwards, in O(1)
    // extra space: find the middle, reverse the second half in place,
    // compare the two halves, then reverse the second half back so the
    // list is left exactly as it was found (a "checking" function
    // shouldn't have side effects).
    bool isPalindrome() const  // Time O(n), Space O(1)
    {
        if (head == nullptr || head->next == nullptr) return true;

        // Step 1: find the middle (same slow/fast technique as findMiddleValue).
        Node* slow = head;
        Node* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: reverse the second half (from `slow` to the end).
        Node* prev = nullptr;
        Node* current = slow;
        while (current != nullptr) {
            Node* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        Node* secondHalfHead = prev;

        // Step 3: walk both halves together and compare.
        Node* firstHalfPtr = head;
        Node* secondHalfPtr = secondHalfHead;
        bool isPalin = true;
        while (secondHalfPtr != nullptr) {
            if (firstHalfPtr->data != secondHalfPtr->data) {
                isPalin = false;
                break;
            }
            firstHalfPtr = firstHalfPtr->next;
            secondHalfPtr = secondHalfPtr->next;
        }

        // Step 4: un-reverse the second half so the list is left untouched.
        prev = nullptr;
        current = secondHalfHead;
        while (current != nullptr) {
            Node* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return isPalin;
    }

    // Floyd's Cycle Detection ("Tortoise and Hare"). If a cycle exists, the
    // fast pointer eventually laps the slow pointer from inside the loop.
    // Time O(n), Space O(1).
    bool hasCycle() const {
        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }

    // TESTING HELPER ONLY: artificially links the tail back to the node at
    // `position`, creating a cycle so hasCycle() has something to find.
    // Returns the tail node so you can pass it to removeCycleForDemo() and
    // safely undo this before the list is used or destroyed normally -
    // printList(), the destructor, etc. would all loop forever on a real cycle.
    Node* createCycleAt(int position) {
        Node* cycleTarget = getNodeAt(position);
        if (cycleTarget == nullptr || head == nullptr) return nullptr;

        Node* tail = head;
        while (tail->next != nullptr) tail = tail->next;

        tail->next = cycleTarget;
        return tail;
    }

    // Pairs with createCycleAt(): pass in the Node* it returned to safely
    // break the cycle again.
    void removeCycleForDemo(Node* tailNode) {
        if (tailNode != nullptr) tailNode->next = nullptr;
    }

    // ------------------------------------------------------------------
    // Operations that combine two lists
    // ------------------------------------------------------------------

    // Merges two ALREADY-SORTED lists into a brand new sorted list.
    // Builds the result from fresh nodes rather than splicing the
    // originals, so `a` and `b` stay fully intact and independently
    // destructible afterward.
    static LinkedList mergeSorted(const LinkedList& a, const LinkedList& b)  // O(n + m)
    {
        LinkedList result;
        Node* p1 = a.head;
        Node* p2 = b.head;

        while (p1 != nullptr && p2 != nullptr) {
            if (p1->data <= p2->data) {
                result.insertAtTail(p1->data);
                p1 = p1->next;
            } else {
                result.insertAtTail(p2->data);
                p2 = p2->next;
            }
        }
        while (p1 != nullptr) {
            result.insertAtTail(p1->data);
            p1 = p1->next;
        }
        while (p2 != nullptr) {
            result.insertAtTail(p2->data);
            p2 = p2->next;
        }

        return result;  // moved out, not copied - see the move constructor above
    }

    // Classic "Add Two Numbers": each list stores one number with its
    // LEAST significant digit at the head (342 is stored as 2 -> 4 -> 3).
    // We walk both lists together like grade-school column addition,
    // carrying whenever a column totals 10 or more.
    static LinkedList addTwoNumbers(const LinkedList& a, const LinkedList& b)  // O(max(n, m))
    {
        LinkedList result;
        Node* p1 = a.head;
        Node* p2 = b.head;
        int carry = 0;

        while (p1 != nullptr || p2 != nullptr || carry != 0) {
            int digit1 = (p1 != nullptr) ? p1->data : 0;
            int digit2 = (p2 != nullptr) ? p2->data : 0;

            int columnSum = digit1 + digit2 + carry;
            carry = columnSum / 10;
            result.insertAtTail(columnSum % 10);

            if (p1 != nullptr) p1 = p1->next;
            if (p2 != nullptr) p2 = p2->next;
        }

        return result;
    }
};

// ----------------------------------------------------------------------------
// Demo driver - exercises every operation above so you can compile, run,
// and watch each technique work on real data.
// ----------------------------------------------------------------------------
int main() {
    cout << "===== Insertion & traversal =====" << endl;
    LinkedList list1;  // empty list - your original code couldn't represent this
    list1.insertAtTail(10);
    list1.insertAtTail(20);
    list1.insertAtTail(30);
    list1.insertAtHead(5);
    list1.insertAtPosition(15, 2);  // 5 10 15 20 30
    list1.printList();
    cout << "Size: " << list1.getSize() << endl;

    cout << "\n===== Search =====" << endl;
    cout << "Contains 15? " << (list1.search(15) ? "yes" : "no") << endl;
    cout << "Index of 20: " << list1.indexOf(20) << endl;

    cout << "\n===== Deletion =====" << endl;
    list1.deleteAtHead();
    list1.deleteAtTail();
    list1.deleteAtPosition(1);
    list1.deleteByValue(20);
    list1.printList();

    cout << "\n===== Reversal =====" << endl;
    LinkedList list2(1);
    list2.insertAtTail(2);
    list2.insertAtTail(3);
    list2.insertAtTail(4);
    list2.insertAtTail(5);
    cout << "Before:                  ";
    list2.printList();
    list2.reverseIterative();
    cout << "After reverseIterative(): ";
    list2.printList();
    list2.reverseRecursive();
    cout << "After reverseRecursive(): ";
    list2.printList();

    cout << "\n===== Middle element =====" << endl;
    cout << "Middle of list2: " << list2.findMiddleValue() << endl;

    cout << "\n===== Remove Nth from end =====" << endl;
    list2.removeNthFromEnd(2);  // removes the 2nd-from-last element (the 4)
    cout << "After removing 2nd-from-end: ";
    list2.printList();

    cout << "\n===== Palindrome check =====" << endl;
    LinkedList palinList(1);
    palinList.insertAtTail(2);
    palinList.insertAtTail(3);
    palinList.insertAtTail(2);
    palinList.insertAtTail(1);
    cout << "1 2 3 2 1 is palindrome? " << (palinList.isPalindrome() ? "yes" : "no") << endl;
    cout << "List still intact after check: ";
    palinList.printList();

    cout << "\n===== Cycle detection =====" << endl;
    LinkedList cycleDemo(1);
    cycleDemo.insertAtTail(2);
    cycleDemo.insertAtTail(3);
    cycleDemo.insertAtTail(4);
    cout << "Cycle present before linking? " << (cycleDemo.hasCycle() ? "yes" : "no") << endl;
    Node* cycleTail = cycleDemo.createCycleAt(1);  // tail (4) now points back to index 1 (the 2)
    cout << "Cycle present after linking?   " << (cycleDemo.hasCycle() ? "yes" : "no") << endl;
    cycleDemo.removeCycleForDemo(cycleTail);  // restore before this list goes out of scope!

    cout << "\n===== Merging two sorted lists =====" << endl;
    LinkedList sortedA(1);
    sortedA.insertAtTail(3);
    sortedA.insertAtTail(5);
    LinkedList sortedB(2);
    sortedB.insertAtTail(4);
    sortedB.insertAtTail(6);
    LinkedList merged = LinkedList::mergeSorted(sortedA, sortedB);
    cout << "Merged: ";
    merged.printList();

    cout << "\n===== Adding two numbers (digits stored least-significant first) =====" << endl;
    // 342 -> stored as 2,4,3   |   465 -> stored as 5,6,4   |   342 + 465 = 807
    LinkedList numA(2);
    numA.insertAtTail(4);
    numA.insertAtTail(3);
    LinkedList numB(5);
    numB.insertAtTail(6);
    numB.insertAtTail(4);
    LinkedList sum = LinkedList::addTwoNumbers(numA, numB);
    cout << "Sum (least-significant digit first): ";
    sum.printList();

    return 0;
}