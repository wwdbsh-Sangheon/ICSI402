#include<stdio.h>
#include<stdlib.h>
#include "knapsack.h"

listitemptr cur = NULL; // Global pointer variable for current node
listitemptr new_item = NULL; // Global pointer variable for new node.

listitemptr KnapsackAdd(listitemptr knapsack, int item)
{
	int i = 0; // Initializing counter value.

	new_item = (listitemptr)malloc(sizeof(struct listitem)); // Allocating memory.
	new_item->next = NULL; // Initializing pointer.

	if(new_item == NULL) // Case: failed memory allocation.
	{
		return NULL; // Return NULL.
	}

	if(knapsack == NULL) // Case: Knapsack is NULL.
	{
		new_item->item = item;
		new_item->count = 1;
		knapsack = new_item; // Storing values.
		cur = knapsack;

		printf("Item is stored.\n");
		fflush(stdout);
	}
	else
	{
		for(cur = knapsack; cur != NULL; cur = cur->next) // Loop for updating count.
		{
			if(cur->item == item) // Case: Current node's item is same as new item.
			{
				cur->count += 1; // Increasing count by adding 1.
				i++; // Increasing i by adding 1.

				printf("Item is stored.\n");
				fflush(stdout);
			}
		}

		if(i == 0) // Case: i is 0.
		{
			new_item->item = item;
			new_item->count = 1;

			for(cur = knapsack; cur != NULL; cur = cur->next) // Loop for making current node move to last position.
			{
				if(cur->next == NULL) // Case: Current node's next node is NULL.
					break;
			}

			new_item->next = cur->next;
			cur->next = new_item; // Storing values.

			printf("Item is stored.\n");
			fflush(stdout);
		}
	}

	return knapsack; // Return pointer value.
}

listitemptr KnapsackRemove(listitemptr knapsack, int item)
{
	int i = 0; // Initializing counter value.

 	listitemptr del = (listitemptr)malloc(sizeof(struct listitem)); // Pointer variable for deleting node.
 	listitemptr *head = &knapsack; // Pointer variable for deleting first node in linked list.
	listitemptr cur2; // Pointer variable for deleting first node in linked list.

	if(knapsack == NULL) // Case: knapsack is NULL.
	{
		printf("No items in your knapsack.\n");
		fflush(stdout);
	}
	else 
	{
		for(cur = knapsack; cur != NULL; cur = cur->next) // Loop for handling count.
		{
			if(cur->item == item && cur->count > 1)
			{
				cur->count -= 1; // Decreasing node's count by subtracting 1.
				i++; // Increasing i by adding 1.
				
				printf("Deleted.\n");
				fflush(stdout);
			}
		}

		if(i == 0) // Case: i is 0.
		{	
			cur = knapsack; // Cur gets knapsack's address.

			if(cur->next == NULL) // Case: Linked list has one node.
			{
				cur2 = *head; // Cur2 has &&head's value.

				if(*head == cur2  && cur->item == item) // Case: *head is cur2.
				{
					*head = cur2->next; // Head points to cur2's next.

					printf("Deleted.\n");
					fflush(stdout);
					
					return *head; // Return *head.
				}
				else
				{
					printf("%d is not existed in your knapsack.\n", item);
					fflush(stdout);
				}
			}	
			else
			{
				if(cur->item == item) // Case: cur's item is item.
				{
					cur2 = *head; // Cur2 has &&head's value.

					if(*head == cur2 && cur->item == item) // Case: *head is cur2.
					{
						*head = cur2->next; // Head points to cur2's next.

						printf("Deleted.\n");
						fflush(stdout);
					
						return *head; // Return *head;
					}
				}
				else
				{
					for(cur = knapsack; cur != NULL; cur = cur->next) // Loop for finding node which user will delete.
					{
						if(cur->next == NULL) // Case: Cur's next is NULL.
							break;

						if(cur->next->item == item) // Case: Item of the node which user wants to delete is item.
							break;
					}

					if(cur->next == NULL) // Case: Cur's next is NULL.
					{
						printf("%d is not existed in your knapsack.\n", item);
						fflush(stdout);
					}
					else
					{
						del = cur->next; // Cur->next is the node which user wants to find.
						cur->next = del->next;
						free(del); // Free del.
						del = NULL; // del to NULL.

						printf("Deleted.\n");
						fflush(stdout);
					}
				}
			}
			
			return knapsack; // Return knapsack.
		}
	}
	
	return knapsack; // Return knapsack.
}
	

void KnapsackPrint(listitemptr knapsack)
{
	listitemptr cur = NULL; // Initializing cur to NULL.

	if(knapsack == NULL) // Case: Knapsack is NULL.
	{
		printf("No items in your knapsack.\n");
		fflush(stdout);
	}
	else
	{
		for(cur = knapsack; cur != NULL; cur = cur->next) // Loop for printing values of pointer variable.
		{
			printf("Item: %d, Count: %d\n", cur->item, cur->count);
			fflush(stdout);
		}
	}
}

unsigned int KnapsackItemCount(listitemptr knapsack, int item)
{
	int i = 0; // Initializing value which the function will return.

	for(cur = knapsack; cur != NULL; cur = cur->next) // Loop for finding count of node which user wants to find.
	{
		if(cur->item == item) // Case: Cur's item is item.
		{
			i = cur->count; // Initializing i to cur's count.
		}
	}

	return i; // Return i.
}

unsigned int KnapsackSize(listitemptr knapsack)
{
	int i = 0; // Initializing i to 0.

	for(cur = knapsack; cur != NULL; cur = cur->next) // Loop for getting size.
	{
		i += cur->count; // Increasing i by adding cur's count.
	}

	return i; // Return i.
}