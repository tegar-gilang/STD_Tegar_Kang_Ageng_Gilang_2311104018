#include <iostream>
using namespace std;

void tukar (int *a, int *b){
    int temp;
    temp =*a;
    *a = *b;
    *b = temp;
}

int main(){
    int bil1, bil2;
    cout << "Masukkan bilangan pertama = ";
    cin >> bil1;
    cout <<"Masukkan bilangan pada = ";
    cin >> bil2;
    cout << "Sebelum Penukaran = \n";
    cout << "Bil 1 = " << bil1 << " Bil 2 = "<< bil2 << endl;
    tukar(&bil1, &bil2);
    cout <<"Setelah pertukaran\n";
    cout <<"Bil 1 = "<< bil1 << " Bil 2 = " << bil2 << endl;
    return 0;
}