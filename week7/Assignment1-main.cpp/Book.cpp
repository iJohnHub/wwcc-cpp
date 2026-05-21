#include "Book.h"
#include <iostream>
using namespace std;

Book::Book(string t, int year, string i, Author a)
    : title(t), publicationYear(year), isbn(i), author(a) {}

string Book::getTitle() const { return title; }
int Book::getPublicationYear() const { return publicationYear; }
string Book::getIsbn() const { return isbn; }
Author Book::getAuthor() const { return author; }

void Book::setPublicationYear(int year) {
    if (year > 0) publicationYear = year;
}

void Book::display() const {
    cout << "Title: " << title << " | Year: " << publicationYear
         << " | Isbn: " << isbn << "| ";
    author.display();
    cout << endl;
}
