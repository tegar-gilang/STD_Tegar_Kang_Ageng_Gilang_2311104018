#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string NIM;
    string nama;   // Tambahkan atribut nama
    Mahasiswa* next;
};

struct List {
    Mahasiswa* head;
};

void createList(List &L) {
    L.head = NULL;
}

// Fungsi untuk mengalokasikan data mahasiswa baru
Mahasiswa* alokasi(string nim, string nama) {
    Mahasiswa* newMhs = new Mahasiswa;
    newMhs->NIM = nim;
    newMhs->nama = nama;  // Simpan nama mahasiswa
    newMhs->next = NULL;
    return newMhs;
}

// Fungsi untuk menambahkan mahasiswa ke dalam list
void insertFirst(List &L, Mahasiswa* M) {
    M->next = L.head;
    L.head = M;
}

// Fungsi untuk mencari mahasiswa berdasarkan NIM
Mahasiswa* cariMahasiswa(List L, string nim) {
    Mahasiswa* current = L.head;
    while (current != NULL) {
        if (current->NIM == nim) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int main() {
    List L;
    createList(L);

    int pilihan;
    do {
        cout << "Menu:\n";
        cout << "1. Tambah Mahasiswa\n";
        cout << "2. Cari Mahasiswa\n";
        cout << "3. Keluar\n";
        cout << "Pilih: ";
        
        // Validasi input menu agar tidak terjadi infinite loop jika input tidak valid
        while (!(cin >> pilihan) || (pilihan < 1 || pilihan > 3)) {
            cout << "Input tidak valid. Masukkan pilihan yang benar (1-3): ";
            cin.clear();         // Menghapus flag error di cin
            cin.ignore(1000, '\n'); // Membersihkan input buffer
        }
        cin.ignore(); // Mengabaikan newline setelah pilihan agar tidak mengganggu getline

        if (pilihan == 1) {
            string nim, nama;
            cout << "Masukkan NIM: ";
            getline(cin, nim);  // Membaca NIM
            cout << "Masukkan Nama: ";
            getline(cin, nama);  // Membaca nama

            Mahasiswa* M = alokasi(nim, nama);
            insertFirst(L, M);

            cout << "Mahasiswa dengan NIM " << nim << " dan Nama " << nama << " berhasil ditambahkan.\n";
        } else if (pilihan == 2) {
            string nim;
            cout << "Masukkan NIM yang ingin dicari: ";
            getline(cin, nim);

            Mahasiswa* found = cariMahasiswa(L, nim);
            if (found != NULL) {
                cout << "Mahasiswa ditemukan: NIM: " << found->NIM << ", Nama: " << found->nama << endl;
            } else {
                cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan.\n";
            }
        } else if (pilihan != 3) {
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 3);

    cout << "Program selesai.\n";
    return 0;
}
