#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

// Struct definition
struct TypeSpeedLeader {
    int rank;
    string racer;
    double text_bests;
    int races;
    int texts;
    double career;
    double best_10;
    double best_race;
    double points;
    int wins;
    double win_percent;
    int marathon;
    string last_race;
    double variation;
};

// Helper function to safely analyze numbers
int safe_stoi(const string& s) {
    try {
        return stoi(s);
    }
    catch (...) {
        return 0;
    }
}

double safe_stod(const string& s) {
    try {
        return stod(s);
    }
    catch (...) {
        return 0.0;
    }
}

int main() {
    vector<TypeSpeedLeader> leaders;
    ifstream file("TypeSpeedLeaders.csv");
    string line;
    bool firstLine = true;

    while (getline(file, line))
    {
        if (firstLine)
        {
            firstLine = false;
            continue;
        }
        stringstream ss(line);
        string value;
        TypeSpeedLeader leader;

        // Skip the index column
        getline(ss, value, ',');

        // Parse in order
        getline(ss, value, ','); // Rank
        leader.rank = static_cast<int>(safe_stod(value));
        getline(ss, leader.racer, ','); // Racer
        getline(ss, value, ','); // Text_Bests
        leader.text_bests = safe_stod(value);
        getline(ss, value, ','); // Races
        leader.races = safe_stoi(value);
        getline(ss, value, ','); // Texts
        leader.texts = safe_stoi(value);
        getline(ss, value, ','); // Career
        leader.career = safe_stod(value);
        getline(ss, value, ','); // Best_10
        leader.best_10 = safe_stod(value);
        getline(ss, value, ','); // Best_Race
        leader.best_race = safe_stod(value);
        getline(ss, value, ','); // Points
        leader.points = safe_stod(value);
        getline(ss, value, ','); // Wins
        leader.wins = safe_stoi(value);
        getline(ss, value, ','); // Win_%
        leader.win_percent = safe_stod(value);
        getline(ss, value, ','); // Marathon
        leader.marathon = safe_stoi(value);
        getline(ss, leader.last_race, ','); // Last_Race
        getline(ss, value, ','); // Variation
        leader.variation = safe_stod(value);

        if (!leader.racer.empty())
            leaders.push_back(leader);
    }

    // ask user for range
    int start_row = 0, end_row = 0;
    cout << "Enter start row (1-" << leaders.size() << "): ";
    cin >> start_row;
    cout << "Enter end row (" << start_row << "-" << leaders.size() << "): ";
    cin >> end_row;


    if (start_row < 1) start_row = 1;
    if (end_row > (int)leaders.size()) end_row = (int)leaders.size();
    if (end_row < start_row) end_row = start_row;
    start_row--;
    end_row--;

    // header
    system("cls");
    cout << setw(5) << "Rank" << setw(36) << "Racer" << setw(12) << "Best" << setw(10) << "Races"
        << setw(10) << "Texts" << setw(12) << "Career" << setw(12) << "Best_10"
        << setw(14) << "BestRace" << setw(16) << "Points" << setw(10) << "Wins"
        << setw(10) << "Win%" << setw(12) << "Marathon" << setw(16) << "LastRace"
        << setw(12) << "Var" << endl;


    for (int i = start_row; i <= end_row; ++i)
    {
        const auto& l = leaders[i];
        cout << setw(5) << l.rank << setw(36) << l.racer << setw(12) << l.text_bests
            << setw(10) << l.races << setw(10) << l.texts << setw(12) << l.career
            << setw(12) << l.best_10 << setw(14) << l.best_race << setw(16) << l.points
            << setw(10) << l.wins << setw(10) << l.win_percent << setw(12) << l.marathon
            << setw(16) << l.last_race << setw(12) << l.variation << endl;
    }
    cout << "\n... (showing rows " << (start_row + 1) << " to " << (end_row + 1) << " of " << leaders.size() << ") ..." << endl;


    double total_text_bests = 0;
    for (const auto& l : leaders) total_text_bests += l.text_bests;
    cout << "\nAverage Text_Bests: " << (leaders.empty() ? 0 : total_text_bests / leaders.size()) << endl;

    double max_win_percent = 0;
    string top_racer;
    for (const auto& l : leaders)
    {
        if (l.win_percent > max_win_percent)
        {
            max_win_percent = l.win_percent;
            top_racer = l.racer;
        }
    }
    cout << "Highest Win %: " << max_win_percent << " by " << top_racer << endl;

    double total_points = 0;
    for (const auto& l : leaders) total_points += l.points;
    cout << "Total Points (all racers): " << total_points << endl;

    double total_variation = 0;
    for (const auto& l : leaders) total_variation += l.variation;
    cout << "Average Variation: " << (leaders.empty() ? 0 : total_variation / leaders.size()) << endl;

    return 0;
}