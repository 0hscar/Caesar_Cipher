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

    cout << "Encrypted message: " << result;

}


int main()
{
    
    while (true) {
        int shift;
        string message;
        cout << "Set cypher shift (negative to decipher)\n";
        cin >> shift;
        cout << "Write message\n";
        cin >> message;

        CaesarCipher(message, shift);


        cout << "\n(a) to run again\n";
        string again;
        cin >> again;

        if (again == "a") {
            continue;
        }
        else {
            break;
        }
    }

    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

