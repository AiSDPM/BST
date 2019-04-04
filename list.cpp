#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;

struct list{ 
	int key;
	struct list *next;
};

struct list *insert(struct list *start, int x) { 

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
	    //printf(" %d",currentList->key);
	    free(currentList);
	    currentList = start;
	}

}

struct list *search(struct list *start, int x) { 

	struct list *currentList = start;
	while(currentList !=NULL && currentList->key != x)
	      {
	          currentList = currentList ->next;
	      }
	return(currentList);
}


int main ()
{
    double roznica;
    int i,x;
    fstream plik, pliksearch,plikdelete,plik_in;
    struct list *Lista = NULL;
    struct list *a = NULL;
    plik.open("ListaInsert.txt", ios::out | ios::app); //dopisywanie wynikow, tworzy nowy plik jesli brak
    pliksearch.open("ListaSearch.txt", ios::out | ios::app);
    plikdelete.open("ListaDelete.txt", ios::out | ios::app);
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
	
    for(int j =1;j<16;j++){
    	Lista = NULL;
    	cout<< j<<endl;
    	plik_in.open("dane.txt", ios::in);
   	start = std::chrono::high_resolution_clock::now();
    	for(i = 0; i < 20000*j; i++){ //budowa listy
            	plik_in >> x;
            	Lista = insert(Lista,x);
    	}
    	end = std::chrono::high_resolution_clock::now();
    	std::chrono::duration<double> elapsed_seconds = end-start;
    	plik << "Tworzenie: " <<elapsed_seconds.count() << endl;
    	plik_in.close();

    	plik_in.open("C:\\Users\\Michal\\PycharmProjects\\untitled2\\venv\\Include\\dane.txt", ios::in);
    	start = std::chrono::high_resolution_clock::now();
    	for(i = 0; i < 10000*j; i++){ // test search
           	 plik_in >> x;
            	 a = search(Lista,x);
    	}
    	end = std::chrono::high_resolution_clock::now();
    	plik_in.close();
    	elapsed_seconds = end-start;
    	pliksearch << "Przeszukanie: " <<elapsed_seconds.count() << endl;

    	start = std::chrono::high_resolution_clock::now();
    	deleteList(Lista);
    	end = std::chrono::high_resolution_clock::now();
    	elapsed_seconds = end-start;
    	plikdelete << "Usuniecie: " <<elapsed_seconds.count() << endl;

    }
    plik.close();
    pliksearch.close();
    plikdelete.close();
    return 0;

}
