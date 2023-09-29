


int calculateDeathFromHungerCount(int currentPopulation, float wheatBushelsEat) {
	int deathCount = 0;
	float wheatBushelsNeed = currentPopulation * 20;
	deathCount = (int)(currentPopulation - (wheatBushelsEat / 20));
	return deathCount;
}