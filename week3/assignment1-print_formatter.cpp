#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

string format(int value);
string format(double value);
string format(double value, int precision);
string format(string text);

int main() {
    cout << "Interger formatting:\n";
    cout << "Original: 7013456 \n";
    cout << "Formatted: " << format(7013456) << "\n\n";

    cout << "Double formatting(default 2 decimal places): \n";
    cout << "Original: 23.8896 \n";
    cout << "Formatted: " << format(23.8896) << "\n\n";

    cout << "Double formatting(custom decimal places): \n";
    cout << "Original: 23.8896 with precision 3 \n";
    cout << "Formatted: " << format(23.8896, 3) << " \n\n";

    string text = "hello world of c++ programming";
    cout << "String formatting: \n";
    cout << "Original: 'hello world of c++ programming'\n";
    cout << "Formated: \"" << format(text) << "\"";

    return 0;
}
    string format(int value) {
    string s = to_string(value);
    for(int i = (int)s.length() - 3; i > 0; i -= 3) {
        s.insert (i,",");
        
    }
    return s;
}

    string format(double value) {
        return format(value,2); 
    }

    string format(double value, int precision) {
        stringstream ss;
        ss << fixed << setprecision(precision) << value;
        return ss.str();
    }

    string format(string text) {
    for(int i = 0; i < text.length(); i++)
    if (i == 0 || text[i-1] == ' ') {
        text[i] = toupper(text[i]);
        return text;
    }
}


