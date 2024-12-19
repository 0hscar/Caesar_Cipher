// Caesar_Cipher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>

using namespace std;
string alphabetEnglish = "abcdefghijklmnopqrstuvwxyz";

void stringToLower(string& txt) {
    std::transform(txt.begin(), txt.end(), txt.begin(), [](unsigned char c) {return std::tolower(c);});
}

void CaesarCipher(string message, int shift) {
    
    string result;
    stringToLower(message);

    for (char letter : message) {
        if (alphabetEnglish.find(letter)) {
            int index = alphabetEnglish.find(letter);

            index = (index + shift) % alphabetEnglish.length();

            if (index < 0) {
                index = index + alphabetEnglish.length();
            }
            result += alphabetEnglish[index];
        }
        else {
            result += letter;
        }
        
    };

    cout << result;

}


int main()
{
    int shift;
    string message;
    cout << "Set cypher shift (negative to decipher)\n";
    cin >> shift;
    cout << "Write message\n";
    cin >> message;

    CaesarCipher(message, shift);
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
