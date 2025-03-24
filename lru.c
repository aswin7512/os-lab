// LRU
#include<stdio.h>

int main() {
    int n, w;
    printf("Enter Length of reference string: ");
    scanf("%d", &n);

    int rs[n];
    printf("Enter reference string: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &rs[i]);
    
    printf("Enter frame width: ");
    scanf("%d", &w);

    int f[w], lat[w];
    int hc = 0, fc = 0;
    for (int i = 0; i < w; i++){
        f[i] = -1;
        lat[i] = 0;
    }
    
    printf("\n###Implementing LRU...\n\n");
    printf("Access => Page In Memory ---> Fault/Hit\n");
    for (int i = 0; i < n; i++) {
        int hit = 0;
        for (int j = 0; j < w; j++)
            if (rs[i] == f[j]) {
                hit = 1;
                lat[j] = i+1;
                break;
            }
        if (!hit) {
            int min = 0;
            for (int j = 0; j < w; j++) 
                if (lat[j] < lat[min])
                    min = j;
            f[min] = rs[i];
            lat[min] = i+1;
        }

        
        printf("%d      => ", rs[i]);
        for (int j = 0; j < w; j++){
            if (f[j] == -1)
                printf("* ");
            else
                printf("%d ", f[j]);
        }
        if (hit)
            printf("         ---> Hit %d\n", ++hc);
        else
            printf("         ---> Fault %d\n", ++fc);
    }
    return 0;
}