#include <iostream>
#include <iomanip>
using namespace std;

char getLetterGrade(double score) {
    if(score >= 90) return 'A';
    if(score >= 80) return 'B';
    if(score >= 70) return 'C';
    if(score >= 60) return 'D';
    if(score <= 59) return 'F';
}

    const int NUM_QUIZZES = 5;

int main() {
    double sum = 0;
    double scores[NUM_QUIZZES];
    int count[5] = {0 ,0 ,0 ,0 ,0};

    cout << "QUIZ GRADE TRACKER\n";
    cout << "------------------\n";
    for (int i = 0; i < NUM_QUIZZES; i++) {
        cout << "Enter score for Quiz " << (i + 1) << "(0-100): \n";
        cin >> scores[i];
        sum += scores[i];
    }

    double Average = sum / NUM_QUIZZES;
    double highest = scores[0];
    double lowest = scores[0];
    int highestScore = 0;
    int lowestScore = 0;

    cout << "Quiz Results: \n";
    for (int i = 0; i < NUM_QUIZZES; i++) {
        char grade = getLetterGrade(scores[i]);
        cout << "   Quiz " << (i + 1) << ":  " << (int)scores[i] << " (" << grade << ")\n"; 

        if(grade == 'A') count[0]++;
        else if(grade == 'B') count[1]++;
        else if(grade == 'C') count[2]++;
        else if(grade == 'D') count[3]++;
        else if(grade == 'F') count[4]++;

        if(scores[i] > highestScore) {
            highest = scores[i];
            highestScore = i;
        }
        if(scores[i] < lowestScore) {
            lowest = scores[i];
            lowestScore = i;
        }
    }
    cout << fixed << setprecision(1);
    cout << "\nStatistics: \n";
    cout << "   Average score:  " << Average << "\n";
    cout << "   Highest score:  " << highest << "   (Quiz " << highestScore + 1 << ") \n";
    cout << "   Lowest score:   " << lowest << "    (Quiz " << lowestScore + 1 << ") \n";
    cout << "   Overall Grade:  " << getLetterGrade(Average) << "\n\n";

    cout << "Grade Distribution: \n";
    cout << "   A: " << count[0] << "\n";
    cout << "   B: " << count[1] << "\n";
    cout << "   C: " << count[2] << "\n"; 
    cout << "   D: " << count[3] << "\n";
    cout << "   F: " << count[4];

    return 0;
}