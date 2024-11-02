#include <iostream>
#include <stack>
#include <sstream>
#include <string>

int main() {
    std::stack<std::string> kataStack;
    std::string kalimat;

    // Meminta input kalimat dari pengguna
    std::cout << "Masukkan kalimat (minimal 3 kata): ";
    std::getline(std::cin, kalimat);

    // Menggunakan stringstream untuk memisahkan kata-kata
    std::stringstream ss(kalimat);
    std::string kata;
    
    // Memasukkan setiap kata ke dalam stack
    while (ss >> kata) {
        kataStack.push(kata);
    }

    // Menampilkan hasil pembalikan
    std::cout << "Datastack Array :" << std::endl;
    std::cout << "Data : ";
    while (!kataStack.empty()) {
        std::cout << kataStack.top() << " ";
        kataStack.pop();
    }
    std::cout << std::endl;

    return 0;
}
