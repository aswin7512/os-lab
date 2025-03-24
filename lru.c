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
    printf("\nPage Fault: %d\n", fc);
	printf("Page Hit: %d\n", hc);
    return 0;
}




/*

Enter Length of reference string: 10
Enter reference string: 1 5 3 8 5 9 8 4 2 0
Enter frame width: 3

###Implementing LRU...

Access => Page In Memory ---> Fault/Hit
1      => 1 * *          ---> Fault 1
5      => 1 5 *          ---> Fault 2
3      => 1 5 3          ---> Fault 3
8      => 8 5 3          ---> Fault 4
5      => 8 5 3          ---> Hit 1
9      => 8 5 9          ---> Fault 5
8      => 8 5 9          ---> Hit 2
4      => 8 4 9          ---> Fault 6
2      => 8 4 2          ---> Fault 7
0      => 0 4 2          ---> Fault 8

Page Fault: 8
Page Hit: 2

*/
