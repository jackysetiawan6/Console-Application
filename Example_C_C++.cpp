#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

int DP[1000000] = {};
int DP_2D[1000][1000] = {};

void soal_01()
{
    char input[100] = ""; scanf("%[^\n]", input);
    int length = strlen(input);
    for (int i = 0; i < length; i++)
    {
        if (input[i] >= 'a') input[i] -= 32;
        else if (input[i] >= 'A') input[i] += 32;
    }
    printf("%s\n", input);
    return;
}

void soal_02()
{
    int number = 0, kesabaran = 0, input[1010] = {}, sum = 0, count = 0;
    scanf("%d %d", &number, &kesabaran);
    for (int i = 0; i < number; i++)
    {
        scanf("%d", &input[i]);
        sum += input[i];
    }
    int durasi = (int)(sum / number * kesabaran / 100);
    for (int i = 0; i < number; i++)
    {
        if (input[i] > durasi)
        {
            printf("%s", count == 0 ? "" : " ");
            printf("%d", i + 1);
            count++;
        }
    }
    if (count == 0) printf("0");
    return;
}

void soal_03()
{
    int apel = 0, jeruk = 0, nanas = 0;
    scanf("%d %d %d", &apel, &jeruk, &nanas);
    int harga_apel = apel * 5000;
    int harga_jeruk = jeruk * 6000;
    int harga_nanas = nanas * 7000;
    if (harga_apel > harga_jeruk && harga_apel > harga_nanas) printf("%d Apel\n", harga_apel);
    else if (harga_jeruk > harga_apel && harga_jeruk > harga_nanas) printf("%d Jeruk\n", harga_jeruk);
    else if (harga_nanas > harga_apel && harga_nanas > harga_jeruk) printf("%d Nanas\n", harga_nanas);
    else printf("Cancel\n");
    return;
}

void soal_04()
{
	char input[100] = ""; scanf("%[^\n]", input);
    int length = strlen(input);
    int i = 0, j = 0;
    while (i < length)
    {
        j = i;
        while (j < length && input[j] != ' ') j++;
        for (int k = i; k < (i + j) / 2; k++)
        {
            char temp = input[k];
            input[k] = input[i + j - k - 1];
            input[i + j - k - 1] = temp;
        }
        i = j + 1;
    }
    printf("%s\n", input);
    return;
}

void soal_05()
{
    int ban = 0, pintu = 0, kaca = 0;
    scanf("%d %d %d", &ban, &pintu, &kaca);
    int min_ban = 4, min_pintu = 2, min_kaca = 1;
    int number_ban = ceil((double)ban / min_ban);
    int number_pintu = ceil((double)pintu / min_pintu);
    int number_kaca = ceil((double)kaca / min_kaca);
    int number = max(number_ban, max(number_pintu, number_kaca));
    int required_ban = number * min_ban - ban;
    int required_pintu = number * min_pintu - pintu;
    int required_kaca = number * min_kaca - kaca;
    printf("%d %d %d %d\n", number, required_ban, required_pintu, required_kaca);
    return;
}

int main(int argc, char *argv[])
{
    soal_04();
    return 0;
}