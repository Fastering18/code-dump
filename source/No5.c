// Kaisar Chip

#include <stdio.h>
#include <string.h>

#define START_KECIL 97
#define START_BESAR 65
#define JUMLAH_CHAR 26

char hurufKecil(char x)
{
    if (x >= START_KECIL)
    {
        return x;
    }
    else
    {
        return x + (START_KECIL - START_BESAR);
    }
}

int urutanChar(char x)
{
    if (x >= START_KECIL)
    {
        return x - START_KECIL;
    }
    else
    {
        return x - START_BESAR;
    }
}

char deciperKarakter(char x, int k)
{
    if (x > START_KECIL + JUMLAH_CHAR || x < START_BESAR)
    {
        return x;
    }

    int urut = urutanChar(x);
    char target = (urut + k) % JUMLAH_CHAR;
    if (target < 0)
    {
        target += START_BESAR + JUMLAH_CHAR;
    }
    else
    {
        target += START_BESAR;
    }

    if (x >= START_KECIL && x <= START_KECIL+JUMLAH_CHAR)
    {
        return hurufKecil(target);
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

    // skip newline
    getchar();

    char str[100001];
    if (fgets(str, sizeof(str), stdin) != NULL)
    {
        str[strcspn(str, "\n")] = 0;
    }

    for (int i = 0; i < strlen(str); i++)
    {
        printf("%c", deciperKarakter(str[i], k));
    }
    printf("\n");

    return 0;
}