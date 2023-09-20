#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <math.h>

void calculator(), roman(), piglay(), reverse(), nospace();

void squares(), windows(), rot13(), pascaltriangle(), glitch();

void trimmed(), diamond(), christmas(), timer();

int main() { calculator(); return 0; }

void calculator()
{
	char operation; long int first, second;
  	
	scanf("%ld %c %ld", &first, &operation, &second);

	system("cls");

	printf("INPUT: %ld %c %ld = %ld", first, operation, second, operation == '+' ? first + second : operation == '-' ? first - second :
																operation == '*' ? first * second : operation == '/' ? first / second :
																operation == '%' ? first % second : -1);
	printf("\n");
}

void roman()
{
	int input, i; char result[100];
	
	int value[13] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
	
	char roman[13][3] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
	
	scanf("%d", &input);
	
	for (i = 12; i >= 0; i--)
	{
		while (input >= value[i])
		{
			input = input - value[i];
			
			printf("%s", roman[i]);
		}
	}
}

void piglay()
{
	int status = 0, i; char input[100]; gets(input);
	
	char *token = strtok(input, " ");

    while (token != NULL)
	{
		for (i = 0; i < strlen(token); i++)
		{
			char temp = i == 0 ? token[i] : temp;
			
			token[i] = i > 0 && i == strlen(token) - 1 ? temp : token[i + 1];
		}
        printf("%s%say", status == 0 ? "" : " ", token);
        
        token = strtok(NULL, " "); status++;
    }
    printf("\n");
}

void reverse()
{
	char input[100]; gets(input);
	
	char *token = strtok(input, " ");
	
	int status = 0;

    while (token != NULL)
	{
        printf("%s%s", status == 0 ? "" : " ", strrev(token));
        
        token = strtok(NULL, " "); status++;
    }
    printf("\n");
}

void nospace()
{
	char input[100], i; gets(input);

	const char* pointer = input;
	
	char* string = (char*)malloc(sizeof(char) * strlen(pointer));

	strncpy(string, pointer, strlen(pointer));
  
	int index = 0;
 
    for (i = 0; string[i] != '\0'; i++)
    {
        if (string[i] != ' ')
        {
            string[index] = pointer[i];
            
			index++;
        }
    }
    string[index] = '\0';
    
    printf("%s", string);
}

void squares()
{
	int edge, limit, column, loop; printf("INPUT: "); scanf("%d", &edge);
	
	while (limit++ < edge)
	{
		printf("\n%02d. ", limit);
		
		for (column = edge; column >= limit; column--)
		{
			for (loop = column; loop > 0; loop--) { printf("#"); } printf(" ");
		}
		printf("\n");
	}
}

void windows()
{
	int input, a, b; scanf("%d", &input);
	
	if (input % 2 == 0)
	{
		for (a = 1; a <= input; a++)
		{
			for (b = 1; b <= input; b++)
			{
				if (a == 1 || a == input || b == a || b == input - a + 1) { printf("#"); }
				
				else { printf(" "); }
			}
			printf("\n");
		} 
	}
	else
	{
		for (a = 1; a <= input; a++)
		{
			for (b = 1; b <= input; b++)
			{
				if (a == 1 || a == input || a == (input + 1) / 2 || b == 1 || b == input || b == (input + 1) / 2) { printf("#"); }
				
				else { printf(" "); }
			}
			printf("\n");
		}
	}
}

void rot13()
{
	char encdec[101]; int i; gets(encdec);
	
	for (i = 0; i < strlen(encdec); i++)
	{
		encdec[i] = isalpha(encdec[i]) == 1 ? encdec[i] > 'N' ? encdec[i] - 13 : encdec[i] + 13 :
					
					isalpha(encdec[i]) == 2 ? encdec[i] > 'n' ? encdec[i] - 13 : encdec[i] + 13 :
					
					encdec[i];
	}
	printf("%s\n", encdec);
}

void pascaltriangle()
{
	int input = 0, line = 0; scanf("%d", &input);

	while (line++ <= input)
	{
	    int C = 1, number = 0;
	    
	    while (number++ < line)
	    {
		    printf("%4lld ", C); C = C * (line - number) / number;
    	}
    	printf("\n");
	}
}

void glitch()
{
	int edge, i, column, loop; scanf("%d", &edge);
	
	for (i = 0; i < edge; i++)
	{
		int limit = i;
		
		while (limit++ < edge)
		{
			for (column = edge; column > 0; column--)
			{
				for (loop = column; loop > 0; loop--) { printf("|"); }
				
				printf(" ");
			}
			printf("\n");
		}
		printf("\n");
	}
}

void trimmed()
{
	int i, j;

	char input[101]; gets(input); int length = strlen(input);
	
	for (i = 0; i <= length / 2; i++)
	{
		for (j = 0; j < length; j++)
		{
			printf("%c", j >= i && j <= length - 1 - i ? ' ' : input[j]);
		}
		printf("\n");
	}
}

void diamond()
{
	int input, a, b; scanf("%d", &input);
	
	for (a = 1; a < 2 * input; a++)
	{
		for (b = 1; b < 2 * input; b++)
		{
            int value = 2 * input - abs(input - b) - abs(input - a) - 1;

			if (value <= input) printf("%s%02d", b == 1 ? "" : " ", value);

            else printf("   ");
		}
		printf("\n");
	}
}

void christmas()
{
	int input, temp, column, row = 0, set = 1; scanf("%d", &input);

	while (row++ < input * input)
	{
		printf("  "); temp = row % input == 0 ? input : row % input;

		for (column = 1; column <= 4 * input - 3; column++)
		{
			printf((row <= set * input && (column > 2 * input - temp - set && column < 2 * input + temp + set - 2)) ? "*" : " ");
		}
		printf("\n"); set += row % input == 0 ? 1 : 0;
	}
}

void timer()
{
	int input = -1, status = 0, a;
	
	SetConsoleTitle("Timer by Jacky Setiawan PPTI 16");
	
	HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE), rHnd = GetStdHandle(STD_INPUT_HANDLE);
	
	SMALL_RECT windowSize = { 0, 0, 154, 23 };
	
    SetConsoleWindowInfo(wHnd, 1, &windowSize);
    
	COORD bufferSize = { 10, 10 };
    
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	
	const char *zero[16];
	zero[0] =  "####################";
	zero[1] =  "####################";
	zero[2] =  "####################";
	zero[3] =  "#####          #####";
	zero[4] =  "#####          #####";
	zero[5] =  "#####          #####";
	zero[6] =  "#####          #####";
	zero[7] =  "#####          #####";
	zero[8] =  "#####          #####";
	zero[9] =  "#####          #####";
	zero[10] = "#####          #####";
	zero[11] = "#####          #####";
	zero[12] = "#####          #####";
	zero[13] = "####################";
	zero[14] = "####################";
	zero[15] = "####################";
	
	const char *one[16];
	one[0] =  "               #####";
	one[1] =  "               #####";
	one[2] =  "               #####";
	one[3] =  "               #####";
	one[4] =  "               #####";
	one[5] =  "               #####";
	one[6] =  "               #####";
	one[7] =  "               #####";
	one[8] =  "               #####";
	one[9] =  "               #####";
	one[10] = "               #####";
	one[11] = "               #####";
	one[12] = "               #####";
	one[13] = "               #####";
	one[14] = "               #####";
	one[15] = "               #####";
	
	const char *two[16];
	two[0] =  "####################";
	two[1] =  "####################";
	two[2] =  "####################";
	two[3] =  "               #####";
	two[4] =  "               #####";
	two[5] =  "               #####";
	two[6] =  "####################";
	two[7] =  "####################";
	two[8] =  "####################";
	two[9] =  "####################";
	two[10] = "#####               ";
	two[11] = "#####               ";
	two[12] = "#####               ";
	two[13] = "####################";
	two[14] = "####################";
	two[15] = "####################";
	
	const char *three[16];
	three[0] =  "####################";
	three[1] =  "####################";
	three[2] =  "####################";
	three[3] =  "               #####";
	three[4] =  "               #####";
	three[5] =  "               #####";
	three[6] =  "####################";
	three[7] =  "####################";
	three[8] =  "####################";
	three[9] =  "####################";
	three[10] = "               #####";
	three[11] = "               #####";
	three[12] = "               #####";
	three[13] = "####################";
	three[14] = "####################";
	three[15] = "####################";
	
	const char *four[16];
	four[0] =  "#####          #####";
	four[1] =  "#####          #####";
	four[2] =  "#####          #####";
	four[3] =  "#####          #####";
	four[4] =  "#####          #####";
	four[5] =  "#####          #####";
	four[6] =  "####################";
	four[7] =  "####################";
	four[8] =  "####################";
	four[9] =  "####################";
	four[10] = "               #####";
	four[11] = "               #####";
	four[12] = "               #####";
	four[13] = "               #####";
	four[14] = "               #####";
	four[15] = "               #####";
	
	const char *five[16];
	five[0] =  "####################";
	five[1] =  "####################";
	five[2] =  "####################";
	five[3] =  "#####               ";
	five[4] =  "#####               ";
	five[5] =  "#####               ";
	five[6] =  "####################";
	five[7] =  "####################";
	five[8] =  "####################";
	five[9] =  "####################";
	five[10] = "               #####";
	five[11] = "               #####";
	five[12] = "               #####";
	five[13] = "####################";
	five[14] = "####################";
	five[15] = "####################";
	
	const char *six[16];
	six[0] =  "####################";
	six[1] =  "####################";
	six[2] =  "####################";
	six[3] =  "#####               ";
	six[4] =  "#####               ";
	six[5] =  "#####               ";
	six[6] =  "####################";
	six[7] =  "####################";
	six[8] =  "####################";
	six[9] =  "####################";
	six[10] = "#####          #####";
	six[11] = "#####          #####";
	six[12] = "#####          #####";
	six[13] = "####################";
	six[14] = "####################";
	six[15] = "####################";
	
	const char *seven[16];
	seven[0] =  "####################";
	seven[1] =  "####################";
	seven[2] =  "####################";
	seven[3] =  "               #####";
	seven[4] =  "               #####";
	seven[5] =  "               #####";
	seven[6] =  "               #####";
	seven[7] =  "               #####";
	seven[8] =  "               #####";
	seven[9] =  "               #####";
	seven[10] = "               #####";
	seven[11] = "               #####";
	seven[12] = "               #####";
	seven[13] = "               #####";
	seven[14] = "               #####";
	seven[15] = "               #####";
	
	const char *eight[16];
	eight[0] =  "####################";
	eight[1] =  "####################";
	eight[2] =  "####################";
	eight[3] =  "#####          #####";
	eight[4] =  "#####          #####";
	eight[5] =  "#####          #####";
	eight[6] =  "####################";
	eight[7] =  "####################";
	eight[8] =  "####################";
	eight[9] =  "####################";
	eight[10] = "#####          #####";
	eight[11] = "#####          #####";
	eight[12] = "#####          #####";
	eight[13] = "####################";
	eight[14] = "####################";
	eight[15] = "####################";
	
	const char *nine[16];
	nine[0] =  "####################";
	nine[1] =  "####################";
	nine[2] =  "####################";
	nine[3] =  "#####          #####";
	nine[4] =  "#####          #####";
	nine[5] =  "#####          #####";
	nine[6] =  "####################";
	nine[7] =  "####################";
	nine[8] =  "####################";
	nine[9] =  "####################";
	nine[10] = "               #####";
	nine[11] = "               #####";
	nine[12] = "               #####";
	nine[13] = "####################";
	nine[14] = "####################";
	nine[15] = "####################";
	
	const char *separator[16];
	separator[0] =  "          ";
	separator[1] =  "          ";
	separator[2] =  "          ";
	separator[3] =  "  ######  ";
	separator[4] =  "  ######  ";
	separator[5] =  "  ######  ";
	separator[6] =  "          ";
	separator[7] =  "          ";
	separator[8] =  "          ";
	separator[9] =  "          ";
	separator[10] = "  ######  ";
	separator[11] = "  ######  ";
	separator[12] = "  ######  ";
	separator[13] = "          ";
	separator[14] = "          ";
	separator[15] = "          ";
	
	scanf("%d", &input);
	
	do
	{
		system("cls"); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
		
		if (input < 0) { scanf("%d", &input); }
		
		else if (input == 0 && status == 1)
		{
			printf("Mau reset?"); char reset = getchar();
			
			if (reset == 'Y' || reset == 'y') { status = 0; input = -1; } else if (reset == 'N' || reset == 'n') { break; }
		}
		else
		{
			printf("\n   Time remaining: %02d:%02d:%02d", input / 3600, (input % 3600) / 60, input % 60);
			
			if (input / 3600 == 0 && (input % 3600) / 60 == 0 && input % 60 <= 10) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			
			printf("\n\n\n\n\n");
			
			for (int a = 0; a < 16; a++)
			{
				int tenths = (input / 3600) / 10, digits = (input / 3600) % 10;
				
				printf("   %s   %s", tenths == 0 ? zero[a] : tenths == 1 ? one[a] : tenths == 2 ? two[a] : tenths == 3 ? three[a] : tenths == 4 ? four[a] :
									 tenths == 5 ? five[a] : tenths == 6 ? six[a] : tenths == 7 ? seven[a] : tenths == 8 ? eight[a] : nine[a]
								   , digits == 0 ? zero[a] : digits == 1 ? one[a] : digits == 2 ? two[a] : digits == 3 ? three[a] : digits == 4 ? four[a] :
									 digits == 5 ? five[a] : digits == 6 ? six[a] : digits == 7 ? seven[a] : digits == 8 ? eight[a] : nine[a]);
				
				printf("%s", separator[a]);
				
				tenths = ((input % 3600) / 60) / 10; digits = ((input % 3600) / 60) % 10;
				
				printf("%s   %s", tenths == 0 ? zero[a] : tenths == 1 ? one[a] : tenths == 2 ? two[a] : tenths == 3 ? three[a] : tenths == 4 ? four[a] :
									 tenths == 5 ? five[a] : tenths == 6 ? six[a] : tenths == 7 ? seven[a] : tenths == 8 ? eight[a] : nine[a]
								   , digits == 0 ? zero[a] : digits == 1 ? one[a] : digits == 2 ? two[a] : digits == 3 ? three[a] : digits == 4 ? four[a] :
									 digits == 5 ? five[a] : digits == 6 ? six[a] : digits == 7 ? seven[a] : digits == 8 ? eight[a] : nine[a]);
				
				printf("%s", separator[a]);
				
				tenths = (input % 60) / 10; digits = (input % 60) % 10;
				
				printf("%s   %s\n", tenths == 0 ? zero[a] : tenths == 1 ? one[a] : tenths == 2 ? two[a] : tenths == 3 ? three[a] : tenths == 4 ? four[a] :
									   tenths == 5 ? five[a] : tenths == 6 ? six[a] : tenths == 7 ? seven[a] : tenths == 8 ? eight[a] : nine[a]
								     , digits == 0 ? zero[a] : digits == 1 ? one[a] : digits == 2 ? two[a] : digits == 3 ? three[a] : digits == 4 ? four[a] :
									   digits == 5 ? five[a] : digits == 6 ? six[a] : digits == 7 ? seven[a] : digits == 8 ? eight[a] : nine[a]);
			}
			Sleep(1000); input--; status = 1;
		}
	}
	while (1);
}