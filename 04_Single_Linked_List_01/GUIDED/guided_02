#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* alokasi(int value) {
    Node* newNode = new Node;

    if (newNode != nullptr) {
        newNode->data = value;
        newNode->next = nullptr;
    }

    return newNode;
}

void dealokasi(Node* node) {
    delete node;
}

bool isListEmpty(Node* head) {
    return head == nullptr;
}

void insertFirst(Node* &head, int value) {
    Node* newNode = alokasi(value);

    if (newNode != nullptr) {
        newNode->next = head;
        head = newNode;
    }
}

void insertLast(Node* &head, int value) {
    Node* newNode = alokasi(value);

    if (newNode != nullptr) {
        if (isListEmpty(head)) {
            head = newNode;
        } else {
            Node* temp = head;

            while (temp->next != nullptr) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }
}

void printList(Node* head) {
    if (isListEmpty(head)) {
        cout << "List Kosong!" << endl;
    } else {
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
}

int countElements(Node* head) {
    int count = 0;
    Node* temp = head;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    return count;
}

void clearList(Node* &head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        dealokasi(temp);
    }
}

int main() {
    Node* head = nullptr;

    insertFirst(head, 10);
    insertLast(head, 20);
    insertLast(head, 30);

    cout << "Isi List: ";
    printList(head);

    cout << "Jumlah elemen: " << countElements(head) << endl;

    clearList(head);

    cout << "Isi list setelah penghapusan: ";
    printList(head);

    return 0;
}