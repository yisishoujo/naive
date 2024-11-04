#include <iostream>
#include <vector>

// Template class for ListNode
template <typename T>
class ListNode {
public:
    T val;
    ListNode<T>* next;

    // Constructor to initialize node value
    ListNode(T x) : val(x), next(nullptr) {}
};

// Template class for LinkedList
template <typename T>
class LinkedList {
private:
    ListNode<T>* head;

public:
    // Constructor initializes the list with no elements
    LinkedList() : head(nullptr) {}

    // Constructor to build list from vector
    LinkedList(const std::vector<T>& elements) : head(nullptr) {
        if (elements.empty()) return;

        head = new ListNode<T>(elements[0]);
        ListNode<T>* current = head;

        for (size_t i = 1; i < elements.size(); ++i) {
            current->next = new ListNode<T>(elements[i]);
            current = current->next;
        }
    }

    // Destructor to free memory
    ~LinkedList() {
        ListNode<T>* current = head;
        while (current != nullptr) {
            ListNode<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // Function to print the linked list
    void printList() const {
        ListNode<T>* current = head;
        while (current != nullptr) {
            std::cout << current->val << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    // Vector of integers
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    // Create a LinkedList from the vector
    LinkedList<int> list(vec);

    // Print the list
    list.printList();

    return 0;
}
