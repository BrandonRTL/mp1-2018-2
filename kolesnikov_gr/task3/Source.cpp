#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include <stdio.h>

void main()
{
	setlocale(LC_ALL, "Rus");
	int dlina;
	int numb[5];
	int number[5];
	int numb1, numb2;
	int mult, mult1;
	int korovki;
	int bi4ki;
	int nmb;
	int i, j, k;
	int truth;
	int popitki;
	srand(time(NULL));
	printf("������� ����� ����� �� 2 �� 5\n");
	scanf_s("%i", &dlina);
	popitki = 0;
		while ((dlina < 2) || (dlina > 5))
		{
			printf("����� ������ �������, ������� ����� �����\n");
			scanf_s("%i", &dlina);
		}
		numb[0] = rand() % 9 + 1;
		for (i = 1; i < dlina; i++)
		{
			numb1 = rand() % 10;
			for (j = 0; j <= i - 1; j++)
			{

				while (numb1 == numb[j])
				{
					j = 0;
					numb1 = rand() % 10;
				}

				numb[i] = numb1;
			}
		}
		numb1 = 0;
		mult = 1;
		for (i = dlina - 1; i >= 0; i = i - 1)
		{
			numb1 = numb1 + mult * numb[i];
			mult = mult * 10;
		}

		printf("%d\n", numb1);
	truth = 0;
	while (truth == 0)
	{
		printf("������� �����\n");
		scanf_s("%i", &numb2);
		korovki = 0;
		bi4ki = 0;
		mult1 = mult;
		popitki = popitki + 1; 

		for (i = 0; i <= dlina; i++)
		{
			number[i] = numb2 % 10;
			numb2 = numb2 / 10;
		}
		for (i = 0; i < dlina; i++)
		{
			if (number[i] == numb[i])
				bi4ki = bi4ki + 1;
			else
			{
				for (j = 0; j < dlina; j++)
				{
					if (number[i] == numb[j])
						korovki = korovki + 1;
				}
			}
		}
		if (korovki == 0)
			if (bi4ki != dlina)
			    printf("�����.���\n");
		if (bi4ki == 0)
			if (bi4ki != dlina)
			    printf("�����.���\n");
		if (korovki > 0)
			if (bi4ki != dlina)
			    printf("������ %d\n", korovki);
		if (bi4ki > 0)
			if (bi4ki != dlina)
			    printf("���� %d\n", bi4ki);
		if (bi4ki == dlina)
		{
			printf("�� ������� �����\n");
			truth = 1;
		}
	}
	printf("���������� ������� %i\n", popitki);
	_getch();
}