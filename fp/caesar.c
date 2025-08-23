#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define max(a, b) \
    ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

#define START_KECIL 97
#define START_BESAR 65
#define JUMLAH_CHAR 26

char kecilkan(char x)
{
    if (x >= 97)
    {
        return x;
    }
    else
    {
        return x + (START_KECIL - START_BESAR);
    }
}

char besarkan(char x)
{
    if (x >= 97)
    {
        return x - (START_BESAR - START_KECIL);
    }
    else
    {
        return x;
    }
}

int urutan(char x)
{
    if (x >= 97)
    {
        return x - START_KECIL;
    }
    else
    {
        return x - START_BESAR;
    }
}

char deciper_k(char x, int k)
{
    if (x > START_KECIL + JUMLAH_CHAR || x < START_BESAR)
    {
        return x;
    }

    int urut = urutan(x);
    char target = (urut + k) % JUMLAH_CHAR;
    if (target < 0)
    {
        target += START_BESAR + JUMLAH_CHAR;
    }
    else
    {
        target += START_BESAR;
    }

    if (x >= 97)
    {
        // printf("target: %d %d\n", (int)target, (int)kecilkan(target));
        return kecilkan(target);
    }
    else
    {
        return target;
    }
}

int main()
{
    int k;
    scanf("%d", &k);
    k %= JUMLAH_CHAR;

    getchar();

    char str[100001];
    if (fgets(str, sizeof(str), stdin) != NULL)
    {
        str[strcspn(str, "\n")] = 0;
    }

    for (int i = 0; i < strlen(str); i++)
    {
        printf("%c", deciper_k(str[i], k));
    }
    printf("\n");

    return 0;
}