#include<stdio.h>

int main() {
	int n, w;
	printf("Enter length of reference string: ");
	scanf("%d", &n);
	int rf[n];
	printf("Enter reference String: ");
	for (int i = 0; i < n; i++)
		scanf("%d", &rf[i]);
	
	printf("Enter page width: ");
	scanf("%d", &w);
	int pg[w];
	
	printf("\n###Implementing Optimal Page Replacement...\n\n");
    printf("Access => Page In Memory ---> Fault/Hit\n");
    int hc = 0, fc = 0;
	for (int i = 0; i < w; i++)
		pg[i] = -1;
	
	for (int i = 0; i < n; i++) {
		int hit = 0;
		for (int j = 0; j < w; j++) {
			if (rf[i] == pg[j]) {
				hit = 1;
				break;
			}
		}
		if (!hit) {
			int occ[w], max = 0;
			for (int j = 0; j < w; j++)
				occ[j] = n;
			for (int j = 0; j < w; j++){
				for (int k = i; k < n; k++) 
					if (rf[k] == pg[j]){
						occ[j] = k;
						break;
					}
				if (occ[j] > occ[max])
					max = j;
			}
			for (int j = 0; j < w; j++) {
				if (pg[j] == -1) {
					max = j;
					break;
				}
			}
			pg[max] = rf[i];
		}
		
		printf("%d      => ", rf[i]);
        for (int j = 0; j < w; j++){
            if (pg[j] == -1)
                printf("* ");
            else
                printf("%d ", pg[j]);
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
