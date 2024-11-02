#include <iostream>
#include <string>
#include <algorithm>

bool isPalindrome(const std::string &text) {
    std::string reversedText = text;
    std::reverse(reversedText.begin(), reversedText.end());
    return text == reversedText;
}

int main() {
    std::string text;
    std::cout << "Masukkan kata: ";
    std::cin >> text;

    if (isPalindrome(text)) {
        std::cout << "Kata tersebut adalah palindrom." << std::endl;
    } else {
        std::cout << "Kata tersebut bukan palindrom." << std::endl;
    }

    return 0;
}

