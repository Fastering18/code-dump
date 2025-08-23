#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int sum = 0;
    while (n > 0)
    {
        int botol = 0;
        scanf("%d", &botol);
        sum += botol;
        n--;
    }

    if (sum == 1000)
    {
        printf("Nahh pas nihh, tinggal minum deh\n");
    }
    else if (sum > 1000)
    {
        printf("Yahh tumpah, jadi mubazir deh\n");
    }
    else if (sum < 1000)
    {
        printf("Masih belum penuh ini mahh, tuang lagi dong\n");
    }

    return 0;
}
