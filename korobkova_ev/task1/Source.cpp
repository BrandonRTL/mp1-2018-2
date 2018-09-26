#include <stdio.h>
#include <math.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Russian");
	float height, width, depth; //������, ������, �������
	float pdsp = 0.8, pdvp = 0.82, pwood = 0.75; //��������� ���, ���, ������(���)
	int k; //���������� �����
	float v1, v2, v3, v4, v5; //���, v1 - ����� ������ �����, v2 - ����� �������, v3 - ����� ������� � ������ ������, v4 - ����� ���� ��������� ������, v5 - ����� ���������� �����
	float m; // ��� m-����� �����

	printf("������� ������ � ��������� �� 180 �� 220 � ��\n");
	scanf_s("%f", &height);
	printf("������� ������ � ��������� �� 80 �� 120 � ��\n");
	scanf_s("%f", &width);
	printf("������� ������� � ��������� �� 50 �� 90 � ��\n");
	scanf_s("%f", &depth);

	v1 = height * width * 0.5;
	v2 = 2 * (height * depth * 1.5);
	v3 = 2 * (width * depth * 1.5);
	v4 = height * width * 1;
	k = ceil((height - 3) / 41.5) - 1;
	v5 = k * width *depth* 1.5;
	m = pdvp * v1 + pdsp * (v2 + v3 + v5) + pwood * v4;
	printf("����� ����� %f", m / 1000);
}