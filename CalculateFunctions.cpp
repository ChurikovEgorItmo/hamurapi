#include <iostream>
using namespace std;

int calculateDeathFromHungerCount(int currentPopulation, float wheatBushelsEat) {
	int deathCount = 0;
	float wheatBushelsNeed = currentPopulation * 20;
	deathCount = (int)(currentPopulation - (wheatBushelsEat / 20));
	return deathCount;
}

void evaluateLeadership(int P, int L) {
    if (P > 33 && L < 7) {
        cout << "����� (��-�� ����� ���������������� � ����������, ����� ������� ����, � ������ ��� �� ������. ������ �� ��������� ������� ������ ������������� � ��������)";
    }
    else if (P > 10 && L < 9) {
        cout << "����������������� (�� ������� �������� �����, ������� ������ � ����� ��������. ����� �������� � �����������, � ����� ������ �� ������ ������ ��� ����������)";
    }
    else if (P > 3 && L < 10) {
        cout << "������ (�� ���������� ������ �������, � ���, �������, ���� ���������������, �� ������ ������ �� ������� ��� �� ����� ������ �����)";
    }
    else {
        cout << "������� (����������! ���� �������, �������� � ���������� ������ �� ���������� �� �����)";
    }
}