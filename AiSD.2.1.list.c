#include <stdio.h>

struct list{ // stryktura
	int key;
	struct list *next;
};

struct list *insert(struct list *start, int x) { //budowa listy

	struct list *newList = (struct list*)malloc(sizeof(struct list));
    newList->key = x;
    newList->next = NULL;

	if(!start) {
		start=newList;
		return(start);
	}

    if (start -> key > x)
    {
        newList ->next = start;
        start = newList;
        return(start);
    }

    struct list *currentList = start;
    struct list *nextList  = start->next;
	while(nextList !=NULL && nextList->key < x)
	      {
	          currentList = nextList;
	          nextList = nextList -> next;
	      }
	newList ->next = nextList;
	currentList -> next = newList;

	return(start);
}

void deleteList(struct list *start) {
    struct list *currentList = start;
    while(currentList != NULL)
	{
	    start = currentList -> next;
	    printf(" %d",currentList->key);
	    free(currentList);
	    currentList = start;
	}

}

struct list *search(struct list *start, int x) { //budowa drzewa

	struct list *currentList = start;
	while(currentList !=NULL && currentList->key != x)
	      {
	          currentList = currentList ->next;
	      }
	return(currentList);
}


int main (void)
{
    int tab1[] = {10, 4, 3, 5, 9, 7, 2, 8, 6, 0, 11, 1, 14, 17, 13, 15, 19, 12, 18, 16};
	int i,x;
	struct list *Lista = NULL;
	struct list *a =NULL;

	for(i = 0; i < 20; i++){ //budowa listy
		Lista = insert(Lista,tab1[i]);
	}
    for(i = 0; i < 20; i++){ // test search
		a = search(Lista,tab1[i]);
		x= a->key;
		printf("%d \n", x);
	}
	deleteList(Lista);
	return 0;
}
