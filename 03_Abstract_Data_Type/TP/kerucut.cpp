#include <iostream>
#include <cmath>

using namespace std;

class Kerucut {
private:
    double radius;
    double tinggi;

public:
    // Konstruktor untuk membuat kerucut dengan radius dan tinggi tertentu
    Kerucut(double r, double t) {
        radius = r;
        tinggi = t;
    }

    // Fungsi untuk menghitung volume kerucut
    double volume() {
        return (1.0 / 3) * M_PI * radius * radius * tinggi;
    }

    // Fungsi untuk menghitung luas permukaan kerucut
    double luasPermukaan() {
        double s = sqrt((radius * radius) + (tinggi * tinggi));  // Garis pelukis
        return M_PI * radius * (radius + s);
    }

    // Fungsi untuk menampilkan informasi kerucut
    void tampilkanInfo() {
        cout << "Kerucut dengan radius: " << radius << " dan tinggi: " << tinggi << endl;
        cout << "Volume kerucut: " << volume() << endl;
        cout << "Luas permukaan kerucut: " << luasPermukaan() << endl;
    }
};

int main() {
    // Membuat kerucut dengan radius 3 dan tinggi 4
    Kerucut k(3, 4);

    // Menampilkan informasi kerucut
    k.tampilkanInfo();

    return 0;
}
