#include "pelajaran.h"
#include <iostream>
using namespace std;

int main() {
    // Mendefinisikan nama dan kode pelajaran
    string namapel = "Struktur Data";
    string kodepel = "STD";

    // Membuat pelajaran dengan fungsi create_pelajaran
    Pelajaran pel = create_pelajaran(namapel, kodepel);

    // Menampilkan data pelajaran dengan prosedur tampil_pelajaran
    tampil_pelajaran(pel);

    return 0;
}
