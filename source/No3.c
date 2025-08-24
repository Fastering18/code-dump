// Tebak Pola Pak Fufu

#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    
    long long arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    
    int k;
    scanf("%d", &k);
    
    // aritmatika
    int is_arithmetic = 1;
    long long diff = arr[1] - arr[0];
    
    for(int i = 2; i < n; i++) {
        if(arr[i] - arr[i-1] != diff) {
            is_arithmetic = 0;
            break;
        }
    }
    
    if(is_arithmetic) {
        printf("Aritmetika\n");
        long long kth_term = arr[0] + (k - 1) * diff;
        printf("%lld\n", kth_term);
        return 0;
    }
    
    // geometri
    int is_geometric = 1;

    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) {
            is_geometric = 0;
            break;
        }
    }
    
    if(is_geometric) {
        double ratio = (double)arr[1] / arr[0];
        
        for(int i = 2; i < n; i++) {
            double current_ratio = (double)arr[i] / arr[i-1];
            if(fabs(current_ratio - ratio) > 1e-9) {
                is_geometric = 0;
                break;
            }
        }
        
        if(is_geometric) {
            printf("Geometri\n");
            long long kth_term = arr[0];
            for(int i = 1; i < k; i++) {
                kth_term = (long long)(kth_term * ratio);
            }
            printf("%lld\n", kth_term);
            return 0;
        }
    }
    
    // pola aneh
    printf("Pola aneh! Pak Fufu ga jelas!\n");
    
    return 0;
}