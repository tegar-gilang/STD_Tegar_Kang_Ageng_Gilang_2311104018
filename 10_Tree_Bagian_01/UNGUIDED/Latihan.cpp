#include <iostream>
using namespace std;

struct Pohon {
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root;

// Inisialisasi
void init() {
    root = NULL;
}

// Cek Node
bool isEmpty() {
    return root == NULL;
}

// Buat Node Baru
void buatNode(char data) {
    if (isEmpty()) {
        root = new Pohon{data, NULL, NULL, NULL};
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    } else {
        cout << "\nPohon sudah dibuat." << endl;
    }
}

// Tambah Kiri
Pohon *insertLeft(char data, Pohon *node) {
    if (node->left != NULL) {
        cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
        return NULL;
    }
    Pohon *baru = new Pohon{data, NULL, NULL, node};
    node->left = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
    return baru;
}

// Tambah Kanan
Pohon *insertRight(char data, Pohon *node) {
    if (node->right != NULL) {
        cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
        return NULL;
    }
    Pohon *baru = new Pohon{data, NULL, NULL, node};
    node->right = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
    return baru;
}

// Menampilkan child
void showChild(Pohon *node) {
    if (!node) {
        cout << "\nNode tidak ditemukan!" << endl;
        return;
    }
    cout << "\nNode " << node->data << " memiliki:\n";
    cout << " - Left child: " << (node->left ? node->left->data : 'N') << endl;
    cout << " - Right child: " << (node->right ? node->right->data : 'N') << endl;
}

// Menampilkan descendant
void showDescendants(Pohon *node) {
    if (!node) return;
    if (node->left) {
        cout << node->left->data << " ";
        showDescendants(node->left);
    }
    if (node->right) {
        cout << node->right->data << " ";
        showDescendants(node->right);
    }
}

// Menu
void menu() {
    int pilihan;
    char data, parentData;
    Pohon *parentNode = NULL;
    do {
        cout << "\n===== Menu Binary Tree =====\n";
        cout << "1. Buat Root Node\n2. Tambah Kiri\n3. Tambah Kanan\n4. Tampilkan Child\n";
        cout << "5. Tampilkan Descendants\n6. Keluar\nPilih: ";
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                cout << "Masukkan data root: ";
                cin >> data;
                buatNode(data);
                break;
            case 2:
                cout << "Masukkan data parent: ";
                cin >> parentData;
                cout << "Masukkan data anak kiri: ";
                cin >> data;
                parentNode = root; // Cari parentNode di tree jika diperlukan
                if (parentNode)
                    insertLeft(data, parentNode);
                break;
            case 3:
                cout << "Masukkan data parent: ";
                cin >> parentData;
                cout << "Masukkan data anak kanan: ";
                cin >> data;
                parentNode = root; // Cari parentNode di tree jika diperlukan
                if (parentNode)
                    insertRight(data, parentNode);
                break;
            case 4:
                cout << "Masukkan data node: ";
                cin >> data;
                parentNode = root; // Cari parentNode di tree jika diperlukan
                showChild(parentNode);
                break;
            case 5:
                cout << "Masukkan data node: ";
                cin >> data;
                parentNode = root; // Cari parentNode di tree jika diperlukan
                cout << "\nDescendants of " << data << ": ";
                showDescendants(parentNode);
                cout << endl;
                break;
            case 6:
                cout << "Keluar..." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 6);
}

int main() {
    init();
    menu();
    return 0;
}
