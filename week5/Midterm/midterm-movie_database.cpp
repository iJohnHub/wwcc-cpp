#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Movie {  // Defining a struct with 6 members
    string title;
    string director;
    int year;
    double rating;
    string genre;
    bool watched;  // checks to see if the user has seen the movie
};

string stringToLower(string s) {  // Funtion for lowercase words to be acceptable
    for(int i = 0; i < s.length(); i++) {
     s[i] = tolower(s[i]);   
    }
    return s;
}

int main() {
    const int movies_max = 5; // The maximum amount of movies that can be stored
    Movie database[movies_max];  // An array of movie structs
    int choice = 0; // Stores the user's menu selection
    int movieCount = 0; // Keeps track of the stored movies

    do { // Do a loop for the main menu
    
        cout << "\nMOVIE DATABASE COLLECTION: " << endl; // Main menu
        cout << "--------------------------" << endl;
        cout << "1. Add a Movie" << endl;
        cout << "2. Search for a Movie(by Genre) " << endl;
        cout << "3. Filter Movies(by Year) " << endl;
        cout << "4. Display Statistics " << endl;
        cout << "5. Create a watchlist " << endl; 
        cout << "6. Exit " << endl;

        cout << "Enter your choice(1-6): ";
        cin >> choice;


        if(choice == 1) { // Adding a new movie to the array
            if(movieCount < movies_max) { 
                cout << "\nEnter the Movie's title: ";
                getline(cin >> ws, database[movieCount].title); // ws skips the whitespace, getline reads the full title with spaces
                cout << "Enter the Movie's director: ";
                getline(cin, database[movieCount].director);
                cout << "Enter the Movie's year: ";
                cin >> database[movieCount].year;
                cout << "Enter the Movie's rating: ";
                cin >> database[movieCount].rating;
                cin.ignore(); // Clear the newline character left in the buffer by 'cin >>'
                cout << "Enter the Movie's genre: ";
                getline(cin, database[movieCount].genre);

                database[movieCount].watched = false; // New movies added are automatically unwatched
                movieCount++;
                cout << "\nMovie Added!\n";
            } else {
                cout << "Database is full.\n";
            }
    } 

    else if(choice == 2) { // Search for a movie by genre, case insensetive
        string searchGenre;
        cout << "Search by Genre: " << searchGenre;
        cin.ignore();
        getline(cin, searchGenre);

        bool found = false;
        for(int i = 0; i < movieCount; i++) {
            if(stringToLower(database[i].genre) == stringToLower(searchGenre)) {
                cout << "- " << database[i].title << endl;
                found = true; 
            }
        }
        if(!found) {
            cout << "No results found.";
        }
    } 

    else if(choice == 3) { // Filter movies by year(from start to end)
        int startYear, endYear;
        cout << "Enter Start Year: ";
        cin >> startYear;
        cout << "Enter End Year: ";
        cin >> endYear;

        cout << "\nMovies from " << startYear << " to " << endYear << ": \n";
        for(int i = 0; i < movieCount; i++) {
            if(database[i].year >= startYear && database[i].year <= endYear) { // Checks to see if a movie falls within a certain range the user inputs
                cout << "- " << database[i].title << " (" << database[i].year << ")\n";
            }
        }
    }

    else if(choice == 4) { // Displays the calculated average ratings of all movies entered and movie count 
        if(movieCount != 0) {
            double totalRatings = 0.0;
            for(int i = 0; i < movieCount; i++) {
                totalRatings += database[i].rating;
            }
            double average = totalRatings / movieCount;

            cout << fixed << setprecision(1); // Formats the average to the first decimal
            cout << "\nDatabase Statictics: \n";
            cout << "Total Movies stored: " << movieCount << endl;
            cout << "Average Ratings: " << average << " / 10.0" << endl;
            }
            else {
                cout << "\nNo movies in the database to calculate.";
            }
    }

    else if(choice == 5) { // Creates watchlist
            if(movieCount == 0) {
                cout << "\nYour watchlist is empty...\n";
            } else {
                cout << "\nYOUR WATCHLIST: \n";
                bool hasUnwatched = false;

                for(int i = 0; i < movieCount; i++) {
                    if(!database[i].watched) { // Displays the movies as wathced == false
                        cout << "- " << database[i].title << " (" << database[i].year << ") " << endl;
                        hasUnwatched = true;
                    }
                }

                if(!hasUnwatched) { // Displays if all movies entered are marked as 'seen'
                    cout << "\nYour all caught up with your watchlist currently...\n"; 
                } else {
                    cout << "\nWould you like to mark a movie as watched? (y/n) ";
                    char response;
                    cin >> response;
                    if (response == 'Y' || response == 'y') { // Gives the user the option to mark a movie as 'seen'
                        string markedTitle;
                        cout << "Enter the exact movie title: ";
                        cin.ignore();
                        getline(cin, markedTitle);

                        for(int i = 0; i < movieCount; i++){
                            if(database[i].title == markedTitle) { // Search for the movie title to update it as 'seen'
                                database[i].watched = true;
                                cout << markedTitle << " has been marked as 'seen.' " << endl;
                            }
                        }
                    } 
                }
            }
        }

        else if (choice == 6) {   //  Ends the program if the user enters 6
            cout << "Exiting...\n";
        }
        else {
            cout << "\nError! Please enter a number 1 - 6\n"; // Will handle error if the user enters a number outside of 1-6

            if(cin.fail()) {   // Will ingore if the user enters a letter and clear the error
                cin.clear();
                cin.ignore(1000, '\n');
            }
        }
    } while (choice != 6);   // Continues to loop until the user enters 6

    return 0;
}