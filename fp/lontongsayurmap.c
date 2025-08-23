#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    double x, y;
    double w, h;
} Entity;

typedef struct
{
    double x, y;
} Vector2;

bool dalamArea(Entity area, Vector2 titik) {
    return area.x + area.w/2 >= titik.x && area.x - area.w/2 <= titik.x &&
    area.y + area.h/2 >= titik.y && area.y - area.y/2 <= titik.y;
}

float jarak2Titik(Vector2 a, Vector2 b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main()
{
    double mapSizeX, mapSizeY;
    scanf("%lf %lf", &mapSizeX, &mapSizeY);

    Entity rm, larangan;
    Vector2 lifraf;
    scanf("%lf %lf %lf %lf", &rm.x, &rm.y, &rm.w, &rm.h);
    scanf("%lf %lf %lf %lf", &larangan.x, &larangan.y, &larangan.w, &larangan.h);
    scanf("%lf %lf", &lifraf.x, &lifraf.y);

    if (dalamArea(rm, lifraf)) {
        printf("KAMU SUDAH SAMPAI\n");
    } else if (dalamArea(larangan, lifraf)) {
        printf("KAMU TERHALANG\n");
    } else {
        Vector2 maumakan = {rm.x, rm.y};
        float jarak = jarak2Titik(lifraf, maumakan);
        printf("%.2f METER LAGI\n", jarak);
    }

    return 0;
}