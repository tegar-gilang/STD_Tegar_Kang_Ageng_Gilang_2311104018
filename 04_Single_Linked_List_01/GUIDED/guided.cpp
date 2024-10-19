#include <iostream>
#include <string>
using namespace std;

struct mahasiswa
{
    char nama[30];
    char nim[10];
};


struct  Node
{
    mahasiswa data;
    Node *next;
};

Node *head;
Node *tail;

void init(){
    head = nullptr;
    tail = nullptr;
}

bool isEmpty(){
    return head == nullptr;
}

void insertDepan(const mahasiswa &data){
    Node *baru = new Node;
    baru -> data = data;
    baru ->next = nullptr;
    if (isEmpty())
    {
        head = tail = nullptr;
    }else{
        baru -> next = head;
        head = baru;
    }
}

void insertBelakang(const mahasiswa &data){
    Node *baru = new Node;
    baru -> data = data;
    baru -> next = nullptr;
    if (isEmpty())
    {
        head = tail =baru;
    }else{
        tail -> next =baru;
        tail = baru;
    }
}

int hitungList(){
    Node *currenct = head;
    int jumlah = 0;
    while (currenct != nullptr)
    {
        jumlah++;
        currenct = currenct ->next;
    }
    return jumlah;
}

// Hapus Depan
void hapusDepan() {
    if (!isEmpty()) {
        Node *hapus = head;
        head = head->next;
        delete hapus;
        if (head == nullptr) {
            tail = nullptr; // Jika list menjadi kosong
        }
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang() {
    if (!isEmpty()) {
        if (head == tail) {
            delete head;
            head = tail = nullptr; // List menjadi kosong
        } else {
            Node *bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            delete tail;
            tail = bantu;
            tail->next = nullptr;
        }
    } else {
        cout << "List kosong!" << endl;
    }
}

// Tampilkan List
void tampil() {
    Node *current = head;
    if (!isEmpty()) {
        while (current != nullptr) {
            cout << "Nama: " << current->data.nama << ", NIM: " << current->data.nim << endl;
            current = current->next;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus List
void clearList() {
    Node *current = head;
    while (current != nullptr) {
        Node *hapus = current;
        current = current->next;
        delete hapus;
    }
    head = tail = nullptr;
    cout << "List berhasil terhapus!" << endl;
}

// Main function
int main() {
    init();
    
    // Contoh data mahasiswa
    mahasiswa m1 = {"Alice", "123456"};
    mahasiswa m2 = {"Bob", "654321"};
    mahasiswa m3 = {"Charlie", "112233"};

    // Menambahkan mahasiswa ke dalam list
    insertDepan(m1);
    tampil();
    insertBelakang(m2);
    tampil();
    insertDepan(m3);
    tampil();

    // Menghapus elemen dari list
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();

    // Menghapus seluruh list
    clearList();
    
    return 0;
}