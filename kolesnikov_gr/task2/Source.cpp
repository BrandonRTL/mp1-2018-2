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
	
	predpolozhenie = -1;
	chislo = rand() % 1001;
	printf("%i\n", chislo); //  ��� ��������
	while (predpolozhenie != chislo)
	{
		printf("������� ���� �������������\n");
		scanf_s("%d", &predpolozhenie);
		if (predpolozhenie == chislo)
			printf("�� ����� ���������� �����\n");
		else if (predpolozhenie > chislo)
			printf("���������� ����� ������\n");
		else printf("���������� ����� ������\n");
	}

	_getch();
}