#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    // Constructor untuk inisialisasi head dan tail
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Fungsi untuk menambahkan elemen di depan list (push)
    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode; // Jika list kosong, tail juga mengarah ke node baru
        }
        head = newNode;
    }

    // Fungsi untuk menghapus elemen dari depan list (pop)
    void pop() {
        if (head == nullptr) {
            cout << "List is empty, nothing to delete." << endl;
            return; // Jika list kosong
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr; // Jika hanya satu elemen di list
        }
        delete temp; // Hapus elemen
    }

    // Fungsi untuk mengupdate data di list
    bool update(int oldData, int newData) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true; // Jika data ditemukan dan diupdate
            }
            current = current->next;
        }
        return false; // Jika data tidak ditemukan
    }

    // Fungsi untuk menghapus semua elemen di list
    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    // Fungsi untuk menampilkan semua elemen di list
    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    bool done = false;

    while (!done) {
        cout << "\n1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number between 1 and 6." << endl;
            cin.clear();             // Menghapus status error
            cin.ignore(1000, '\n');   // Membersihkan buffer input
            continue;                 // Ulang kembali ke awal loop
        }

        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                if (!(cin >> data)) {
                    cout << "Invalid input. Please enter a valid integer." << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                } else {
                    list.push(data);
                }
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                if (!(cin >> oldData)) {
                    cout << "Invalid input. Please enter a valid integer." << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    break;
                }
                
                cout << "Enter new data: ";
                if (!(cin >> newData)) {
                    cout << "Invalid input. Please enter a valid integer." << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    break;
                }

                if (!list.update(oldData, newData)) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                cout << "All data has been cleared." << endl;
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                done = true; // Set flag done untuk mengakhiri loop
                cout << "Exiting program." << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please select a number between 1 and 6." << endl;
                break;
            }
        }
    }
    return 0;
}
