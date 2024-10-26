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

    // Fungsi untuk menambahkan elemen di awal list
    void insertFirst2311104018(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode; // Jika list kosong, tail juga mengarah ke node baru
        }
        head = newNode;
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
};

int main() {
    DoublyLinkedList list;
    int data;

    // Input elemen pertama dan tambahkan di awal list
    cout << "Masukkan elemen pertama: ";
    cin >> data;
    list.insertFirst2311104018(data);

    // Input elemen kedua dan tambahkan di awal list
    cout << "Masukkan elemen kedua di awal: ";
    cin >> data;
    list.insertFirst2311104018(data);

    // Input elemen ketiga dan tambahkan di akhir list
    cout << "Masukkan elemen ketiga di akhir: ";
    cin >> data;
    list.insertLast2311104018(data);

    // Tampilkan semua elemen dari depan ke belakang
    cout << "DAFTAR ANGGOTA LIST: ";
    list.displayForward2311104018();

    return 0;
}
