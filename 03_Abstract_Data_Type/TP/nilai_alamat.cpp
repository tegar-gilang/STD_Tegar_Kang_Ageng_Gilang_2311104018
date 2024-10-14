#include <iostream>
using namespace std;

int main() {
    int x = 100;
    int* ptr = &x;  // Pointer ptr menyimpan alamat variabel x
    
    // Menampilkan alamat memori
    cout << "Alamat memori x: " << ptr << endl;
    
    // Menampilkan nilai yang disimpan di alamat tersebut
    cout << "Nilai yang disimpan di alamat: " << *ptr << endl;
    
    return 0;
}
