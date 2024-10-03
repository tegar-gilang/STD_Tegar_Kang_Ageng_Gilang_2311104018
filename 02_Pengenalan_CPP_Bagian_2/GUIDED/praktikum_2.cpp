#include <iostream>
#define MAX 5

using namespace std;

int main(){
    int x,y;
    int *px;

    x = 87;
    px = &x;
    y = *px;

    cout << "Alamat x = " << &x <<endl;
    cout << "Isi px = " << px <<endl;
    cout << "Isi x = " << x <<endl;
    cout << "Nilai yang ditunjuk px = " << *px <<endl;
    cout << "Alamat y = " << y <<endl;
    cin.get();
    return 0;
}

// POINTER_ARRAY
int main(){
    int i,j;
    float nilai_total, rata_rata;
    float nilai[MAX];
    static int nilai_tahun[MAX] [MAX] =
    {
        {0,2,2,0,0},
        {0,1,1,1,0},
        {0,3,3,3,0},
        {4,4,0,0,4},
        {5,0,0,0,5}
    };

// INISIALISASI ARRAY 2D
    for ( i = 0; i < MAX; i++)
    {
        cout << "Masukan Nilai ke- " << i + 1 << endl;
        cin >> nilai[i];
    }
    cout << "\n data nilai siswa : \n";

// OUTPUT ARRAY 1D
    for ( i = 0; i < MAX; i++)
    {
        cout << "Nilai k- "<< i+1 << "= " << nilai[i] <<endl;
        cout << "\n Nilai Tahunan : \n" <<endl;
    }
    
// ARRAY 2D
    for ( i = 0; i < MAX; i++)
    {
        for ( j = 0; j < MAX; j++)
        {
            cout << nilai_tahun [i] [j] << " ";
            cout << "\n";
        }
        
    }
    cin.get();
    return 0;
}

// STRING
int main(){
    int x,y,z;
    cout << "Masukan Nilai Bilangan 1 = ";
    cin >> x;
    cout << "Masukan Nilai Bilangan 2 = ";
    cin >> y;
    cout << "Masukan Nilai Bilangan 3 = ";
    cin >> z;
    cout << "Nilai Maximum = " << maks3(x,y,z);
    cin.get();
    return 0;
}
// FUNGSI
int maks3(int a, int b, int c){
    int temp_max = a;
    if(b > temp_max)
    temp_max = b;
    if (c > temp_max)
    temp_max = c;
    return (temp_max);
}