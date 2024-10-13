#include <iostream>
#include <string>

using namespace std;

// Struktur data untuk menyimpan informasi mahasiswa
struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

// Fungsi untuk menghitung nilai akhir
float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

int main() {
    Mahasiswa mahasiswa[10];  // Array untuk menyimpan data maksimal 10 mahasiswa
    int jumlahMahasiswa;

    // Meminta input jumlah mahasiswa
    cout << "Masukkan jumlah mahasiswa (maksimal 10): ";
    cin >> jumlahMahasiswa;

    // Validasi input jumlah mahasiswa
    if (jumlahMahasiswa > 10) {
        cout << "Jumlah mahasiswa tidak boleh lebih dari 10." << endl;
        return 1;
    }

    // Input data mahasiswa
    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Masukkan Nama: ";
        cin.ignore();  // Membersihkan buffer input
        getline(cin, mahasiswa[i].nama);
        cout << "Masukkan NIM: ";
        getline(cin, mahasiswa[i].nim);
        cout << "Masukkan Nilai UTS: ";
        cin >> mahasiswa[i].uts;
        cout << "Masukkan Nilai UAS: ";
        cin >> mahasiswa[i].uas;
        cout << "Masukkan Nilai Tugas: ";
        cin >> mahasiswa[i].tugas;

        // Menghitung nilai akhir menggunakan fungsi hitungNilaiAkhir
        mahasiswa[i].nilaiAkhir = hitungNilaiAkhir(mahasiswa[i].uts, mahasiswa[i].uas, mahasiswa[i].tugas);
    }

    // Menampilkan data mahasiswa
    cout << "\nData Mahasiswa:\n";
    cout << "--------------------------------------------------\n";
    cout << "No\tNama\t\tNIM\t\tNilai Akhir\n";
    cout << "--------------------------------------------------\n";
    
    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << i + 1 << "\t" << mahasiswa[i].nama << "\t\t" << mahasiswa[i].nim << "\t\t" << mahasiswa[i].nilaiAkhir << endl;
    }

    return 0;
}
