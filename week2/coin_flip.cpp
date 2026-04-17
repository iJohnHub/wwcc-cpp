#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    int flips;
    int heads = 0;
    int tails = 0;

    cout << "Coin Flip Simulator" << endl;
    cout << "How many flips would you like to simulate? ";
    cin >> flips;

    cout << "Stimulating " << flips << " coin flips...\n" << endl;

    for (int i = 0; i < flips; i++) {
    if (rand() % 2 == 0) {
        heads++;
    } else {
        tails++;
    }
}

    double percentheads = (heads * 100.0) / flips;
    double percenttails = (tails * 100.0) / flips;


    cout << "Results:  " << endl; 
    printf("Heads: %d (%.2f%%)\n", heads, percentheads);
    printf("Tails: %d (%.2f%%)\n", tails, percenttails);

    return 0;
}