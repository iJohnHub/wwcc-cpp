/*
 * Interactive Story Game - Prisoner's Break
 * Author: - Josiah Aguilera
 * Submission Date: - 6/12/2026
 * 
 *  === Project Features ===
 * Variables (3+ types): Lines 34-38
 * If/else: Lines 77-86
 * Loops: Lines 51-161
 * Switch: Lines 52-160
 * Functions w/ return value: Line 168-169
 * Void functions\: Lines 42, 172
 * Funtions w/ pararmeters: Lines 205-213
 * Vector or array: Lines 41-44
 * Struct or class: Lines 33-38
 * Enum: Lines 31
 * File reading: Lines 192-203
 * File writing: Lines 205-214
 * Moedern feature 1 (auto): Lines 179
 * Modern feature 2 (range-based for): Lines 179
 * =====================================
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <limits>
using namespace std;

enum class GameState { Intro, Scene_start, scene_Hallway, scene_CourtYard, End_win, End_lose };

struct Player {
    string name;
    int health = 100;
    bool hasKey = false;
    double gold = 15.0;
    vector<string> inventory;
};

    bool validateChoice(int choice, int max);
    void displayEnding(const Player& player);
    void loadIntro();
    void saveGameSummary(const Player& p);

    int main() {
        Player player;
        GameState state = GameState::Intro;
        int choice = 0;

        while(state != GameState::End_lose && state != GameState::End_win) {
            switch(state) {
                case GameState::Intro:
                    cout << " Welcome to Prisoner's Break!\n";
                    cout << "Enter your character's name: ";
                    getline(cin, player.name);

                    loadIntro();
                    state = GameState::Scene_start;
                    break;

                    case GameState::Scene_start:
                    cout << "\n--- Scene 1: The Wakeup Call ---\n";
                    cout << "You wake up to only find yourself in a prison cell with no recall of what happened the night before. A sleeping guard sits nearby with a shiny key on his belt.\n";
                    cout << "1. Try to sneakily take the key from the guard.\n";
                    cout << "2. Look around the cell for any useful items.\n";

                    do {
                        cout << "Enter your choice (1 or 2): ";
                        if (!(cin >> choice)) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            choice = -1;
                        }
                    } while (!validateChoice(choice, 2));

                    if (choice == 1) {
                        cout << "\nSuccess! You carefully lift the key without making a sound!\n";
                        player.hasKey = true;
                        player.inventory.push_back("Shiny Key");
                        state = GameState::scene_Hallway;
                    } else {
                        cout << "\nYou find not only an old and hidden iron dagger but also a small pouch of gold inside the wall cavity!\n";
                        player.gold += 10.0;
                        state = GameState::scene_Hallway;
                    }
                    break;

                case GameState::scene_Hallway:
                    cout << "\n--- Scene 2: The Hallway Gate ---\n";
                    cout << "You slip out of your cell into a hallway but find a heavy iron gate blocking the exit.\n"; 

                    if (player.hasKey) {
                        cout << "Your collected 'Shiny Key' unlocks the gate perfectly! You escape into the courtyard. \n";
                        state = GameState::scene_CourtYard;
                    } else {
                        cout << "The gate is locked tight. You look down and notice a riddle carved on the lock stone lock:\n";
                        cout << "\n'What gets bigger the more you take away?'\n";
                        cout << "1. A hole\n";
                        cout << "2. A shadow\n";
                        cout << "3. A secret\n";

                        do {
                            cout << "Enter your choice (1-3): ";
                            if (!(cin >> choice)) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                choice = -1;
                            }
                        } while (!validateChoice(choice, 3));

                        if (choice == 1) {
                            cout << "\nCorrect! The gate clicks open and you quickly run to the courtyard!\n ";
                            state = GameState::scene_CourtYard; 
                        } else {
                            cout << "\nIncorrect! The gate doesn't budge an inch and a volley of arrows rains down from the ceiling!\n";
                            player.health -= 50;
                            if (player.health <= 0) {
                                state = GameState::End_lose;
                            } else {
                                state = GameState::scene_CourtYard;
                            }
                        }
                    }
                    break;

                case GameState::scene_CourtYard:
                    cout << "\n--- Scene 3: The Court Yard ---\n";
                    cout << "Current Health: " << player.health << "%\n";
                    cout << "Gold Collected: " << player.gold << "\n";
                    cout << "You stand in the moonlit courtyard. The final outer wall looms ahead with a guard tower scanning the field.\n";
                    cout << "1. Sprint towards the main gate shadow.\n";
                    cout << "2. Bribe a nearby stable master to hide you in a cart.\n";
                    do {
                        cout << "Enter your choice (1-2): ";
                        if (!(cin >> choice)) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            choice -= 1;
                        }
                    } while (!validateChoice(choice, 2));

                    if (choice == 1) {
                        cout << "\nYou try to run away, but the searchlight catches you. Spotter sound the alarm!";
                        player.health = 0;
                        state = GameState::End_lose;
                    } else {
                        if (player.gold >= 20.0) {
                            cout << "You pay the stable master. He safely smuggles you past the gate checkpoint!\n";
                            state = GameState::End_win;
                        } else {
                            cout << "\n\"You don't have enough coin!\" the stable master yells, alerting the guards!\n";
                            player.health = 0;
                            state = GameState::End_lose;
                        }
                    }
                    break;
                default:
                    break;
            }
        }
        displayEnding(player);
        saveGameSummary(player);

        return 0;
    }

    bool validateChoice(int choice, int max) {
        return choice >= 1 && choice <= max;
    }

    void displayEnding(const Player& player) {
        if (player.health > 0) {
            cout << "\n======================================\n";
            cout << "Congratulations " << player.name << "! You have successfully escaped the prison!\n";
            cout << "Final Health: " << player.health << "%\n";
            cout << "Gold Collected: " << player.gold << "\n";
            cout << "Inventory: ";
            for (const auto& item : player.inventory) {
                cout << "[" << item << "]";
            }
            cout << "\n=======================================\n";
        } else {
            cout << "\n=======================================\n";
           cout << "--- Scene 4: Captivity (LOSS) ---\n";
           cout << "GAME OVER! " << player.name << " was recaptured.\n";
           cout << "==========================================\n";
        }
    }

    void loadIntro() {
        ifstream inFile("story.txt");
        if (!inFile) {
            cout << "\n[Backstory log]: Escaping a max-security sector...\n";
            return;
        }
        string line;
        cout << "\n--- Prolouge Asset stream ---\n";
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    }

    void saveGameSummary(const Player& p) {
        ofstream outFile("game_summary.txt");
        if (outFile.is_open()) {
            outFile << "Player Name: " << p.name << endl;
            outFile << "Survival Status: " << p.health << "\n";
            outFile << "Net Gold: " << p.gold << "\n";
            outFile.close();
            cout << "\nGame summary saved to 'game_summary.txt'.\n";
        }
    }