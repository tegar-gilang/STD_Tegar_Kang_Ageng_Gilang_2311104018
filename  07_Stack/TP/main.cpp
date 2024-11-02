#include <iostream>
#include <cstring> // Untuk fungsi strlen
#include "stack.h"
#include "stack.cpp" 
using namespace std;

void displayStackOutput(stack &S, const char* elements, int popCount) {
    createStack(S);

    int length = strlen(elements); // Menggunakan strlen untuk mendapatkan panjang elemen

    // Memasukkan elemen ke dalam stack secara terbalik
    for (int i = length - 1; i >= 0; i--) {
        push(S, elements[i]);
    }

    cout << "Isi stack awal:\n";
    printInfo(S);

    // Melakukan operasi pop sesuai dengan jumlah yang ditentukan
    for (int i = 0; i < popCount; i++) {
        pop(S);
    }

    cout << "Isi stack setelah beberapa kali pop:\n";
    printInfo(S);
}

int main() {
    stack S;
    int lastDigit;

    cout << "Masukkan digit terakhir NIM: ";
    cin >> lastDigit;

    cout << "Digit terakhir NIM MOD 4 sisa " << (lastDigit % 4) << ":\n";

    // Menentukan elemen untuk dimasukkan ke stack berdasarkan hasil modulus
    switch (lastDigit % 4) {
        case 0:
            displayStackOutput(S, "IFLABJAYA", 5);
            break;
        case 1:
            displayStackOutput(S, "HALOBANDUNG", 4);
            break;
        case 2:
            displayStackOutput(S, "PERCAYADIRI", 7);
            break;
        case 3:
            displayStackOutput(S, "STRUKTURDATA", 8);
            break;
        default:
            cout << "Input tidak valid" << endl;
    }

    return 0;
}
