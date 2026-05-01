#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
using namespace std;

string noPunct(string s) {
    s.erase(remove_if(s.begin(), s.end(), ::ispunct), s.end());
    return s;
}

int main() {
    string phraseInput;
    cout << "TEXT ANALYZER\n";
    cout << "-------------\n";
    cout << "Enter a sentence or paragraph:\n";
    getline(cin, phraseInput);

    int charCount = phraseInput.length();

    stringstream ss(phraseInput);
    string word;
    string longestword = "";
    int wordCount = 0;
    double totalChar = 0;

    int sentenceCount = 0;
    for(char c : phraseInput) {
        if (c == '.' || c == '?' || c == '!') {
            sentenceCount++;
        }
    }

    while (ss >> word) {
        wordCount++;
        string cleaned = noPunct(word);
        totalChar += cleaned.length();

        if (cleaned.length() > longestword.length()) {
            longestword = cleaned;
        }

    }

    string upperCase = phraseInput;
    string lowerCase = phraseInput;
    for(int i = 0; i < phraseInput.length(); i++) {
        upperCase[i] = toupper(phraseInput[i]);
        lowerCase[i] = tolower(phraseInput[i]);
    }

    cout << "\nAnalysis: \n";
    cout << "   Characters (with spaces): " << charCount;
    cout << "\n   Word Count:               " << wordCount << "\n";
    cout << "   Sentence Count:           " << sentenceCount << "\n";
    cout << "   Longest word:             " << longestword << "\n";
    if (wordCount > 0) {
        double average = (double) totalChar / wordCount;
        cout << fixed << setprecision(1);
        cout << "   Average word length:      " << average << " characters\n";
        }

    cout << "\nUppercase: \n";
    cout << "   " << upperCase << "\n\n";
    cout << "Lowercase: \n";
    cout << "   " << lowerCase;
    
    return 0;
}