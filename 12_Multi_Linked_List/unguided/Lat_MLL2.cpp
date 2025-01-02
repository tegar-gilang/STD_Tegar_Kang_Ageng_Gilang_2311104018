#include <iostream>
#include <string>
using namespace std;

struct Buku {
    string judulBuku;
    string tanggalPengembalian;
};

struct Anggota {
    string namaAnggota;
    string idAnggota;
};

struct ElmBuku {
    Buku info;
    ElmBuku* next;
};

struct ElmAnggota {
    Anggota info;
    ElmBuku* firstBuku;
    ElmAnggota* next;
};

struct List {
    ElmAnggota* first;
};

void createList(List &L) {
    L.first = nullptr;
}

ElmAnggota* allocateAnggota(const Anggota &data) {
    ElmAnggota* P = new ElmAnggota;
    P->info = data;
    P->next = nullptr;
    P->firstBuku = nullptr;
    return P;
}

ElmBuku* allocateBuku(const Buku &data) {
    ElmBuku* P = new ElmBuku;
    P->info = data;
    P->next = nullptr;
    return P;
}

void insertAnggota(List &L, ElmAnggota* P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

void insertBuku(ElmAnggota* anggota, ElmBuku* buku) {
    if (anggota->firstBuku == nullptr) {
        anggota->firstBuku = buku;
    } else {
        ElmBuku* Q = anggota->firstBuku;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = buku;
    }
}

void removeAnggota(List &L, const string &idAnggota) {
    ElmAnggota* P = L.first;
    ElmAnggota* prev = nullptr;

    while (P != nullptr) {
        if (P->info.idAnggota == idAnggota) {
            ElmBuku* buku = P->firstBuku;
            while (buku != nullptr) {
                ElmBuku* temp = buku;
                buku = buku->next;
                delete temp;
            }

            if (prev == nullptr) {
                L.first = P->next;
            } else {
                prev->next = P->next;
            }
            delete P;
            return;
        }
        prev = P;
        P = P->next;
    }
}

void printList(const List &L) {
    ElmAnggota* P = L.first;
    while (P != nullptr) {
        cout << "Anggota: " << P->info.namaAnggota << " (ID: " << P->info.idAnggota << ")\n";
        ElmBuku* Q = P->firstBuku;
        while (Q != nullptr) {
            cout << "  Buku: " << Q->info.judulBuku << ", Pengembalian: " << Q->info.tanggalPengembalian << "\n";
            Q = Q->next;
        }
        cout << endl;
        P = P->next;
    }
}

int main() {
    List L;
    createList(L);

    Anggota a1 = {"Rani", "A001"};
    Anggota a2 = {"Dito", "A002"};
    Anggota a3 = {"Vina", "A003"};

    ElmAnggota* anggota1 = allocateAnggota(a1);
    ElmAnggota* anggota2 = allocateAnggota(a2);
    ElmAnggota* anggota3 = allocateAnggota(a3);

    insertAnggota(L, anggota1);
    insertAnggota(L, anggota2);
    insertAnggota(L, anggota3);

    Buku b1 = {"Pemrograman C++", "01/12/2024"};
    Buku b2 = {"Algoritma Pemrograman", "15/12/2024"};
    Buku b3 = {"Struktur Data", "10/12/2024"};

    insertBuku(anggota1, allocateBuku(b1));
    insertBuku(anggota2, allocateBuku(b2));
    insertBuku(anggota1, allocateBuku(b3));

    removeAnggota(L, "A002");

    printList(L);

    return 0;
}
