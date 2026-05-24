#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Recipe {
    string name;
    vector<string> ingredients;
    vector<string> steps;
};

void addRecipe(vector<Recipe>& collection);
void displayAllRecipes(const vector<Recipe>& collection);
void searchRecipes(const vector<Recipe>& collection);
void removeRecipe(vector<Recipe>& collection);
void showStatistics(const vector<Recipe>& collection);

void addRecipe(vector<Recipe>& collection) {
    Recipe newRecipe;
    int mainIngredients, numberOfSteps;

    cout << "Enter recipe name: ";
    getline(cin, newRecipe.name);
    cout << "How many ingredients? ";
    cin >> mainIngredients;
    cin.ignore();
    for (int i = 0; i < mainIngredients; i++) {
        string ing;
        cout << "Enter ingredient " << i + 1 << ": ";
        getline(cin, ing);
        newRecipe.ingredients.push_back(ing);
    }

    cout << "How many steps? ";
    cin >> numberOfSteps;
    cin.ignore();
    for (int i = 0; i < numberOfSteps; i++) {
        string step;
        cout << "Enter step " << i + 1 << ": ";
        getline(cin, step);
        newRecipe.steps.push_back(step);
    }

    collection.push_back(newRecipe);
    cout << "Recipe added successfully!" << endl;
}

void displayAllRecipes(const vector<Recipe>& collection) {
    if (collection.empty()) {
        cout << "No recipes found in the collection." << endl;
        return;
    }
    for ( size_t i = 0; i < collection.size(); i++) {
        cout << "\n---" << collection[i].name << "---" << endl;
        cout << "Ingredients: " << endl;
        for (const auto& ing : collection[i].ingredients) {
            cout << " - " << ing << endl;
        }
        cout << "Steps: " << endl;
        for (size_t j = 0; j < collection[i].steps.size(); j++) {
            cout << j + 1 << ". " << collection[i].steps[j] << endl;
        }
    }
}
void searchRecipes(const vector<Recipe>& collection) {
    string searchName;
    cout << "Search by name or ingredient: ";
    getline(cin, searchName);
    bool found = false;

    for (const auto& r : collection) {
        bool inIngredients = false;
        for (const auto& ing : r.ingredients) {
            if (ing.find(searchName) != string::npos) {
                inIngredients = true;
                break;
            }
        }

        if (r.name.find(searchName) != string::npos || inIngredients) {
            cout << "Match found: " << r.name << endl;
            found = true;
        }
    }
    if (!found) cout << "No matches found." << endl;
}

void removeRecipe(vector<Recipe>& collection) {
    string name;
    cout << "Enter the exact name of the recipe to remove: ";
    getline(cin, name);

    for (auto it = collection.begin(); it != collection.end(); ++it) {
        if (it->name == name) {
            collection.erase(it);
            cout << "Recipe removed." << endl;
            return;
        }
    }
    cout << "Recipe not found." << endl;
}

void showStatistics(const vector<Recipe>& collection) {
    if (collection.empty()) {
        cout << "No statistics available." << endl;
        return;
    }

    double totalIngredients = 0;
    double totalSteps = 0;
    for (const auto& r : collection) {
        totalIngredients += r.ingredients.size();
        totalSteps += r.steps.size();
    }

    cout << fixed << setprecision(1);
    cout << "Collection Statistics." << endl;
    cout << "Total recipes: " << collection.size() << endl;
    cout << "Average ingredients per recipe: " << totalIngredients / collection.size() << endl;
    cout << "Average steps per recipe: " << totalSteps / collection.size() << endl;
}

int main() {
    vector<Recipe> collection;
    int choice;

    do {
        cout << "\nDYNAMIC RECIPE MANAGER" << endl;
        cout << "------------------------" << endl;
        cout << "1. Add Recipe" << endl;
        cout << "2. Display All Recipes" << endl;
        cout << "3. Search Recipes" << endl;
        cout << "4. Remove Recipes" << endl;
        cout << "5. Show Statistics" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        
        if (!(cin >> choice)) {
            cout << "Error! Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        cin.ignore();

        switch (choice) {
            case 1: addRecipe(collection); break;
            case 2: displayAllRecipes(collection); break;
            case 3: searchRecipes(collection); break;
            case 4: removeRecipe(collection); break;
            case 5: showStatistics(collection); break;
            case 6: cout << "Exiting..." << endl; break;
            default: cout << "Invalid input." << endl;
        }
    } while (choice != 6);

    return 0;
}

 