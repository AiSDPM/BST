#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <chrono>
#include <time.h>
#include <fstream>

using namespace std;

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
	   // printf(" %d",currentList->key);
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
    time_t start, koniec;
    double roznica;
    int tab1[] = {10, 4, 3, 5, 9, 7, 2, 8, 6, 0, 11, 1, 14, 17, 13, 15, 19, 12, 18, 16};
	int i,x, petla, y=3000;
	fstream plik, pliksearch,plikdelete;

	struct list *Lista = NULL, Lista2;
	struct list *a =NULL;

    plik.open("wynikilista.txt", ios::out | ios::app); //dopisywanie wyników, tworzy nowy plik jesli brak
    pliksearch.open("searchlista.txt", ios::out | ios::app);
    plikdelete.open("deletelista.txt", ios::out | ios::app);

    time( & start );
    for (petla = 0; petla < y; petla++){
	for(i = 0; i < 20; i++){ //budowa listy
            Lista = insert(Lista,tab1[i]);
        }
	}
	time( & koniec );
    roznica = difftime( koniec, start );
    cout << "Obliczenia zajely Ci: " << roznica/y << " sekund\n";
    plik << roznica << "     " << roznica/y << " y to " << y << endl;
    plik.close();

    time( & start );
    for (petla = 0; petla < y; petla++){
        for(i = 0; i < 20; i++){ // test search
            a = search(Lista,tab1[i]);
            x= a->key;
            //printf("%d \n", x);
        }
	}
	time( & koniec );
    roznica = difftime( koniec, start );
    cout << "Obliczenia zajely Ci: " << roznica/y << " sekund\n";
    pliksearch << roznica << "     " << roznica/y << " y to " << y << endl;
    pliksearch.close();

	time( & start );
    deleteList(Lista);
    time( & koniec );
    roznica = difftime( koniec, start );
    cout << "Obliczenia zajely Ci: " << roznica/y << " sekund\n";
    plikdelete << roznica << "     " << roznica/y << " y to " << y << endl;
    plikdelete.close();

	return 0;
}
