#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  
#include <time.h>  

int main(void)
{
	struct _finddata_t c_file;
	intptr_t hFile;
	char path[200];
	int count = 0;
	int k = 0, i = 0, j = 0;
	int sisez[100] = { 0 };
	char namez[100][250];
	char add_str[100];
	printf("Enter catalog adress with \\\\*.*\n");
	gets(path);
	printf("Choose the sorting algorithm\n");
	printf(" 1) - bubble sort\n 2) - select sort\n 3) - insert sort\n 4) - merge sort\n 5) - quick(Hoala) sort\n 6) - shell sort\n 7) - counting sort\n");
	while ((k < 1) || (k > 7))
		scanf("%d", &k);

	if ((hFile = _findfirst(path, &c_file)) == -1L)
		printf("No *.c files in current directory!\n");
	else
	{
		printf("Listing of .c files\n\n");
		printf("FILE         DATE %24c   SIZE\n", ' ');
		printf("----         ---- %24c   ----\n", ' ');
		do {
			char buffer[30];
			ctime_s(buffer, _countof(buffer), &c_file.time_write);
			if (count <= 20)
			{
				printf("%-12.12s %.24s  %10ld\n", c_file.name, buffer, c_file.size);
				sisez[i] = c_file.size;
				strncpy(namez[i], c_file.name, 250);
				i++;
			}
			count++;
		} while (_findnext(hFile, &c_file) == 0);
		_findclose(hFile);
		printf("\ncount of files: %d", count);
	}
	switch (k)
	{
	case '1':;
	}
	_getch();
}
