#include<stdio.h>
#include<stdlib.h>
#include "knapsack.h"

int main(void)
{
	int op, itm, del; // Declaring variables.

	listitemptr k1 = NULL; // Pointer variable k1 to NULL.
	listitemptr k2 = NULL; // Pointer variable k2 to NULL.

	do
	{
		printf("Select an option.\n"); fflush(stdout);
		printf("1. Add item to k1.\n"); fflush(stdout);
		printf("2. Remove item from k1.\n"); fflush(stdout);
		printf("3. Print items from k1.\n"); fflush(stdout);
		printf("4. Count the number of specific item from k1.\n"); fflush(stdout);
		printf("5. Size of k1.\n"); fflush(stdout);
		printf("6. Add item to k2.\n"); fflush(stdout);
		printf("7. Remove item from k2.\n"); fflush(stdout);
		printf("8. Print items from k2.\n"); fflush(stdout);
		printf("9. Count the number of specific item from k2.\n"); fflush(stdout);
		printf("10. Size of k2.\n"); fflush(stdout);
		printf("11. Exit.\n"); fflush(stdout);

		scanf("%d", &op); // Select an option.
		printf("\n"); fflush(stdout);

		if(op == 1)
		{
			printf("Put the item on k1.\n"); fflush(stdout);
			scanf("%d", &itm);
			k1 = KnapsackAdd(k1, itm);
			printf("\n"); fflush(stdout);
		}

		if(op == 2)
		{
			printf("Remove the item in k1.\n"); fflush(stdout);
			scanf("%d", &itm);
			k1 = KnapsackRemove(k1, itm);
			printf("\n"); fflush(stdout);	
		}

		if(op == 3)
		{
			printf("k1's items and count.\n"); fflush(stdout);
			KnapsackPrint(k1);
			printf("\n"); fflush(stdout);
		}

		if(op == 4)
		{
			printf("Enter the item for finding count.\n"); fflush(stdout);
			scanf("%d", &itm);
			printf("Count: %d\n", KnapsackItemCount(k1, itm)); fflush(stdout);
			printf("\n"); fflush(stdout);
		}

		if(op == 5)
		{
			printf("Size of k1: %d\n", KnapsackSize(k1)); fflush(stdout);
			printf("\n"); fflush(stdout);
		}

		if(op == 6)
		{
			printf("Put the item on k2.\n"); fflush(stdout);
			scanf("%d", &itm);
			k2 = KnapsackAdd(k2, itm);
			printf("\n"); fflush(stdout);
		}

		if(op == 7)
		{
			printf("Remove the item in k2.\n"); fflush(stdout);
			scanf("%d", &itm);
			k2 = KnapsackRemove(k2, itm);
			printf("\n"); fflush(stdout);
		}

		if(op == 8)
		{
			printf("k2's items and count.\n"); fflush(stdout);
			KnapsackPrint(k2);
			printf("\n"); fflush(stdout);
		}

		if(op == 9)
		{
			printf("Enter the item for finding count.\n"); fflush(stdout);
			scanf("%d", &itm);
			printf("Count: %d\n", KnapsackItemCount(k1, itm)); fflush(stdout);
			printf("\n"); fflush(stdout);
			printf("\n"); fflush(stdout);
		}

		if(op == 10)
		{
			printf("Size of k2: %d\n", KnapsackSize(k2)); fflush(stdout);
			printf("\n"); fflush(stdout);
		}
	
	}while(op != 11);

	return 0;
}