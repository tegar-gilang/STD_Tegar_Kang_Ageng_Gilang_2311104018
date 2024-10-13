#include <iostream>

using namespace std;

// Fungsi untuk menampilkan isi array 2D
void tampilkanArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Fungsi untuk menukarkan isi array pada posisi tertentu
void tukarElemenArray(int arr1[3][3], int arr2[3][3], int row, int col) {
    int temp = arr1[row][col];
    arr1[row][col] = arr2[row][col];
    arr2[row][col] = temp;
}

// Fungsi untuk menukarkan nilai yang ditunjuk oleh dua pointer
void tukarIsiPointer(int* ptr1, int* ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    // Deklarasi dua array 2D integer berukuran 3x3
    int array1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int array2[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    // Menampilkan isi kedua array sebelum penukaran
    cout << "Array 1 sebelum penukaran:" << endl;
    tampilkanArray(array1);

    cout << "Array 2 sebelum penukaran:" << endl;
    tampilkanArray(array2);

    // Menukar elemen pada posisi (1, 1)
    tukarElemenArray(array1, array2, 1, 1);

    // Menampilkan isi kedua array setelah penukaran
    cout << "Array 1 setelah penukaran elemen pada posisi (1, 1):" << endl;
    tampilkanArray(array1);

    cout << "Array 2 setelah penukaran elemen pada posisi (1, 1):" << endl;
    tampilkanArray(array2);

    // Deklarasi dua buah pointer integer
    int* ptr1 = &array1[0][0];  // Menunjuk ke elemen pertama array1
    int* ptr2 = &array2[2][2];  // Menunjuk ke elemen terakhir array2

    cout << "Nilai sebelum penukaran dengan pointer:" << endl;
    cout << "Pointer 1 menunjuk nilai: " << *ptr1 << endl;
    cout << "Pointer 2 menunjuk nilai: " << *ptr2 << endl;

    // Menukar isi variabel yang ditunjuk oleh pointer
    tukarIsiPointer(ptr1, ptr2);

    cout << "Nilai setelah penukaran dengan pointer:" << endl;
    cout << "Pointer 1 menunjuk nilai: " << *ptr1 << endl;
    cout << "Pointer 2 menunjuk nilai: " << *ptr2 << endl;

    return 0;
}
