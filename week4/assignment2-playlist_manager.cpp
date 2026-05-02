#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Artist {
    string name;
    string hometown;
};

struct Song {
    string songname;
    string genre;
    Artist artist;
    int songtimeSec;
};

string tolower(string s) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}

string formatDuration(int seconds) {
    int minutes = seconds / 60;
    int timeSeconds = seconds % 60;
    return to_string(minutes) + ":" + (timeSeconds < 10 ? "0" : "") + to_string(timeSeconds);
}

int main() {
    const int songSize = 5;
    Song playlist[songSize];
    int totaltime = 0;

    cout << "PERSONAL PLAYLIST MANAGER\n";
    cout << "-------------------------";
    for(int i = 0; i < songSize; i++) {
        cout << "\nEnter information for Song " << i + 1 << ":";
        cout << "\n Title: ";
        getline(cin >> ws, playlist[i].songname);
        cout << " Artist name: ";
        getline(cin, playlist[i].artist.name);
        cout << " Artist hometown: ";
        getline(cin, playlist[i].artist.hometown);
        cout << " Genre: ";
        getline(cin, playlist[i].genre);
        cout << " Duration(seconds): ";
        cin >> playlist[i].songtimeSec;

        totaltime += playlist[i].songtimeSec;
    }

    cout << "YOUR PLAYLIST: \n";
    cout << "-------------\n";
    for (int i = 0; i < songSize; i++) {
        cout << i + 1 << "." << playlist[i].songname << endl;
        cout << "   Artist: " << playlist[i].artist.name << " (" << playlist[i].artist.hometown << ") \n";
        cout << "   Genre: " << playlist[i].genre << endl;
        cout << "   Duration: " << formatDuration(playlist[i].songtimeSec) << "\n\n";
    }

    cout << "\nPlaylist stats: " << endl;

    Song longest = playlist[0];
    for(int i = 0; i < songSize; i++) {
        if(playlist[i].songtimeSec > longest.songtimeSec) {
            longest = playlist[i];
        }
    }

    cout << "   Total Runtime: " << formatDuration(totaltime) << endl;
    cout << "   Longest Song:  " << longest.songname << " (" << formatDuration(longest.songtimeSec) << ") " << endl;  
    
    string searchArtist;
    bool ifArtist = false;
    cout << "\nSearch by artist: ";
    getline(cin >> ws, searchArtist);

    cout << "Song by " << searchArtist << ":" << endl;
    for(int i = 0; i < songSize; i++) {
        if(tolower(playlist[i].artist.name) == tolower(searchArtist)) {
            cout << "- " << playlist[i].songname << " (" << formatDuration(playlist[i].songtimeSec) << ")\n";
            ifArtist = true;
        }
    }
    if(!ifArtist) {
        cout << "No Results" << endl;
    }

    string searchGenre;
    bool ifGenre = false;
    cout << "\nSearch by genre: " << searchGenre;
    getline(cin >> ws, searchGenre);

    cout << "Songs in genre: " << searchGenre << endl;
    for(int i = 0; i < songSize; i++) {
        if(tolower(playlist[i].genre) == tolower(searchGenre)) {
            cout << "- " << playlist[i].songname << " (" << formatDuration(playlist[i].songtimeSec) << ") " << endl;
            ifGenre = true;
        }
    }
    if(!ifGenre) {
        cout << "No Results." << endl;
    }
    return 0;
}