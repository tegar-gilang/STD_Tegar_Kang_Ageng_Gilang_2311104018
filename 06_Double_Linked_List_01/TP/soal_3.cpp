#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    // Constructor untuk inisialisasi head dan tail
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Fungsi untuk menambahkan elemen di akhir list
    void insertLast2311104018(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = tail;

        if (tail != nullptr) {
            tail->next = newNode;
        } else {
            head = newNode; // Jika list kosong, head juga mengarah ke node baru
        }
        tail = newNode;
    }

    // Fungsi untuk menampilkan semua elemen di list dari depan ke belakang
    void displayForward2311104018() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) cout << " <-> ";
            current = current->next;
        }
        cout << endl;
    }

    // Fungsi untuk menampilkan semua elemen di list dari belakang ke depan
    void displayBackward2311104018() {
        if (tail == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = tail;
        while (current != nullptr) {
            cout << current->data;
            if (current->prev != nullptr) cout << " <-> ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    int data;

    // Input 4 elemen
    for (int i = 0; i < 4; i++) {
        cout << "Masukkan elemen ke-" << (i + 1) << ": ";
        cin >> data;
        list.insertLast2311104018(data);
    }

    // Tampilkan elemen dari depan ke belakang
    cout << "Daftar elemen dari depan ke belakang: ";
    list.displayForward2311104018();

    // Tampilkan elemen dari belakang ke depan
    cout << "Daftar elemen dari belakang ke depan: ";
    list.displayBackward2311104018();

    return 0;
}
