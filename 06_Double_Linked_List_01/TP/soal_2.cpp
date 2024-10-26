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

    // Fungsi untuk menghapus elemen pertama
    void deleteFirst2311104018() {
        if (head == nullptr) {
            cout << "List is empty. No element to delete." << endl;
            return; // Jika list kosong
        }
        Node* temp = head;
        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr; // Jika hanya satu elemen di list
        }
        delete temp; // Hapus elemen
    }

    // Fungsi untuk menghapus elemen terakhir
    void deleteLast2311104018() {
        if (tail == nullptr) {
            cout << "List is empty. No element to delete." << endl;
            return; // Jika list kosong
        }
        Node* temp = tail;
        tail = tail->prev;

        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr; // Jika hanya satu elemen di list
        }
        delete temp; // Hapus elemen
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

    // Input elemen pertama
    cout << "Masukkan elemen pertama: ";
    cin >> data;
    list.insertLast2311104018(data);

    // Input elemen kedua di akhir
    cout << "Masukkan elemen kedua di akhir: ";
    cin >> data;
    list.insertLast2311104018(data);

    // Input elemen ketiga di akhir
    cout << "Masukkan elemen ketiga di akhir: ";
    cin >> data;
    list.insertLast2311104018(data);

    // Tampilkan semua elemen sebelum penghapusan
    cout << "DAFTAR ANGGOTA LIST SEBELUM PENGHAPUSAN: ";
    list.displayForward2311104018();

    // Hapus elemen pertama dan terakhir
    list.deleteFirst2311104018();
    list.deleteLast2311104018();

    // Tampilkan semua elemen setelah penghapusan
    cout << "DAFTAR ANGGOTA LIST SETELAH PENGHAPUSAN: ";
    list.displayForward2311104018();

    return 0;
}
