#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  
#include <time.h>  
#include <string.h>
#include <time.h>
#include <math.h>
void Exponenta(double Tochnost, double x, int n)
{
	double ImExp = 1;
	double ImAdding = 1;
	int count = 0;
	double y = exp(x);
	for (int i = 1; i < n; i++)
	{
		ImAdding = ImAdding * (x / i);
		ImExp = ImExp + ImAdding;
		count++;

		if (abs(y - ImExp) < (Tochnost))
			i = n + 1;

	}
	printf("%lf\n", ImExp);
	printf("%lf\n", y);
	printf("%lf\n", ImExp - y);
	printf("%d", count);

}
void Arctangens(double Tochnost, double x, int n)
{
	while (abs(x) > 1)
	{
		printf("|x|<=1");
		scanf_s("%f", &x);
	}
}
void Cosinus (double Tochnost, double x, int n)
{

}
void Sinus(double Tochnost, double x, int n)
{

}
int ZnakChetn(int n)
{
	int Znak;
	if ((n % 2) == 0)
		Znak = 1;
	if ((n % 2) == 1)
		Znak = -1;
	return Znak;
}
int ZnakNeChetn(int n)
{
	int Znak;
	if ((n % 2) == 0)
		Znak = -1;
	if ((n % 2) == 1)
		Znak = 1;
	return Znak;
}
int main()
{
	double x, y, z, t;
	int n = 100;
	int flag = 1;
	double Tochnost = 1;
	float ImAdding;
	scanf_s("%lf", &x);
	printf("%lf\n", x);
	int count = 0;
	int Znak;
	x = 1; 
	ImAdding = x * x*x;
	float ImAtan = x;
	y = atan(x);
	printf("%lf\n", y);
	for (int i = 1; i < 100; i++)
	{
		Znak = ZnakNeChetn(n);
		ImAdding = ImAdding * x*x;
		ImAtan = ImAtan + Znak*ImAdding/(2*i-1);
	}
	_getch();
}