//Bryce Golamco
//bgolamco@sfu.ca




//You can comment out the code bounded by the commented out Dashed Lines -------

//Change the ARRAY_LENGTH and LIST_LENGTH in the implementation file to change the Capacity of the arrays
//Currently set to:
//Heads:10
//Nodes:100


#include <stdio.h>
#include <stdlib.h>
#include "list.h"


void printlist(LIST *list);	// Prints every item in the list (integers only)
void itemFree(void * x);


int main (void){
    int i = 0;
    int j =0;
    int * y =  NULL;
    LIST * list1 = NULL;
    LIST * list2 = NULL;
    list1 = ListCreate();
    list2 = ListCreate();


//-------------------------------------------------------------------------
	printf("\n\n\nBy: Bryce Golamco\n");
	printf("------------------------------------------BASIC CASES---------------------------------------\n");
	//
for(j = 0; j<4; j++){

    if(j == 0){
        printf("Implementation of ListAdd and ListRemove Function\n");
    }else if (j == 1){
        printf("Implementation of ListInsert and ListRemove Function\n");
    }else if (j== 2){
        printf("Implementation of ListAppend and ListRemove Function\n");
    }else if(j==3){
        printf("Implementation of ListPrepend and ListRemove Function\n");
    }
    for(i = 0; i < 9; i++){
        y = malloc(sizeof(int));
        *y = i;
        if(j== 0){
            if(ListAdd(list1, y) == -1){
                printf("Error adding");
            }
        }else if(j == 1){
            if(ListInsert(list1, y) == -1){
                printf("Error adding");
            }
        }else if (j==2){
            if(ListAppend(list1, y) == -1){
                printf("Error adding");
            }
        }else if (j==3){
            if(ListPrepend(list1, y) == -1){
                printf("Error adding");
            }
        }
    }
    printf("List1 Size is: %i\n",ListCount(list1));
    printf("Total node size is: %i\n", TotalNodes());

    printf("The Current items in the list are:\n");
    ListFirst(list1);
    for(i = 0; i<9; i++){
        y = list1->current->item;
        printf("%i\n", *y);
        ListNext(list1);
    }

    printf("\n\nPopping each item off of the list starting from the head gives:\n");
    ListFirst(list1);
    for(i = 0; i < 9; i++){
        y = ListRemove(list1);
        if(y == NULL){
            printf("NULL\n");
        }else{
        printf("%i", *y);
        printf("\n");
        }
    }
    printf("New Size is: %i\n",ListCount(list1));
    printf("Total Node Size is: %i\n\n",TotalNodes());
}
    printf("Expected Outcome for ListAdd and ListAppend should be: \n");//Prints the Expected outcome of each
    printf("0\n1\n2\n3\n4\n5\n6\n7\n8\n");

    printf("Expected Outcome for ListInsert and ListPrepend should be: \n");//Prints the Expected outcome
    printf("8\n7\n6\n5\n4\n3\n2\n1\n0\n");
    printf("ListRemove Function should output on each corresponding function with node sizes of 0 each.\n");

//-------------------------------------------------------------------------


    printf("------------------------------------------CORNER CASES---------------------------------------\n");








    
//-------------------------------------------------------------------------
//NULL POINTERS PASSED THROUGH THE FUNCTIONS
//
//ListAdd
    printf("Case:ListAdd is given a NULL pointer:\n");
    printf("Failing outcome is a value of -1\n");
    printf("Expected Outcome is to fail.\n");
    printf("Outcome: ");
    j = 1;
    printf("%i",ListAdd(NULL,&j));
    printf("\n\n");

//ListInsert
    printf("Case:ListInsert is given a NULL pointer:\n");
    printf("Expected Outcome is to fail.\n");
    printf("Outcome: ");
    j = 1;
    printf("%i",ListInsert(NULL,&j));
    printf("\n\n");
//ListAppend
    printf("Case:ListAppend is given a NULL pointer:\n");
    printf("Expected Outcome is to fail.\n");
    printf("Outcome: ");
    j = 1;
    printf("%i",ListAppend(NULL,&j));
    printf("\n\n");

//ListPrepend
    printf("Case:ListPrepend is given a NULL pointer:\n");
    printf("Expected Outcome is to fail.\n");
    printf("Outcome: ");
    j = 1;
    printf("%i",ListPrepend(NULL,&j));
    printf("\n\n");

//ListPrepend
    printf("Case:ListRemove is given a NULL pointer:\n");
    printf("Expected Outcome is to fail.\n");
    printf("Outcome: ");
    j = 1;
    if(ListRemove(NULL) == NULL){
    	printf("returns a NULL");
    }else{
	printf("returns a non-NULL address");
    }

    printf("\n\n");
//-------------------------------------------------------------------------




//-------------------------------------------------------------------------
//Case where Nodes are exhausted
//Fills the list with the maximum number of nodes
    printf("Case: all Nodes in the list are exhausted\n");
    printf("Assuming the maximum number of nodes are 100\n");
    LIST * list_full = NULL;
    list_full = ListCreate();
    int some_var = 0;
    for(i = 0; ListAdd(list_full,&some_var) != -1; i++); //Adds nodes until it is full;
    printf("The Size of the current list is:\n");
    printf("Expected: 100\n");
    printf("Outcome: %i\n",ListCount(list_full) );


//Prints everything on the list (Should be 100 0s). Recommended to comment out unless you want to see the values of every node.

//    int *list_full_item = NULL;
//    printf("Now printing everything on the list\n");
//    ListFirst(list_full);
//    for(i = 1; list_full->current != NULL; i++){
//	list_full_item = list_full->current->item;
//	printf("%i. Node value is %i\n", i,*list_full_item);
//	ListNext(list_full);
//    }


//Removes everything on the list
    printf("\n\n");
    printf("Removing everything on the current list...\n");
    for(i = 0; ListRemove(list_full) != NULL; i++);	//Removes everything from the list
    printf("Current list size is now:\n");
    printf("Expected: 0\n");
    printf("Outcome: %i\n", ListCount(list_full));
    printf("\n\n");

//-------------------------------------------------------------------------





//-------------------------------------------------------------------------
//Case where two lists are being concatenated
    int *list_concat_pointer = NULL;

    printf("Case where 2 lists are concatenated to each other\n");

    printf("Number of current lists in pool: %i\n", TotalHeads()); 

    for(i = 0; i < 10; i++){
	list_concat_pointer = malloc(sizeof(int));
	*list_concat_pointer = i;
	ListAdd(list1,list_concat_pointer);
    }

    for(i = 0; i < 10; i++){
	list_concat_pointer = malloc(sizeof(int));
	*list_concat_pointer = i;
	ListAdd(list2,list_concat_pointer);
    }

    ListFirst(list1);
    ListFirst(list2);
    printf("Current items in the first list are: ");
    printlist(list1);
    printf("\n");
    printf("Current items in the second list are: ");
    printlist(list2);
    printf("\n");
    printf("Merging the two lists together and freeing list2...\n");
    ListConcat(list1,list2);
    printf("Items in the first list are :");
    printlist(list1);
    printf("\n");
    printf("Number of current lists in pool: %i\n", TotalHeads()); 
    printf("Expected: All the items will be in the first list, and there would be one less lists in the pool\n");
    printf("\n\n");

//Case where the listTrim is used
   printf("Case where the list is trimmed\n");
   printf("Current list has items: ");
   printlist(list1);
   printf("\n");
   printf("Trimming one from the list gives: ");
   ListTrim(list1);
   printlist(list1);
   printf("\n Expected: The last item on the list should be taken away.\n");

//-------------------------------------------------------------------------


//-------------------------------------------------------------------------

//Case where itemFree function is being used
   LIST * list_itemfree = NULL;
   int * test = NULL;
   int *xz = malloc(sizeof(int));
   *xz = 5;


   list_itemfree = ListCreate();
   ListAdd(list_itemfree, xz);
   printf("Case where itemFree function is being used.\n");
   printf("Current item in the list is: ");
   printlist(list_itemfree);
   printf("\n");
   printf("Freeing the item from the list...\n");
   test = list_itemfree->head->item;
   ListFree(list_itemfree, itemFree);
   printf("Current item is now: %i\n", *test);
   printf("\n\n");
 


//-------------------------------------------------------------------------




//-------------------------------------------------------------------------


//Case where all the List heads are exhausted
//Depending on the different sections of the code, The current number of lists may not be 0
    LIST * list_head_full = NULL;
    printf("Case where the list heads are exhausted, defaulted at 10 heads max.\n");
    printf("Depending if the different sections of the code are commented out, The current number of lists may not start at zero\n");
    printf("Maximum by default is 10\n");
    printf("Current number of lists: %i\n", TotalHeads());

    do{
    list_head_full = ListCreate();
    }while(list_head_full != NULL);
    
    printf("Expected : 10\n");
    printf("Outcome: %i\n", TotalHeads());
    printf("\n\n");




//-------------------------------------------------------------------------



















return 0;
}

//Prints out everything in the list, Only works with integers
void printlist(LIST *list){
    int * x = NULL;
    ListFirst(list);
    while(list->current != NULL){
	x = list->current->item;
	printf("%i ,",*x);
	ListNext(list);
    }

}

void itemFree(void * x){ //ItemFree Test function (INTEGERS ONLY)
int * y = NULL;
y = x;
free(y);
}


