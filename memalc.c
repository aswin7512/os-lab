#include<stdio.h>

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
	printf("###\nChoices...\n\
	0. Exit\n\
	1. First fit\n\
	2. Best fit\n\
	Enter your choice: ");
	scanf("%d", &ch);
	while (1) {
		switch (ch){
			case 0: printf("Exiting...\n");
				return 0;
			
			case 1: printf("Implementing First Fit...\n");
				ffit(blk, proc, nb, np);
				break;
			
			case 2: printf("Implementing Best Fit...\n");
				bfit(blk, proc, nb, np);
				break;
			
			default: printf("Please Enter a valid choice...\n");
		}
	}
}
