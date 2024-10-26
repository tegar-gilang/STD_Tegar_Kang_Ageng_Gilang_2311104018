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

// Fungsi untuk mengurutkan elemen-elemen dalam list menggunakan Bubble Sort
void bubbleSortList2311104018(List &L) {
    if (L.head == NULL) return;  // Jika list kosong, tidak perlu diurutkan

    bool swapped;
    do {
        swapped = false;
        Elemen* current = L.head;

        // Melakukan iterasi pada list
        while (current->next != NULL) {
            if (current->data > current->next->data) {
                // Pertukaran nilai data (bukan pointer)
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                
                swapped = true;  // Menandakan bahwa ada pertukaran
            }
            current = current->next;
        }
    } while (swapped);  // Ulangi hingga tidak ada pertukaran
}

int main() {
    List L;
    createList2311104018(L);

    // Meminta pengguna untuk memasukkan 5 elemen integer
    cout << "Masukkan 5 elemen integer ke dalam list:" << endl;
    for (int j = 0; j < 5; j++) {
        int value;
        cout << "Masukkan elemen ke-" << j + 1 << ": ";
        cin >> value;
        Elemen* newElemen = alokasi2311104018(value);
        insertFirst2311104018(L, newElemen);
    }

    // Menampilkan isi list sebelum diurutkan
    cout << "Isi list sebelum diurutkan:" << endl;
    printInfo2311104018(L);

    // Mengurutkan list menggunakan Bubble Sort
    bubbleSortList2311104018(L);

    // Menampilkan isi list setelah diurutkan
    cout << "Isi list setelah diurutkan (ascending):" << endl;
    printInfo2311104018(L);

    return 0;
}
