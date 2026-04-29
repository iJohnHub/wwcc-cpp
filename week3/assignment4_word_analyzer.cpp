#include <iostream>
#include <string>
using namespace std;

int countVowels(string word) {
    int count = 0;
    for(int i = 0; i < word.length(); i++) {
        char c = (word[i]);
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        count++;
    }
    return count;
}

int countConstants(string word) {
    int count = 0;
    for(int i = 0; i < word.length(); i++) {
        char c = (word[i]);
        if(!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'))
        count++;
    }
    return count;
}

char firstLetter(string word) {
    if(word.length() == 0) {
        return ' ';
    } else {
        return word[0];
    }
}

string reverse(string word) {
    return string(word.rbegin(), word.rend());
}

bool isPalindrome(string word) {
    int n = word.length();
    for( int i = 0; i <= n / 2; i++) {
        if(word[i] != word[n-1-i])
        return false;
    }
    return true;
} 


int main () {
    char repeat;
    do {
        string word;
        cout << "\nEnter a word: ";
        cin >> word;

        cout << "\n\nWord Analysis: \n";
        cout << "-------------\n";
        cout << "Original word: " << word << "\n";
        cout << "Number of Vowels: " << countVowels(word) << "\n";
        cout << "Number of Constants: " << countConstants(word) << "\n";
        cout << "First letter: " << firstLetter(word) << "\n";
        cout << "Reversed: " << reverse(word) << "\n";

        if(isPalindrome(word)) {
            cout << "Is Palindrome: Yes\n\n";
        } else {
            cout << "Is Palindrome: No\n\n";
        }

        cout << "Would you like to analyze another word? (y/n): ";
        cin >> repeat;
    } while (repeat == 'y' || repeat =='Y');

    return 0;
}