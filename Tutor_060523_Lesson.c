// Tutor_060523.cpp

#include <stdio.h>

/*
	Standard Input Output -> printf, scanf
	Variables -> Global, Local, Const
			  -> namaVariable, NamaVariable, nama_variable
	DataTypes -> Integer (%d), Char (%c), Float (%f), Double (%lf)
	          -> String (%s) -> Kumpulan character
*/

// Global Variable
const int global1 = 7;
int global2 = 5;

int main()
{
	double dec = (double)22/7;
	printf("%lf\n", dec);
	printf("%.2lf\n", dec);
	
	int number = 0;
	number += 5;
	printf("%03d\n", number); // 5
	
	// Minta input user
	int input;
	char nama[100];
	scanf("%d", &input);
	// Ketik angkanya, tekan enter ("\n")
	getchar();
//	scanf("%[^\n]", nama);
	gets(nama);
	printf("| %50s |\n", nama);
	printf("| %-50s |\n", nama);
	
	// Ukuran untuk setiap data type
	printf("Size of int: %d bytes\n", sizeof(int));
	printf("Size of char: %d bytes\n", sizeof(char));
	printf("Size of float: %d bytes\n", sizeof(float));
	printf("Size of double: %d bytes\n", sizeof(double));
	
	// Declare and display variabel
	global2 = 4;
	int bilangan1, bilangan2 = 7, bilangan3 = 3;
	char huruf1 = '2';
	char kata[100] = "Hello Binusian";
	printf("%c\n", kata[0]);
	
	// Operators
	int a = 1;
	int b = 7;
	printf("%d\n", (a > b) && (a < b));
	printf("%d\n", 1 << 5);
	
	// Conditions
	if (a < b)
	{
		printf("a kurang dari b");
		if (a < 5)
		{
			printf(" dan a kurang dari 5\n");
		}
	}
	else if (a < 10)
	{
		printf("a kurang dari 10\n");
	}
	char day = 'c';
	switch (day)
	{
		case 'a':
			{
				int bil = 0;
				printf("Monday\n");
			}
			break;
		case 'b':
			printf("Tuesday\n");
			break;
		default:
			printf("Day must between 1 and 7\n");
			break;
	}
	printf(a < b ? "a kurang dari b" : "a lebih dari b");
	puts("");
	
	// Loops
	int i = 1;
	for (; i <= 10; i++)
	{
		printf("%d\n", i);
	}
	do
	{
		printf("Masukkan angka: ");
		scanf("%d", &input); getchar();
		printf("%d\n", input);
		input++;
	} while (input < 10);
	printf("%d\n", i);
	while (i > 1)
	{
		printf("%d\n", i);
		i--;
	}
	
	// Increment Decrement -> (++) sama dengan +1
	int awal = 20;
	printf("%d\n", awal);
	while (awal++ <= 30)
	{
		printf("%d\n", awal);
	}
	
	return 0;
}
