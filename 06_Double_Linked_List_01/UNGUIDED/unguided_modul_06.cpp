#include <iostream>
#include <string>
using namespace std;

// Struktur untuk menyimpan informasi buku
struct Book {
    int id;
    string title;
    string author;
};

// Struktur Node untuk doubly linked list
class Node {
public:
    Book data;
    Node* prev;
    Node* next;
    
    Node(Book bookData) {
        data = bookData;
        prev = nullptr;
        next = nullptr;
    }
};

// Kelas untuk mengelola doubly linked list
class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    // Constructor untuk inisialisasi head dan tail
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Fungsi untuk menambahkan buku di akhir list
    void insertBook(Book book) {
        Node* newNode = new Node(book);
        if (tail != nullptr) {
            tail->next = newNode;
            newNode->prev = tail;
        } else {
            head = newNode; // Jika list kosong, head juga mengarah ke node baru
        }
        tail = newNode;
    }

    // Fungsi untuk menampilkan semua buku dari awal ke akhir
    void displayForward() {
        Node* current = head;
        if (current == nullptr) {
            cout << "Daftar buku kosong." << endl;
            return;
        }
        cout << "Daftar Buku (Awal ke Akhir):" << endl;
        while (current != nullptr) {
            cout << "ID: " << current->data.id
                 << ", Judul: " << current->data.title
                 << ", Penulis: " << current->data.author << endl;
            current = current->next;
        }
    }

    // Fungsi untuk menampilkan semua buku dari akhir ke awal
    void displayBackward() {
        Node* current = tail;
        if (current == nullptr) {
            cout << "Daftar buku kosong." << endl;
            return;
        }
        cout << "Daftar Buku (Akhir ke Awal):" << endl;
        while (current != nullptr) {
            cout << "ID: " << current->data.id
                 << ", Judul: " << current->data.title
                 << ", Penulis: " << current->data.author << endl;
            current = current->prev;
        }
    }
};

int main() {
    DoublyLinkedList bookList;
    int n;

    cout << "Masukkan jumlah buku yang ingin ditambahkan: ";
    cin >> n;
    cin.ignore(); // Mengabaikan newline setelah input integer

    for (int i = 0; i < n; ++i) {
        Book newBook;
        cout << "Masukkan ID Buku: ";
        cin >> newBook.id;
        cin.ignore(); // Mengabaikan newline
        cout << "Masukkan Judul Buku: ";
        getline(cin, newBook.title);
        cout << "Masukkan Penulis Buku: ";
        getline(cin, newBook.author);
        bookList.insertBook(newBook);
    }

    // Tampilkan buku dari awal ke akhir
    bookList.displayForward();

    // Tampilkan buku dari akhir ke awal
    bookList.displayBackward();

    return 0;
}
