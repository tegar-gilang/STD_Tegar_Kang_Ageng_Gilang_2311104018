#include "stack.h"
#include <iostream>
using namespace std;

// Menginisialisasi stack
void createStack(stack &S) {
    S.Top = -1;  // Inisialisasi Top ke -1 agar stack kosong
}

// Mengecek apakah stack kosong
bool isEmpty(stack S) {
    return S.Top < 0;
}

// Mengecek apakah stack penuh
bool isFull(stack S) {
    return S.Top == MAX_SIZE - 1; // Top maksimal adalah MAX_SIZE - 1
}

// Menambahkan elemen ke stack
void push(stack &S, infotype x) {
    if (!isFull(S)) {
        S.Top++;
        S.info[S.Top] = x; // Menambahkan elemen ke Top
    } else {
        cout << "Stack penuh, tidak bisa menambahkan elemen." << endl;
    }
}

// Menghapus elemen dari stack dan mengembalikannya
int pop(stack &S) {
    infotype x = '\0'; // Inisialisasi x
    if (!isEmpty(S)) {
        x = S.info[S.Top]; // Ambil elemen teratas
        S.Top--; // Mengurangi Top
    } else {
        cout << "Stack kosong, tidak bisa melakukan pop." << endl;
    }
    return x; // Mengembalikan elemen yang dihapus
}

// Menampilkan elemen stack
void printInfo(stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong." << endl;
    } else {
        cout << "Isi stack dari atas ke bawah: ";
        for (int i = S.Top; i >= 0; i--) { // Menampilkan dari Top ke bawah
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}
