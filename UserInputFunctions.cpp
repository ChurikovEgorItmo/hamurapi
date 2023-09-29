#include <iostream>
using namespace std;

int inputHowManyAcresBuy(int acreCostInWheatBushels, int wheatBushelsNumber) {
    double howManyAcresBuy;
    bool isRightNumber = false;
    cout << "Сколько акров земли повелеваешь купить?  ";
    while (!(cin >> howManyAcresBuy) || howManyAcresBuy < 0 || !(howManyAcresBuy == static_cast<int>(howManyAcresBuy)) || (wheatBushelsNumber < acreCostInWheatBushels * howManyAcresBuy)) {
        cin.clear(); //clear bad input flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
        cout << "Неверно! Сколько акров земли повелеваешь купить?  ";
    }
    return howManyAcresBuy;
}

int inputHowManyAcresSell(int acreCostInWheatBushels, int citySquareInAcres) {
    double howManyAcresSell;
    bool isRightNumber = false;
    cout << "Сколько акров земли повелеваешь продать?  ";
    while (!(cin >> howManyAcresSell) || howManyAcresSell < 0 || !(howManyAcresSell == static_cast<int>(howManyAcresSell)) || citySquareInAcres < howManyAcresSell) {
        cin.clear(); //clear bad input flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
        cout << "Неверно! Сколько акров земли повелеваешь продать?  ";
    }
    return howManyAcresSell;
}

int inputHowManyAcresSow(int population, float wheatBushelsNumber, int citySquareInAcres) {
    double howManyAcresSow;
    bool isRightNumber = false;
    cout << "Сколько акров земли повелеваешь засеять пшеницей?  ";
    while (!(cin >> howManyAcresSow) || howManyAcresSow < 0 || !(howManyAcresSow == static_cast<int>(howManyAcresSow)) || howManyAcresSow > population*10 || ((howManyAcresSow / 2) > wheatBushelsNumber) || howManyAcresSow > citySquareInAcres) {
        cin.clear(); //clear bad input flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
        cout << "Неверно! Сколько акров земли повелеваешь засеять пшеницей?  ";
    }
    return howManyAcresSow;
}

int inputHowManyBushelsEat(float wheatBushelsNumber) {
    double howManyBushelsEat;
    bool isRightNumber = false;
    cout << "Сколько бушелей пшеницы повелеваешь съесть?  ";
    while (!(cin >> howManyBushelsEat) || howManyBushelsEat < 0 || !(howManyBushelsEat == static_cast<int>(howManyBushelsEat)) || howManyBushelsEat > wheatBushelsNumber) {
        cin.clear(); //clear bad input flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
        cout << "Неверно! ССколько бушелей пшеницы повелеваешь съесть?  ";
    }
    return howManyBushelsEat;
}
