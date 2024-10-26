#include <iostream>
using namespace std;

// definisi pointer ke elemen
struct Elemen
{
    int data;
    Elemen *next;
};

// definisi tipe data untuk list
struct List
{
    Elemen *first;
};

// buat list kosong
void createList(List &L)
{
    L.first = NULL;
}

// fungsi alokasi elemen baru
Elemen *alokasi(int x)
{
    Elemen *p = new Elemen;
    if (p != NULL)
    {
        p->data = x;
        p->next = NULL;
    }
    return p;
}

// tambah elemen di depan
void insertFirst(List &L, Elemen *P)
{
    P->next = L.first;
    L.first = P;
}

// tambah elemen di akhir
void insertLast(List &L, Elemen *P)
{
    if (L.first == NULL)
    {
        L.first = P;
    }
    else
    {
        Elemen *p = L.first;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = P;
    }
}

// hapus elemen pertama
void deleteFirst(List &L)
{
    if (L.first != NULL)
    {
        Elemen *p = L.first;
        L.first = L.first->next;
        delete p;
    }
}

// cetak semua elemen dan jumlah elemen
void printInfo(List L)
{
    Elemen *p = L.first;
    int count = 0;
    cout << "Elemen dalam list: ";
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
        count++;
    }
    cout << "\nJumlah elemen: " << count << endl;
}

// cari elemen x
Elemen *findElm(List L, int x)
{
    Elemen *p = L.first;
    while (p != NULL)
    {
        if (p->data == x)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

// fungsi hitung total nilai semua elemen
int hitungTotal(List L)
{
    Elemen *p = L.first;
    int total = 0;
    while (p != NULL)
    {
        total += p->data;
        p = p->next;
    }
    return total;
}

int main()
{
    List L;
    createList(L);

    insertFirst(L, alokasi(5));
    insertFirst(L, alokasi(10));
    insertLast(L, alokasi(20));
    insertLast(L, alokasi(25));
    
    printInfo(L);

    cout << "Total nilai elemen: " << hitungTotal(L) << endl;

    int cari = 10;
    Elemen *found = findElm(L, cari);
    if (found != NULL)
    {
        cout << "Elemen " << cari << " ditemukan di alamat: " << found << endl;
    }
    else
    {
        cout << "Elemen " << cari << " tidak ditemukan." << endl;
    }

    deleteFirst(L);
    printInfo(L);

    return 0;
}
