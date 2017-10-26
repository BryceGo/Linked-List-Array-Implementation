//Bryce Golamco
//bgolamco@sfu.ca









#ifndef ASSIGNMENT1_H
#define ASSIGNMENT1_H


typedef struct node{
   void * item;
   struct node * next;
   struct node * before;
   struct list * list_head;
}Node;


typedef struct list{
    Node * head;
    Node * tail;
    Node * current;
    int before_start;
    int beyond_end;
    int in_use;
    int size;
    //Node list_array[ARRAY_LENGTH];
}LIST;

//LIST *list_heads[LIST_LENGTH];


LIST *ListCreate(); // Makes a new empty list, and returns its reference on success. Returns a NULL pointer on failure
int ListCount(LIST *list); // returns the number of items in list
void *ListFirst(LIST *list); // returns a pointer to the first item in list and makes the first item the current item

void *ListLast(LIST *list); //Returns a pointer the last node in the list
void *ListNext(LIST *list);	//Returns a pointer the next node in the list
void *ListPrev(LIST *list);	//Returns a pointer to the previous node
void *ListCurr(LIST *list); //Returns a pointer to the current node in the list
int ListAdd(LIST *list,void *item); //Adds a node into the list
int ListInsert(LIST *list,void *item); //Inserts an item into the list (can be of any type)
int ListAppend(LIST *list,void *item); //Appends an item into the list (can be of any type)
int ListPrepend(LIST *list,void *item); //Prepends an item into the list (can be of any type)
void *ListRemove(LIST *list); //Removes the current node from the list.
void ListConcat(LIST *list1,LIST *list2); //Concatenate two lists together
void ListFree(LIST *list,void (*itemFree)(void *)); // Frees all the items in the list. (List still exists but all items will be deleted inside)
void *ListTrim(LIST *list); //Removes the last node from the list
void *ListSearch(LIST *list, int (*comparator)(void*, void*), void *comparisonArg); //Searches for the item in the list and returns a pointer to it when a match is found

int TotalNodes();//returns the number of nodes
int TotalHeads();// returns the number of heads

#endif // ASSIGNMENT1_H
