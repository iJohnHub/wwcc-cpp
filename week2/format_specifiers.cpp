#include <iostream>
#include <cstdio> 
using namespace std;

int main() {
    int interger_value = 42;
    float float_value = 3.14159265f;
    double double_value = 3.14159265;
    char char_value = 'X';
    const char* string_value = "Hello, World!";

    printf("Format Specifier Practice\n");
    printf("------------------------\n\n");

    printf("Interger formats:\n"); 
    printf("Decimal: %d\n", interger_value); // %d used for standard decimal interger
    printf("Hexadecimal: 0x%x\n", interger_value); // %x used for lowercase hexadecimal
    printf("With width(5): |%5d|\n", interger_value); // %5d used for minimal field width
    printf("Left-aligned:  |%-5d|\n\n"); // %-5d used for left-aligns in the width field

    printf("Float formats:\n");
    printf("Default: %f\n", float_value); // %f used for decimal floating point
    printf("with precision (2): %.2f\n", float_value); // %.2f used to round to two decimal places
    printf("Scientific: %e\n", float_value); // %e used for scientific notation
    printf("Fixed with precesion (4): %.4f\n\n", double_value); //  Used for double precision

    printf("Character and String formats: \n");
    printf("Character: %c\n", char_value); // %c used for single character
    printf("String: %s\n", string_value); // %s used for sting of characters
    printf("String with width (20): |%20s|\n", string_value); // %20s used to right-aligned a string of characters for 20 spaces

    return 0;

}