#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include <stdio.h>

struct eda
{
	int code[4];
	char imya[20];
	int cena;
	int skidka;
};
void main()
{
	int Code1[4];
	int truth = 1;
	struct eda Food[6];
	struct eda Chicken = { {0, 0, 0, 1}, "Chicken", 200, 20 };
	struct eda Pork = { {0, 0, 0, 2}, "Pork", 300, 15 };
	struct eda Mutton = { {0, 0, 1, 0}, "Mutton", 340, 30 };
	struct eda Beef = { {0, 1, 0, 0}, "Beef", 400, 10 };
	struct eda Dog_Meat = { {1, 0, 0, 0}, "Dog_Meat", 50, 50 };
	struct eda Horse_flesh = { {0, 0, 2, 0}, "Horse_flesh", 350,5 };
	int set; 
	int tovar;
	float Fprice = 0;
	Food[0] = Chicken;
	Food[1] = Pork;
	Food[2] = Mutton;
	Food[3] = Beef;
	Food[4] = Dog_Meat;
	Food[5] = Horse_flesh;
	printf_s("Welcome to Gleb's\nOur menu for today\n");
	for (int i = 0; i <= 4; i++)
	{
		printf("%s product code ", Food[i].imya);
		for (int j = 0; j < 4; j++)
		{
			printf("%d ", Food[i].code[j]);
		}
		printf("\n");
	}
	while (truth = 1)
	{
		printf_s("Press 1 to enter the code; 2 to form a check\n");
		scanf_s("%d", &set);
		switch (set)
		{
		case 1:
		{
			printf("Code\n");
			int tovar = -1;
			scanf_s("%d %d %d %d", &Code1[0], &Code1[1], &Code1[2], &Code1[3]);
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 4; j++)
					if (Code1[j] != Food[i].code[j])
						break;
					else
					{
						if (j == 3)
							tovar = i;
					}
			}
			Fprice = (Food[tovar].cena * (100.0 - Food[tovar].skidka)/100);
			printf("%5.2f", Fprice);
			printf_s("Your %s for %5.2f \n", Food[tovar].imya, Fprice);
			break;
		}
		case 2:
		{
			printf_s("Stop scanning");
		}
		}
	}
	_getch();
}