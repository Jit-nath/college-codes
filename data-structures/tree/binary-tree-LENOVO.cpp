#include <iostream>
using namespace std;
typedef struct node {
    int data;
    node *next;
} node;
class list {
    node *head;

  public:
    list() {}
    list(int data) {
        head = new node;
        head->data = data;
        head->next = NULL;
    }
    ~list() {}

    void push(int data) {
        node *newNode = new node;
        while (head->next != NULL) {
            head = head->next;
        }
        head->next = newNode;
        newNode->data = data;
        newNode->next = NULL;
    }
    void printList() {
        node *temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        if (temp->next == NULL)
            cout << "NULL";
    }
};

int main() {
    list node(10);

    for (int i = 20; i <= 100; i += 10) {
        node.push(i);
    }
    node.printList();

    return 0;
}