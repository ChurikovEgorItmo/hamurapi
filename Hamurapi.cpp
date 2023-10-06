#include <iostream>
#include <fstream>
#include "UserInputFunctionsHeader.h"
#include "GenerateRandomValuesFunctionsHeader.h"
#include "CalculateFunctionsHeader.h"

using namespace std;


int currentRound = 1; // какой сейчас идет раунд
bool youLoose = false; // проиграли ли вы

int citySquareInAcres = 1000; // площадь города в акрах
float acreCostInWheatBushels = 0.0; // стоиость 1 акра площади в бушелях пшеницы

int currentPopulation = 100; // текущее населения города
int peopleDiedFromHunger = 0; // сколько человек умерло от голода
int peopleDiedFromChuma = 0; // сколько человек умерло от чумы
int peopleCameToCity = 0; // сколько человек приехало в город

int wheatAcresSow = 0; // сколько акров было засеяно пшеницей
float wheatBushelsNumber = 2800.0; // сколько в казне бушелей пшеницы
float wheatBushelsGot = 0.0; // сколько бушелей пшеницы было собрано
float wheatBushelsEat = 0.0; // сколько бушелей пшеницы было съедено
float wheatBushelsRatsDestroyed = 0.0; // сколько бушелей пшеницы уничтожили крысы
float gotBushelsFromOneSowAcre = 0.0; // сколько бушелей пшеницы уничтожили крысы

// statistics
float diedFromHungerPercentageSumAllTime = 0.0; // Среднегодовой процент умерших от голода

void saveProgress() {
    ofstream file("progress.txt");
    if (file.is_open()) {
        file.clear();
        file << currentRound << endl;
        file << citySquareInAcres << endl;
        file << acreCostInWheatBushels << endl;
        file << currentPopulation << endl;
        file << peopleDiedFromHunger << endl;
        file << peopleDiedFromChuma << endl;
        file << peopleCameToCity << endl;
        file << wheatAcresSow << endl;
        file << wheatBushelsNumber << endl;
        file << wheatBushelsGot << endl;
        file << wheatBushelsEat << endl;
        file << wheatBushelsRatsDestroyed << endl;
        file << gotBushelsFromOneSowAcre << endl;
        file << diedFromHungerPercentageSumAllTime << endl;
        file.close();
    }
}

void loadProgress() {
    ifstream file("progress.txt");
        if (file.is_open()) {
            int needLoadGame = inputNeedLoadGame();
            if (needLoadGame == 1) {
                file >> currentRound;
                file >> citySquareInAcres;
                file >> acreCostInWheatBushels;
                file >> currentPopulation;
                file >> peopleDiedFromHunger;
                file >> peopleDiedFromChuma;
                file >> peopleCameToCity;
                file >> wheatAcresSow;
                file >> wheatBushelsNumber;
                file >> wheatBushelsGot;
                file >> wheatBushelsEat;
                file >> wheatBushelsRatsDestroyed;
                file >> gotBushelsFromOneSowAcre;
                file >> diedFromHungerPercentageSumAllTime;
                file.close();
            }
            else {
                file.clear();
            }
        }
}



void generateRandomValues() {
    acreCostInWheatBushels = generateRandomAcreCostInWheatBushels();
    gotBushelsFromOneSowAcre = generateRandomGotBushelsFromOneSowAcre();
    wheatBushelsRatsDestroyed = generateRandomRatsDestroyedBushels(wheatBushelsNumber);
}

void showStats() {
    cout << endl;
    cout << "Мой повелитель, соизволь поведать тебе" << endl;
    if (currentRound > 1) {
        cout << "в году " << currentRound - 1 << " твоего высочайшего правления" << endl;
        cout << peopleCameToCity << " человек прибыло в наш великий город" << endl;
        cout << "Мы собрали " << wheatBushelsGot << " бушелей пшеницы, по " << gotBushelsFromOneSowAcre << " бушелей с акра" << endl;
        cout << "Крысы истребили " << wheatBushelsRatsDestroyed << " бушелей пшеницы" << endl;
        if (peopleDiedFromChuma > 0) {
            cout << peopleDiedFromChuma << " человек умерло от чумы " << endl;
        }
        cout << peopleDiedFromHunger << " человек умерло с голоду" << endl;
    }
    cout << "У нас " << wheatBushelsNumber << " бушелей в амбарах" << endl;
    cout << "Население города сейчас составляет " << currentPopulation << " человек" << endl;
    cout << "Город сейчас занимает " << citySquareInAcres << " акров" << endl;

}

void manageUserInputs() {
    cout << "Что пожелаешь, повелитель ?" << endl;

    int howManyAcresBuy = inputHowManyAcresBuy(acreCostInWheatBushels, wheatBushelsNumber);
    wheatBushelsNumber -= acreCostInWheatBushels * howManyAcresBuy;
    citySquareInAcres += howManyAcresBuy;

    int howManyAcresSell = inputHowManyAcresSell(acreCostInWheatBushels, citySquareInAcres);
    wheatBushelsNumber += acreCostInWheatBushels * howManyAcresBuy;
    citySquareInAcres -= howManyAcresSell;

    wheatAcresSow = inputHowManyAcresSow(currentPopulation, wheatBushelsNumber, citySquareInAcres);

    wheatBushelsEat = inputHowManyBushelsEat(wheatBushelsNumber);
}

void calculateWheatGrow() {
    wheatBushelsGot = gotBushelsFromOneSowAcre * wheatAcresSow;
    wheatBushelsNumber = wheatBushelsNumber + wheatBushelsGot - wheatBushelsRatsDestroyed - wheatBushelsEat;
}

void calculatePopulation() {
    peopleDiedFromHunger = calculateDeathFromHungerCount(currentPopulation, wheatBushelsEat);
    if (peopleDiedFromHunger > currentPopulation * 0.45) {
        youLoose = true;
        cout << peopleDiedFromHunger << " человек умерло от голода" << endl;
        return;
    }
    diedFromHungerPercentageSumAllTime += peopleDiedFromHunger / currentPopulation;

    if (generateRandomWasChuma()) {
        peopleDiedFromChuma = currentPopulation / 2;
    }
    else {
        peopleDiedFromChuma = 0;
    }

    peopleCameToCity = (peopleDiedFromHunger / 2) + ((5 - gotBushelsFromOneSowAcre) * wheatBushelsNumber / 600) + 1;
    if (peopleCameToCity < 0) {
        peopleCameToCity = 0;
    }
    if (peopleCameToCity > 50) {
        peopleCameToCity = 50;
    }

    currentPopulation = currentPopulation - peopleDiedFromHunger - peopleDiedFromChuma + peopleCameToCity;
    if (currentPopulation < 0) {
        currentPopulation = 0;
        youLoose = true;
        cout << endl << "Все вымерли" << endl;
        return;
    }

}

void gameLoop() {
    showStats();
    generateRandomValues();
    manageUserInputs();
    calculateWheatGrow();
    calculatePopulation();
    saveProgress();
}

int main()
{
    setlocale(LC_ALL, "Russian");
    loadProgress();
    while (currentRound < 11)
    {
        if (youLoose) {
            cout << endl << "Цезарь считает, что ты - неродивый наместник!" << endl;
            return 0;
        }
        gameLoop();
        currentRound++;
    }
    if (currentRound == 11 && !youLoose) {
        evaluateLeadership(diedFromHungerPercentageSumAllTime/10, citySquareInAcres/currentPopulation);
    }
    return 0;
}
