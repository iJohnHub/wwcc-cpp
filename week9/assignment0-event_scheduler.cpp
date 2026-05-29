#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <iomanip>
using namespace std;

enum class EventCategory { CONCERT, CONFERENCE, SPORTS, WORKSHOP };

struct Event {
    string name;
    string date;          // format: "YYYY-MM-DD"
    EventCategory category;
    int attendees;
    double ticketPrice;
};

// Returns the display name for a category
string categoryName(EventCategory cat) {
    switch (cat) {
        // BUG: The return values for CONCERT and WORKSHOP were swapped.
        // FIX: Swapped the return values to match the correct categories.
        case EventCategory::CONCERT:    return "Concert";   // Bug 5
        case EventCategory::CONFERENCE: return "Conference";
        case EventCategory::SPORTS:     return "Sports";
        case EventCategory::WORKSHOP:   return "Workshop";    // Bug 5
        default:                        return "Unknown";
    }
}

// Display a single event
void printEvent(const Event& e) {
    cout << left << setw(30) << e.name
         << setw(12) << e.date
         << setw(12) << categoryName(e.category)
         << "Attendees: " << setw(5) << e.attendees
         << " Price: $" << fixed << setprecision(2) << e.ticketPrice
         << "\n";
}

// Display all events
void displayAll(const vector<Event>& events) {
    cout << "\n=== All Events ===\n";
    cout << left << setw(30) << "Name" << setw(12) << "Date"
         << setw(12) << "Category" << "\n";
    cout << string(70, '-') << "\n";
    for (const auto& e : events) {
        printEvent(e);
    }
}

// Calculate total revenue across all events
double totalRevenue(const vector<Event>& events) {
    return accumulate(events.begin(), events.end(), 0.0,
        [](double sum, const Event& e) {
            // BUG: The calculation was missing the multiplication by ticketPrice.
            // FIX: Multiplied attendees by ticketPrice to get the correct revenue for each event.
            return sum + (e.attendees * e.ticketPrice);   // Bug 1: missing * e.ticketPrice
        });
}

// Calculate average ticket price across all events
double averageTicketPrice(const vector<Event>& events) {
    // BUG: The total was declared as int, which causes truncation of the fractional part.
    // FIX: Changed the type of total to double and removed the explicit int cast on size.
    double total = 0.0;                      // Bug 2: should be double
    for (const auto& e : events) {
        total += e.ticketPrice;         // Bug 2: fractional part truncated
    }
    return total / (double)events.size(); // Bug 2: integer division
}

// Sort events by date, oldest first
void sortByDateAscending(vector<Event>& events) {
    sort(events.begin(), events.end(),
        [](const Event& a, const Event& b) {
            // BUG: Using > operator sorts in descending order, but we want ascending.
            // FIX: Changed > to < to sort in ascending order.
            return a.date < b.date;     // Bug 3: > sorts descending, not ascending
        });
}

// Search for events whose name contains the search term (case-sensitive)
void searchByName(const vector<Event>& events, const string& term) {
    cout << "\n=== Search Results for \"" << term << "\" ===\n";
    // BUG: find_if algorithm was used, which only finds the first match. We need to check all events for matches.
    // FIX: Replaced find_if with the starndard loop to check each event for the search term and print all matches.
    bool found = false;
    for (const auto& e : events) {
        if (e.name.find(term) != string::npos) {
            printEvent(e);
            found = true;
        }
    }
    if (!found) {
        cout << "No events found.\n";
    }
}

void sortByAttendees(vector<Event>& events) {
    sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
        return a.attendees > b.attendees;
    });
    cout << "\n=== Events sorted by attendees ===\n";
    for (const auto& e : events) {
        printEvent(e);
    }
}

void filterByCategory(const vector<Event>& events, EventCategory cat) {
    cout << "\n=== " << categoryName(cat) << " Events ===\n";
    vector<Event> filtered;

    copy_if (events.begin(), events.end(), back_inserter(filtered), [cat](const Event& e) {
        return e.category == cat;
    });
    for (const auto& e : filtered) {
        printEvent(e);
    }
}

void exportUpcomingEvents(const vector<Event>& events, const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error opening file for writing: " << filename << "\n";
        return;
    }

    for (const auto& e : events) {
        if (e.date >= "2025-06-01") {
            outFile << e.name << " | " 
                    << e.date << " | "
                    << categoryName(e.category) << " | "
                    << e.attendees << " | $"
                    << fixed << setprecision(2) << e.ticketPrice << "\n";
        }
    }
    outFile.close();
    cout << "Upcoming events exported to " << filename << "\n";
}

int main() {
    vector<Event> events = {
        {"Spring Music Fest",     "2025-04-12", EventCategory::CONCERT,    1200, 45.50},
        {"Tech Summit 2025",      "2025-06-20", EventCategory::CONFERENCE,  350, 129.00},
        {"City 5K Run",           "2025-05-03", EventCategory::SPORTS,      800, 25.25},
        {"Watercolor Workshop",   "2025-07-15", EventCategory::WORKSHOP,     40, 60.00},
        {"Jazz Under the Stars",  "2025-08-02", EventCategory::CONCERT,     600, 35.75},
        {"Leadership Workshop",   "2025-06-28", EventCategory::WORKSHOP,     75, 89.00},
        {"Regional Soccer Cup",   "2025-09-14", EventCategory::SPORTS,     2500, 18.00},
        {"Dev Conf Northwest",    "2025-10-05", EventCategory::CONFERENCE,   420, 199.00},
    };

    cout << "=== Community Event Scheduler ===\n";

    displayAll(events);

    cout << "\nTotal revenue (all events): $"
         << fixed << setprecision(2) << totalRevenue(events) << "\n";

    cout << "Average ticket price: $"
         << fixed << setprecision(2) << averageTicketPrice(events) << "\n";

    sortByDateAscending(events);
    cout << "\n=== Events sorted by date (oldest first) ===\n";
    for (const auto& e : events) {
        printEvent(e);
    }

    searchByName(events, "Workshop");
    sortByAttendees(events);
    filterByCategory(events, EventCategory::CONCERT);
    exportUpcomingEvents(events, "upcoming_events.txt");

    return 0;
}