#include "Author.h"
#include <iostream>

Author::Author(string n, int year) : name(n), birthYear(year) {}
string Author::getName() const { return name; }
int Author::getBirthyear() const { return birthYear; }
void Author::display() const {
    cout << "Author: " << name << " (Born: " << birthYear << ")";
}