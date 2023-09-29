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
        cout << "Плохо (Из-за вашей некомпетентности в управлении, народ устроил бунт, и изгнал вас из города. Теперь вы вынуждены влачить жалкое существование в изгнании)";
    }
    else if (P > 10 && L < 9) {
        cout << "Удовлетворительно (Вы правили железной рукой, подобно Нерону и Ивану Грозному. Народ вздохнул с облегчением, и никто больше не желает видеть вас правителем)";
    }
    else if (P > 3 && L < 10) {
        cout << "Хорошо (Вы справились вполне неплохо, у вас, конечно, есть недоброжелатели, но многие хотели бы увидеть вас во главе города снова)";
    }
    else {
        cout << "Отлично (Фантастика! Карл Великий, Дизраэли и Джефферсон вместе не справились бы лучше)";
    }
}