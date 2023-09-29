#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int generateRandomAcreCostInWheatBushels() {
	std::srand(std::time(nullptr));
	int randomNumber = std::rand() % 10 + 17;
	cout << "1 акр земли стоит сейчас " << randomNumber << " бушелей пшеницы" << endl << endl;
	return randomNumber;
}

int generateRandomGotBushelsFromOneSowAcre(){
	srand(time(0));
	int randomNumber = rand() % 6 + 1;
	return randomNumber;
}

int generateRandomRatsDestroyedBushels(float bushelsWithGotten){
	srand(time(0));
	float ratsK = ((double)rand() / RAND_MAX) * 0.07;
	return bushelsWithGotten * ratsK;

}

bool generateRandomWasChuma() {
	srand(time(0));
	int randomNumber = rand() % 100 + 1;
	return randomNumber <= 15;
}
