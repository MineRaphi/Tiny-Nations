#include <iostream>
#include <random>
#include "nation.h"

using namespace std;

mt19937 rng(random_device{}());

void printState(Nation* nations, int count, int year);
void progressYear(Nation* nations, int count, int* year);
int calculateDeaths(int population, float happiness);
int calculateBirths(int population, float happiness);
float calculateHappiness(int population, float current_happiness, int money, bool isWar);

int main(void) {
    int nation_count = 3;
    int current_year = 0;

    string names[5] = {"red", "blue", "green", "yellow", "purple"};

    cout << "Wecome to Tiny Nation Simulator!\n";
    cout << "how many nations do you want for the simulation? (2-5)\n";
    cout << "!! For development reasons, the nation amount will be set to 3 !!\n\n\n";

    Nation redNation("Red");
    Nation blueNation("Blue");
    Nation greenNation("Green");

    Nation nations[] = { redNation, blueNation, greenNation };

    for(int i=0; i < nation_count; i++) {
        nations[i].m_population = 200;
    }

    for(int i=0; i < nation_count; i++) {
        nations[i].m_happiness = 0.7;
    }

    for(int i=0; i < nation_count; i++) {
        nations[i].m_stateMoney = 50;
    }

    while (1) {
        printState(nations, nation_count, current_year);
        getchar();

        progressYear(nations, nation_count, &current_year);
    }
}

void printState(Nation* nations, int count, int year) {
    cout << "Current year: " << year << "\n=================\n";
    for(int i=0; i < count; i++) {
        cout << nations[i].m_name << "\tPopulation: " << nations[i].m_population
        <<"  Happiness: " << int(nations[i].m_happiness*100) << "%"
        << "  Money: " << nations[i].m_stateMoney << "k"
        << "\n";
    }
}

void progressYear(Nation* nations, int count, int* year) {
    (*year)++;

    for(int i=0; i < count; i++) {
        int deaths = calculateDeaths(nations[i].m_population, nations[i].m_happiness);
        int births = calculateBirths(nations[i].m_population, nations[i].m_happiness);

        nations[i].m_population -= deaths;
        nations[i].m_population += births;

        nations[i].m_happiness = calculateHappiness(nations[i].m_population, nations[i].m_happiness, nations[i].m_stateMoney, nations[i].m_isWartime);
    }
}

int calculateDeaths(int population, float happiness) {
    float average_death = 0.07;
    float happiness_mult = 0.3;

    uniform_real_distribution<float> dist(0.7f, 1.5f);
    float variance = dist(rng);

    return population * average_death * variance * (2 - happiness * happiness_mult);
}

int calculateBirths(int population, float happiness) {
    float average_birth = 0.13;
    float happiness_mult = 0.2;

    uniform_real_distribution<float> dist(0.7f, 1.4f);
    float variance = dist(rng);

    return population * average_birth * variance * (1 + happiness * happiness_mult);
}

float calculateHappiness(int population, float current_happiness, int money, bool isWar) {
    float war_mult = 0.15;
    float money_mult = 0.1;

    float money_per_person = 200.0;

    uniform_real_distribution<float> dist(0.95f, 1.05f);
    float variance = dist(rng);

    float happiness_change = population * money_per_person / (money * 1000);

    float new_happiness = current_happiness * ((1 - happiness_change ) * money_mult + 1) * (1 - float(isWar * war_mult));

    if (new_happiness > 1) {
        new_happiness = 1;
    }
    else if (new_happiness < 0.009) {
        new_happiness = 0.009;
    }

    return new_happiness;
}