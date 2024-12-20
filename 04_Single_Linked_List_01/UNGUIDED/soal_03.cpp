#include <iostream>
using namespace std;

// Definisi struktur Node
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk membuat node baru di depan
void insertAtFront(Node*& head, int value) {
    Node* newNode = new Node(); // Membuat node baru
    newNode->data = value;       // Mengisi nilai pada node baru
    newNode->next = head;        // Menghubungkan node baru ke node pertama
    head = newNode;              // Mengubah head ke node baru
}

// Fungsi untuk membuat node baru di belakang
void insertAtBack(Node*& head, int value) {
    Node* newNode = new Node(); // Membuat node baru
    newNode->data = value;      // Mengisi nilai pada node baru
    newNode->next = nullptr;    // Node terakhir akan menunjuk ke nullptr

    if (head == nullptr) {
        head = newNode;         // Jika list kosong, node baru menjadi head
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;  // Mencari node terakhir
        }
        temp->next = newNode;   // Menghubungkan node terakhir ke node baru
    }
}

// Fungsi untuk mencari node dengan nilai tertentu
bool searchNode(Node* head, int value) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) {
            return true;        // Jika nilai ditemukan, kembalikan true
        }
        temp = temp->next;      // Lanjut ke node berikutnya
    }
    return false;               // Jika tidak ditemukan, kembalikan false
}

// Fungsi untuk menghitung panjang linked list
int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;                // Hitung node
        temp = temp->next;      // Lanjut ke node berikutnya
    }
    return count;               // Kembalikan total jumlah node
}

// Fungsi untuk mencetak isi linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

// Fungsi utama
int main() {
    Node* head = nullptr; // Inisialisasi linked list kosong

    // Contoh operasi
    insertAtFront(head, 10); // Tambah node dengan nilai 10 di depan
    insertAtBack(head, 20);  // Tambah node dengan nilai 20 di belakang
    insertAtFront(head, 5);  // Tambah node dengan nilai 5 di depan

    // Cetak linked list
    cout << "Isi Linked List: ";
    printList(head);  // Output: 5 -> 10 -> 20

    // Cari node dengan nilai tertentu
    int searchValue = 20;
    if (searchNode(head, searchValue)) {
        cout << "Node dengan nilai " << searchValue << " ditemukan." << endl;
    } else {
        cout << "Node dengan nilai " << searchValue << " tidak ditemukan." << endl;
    }

    // Hitung panjang linked list
    int length = countNodes(head);
    cout << "Panjang linked list: " << length << endl; // Output: 3

    return 0;
}
