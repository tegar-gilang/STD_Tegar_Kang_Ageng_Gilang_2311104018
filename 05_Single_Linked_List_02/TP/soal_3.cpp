#include <iostream>
using namespace std;

struct Elemen {
    int data;
    Elemen* next;
};

struct List {
    Elemen* head;
};

void createList2311104018(List &L) {
    L.head = NULL;
}

Elemen* alokasi2311104018(int x) {
    Elemen* newElemen = new Elemen;
    newElemen->data = x;
    newElemen->next = NULL;
    return newElemen;
}

void insertFirst2311104018(List &L, Elemen* P) {
    P->next = L.head;
    L.head = P;
}

void printInfo2311104018(List L) {
    Elemen* current = L.head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Procedure untuk memasukkan elemen secara terurut
void insertSorted2311104018(List &L, Elemen* P) {
    Elemen* Q = L.head;
    Elemen* Prev = NULL;

    // Cari posisi di mana elemen harus dimasukkan
    while (Q != NULL && Q->data < P->data) {
        Prev = Q;
        Q = Q->next;
    }

    // Jika elemen harus dimasukkan di posisi head
    if (Prev == NULL) {
        P->next = L.head;
        L.head = P;
    }
    // Jika elemen harus dimasukkan di antara dua elemen atau di akhir list
    else {
        Prev->next = P;
        P->next = Q;
    }
}

int main() {
    List L;
    createList2311104018(L);

    // Meminta pengguna untuk memasukkan 4 elemen integer
    cout << "Masukkan 4 elemen integer ke dalam list secara terurut:" << endl;
    for (int i = 0; i < 4; i++) {
        int value;
        cout << "Masukkan elemen ke-" << i + 1 << ": ";
        cin >> value;
        Elemen* newElemen = alokasi2311104018(value);
        insertSorted2311104018(L, newElemen);
    }

    // Menampilkan isi list setelah elemen awal dimasukkan
    cout << "List setelah 4 elemen awal dimasukkan:" << endl;
    printInfo2311104018(L);

    // Meminta pengguna memasukkan elemen tambahan
    cout << "Masukkan elemen tambahan untuk dimasukkan secara terurut: ";
    int additionalValue;
    cin >> additionalValue;
    Elemen* additionalElemen = alokasi2311104018(additionalValue);
    insertSorted2311104018(L, additionalElemen);

    // Menampilkan isi list setelah elemen tambahan dimasukkan
    cout << "List setelah elemen tambahan dimasukkan secara terurut:" << endl;
    printInfo2311104018(L);

    return 0;
}
