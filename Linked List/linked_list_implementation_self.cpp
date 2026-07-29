/**
 * Doubly Linked List
 */
#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node* next;
    Node* prev;

   public:
    Node() {
        data = 0;
        next = nullptr;
        prev = nullptr;
    }
    Node(int data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
    Node(int data, Node* next, Node* prev) {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

class LinkedList {
   private:
    Node* head;
    int length = 0;

   public:
    LinkedList(int data) {
        head = new Node(data);
        length = 1;
    }
    LinkedList() {
        head = nullptr;
    }

    void prepend(int data) {
        length++;
        if (!head) {
            head = new Node(data);
            return;
        }
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    void append(int data) {
        length++;
        if (!head) {
            // If list empty->just make new node as head and return
            head = new Node(data);
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new Node(data);
    }

    void delete_head() {
        if (!this->head) {
            cout << "Empty List!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
        length--;
    }

    void delete_tail() {
        if (!this->head) {
            cout << "Empty List!" << endl;
            return;
        }
        length--;
        if (!this->head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* new_tail = head;
        while (new_tail->next->next) {
            new_tail = new_tail->next;
        }
        Node* node_to_delete = new_tail->next;
        new_tail->next = nullptr;
        delete node_to_delete;
        node_to_delete = nullptr;
    }

    void insert(int idx, int data) {
        if (idx < 0 || idx > this->length) {
            cout << "Invalid Position\n";
            return;
        }
        if (idx == 0) {
            prepend(data);

        } else if (idx == length) {
            append(data);
        } else {
            Node* temp = head;
            for (int i = 0; i < idx - 1; i++) {
                temp = temp->next;
            }
            Node* next_to_newNode = temp->next;

            Node* newNode = new Node(data);

            temp->next = newNode;
            newNode->next = next_to_newNode;
            length++;
        }
    }

    void delete_pos(int idx) {
        if (idx < 0 || idx >= this->length) {
            cout << "Invalid Position\n";
            return;
        }

        if (idx == 0)
            delete_head();
        else if (idx == this->length - 1)
            delete_tail();
        else {
            Node* temp = this->head;
            for (int i = 0; i < idx - 1; i++) {
                temp = temp->next;
            }
            Node* node_to_delete = temp->next;
            temp->next = node_to_delete->next;
            node_to_delete->next = nullptr;
            delete node_to_delete;
            length--;
        }
    }

    void size() const {
        cout << "Size: " << this->length << endl;
    }

    void search(int key) const {
        if (head == nullptr) {
            cout << "Empty List\n";
            return;
        }
        Node* temp = head;
        while (temp) {
            if (temp->data == key) {
                cout << "Found key at position: " << length - 1 << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "Key not found!!!" << endl;
    }

    void print_list() const {
        if (!this->head) {
            cout << "Empty List!" << endl;
            return;
        }
        Node* temp = this->head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // this function is not efficient instead use tail to reduce timecomplexity
    void construct_linked_list() {
        while (true) {
            int inputs;
            cout << "Enter the linked list elements: ";
            cin >> inputs;
            if (inputs == -1) break;

            Node* new_node = new Node(inputs);

            if (!this->head) {
                head = new_node;
            } else {
                Node* temp = head;
                // Traverse to the last node
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = new_node;
            }

            length++;
        }
    }

    void convert_array_list(vector<int>& arr, int n) {
        if (head == nullptr) {
            head = new Node(arr[0]);
            Node* temp = head;
            for (int i = 1; i < n; i++) {
                temp->next = new Node(arr[i]);
                temp = temp->next;
            }
        }
    }

    ~LinkedList() {
        while (head) {
            delete_head();
        }
    }
};


class DoublyLinkedList {
   private:
    Node* head;
    int length = 0;

   public:
    DoublyLinkedList() {
        head = nullptr;
        length = 0;
    }

    DoublyLinkedList(int data) {
        head = new Node(data);
        length += 1;
    }
    DoublyLinkedList(int data, Node* next, Node* prev) {
        head = new Node(data, next, prev);
        length += 1;
    }

    void delete_head() {
        if (head == nullptr) {
            cout << "Empty List!" << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node* back = head;
            head = head->next;
            head->prev = nullptr;
            back->next = nullptr;
            delete back;
            back = nullptr;
        }
        length -= 1;
    }

    void delete_tail() {
        if (head == nullptr) {
            cout << "Empty List!" << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node* new_tail = head;
            while (new_tail->next->next != nullptr) {
                new_tail = new_tail->next;
            }
            Node* temp = new_tail->next;
            new_tail->next = nullptr;
            temp->prev = nullptr;
            delete temp;
            temp = nullptr;
        }
        length -= 1;
    }

    void delete_index(int idx) {
        if (head == nullptr || idx < 0 || idx >= length) {
            cout << "Empty List or Invalid Index!" << endl;
            return;
        }
        if (idx == 0) {
            delete_head();
        } else if (idx == length - 1) {
            delete_tail();
        } else {
            Node* node_to_delete = head;
            for (int i = 1; i <= idx; i++) {
                node_to_delete = node_to_delete->next;
            }
            Node* back = node_to_delete->prev;
            Node* front = node_to_delete->next;

            back->next = front;
            front->prev = back;

            delete node_to_delete;
            node_to_delete = nullptr;
            length -= 1;
        }
    }

    void prepend(int data) {
        Node* new_node = new Node(data);
        if (head == nullptr) {
            head = new_node;
        } else {
            new_node->next = head;
            head->prev = new_node;
            head = head->prev;
        }
        length += 1;
    }

    void append(int data) {
        Node* new_node = new Node(data);
        if (head == nullptr) {
            head = new_node;
        } else {
            Node* temp = head;

            while (temp->next != nullptr) {
                temp = temp->next;
            }

            temp->next = new_node;
            new_node->prev = temp;
            temp = nullptr;
        }
        length += 1;
    }

    void insert_index(int idx, int data) {
        if (idx < 0 || idx > length) {
            cout << "Empty List or Invalid Index!" << endl;
            return;
        }
        if (head == nullptr || idx == 0) {
            prepend(data);
        } else if (idx == length) {
            append(data);
        } else {
            Node* front = head;
            for (int i = 1; i <= idx; i++) {
                front = front->next;
            }
            Node* back = front->prev;

            Node* new_node = new Node(data, front, back);

            back->next = new_node;
            front->prev = new_node;

            length += 1;
        }
    }

    void convert_array_to_doubly_list(vector<int>& arr, int n) {
        if (n == 0) {
            cout << "Empty Array!" << endl;
            return;
        }

        while (head) delete_head();

        head = new Node(arr[0]);
        Node* back = head;
        for (int i = 1; i < n; i++) {
            Node* new_node = new Node(arr[i], nullptr, back);
            back->next = new_node;
            back = back->next;
        }
        length = n;
    }

    int size() const {
        return length;
    }

    void print() const {
        if (head == nullptr) {
            cout << "Empty List!" << endl;
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " <-> ";
            temp = temp->next;
        }
        cout << endl;
        temp = nullptr;  // avoiding dangling pointer
    }

    ~DoublyLinkedList() {
        while (head) {
            delete_head();
        }
    }
};

int main() {
    vector<int> arr = {000, 100, 200, 300, 400};
    DoublyLinkedList list;
    list.convert_array_to_doubly_list(arr, arr.size());
    list.print();
    return 0;
}