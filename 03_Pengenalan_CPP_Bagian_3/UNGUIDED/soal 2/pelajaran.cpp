#include "pelajaran.h"
#include <iostream>

// Implementasi fungsi untuk membuat pelajaran
Pelajaran create_pelajaran(string namapel, string kodepel) {
    Pelajaran pel;
    pel.namaMapel = namapel;
    pel.kodeMapel = kodepel;
    return pel;
}

// Implementasi prosedur untuk menampilkan pelajaran
void tampil_pelajaran(Pelajaran pel) {
    cout << "Nama Mata Pelajaran: " << pel.namaMapel << endl;
    cout << "Kode Mata Pelajaran: " << pel.kodeMapel << endl;
}
