#include "Library.h"
#include <iostream>
#include <algorithm>
using namespace std;

Library::Library(string n) : name(n) {}
void Library::addBook(const Book& b) { books.push_back(b); }

void Library::displayAll() const {
    cout << "\n---Catalog for " << name << "---\n";
    for (const auto& b : books) b.display();
}

string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

void Library::searchByAuthor(string authorName) const {
    authorName = toLower(authorName);
    for (const auto& b : books) {
        if(toLower(b.getAuthor().getName()).find(authorName) != string::npos)
        b.display();
    }
}

void Library::searchByTitle(string titleKeyword) const {
    titleKeyword = toLower(titleKeyword);
    for (const auto& b : books) {
        if(toLower(b.getTitle()).find(titleKeyword) != string::npos)
        b.display();
    }
}

void Library::showStats() const {
    cout << "\nTotal Books: " << books.size() << endl;
}