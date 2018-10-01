#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <time.h>

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(0));
	int chislo;
	int predpolozhenie;
	int popitki;
	int rejim;
	int max;
	int min;
	int truth;
	char neravenstvo;

	printf("�������� ����� ����: ������� 1, ����� ��������� �����; ����� 2, ����� ����������\n");
	scanf_s("%d", &rejim);
	if (rejim > 2)
		printf("������ ������ ��� ���(���� ���)\n");
	if (rejim == 1)
	{
		predpolozhenie = -1;
		popitki = 0;
		chislo = rand() % 1001;
		printf("%i\n", chislo); //  ��� ��������
		while (predpolozhenie != chislo)
		{
			popitki = popitki + 1;
			printf("������� ���� �������������\n");
			scanf_s("%d", &predpolozhenie);
			if (predpolozhenie == chislo)
				printf("�� ����� ���������� �����. ���������� �������: %d \n", popitki);
			else if (predpolozhenie > chislo)
				printf("���������� ����� ������\n");
			else printf("���������� ����� ������\n");
		}
	}

	if (rejim == 2)
	{
		max = 1000;
		min = 0;
		truth = 0;
		printf("������� �����\n");
		scanf_s("%d", &chislo);
		popitki = 0;
		predpolozhenie = -1;
		while (predpolozhenie != chislo)
		{
			popitki = popitki + 1;
			predpolozhenie = rand () % (max-min) + min;
			printf("�� �������� ����� %d ?\n", predpolozhenie);
			scanf_s("%c", &neravenstvo);
			scanf_s("%c", &neravenstvo);
			switch (neravenstvo)
			{
			    case('='):
			    {
				    printf("�� � ��� � ����, ��� �� �������� ������ ��� �����. ���������� �������: %d", popitki);
				    predpolozhenie = chislo;
				    break;
			    }
			    case('>'):
			    {
				     min = predpolozhenie + 1;
				     break;
			     }
			    case('<'):
			    {
				     max = predpolozhenie - 1;
				     break;
			    }
			default:
				break;
			}
		}
	}
		_getch();
}