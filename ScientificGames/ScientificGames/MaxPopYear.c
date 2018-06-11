#include <stdio.h>
#include <stdlib.h>

#define NUM 100


int main()
{
	int birth[NUM] = { 0 };
	int death[NUM] = { 0 };
	int i;
	int j;
	for (i = 0; i < NUM; i++)
	{
		birth[i] = rand() % 100 + 1900;
		death[i] = birth[i] + rand() % 75 + 1;
	}

	int MaxYear = 0;
	int MaxPop = 0;
	int YearPop = 0;

	for (i = 1900; i < 2001; i++)
	{
		int YearBirth = 0;
		int YearDeath = 0;
		for (j = 0; j < NUM; j++)
		{
			if (birth[j] == i) { YearBirth += 1; }
			if (death[j] == i) { YearDeath += 1; }
		}
		YearPop = YearPop + YearBirth - YearDeath;
		if (YearPop > MaxPop) 
		{ 
			MaxPop = YearPop;
			MaxYear = i;
		}
	}
	printf("The year with the highest population was %d, with a population of %d.", MaxYear, MaxPop);
	return(MaxYear);
}