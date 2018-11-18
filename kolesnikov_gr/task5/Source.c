#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  
#include <time.h>  
#include <string.h>
#include <time.h>

char namez[1000][250];
void Switch1(char str1[], char  str2[])
{
	char addstr[250] = { 0 };
	strncpy(addstr, str1, 250);
	strncpy(str1, str2, 250);
	strncpy(str2, addstr, 250);
}
void quick_Sort(unsigned long a[],int b[], int count) 
{
	long i = 0, j = count - 1; 
	long p = count / 2;
	unsigned long temp; 
	do {
		while (a[i] < a[p]) i++;
		while (a[j] > a[p]) j--;
		if (i <= j) 
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			temp = b[i];
			b[i] = b[j];
			b[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0) quick_Sort(a,b, j);
	if (count > i) quick_Sort(a + i,b, count - i);
}
int main()
{
	struct _finddata_t c_file;
	intptr_t hFile;
	clock_t t1, t2;
	double T;
	char path[200];
	int count = 0;
	int k = 0, i = 0, j = 0, l = 0;
	unsigned long sizez[100] = { 0 };
	unsigned long x;
	int addnamez[250];
	for (i = 0; i < 250; i++)
		addnamez[i] = i;
	printf("Enter catalog adress with doubled slashes\n");
	gets(path);
	int a = strlen(path);
	path[a + 1] = '\0';
	path[a] = '*';
	i = 0;
	printf("Choose the sorting algorithm\n");
	printf(" 1) - bubble sort\n 2) - select sort\n 3) - insert sort\n 4) - merge sort\n 5) - quick(Hoala) sort\n 6) - shell sort\n 7) - counting sort\n");
	while ((k < 1) || (k > 7))
		scanf("%d", &k);
	if ((hFile = _findfirst(path, &c_file)) == -1L)
		printf("No files fould!\n");
	else
	{
		printf("Listing of files\n\n");
		printf("FILE         DATE %24c   SIZE\n", ' ');
		printf("----         ---- %24c   ----\n", ' ');
		do {
			char buffer[30];
			if (i  > -1)
			{
				sizez[i] = c_file.size;
				count++;
				strncpy(namez[addnamez[i]], c_file.name, 250);
			}
			ctime_s(buffer, _countof(buffer), &c_file.time_write);
			if (count < 20);
				printf("%-12.12s %.24s  %10u\n", c_file.name, buffer, c_file.size);
			i++;
		} while (_findnext(hFile, &c_file) == 0);
		_findclose(hFile);
		printf("\ncount of files: %d\n", count);
	}
	t1 = clock();
	switch (k)
	{
	case 1:
		for (i = 0; i < count; i++)
		{
			for (j = count - 1; j > i; j--)
			{
				if (sizez[j - 1] > sizez[j])
				{
					x = sizez[j - 1];
					sizez[j - 1] = sizez[j];
					Switch1(namez[j - 1], namez[j]);
					sizez[j] = x;
				}
			}
		}
		t2 = clock();
		break;
	case 2:
		for (i = 0; i < count; i++)
		{
			k = i;
			x = sizez[i];
			for (j = i + 1; j < count; j++)
				if (sizez[j] < x)
				{
					k = j;
					x = sizez[j];
				}
			sizez[k] = sizez[i];
			Switch1(namez[k], namez[i]);
			sizez[i] = x;
		}
		t2 = clock();
		break;
	case 3:
		for (i = 0; i < count; i++)
		{
			x = sizez[i];
			for (j = i - 1; j >= 0 && sizez[j] > x; j--)
			{
				sizez[j + 1] = sizez[j];
				Switch1(namez[j], namez[j + 1]);
			}
			sizez[j + 1] = x;
		}
		t2 = clock();
		break;
	case 5:
		quick_Sort(sizez, addnamez, count);
		break;
		t2 = clock();
		break;
	}
	T = (double)(t2 - t1)/(CLOCKS_PER_SEC);
	printf("%f", T);
	for (i = 0; i < count; i++)
	{
		printf("%20.20s\t", namez[addnamez[i]]);
		printf("%u\n", sizez[i]);
	}
	_getch();
}
