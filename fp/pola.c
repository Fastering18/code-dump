#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main() {
    int N, K;
    long long arr[100005];
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
    }
    scanf("%d", &K);

    bool isArit = true, isGeo = true;

    // Cek aritmetika
    long long d = arr[1] - arr[0];
    for (int i = 1; i < N; i++) {
        if (arr[i] - arr[i-1] != d) {
            isArit = false;
            break;
        }
    }

    // Cek geometri
    long long r = 0;
    if (arr[0] != 0) {
        r = arr[1] / arr[0];
        for (int i = 1; i < N; i++) {
            if (arr[i-1] == 0 || arr[i] != arr[i-1] * r) {
                isGeo = false;
                break;
            }
        }
    } else {
        isGeo = false;
    }

    if (isArit) {
        long long result = arr[0] + (long long)(K-1) * d;
        printf("Aritmetika\n%lld\n", result);
    } else if (isGeo) {
        long long result = arr[0];
        for (int i = 1; i < K; i++) {
            result *= r;
        }
        printf("Geometri\n%lld\n", result);
    } else {
        printf("Pola aneh! Pak Fufu ga jelas!\n");
    }

    return 0;
}