#include<stdio.h>
#include<string.h>

void ffit(int blk[], int proc[], int nb, int np) {
	int allc[np];
	for (int i = 0; i < np; i++){
		allc[i] = -1;
		for (int j = 0; j < nb; j++)
			if (proc[i]  <= blk[j]) {
				blk[j] -= proc[i];
				allc[i] = j;
				break;
			}
	}
	
	printf("-1: Not Allocated...\n");
	printf("%5s%8s%10s\n", "PNo.", "P Size", "Block No.");
	for (int i = 0; i < np; i++) {
			printf("%5d%8d%10d\n", i+1, proc[i], allc[i]);
	}
}


void bfit(int blk[], int proc[], int nb, int np) {
	int allc[np];
	for (int i = 0; i < np; i++) {
		allc[i] = -1;
		for (int j = 0; j < nb; j++) {
			if (allc[i] == -1){
				if (proc[i] <= blk[j])
					allc[i] = j;
			}
			else if (proc[i] <= blk[j] && blk[j] < blk[allc[i]])
				allc[i] = j;
		}
		if (allc[i] != -1) {
			blk[allc[i]] -= proc[i];
		}
	}
	printf("-1: Not Allocated...\n");
	printf("%5s%8s%10s\n", "PNo.", "P Size", "Block No.");
	for (int i = 0; i < np; i++) {
			printf("%5d%8d%10d\n", i+1, proc[i], allc[i]);
	}
}


int main() {
	int nb, np, ch;
	printf("Enter No. of blocks and No. of processes: ");
	scanf("%d %d", &nb, &np);
	int blk[nb], proc[np];
	for (int i = 0; i < nb; i++) {
		printf("Enter size of block %d: ", i);
		scanf("%d", &blk[i]);
	}
	printf("###\n");
	for (int i = 0; i < np; i++) {
		printf("Enter size of Process %d: ", i+1);
		scanf("%d", &proc[i]);
	}
	int blk_cpy[nb];
	memcpy(blk_cpy,blk,sizeof(int)*nb);
	printf("\nImplementing First Fit...\n\n");
	ffit(blk_cpy, proc, nb, np);
	printf("\nImplementing Best Fit...\n\n");
	bfit(blk_cpy, proc, nb, np);
}


/*

Enter No. of blocks and No. of processes: 4 5
Enter size of block 0: 200
Enter size of block 1: 350
Enter size of block 2: 140
Enter size of block 3: 230
###
Enter size of Process 1: 130
Enter size of Process 2: 100
Enter size of Process 3: 90
Enter size of Process 4: 400
Enter size of Process 5: 200

Implementing First Fit...

-1: Not Allocated...
 PNo.  P Size Block No.
    1       5         0
    2     100         0
    3      90         0
    4     400        -1
    5     200         1

Implementing Best Fit...

-1: Not Allocated...
 PNo.  P Size Block No.
    1       5         0
    2     100         2
    3      90         1
    4     400        -1
    5     200         3

*/
