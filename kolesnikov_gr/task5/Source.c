#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  
#include <time.h>  
#include <string.h>

char namez[100][250];

int main(void)
{
	struct _finddata_t c_file;
	intptr_t hFile;
	char path[200];
	int count = 0;
	int k = 0, i = 0, j = 0;
	unsigned long sizez[100] = { 0 };
	char add_str[100];
	int add = 0;
	printf("Enter catalog adress with doubled slashes\n");
	gets(path);
	while (path[i] != '\0')
		i++;
	path[i + 1] = '\0';
	path[i] = '*';
	i = 0;
	printf("Choose the sorting algorithm\n");
	printf(" 1) - bubble sort\n 2) - select sort\n 3) - insert sort\n 4) - merge sort\n 5) - quick(Hoala) sort\n 6) - shell sort\n 7) - counting sort\n");
	while ((k < 1) || (k > 7))
		scanf("%d", &k);
	if ((hFile = _findfirst(path, &c_file)) == -1L)
		printf("No files found\n");
	else
	{
		printf("Listing of .c files\n\n");
		printf("FILE         DATE %24c   SIZE\n", ' ');
		printf("----         ---- %24c   ----\n", ' ');
		do {
			char buffer[30];
			ctime_s(buffer, _countof(buffer), &c_file.time_write);
			printf("%-12.12s %.24s  %10u\n", c_file.name, buffer, c_file.size);
			sizez[i] = c_file.size;
			strncpy(namez[i], c_file.name, 250);
			i++;
			count++;
		} while (_findnext(hFile, &c_file) == 0);
		_findclose(hFile);
		printf("\ncount of files: %d", count);
	}
	for (i = 0; i < count; i++)
	{
		for (j = count - 1; j > i; j--)
		{
			if (sizez[j - 1] > sizez[j])
			{
				add = sizez[j - 1]; 
				sizez[j - 1] = sizez[j];
				sizez[j] = add;
			}
		}
	}
	for (i = 0; i < count; i++)
		printf("%u\n", sizez[i]);
	switch (k)
	{
	case '1':;
	}
	_getch();
}
