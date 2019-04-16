/* knapsack.h
 * implements simple knapsack data structure as a linked list 
*/

/* pointer to linked list node data structure */
typedef struct listitem* listitemptr;
/* data structure to use as linked list nodes */
struct listitem {
  int item;           // actual int item
  unsigned int count; // number of the same item in the knapsack; should be >= 1
  listitemptr next;   // pointer to next item 
};

/*
 * adds an item to a knapsack; must only update the "count" if the item already exist in the knapsack; "count" must be set to 1 for previously-nonexisting items
 * @param knapsack: points to the first listitem in a knapsack; NULL if knapsack has not been created yet
 * @param item: integer item to add
 * @return pointer to the listitem added/updated; NULL if unsuccessful 
 */
listitemptr KnapsackAdd(listitemptr knapsack, int item);

/*
 * removes a value from a knapsack; must update the "count" and delete the associated listitem when count becomes 0 
 * @param knapsack: points to the first listitem in a knapsack
 * @param item: integer item to remove
 * @return 0 if successful; 1 otherwise
 */
listitemptr KnapsackRemove(listitemptr knapsack, int item);

/*
 * prints elements and their counts in a knapsack
 * @param knapsack: points to the first listitem in a knapsack
 * @stdout: for example, "" (nothing) when knpsack==NULL, or "125 (4), -10 (1), 26 (2)" when items include four of 125, one of -10, and two of 26 
 * @return void
 */
void KnapsackPrint(listitemptr knapsack);

/*
 * count the number of specific item in the knapsack
 * @param knapsack: points to the first listitem in a knapsack
 * @param item: integer item to search for
 * @return item count, or 0 if it does not exist
 */
unsigned int KnapsackItemCount(listitemptr knapsack, int item);

/*
 * total count of items in the knapsack
 * @param knapsack: points to the first listitem in a knapsack
 * @return total item count. for example, 7 in case of above example "125 (4), -10 (1), 26 (2)"
 */
unsigned int KnapsackSize(listitemptr knapsack);

