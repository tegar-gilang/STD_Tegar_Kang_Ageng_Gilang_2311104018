#include <iostream>
#include "list.h"
#include "list.cpp"

int main() {
    List L;
    createList(L);
    // Input NIM 3 digit terakhir (misalnya: 713)
    cout << "Masukkan 3 digit NIM terakhir secara terbalik (misalnya 713):" << endl;
    // Insert elemen satu per satu di awal (urutan terbalik)
    insertFirst(L, allocate(3));
    insertFirst(L, allocate(1));
    insertFirst(L, allocate(7));
    // Tampilkan isi list (akan terbalik karena insertFirst)
    cout << "Isi list (terbalik): ";
    printInfo(L);
    // Menambahkan elemen menggunakan looping untuk NIM penuh 10 digit
    cout << "\nMasukkan NIM penuh (10 digit) satu per satu:" << endl;
    createList(L);  // Reset list untuk input baru
    for (int i = 1; i <= 10; i++) {
        int digit;
        cout << "Digit " << i << ": ";
        cin >> digit;
        insertLast(L, allocate(digit));
    }
    // Tampilkan isi list (urutan sesuai input karena menggunakan insertLast)
    cout << "Isi list (NIM penuh): ";
    printInfo(L);
    
    return 0;
}
