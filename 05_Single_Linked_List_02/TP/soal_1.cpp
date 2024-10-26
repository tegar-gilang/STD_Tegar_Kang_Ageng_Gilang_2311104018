#include <iostream>
using namespace std;

struct Elemen {
    int data;
    Elemen* next;
};

// Inisialisasi list
struct List {
    Elemen* head;
};

void createList_2311104018(List &L) {
    L.head = NULL;
}

Elemen* alokasi_2311104018(int x) {
    Elemen* newElemen = new Elemen;
    newElemen->data = x;
    newElemen->next = NULL;
    return newElemen;
}

void insertFirst_2311104018(List &L, Elemen* P) {
    P->next = L.head;
    L.head = P;
}

void printInfo_2311104018(List L) {
    Elemen* current = L.head;
    int position = 1;
    while (current != NULL) {
        cout << "Elemen ke-" << position << ": " << current->data << endl;
        current = current->next;
        position++;
    }
}

void searchElement_2311104018(List L, int i) {
    Elemen* current = L.head;
    int position = 1;
    bool found = false;

    // Loop untuk mencari elemen dengan nilai i
    while (current != NULL) {
        if (current->data == i) {
            cout << "Nilai " << i << " ditemukan pada alamat: " << current << " dengan posisi urutan ke-" << position << endl;
            found = true;
            break;
        }
        current = current->next;
        position++;
    }

    // Jika elemen tidak ditemukan
    if (!found) {
        cout << "Elemen dengan nilai " << i << " tidak ada dalam list." << endl;
    }
}

int main() {
    List L;
    createList_2311104018(L);

    // Meminta pengguna untuk memasukkan 6 elemen
    cout << "Masukkan 6 elemen integer ke dalam list:" << endl;
    for (int j = 0; j < 6; j++) {
        int value;
        cout << "Masukkan elemen ke-" << j + 1 << ": ";
        cin >> value;
        Elemen* newElemen = alokasi_2311104018(value);
        insertFirst_2311104018(L, newElemen);
    }

    // Menampilkan isi list
    cout << "Isi list:" << endl;
    printInfo_2311104018(L);

    // Meminta pengguna untuk memasukkan nilai yang ingin dicari
    int cari;
    cout << "Masukkan nilai yang ingin dicari: ";
    cin >> cari;

    // Mencari elemen dalam list
    searchElement_2311104018(L, cari);

    return 0;
}
