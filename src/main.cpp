#include <iostream>
#include "nation.h"

using namespace std;

void printState(Nation* nations, int count);

int main(void) {
    int nation_count = 3;
    string names[5] = {"red", "blue", "green", "yellow", "purple"};

    cout << "Wecome to Tiny Nation Simulator!\n";
    cout << "how many nations do you want for the simulation? (2-5)\n";
    cout << "!! For development reasons, the nation amount will be set to 3 !!\n\n\n";

    Nation redNation("red");
    Nation blueNation("blue");
    Nation greenNation("green");

    Nation nations[] = { redNation, blueNation, greenNation };

    for(int i=0; i < nation_count; i++) {
        nations[i].m_population = 200;
    }

    for(int i=0; i < nation_count; i++) {
        nations[i].m_happiness = 0.7;
    }

    printState(nations, nation_count);
}

void printState(Nation* nations, int count) {
    for(int i=0; i < count; i++) {
        cout << nations[i].m_name << "\tPopulation: " << nations[i].m_population << " \tHappiness: " << int(nations[i].m_happiness*100) << "%\n";
    }
}

