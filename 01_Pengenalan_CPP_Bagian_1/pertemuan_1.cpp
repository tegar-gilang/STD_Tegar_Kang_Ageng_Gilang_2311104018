#include <iostream>

using namespace std;

int main(){

    // input output
    // cout << " saya lagi belajar c++ nih! "<<endl;

    // cin sama seperti input 
    // int inp;
    // cin >> inp;
    // cout << "nilai = " << inp << endl;
    
    // operator aritmatika
    // float W, X, Y; float Z;
    // X = 7, Y = 3, W = 1;
    // Z = (X + Y) / (Y + W);
    // cout << "Nilai Z = " << Z << endl;

    // if else
    // double tot_pembelian, diskon;
    // cout << "total pembelian Rp  ";
    // cin >> tot_pembelian;
    // diskon = 0;
    // if(tot_pembelian >= 100000)
    //     diskon = 0.05 * tot_pembelian;
    // else
    //     diskon = 0;
    // cout << "besar diskon = Rp " << diskon << endl;

    // DO While
    int i = 1;
    int jum;
    cin >> jum;
    do{
        cout << "Baris ke- " << i + 1 << endl;
        i++;
    }while (i<jum);
        cin.get();
    

return 0;
}
