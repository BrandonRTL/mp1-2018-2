#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  
#include <time.h>  
#include <string.h>
#include <time.h>
#include <math.h>
long double Exponenta(double precision, double x, int n, int *Imcount) // MEHANIZM FUNKCII NA SVYAZI
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
		if (fabs(y - ImExp) < precision)
			i = n + 1;
	}
	*Imcount = count+1;
	return ImExp;
}
long double Arctang(double precision, double x, int n, int *Imcount)
{
	long double ImArcTan = x;
	long double ImAdding = x;
	int i = 0;
	long double diff;
	int count = 0;
	for (i = 2; i <= n; i++)
	{
		ImAdding = ImAdding * (-1)*((x * x)*(2*i-3)/(2*i-1));
		ImArcTan = ImArcTan + ImAdding;
		count++;
		diff = fabs(tan(x) - ImArcTan);
		if (diff < precision)
			i = n + 1;
	}
	*Imcount = count+1;
	return(ImArcTan);
}
long double Cosinus (double precision, double x, int n, int *Imcount)
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
		if (fabs(cos(x) - ImCos) < precision)
			i= n+1;
	}
	*Imcount = count+1;
	return ImCos;
}
long double Sinus(double precision, double x, int n, int *Imcount) // 4 FUNKCII
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
		if (fabs(sin(x) - ImSin) < precision)
			i = n + 1;
	}
	*Imcount = count+1;
	return ImSin;
}
int main()
{
	double x, y;
	int n = 100;
	long double ref;
	int Nmax;
	int* pm;
	int i;
	int j = 1;
	int mode;
	int count;
	long double precision = 1;
	void(*p)();  // YKAZATEL NA FUNKCIYU ZDEC'
	long double(*operation[5])(long double, long double, int, int*);  
	operation[1] = Sinus;
	operation[2] = Cosinus;
	operation[3] = Exponenta;
	operation[4] = Arctang;
	long double(*pref[5])(double);
	pref[1] = sin;
	pref[2] = cos;
	pref[3] = exp;
	pref[4] = atan;
	printf("Choose game mode!\n1 - Single function calculation\n2 - Serial experiment\n");
	scanf_s("%d", &mode);
	printf("Choose the function!\n");
	printf("1 - sin\n2 - cos\n3 - exp\n4 - arctan\n");
	scanf_s("%d", &j);
	printf("Choose x!\n");
	scanf_s("%lf", &x);
	if (j == 4)
	{
		while (fabs(x) > 1)
		{
			printf("|x|<=1!!!!");
			scanf_s("%lf", &x);
		}
	}
	ref = pref[j](x);
	if (mode == 1)
	{
		printf("Choose the number of elements in a row!\n");
		scanf_s("%d", &n);
		printf("Choose precision!\n");
		scanf_s("%lf", &precision);
		y = operation[j](precision, x, n, &count);
		printf("calculated value: %f\n", y);
		printf("reference value: %lf\n", ref);
		printf("difference: %lf\n", fabs(ref - y));
		printf("number of elements: %d\n", count);
	}
	if (mode == 2)
	{
		printf("Choose the number of experiments!\n");
		scanf_s("%d", &Nmax);
		printf("N       Ref Value         Calc Value          Diff\n");
		for (i = 1; i <= Nmax; i++)
		{
			y = operation[j](0, x, i, &count);
			printf("%.2d %16.9lf    %14.9lf    %12.9lf\n", i, ref, y, fabs(ref - y));
		}
	}
	_getch();
}