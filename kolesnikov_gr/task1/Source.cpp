#include <stdio.h>

#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	float pDSP, pDEREVA, pDVP;
	float H, W, D;
	float Tzstenki;
	float Tbok;
	float Tdver;
	float Tpolok;
	float Tkrish;
	float Npolok;
	float Mzstenki, Mdver, Mbok, Mvnutr, Mkrish, Mpolok, Mobsh;
	float a;

	printf("������� ������(h), ������(w) � �������(d) � �����������\n");
	scanf_s("%f%f%f", &H, &W, &D);
	printf("������� ��������� ���, ��� � ������ � ������� �� ����������� ����������\n");
	scanf_s("%f%f%f", &pDSP, &pDVP, &pDEREVA);
	printf("������� ������� ������ ������ � �����������\n");
	scanf_s("%f", &Tzstenki);
	printf("������� ������� ������� ������ � �����������\n");
	scanf_s("%f", &Tbok);
	printf("������� ������� ����� � �����������\n");
	scanf_s("%f", &Tdver);
	printf("������� ������� ����� � �����������\n");
	scanf_s("%f", &Tpolok);
	printf("������� ������� ������ � �����������\n");
	scanf_s("%f", &Tkrish);

	Mzstenki = pDVP * H*W*Tzstenki;
	printf("����� ������ ������ %f\n", Mzstenki);
	Mbok = 2 * pDSP*H*D*Tbok;
	printf("����� ������� %f\n", Mbok);
	Mkrish = 2 * pDSP*W*D*Tkrish;
	printf("����� ������ %f\n", Mkrish);
	Mdver = pDEREVA * H*W*Tdver;
	printf("����� ������ %f\n", Mdver);
	Npolok = (int)((H - 2 * Tkrish - 00000.1) / 40);
	printf("���������� ����� %f\n", Npolok);
	Mpolok = Npolok * pDSP*W*D*Tpolok;
	printf("����� ����� %f\n", Mpolok);
	Mobsh = Mzstenki + Mbok + Mkrish + Mdver + Mpolok;
	printf("����� ����� ����� %f\n", Mobsh);
	scanf_s("%f", &a);
}