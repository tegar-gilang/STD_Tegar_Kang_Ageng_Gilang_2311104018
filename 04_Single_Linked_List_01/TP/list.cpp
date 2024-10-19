#include "list.h"
#include <iostream>

// Membuat list kosong
void createList(List &L) {
    L.first = nullptr;
}
// Mengalokasikan elemen baru
address allocate(infotype X) {
    address P = new Node;
    P->info = X;
    P->next = nullptr;
    return P;
}
// Memasukkan elemen di awal list
void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}
// Memasukkan elemen di akhir list
void insertLast(List &L, address P) {
    if (L.first == nullptr) {
        insertFirst(L, P);
    } else {
        address last = L.first;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = P;
    }
}
// Menampilkan isi list
void printInfo(List L) {
    address P = L.first;
    while (P != nullptr) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}
