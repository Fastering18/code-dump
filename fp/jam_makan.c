#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_TIME 780

int main()
{
    int h, m, dur;
    scanf("%d %d %d", &h, &m, &dur);

    int jumlahMenit = h * 60 + m + dur;
    // printf("inp %d %d %d, menit %d\n", h,m,dur,jumlahMenit);
    if (jumlahMenit <= MAX_TIME)
    {
        printf("MASIH WAKTU\n");
    }
    else
    {
        printf("LEWAT WAKTU\n");
    }

    return 0;
}