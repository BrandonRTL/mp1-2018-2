#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  
#include <time.h>  
#include <string.h>
#include <time.h>
#include <math.h>
int ZnakChetn(int n) // + по четным; - по нечетным
{
	int Znak;
	if ((n % 2) == 0)
		Znak = 1;
	if ((n % 2) == 1)
		Znak = -1;
	return Znak;
}
int ZnakNeChetn(int n) // + по нечетным; - по четным
{
	int Znak;
	if ((n % 2) == 0)
		Znak = -1;
	if ((n % 2) == 1)
		Znak = 1;
	return Znak;
}

long double Exponenta(double Tochnost, double x, int n)
{
	long double ImExp = 1;
	long double ImAdding = 1;
	int count = 0;
	double y = exp(x);
	for (int i = 2; i <= n; i++)
	{
		ImAdding = (ImAdding * x) / (i-1);
		ImExp = ImExp + ImAdding;
		count++;
		if (fabs(y - ImExp) < Tochnost)
			i = n + 1;
	}
	return ImExp;
}
long double Arctangens(double Tochnost, double x, int n)
{
	do
	{
		printf("|x|<=1!!!!");
		scanf_s("%f", &x);
	} while (fabs(x) > 1);
	long double ImArcTan = x;
	long double ImAdding = x;
	int i = 0;
	int count = 0;
	for (i = 2; i <= n; i++)
	{
		ImAdding = ImAdding * (-1)*((x * x)*(2*i-3)/(2*i-1));
		ImArcTan = ImArcTan + ImAdding;
		count++;
		if (fabs(tan(x) - ImArcTan) < Tochnost)
			i = n + 1;
	}
	return(ImArcTan);
}
long double Cosinus (double Tochnost, double x, int n)
{
	int i;
	int count = 0;
	long double ImCos = 1;
	long double ImAdding = 1;
	for (i = 2; i <= n; i++)
	{
		ImAdding = ImAdding*(-1)*((x * x) / ((2 * i - 2) * (2 * i - 3)));
		ImCos = ImCos + ImAdding;
		count++;
		if (fabs(cos(x) - ImCos) < Tochnost)
			i= n+1;
	}
	return ImCos;
}
long double Sinus(double Tochnost, double x, int n)
{
	int i;
	long double ImSin = x;
	int count = 0;
	long double ImAdding = x;
	for (i = 2; i <= n; i++)
	{
		ImAdding = ImAdding*(-1)*((x * x) / ((2 * i - 2) * (2 * i - 1)));
		ImSin = ImSin + ImAdding;
		count++;
		if (fabs(sin(x) - ImSin) < Tochnost)
			i = n + 1;
	}
	return ImSin;
}
int main()
{
	double x, y, z, t;
	int n = 100;
	int j = 1;
	int flag = 1;
	double Tochnost = 1;
	void(*p)();
	long double(*operation)(long double, long double, int);
	printf("Choose the function!\n");
	printf("1 - sin\n2 - cos\n3 - exp\n4 - arctan");
	scanf_s("%d", &j);
	operation = Sinus;
	if (j == 2)
		operation = Cosinus;
	if (j == 3)
		operation = Exponenta;
	if (j == 4)
		operation = Arctangens;
	y = operation(0.00001, 1.52, 100);
	printf("%f", y);
	_getch();
}