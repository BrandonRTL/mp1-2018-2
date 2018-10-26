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
	int check[6] = {0};
	Food[0] = Chicken;
	Food[1] = Pork;
	Food[2] = Mutton;
	Food[3] = Beef;
	Food[4] = Dog_Meat;
	Food[5] = Horse_flesh;
	printf_s("Welcome to Gleb's\nOur menu for today\n");
	for (int i = 0; i <= 5; i++)
	{
		printf("%12s product code ", Food[i].imya);
		for (int j = 0; j < 4; j++)
		{
			printf("%d ", Food[i].code[j]);
		}
		printf("\n");
	}
		while (truth)
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
				for (int i = 0; i <= 5; i++)
				{
					for (int j = 0; j < 4; j++)
						if (Code1[j] != Food[i].code[j])
							break;
						else
						{
							if (j == 3)
							{
								tovar = i;
								check[tovar] = check[tovar] + 1;
								printf_s("Your %s for %d rubles with %d percent discount \n", Food[tovar].imya, Food[tovar].cena, Food[tovar].skidka);
								break;
							}
			
						}
				}
				break;
			}
			case 2:
			{
				Fprice = 0;
				printf_s("Stop scanning\n");
				for (int i = 0; i < 6; i++)
				{
					if (check[i] > 0)
					{
						printf("%15s * %d for %d rubles with %d percent discount\n              Total %s price %5.2f\n", Food[i].imya, check[i], Food[i].cena, Food[i].skidka, Food[i].imya, check[i] * Food[i].cena*(100.0 - Food[i].skidka) / 100);
						Fprice = Fprice + check[i] * Food[i].cena*(100.0 - Food[i].skidka) / 100;
					}
				}
				printf("TOTAL %5.2f rubles\n", Fprice);
				truth = 0;
				break;
			}
			}
		}
		_getch();
}
