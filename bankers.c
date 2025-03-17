#include<stdio.h>
#include<stdlib.h>


struct process {
	int pid;
	int alloc[10];
	int max[10];
	int need[10];
	int exec;
} proc[10];

int main() {
	int prn, resn;
	printf("Enter No. of processes and No. of Resources: ");
	scanf("%d %d", &prn, &resn);
	for (int i = 0; i < prn; i++) {
		proc[i].pid = i; 
		proc[i].exec = 0;
		printf("\nAllocation of P%d\n", i);
		for (int j = 0; j < resn; j++) {
			printf("Allocated R%d: ", j+1);
			scanf("%d", &proc[i].alloc[j]);
			printf("Max Need R%d: ", j+1);
			scanf("%d", &proc[i].max[j]);
			proc[i].need[j] = proc[i].max[j] - proc[i].alloc[j];
		}
	}
	
	int avail[resn];
	printf("Enter Current availability\n");
	for (int i = 0; i < resn; i++) {
		printf("R%d: ", i+1);
		scanf("%d", &avail[i]);
	}
	
	int match = 0, sec = 0, dl, comp;
	int seq[prn];
	while (1) {
		comp = 1;
		dl = 1;
		for (int i = 0; i < prn; i++) {
			int res_avl = 1;
			for (int j = 0; j < resn; j++) {
				if (proc[i].need[j] > avail[j] || proc[i].exec) {
					res_avl = 0;
					break;
				}
			}
			if (res_avl) {
				for (int j = 0; j < resn; j++) 
					avail[j] += proc[i].alloc[j];
				proc[i].exec = 1;
				seq[sec++] = i;
			}
			if (!proc[i].exec) {comp = 0;}
			else {dl = 0;}
		}
		if (comp || dl) {break;}
	}
	
	if (dl)
		printf("Dead Lock!!!\n");
	else {
		printf("Safe Sequence: ");
		for (int i = 0; i < prn; i++)
			printf("P%d -> ", seq[i]);
		printf("halt\n");
	}
	
	return 0;
}
