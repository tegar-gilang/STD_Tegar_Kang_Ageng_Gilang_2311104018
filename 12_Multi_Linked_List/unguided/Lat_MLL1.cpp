#include <iostream>
#include <string>
using namespace std;


struct Proyek {
    string nama_proyek;
    int durasi; 
};


struct Pegawai {
    string nama_pegawai;
    string id_pegawai;
};


struct ElmProyek {
    Proyek info;
    ElmProyek* next;
};


struct ElmPegawai {
    Pegawai info;
    ElmPegawai* next;
    ElmProyek* firstProyek; 
};


struct List {
    ElmPegawai* first;
};


void createList(List &L) {
    L.first = nullptr;
}


ElmPegawai* allocatePegawai(const Pegawai &data) {
    ElmPegawai* P = new ElmPegawai;
    P->info = data;
    P->next = nullptr;
    P->firstProyek = nullptr;
    return P;
}


ElmProyek* allocateProyek(const Proyek &data) {
    ElmProyek* P = new ElmProyek;
    P->info = data;
    P->next = nullptr;
    return P;
}


void insertPegawai(List &L, ElmPegawai* P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}


void insertProyek(ElmPegawai* pegawai, ElmProyek* proyek) {
    if (pegawai->firstProyek == nullptr) {
        pegawai->firstProyek = proyek;
    } else {
        ElmProyek* Q = pegawai->firstProyek;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = proyek;
    }
}


void removeProyek(ElmPegawai* pegawai, const string &nama_proyek) {
    if (pegawai->firstProyek == nullptr) return;

    ElmProyek* P = pegawai->firstProyek;
    ElmProyek* prev = nullptr;

    while (P != nullptr) {
        if (P->info.nama_proyek == nama_proyek) {
            if (prev == nullptr) {
                pegawai->firstProyek = P->next;
            } else {
                prev->next = P->next;
            }
            delete P;
            cout << "Proyek " << nama_proyek << " berhasil dihapus!\n";
            return;
        }
        prev = P;
        P = P->next;
    }
    cout << "Proyek " << nama_proyek << " tidak ditemukan!\n";
}


void printList(const List &L) {
    ElmPegawai* P = L.first;
    while (P != nullptr) {
        cout << "Pegawai: " << P->info.nama_pegawai << " (ID: " << P->info.id_pegawai << ")\n";
        ElmProyek* Q = P->firstProyek;
        while (Q != nullptr) {
            cout << "  Proyek: " << Q->info.nama_proyek << ", Durasi: " << Q->info.durasi << " bulan\n";
            Q = Q->next;
        }
        cout << endl;
        P = P->next;
    }
}

int main() {
    List L;
    createList(L);

    
    Pegawai p1 = {"Andi", "P001"};
    Pegawai p2 = {"Budi", "P002"};
    Pegawai p3 = {"Citra", "P003"};

    
    ElmPegawai* pegawai1 = allocatePegawai(p1);
    ElmPegawai* pegawai2 = allocatePegawai(p2);
    ElmPegawai* pegawai3 = allocatePegawai(p3);

    insertPegawai(L, pegawai1);
    insertPegawai(L, pegawai2);
    insertPegawai(L, pegawai3);

    
    Proyek proj1 = {"Aplikasi Mobile", 12};
    Proyek proj2 = {"Sistem Akuntansi", 8};
    Proyek proj3 = {"E-commerce", 10};
    Proyek proj4 = {"Analisis Data", 6};

    
    insertProyek(pegawai1, allocateProyek(proj1)); 
    insertProyek(pegawai2, allocateProyek(proj2)); 
    insertProyek(pegawai3, allocateProyek(proj3)); 
    insertProyek(pegawai1, allocateProyek(proj4)); 

    removeProyek(pegawai1, "Aplikasi Mobile");

    cout << "Data Pegawai dan Proyek:\n";
    printList(L);

    return 0;
}
