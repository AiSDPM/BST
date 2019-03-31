#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <chrono>
#include <time.h>
#include <fstream>

using namespace std;

struct tree { //inicjacja drzewa
	int info;
	struct tree *left;
	struct tree *right;
};

struct tree *insert(struct tree *root, int x) { //budowa drzewa
	if(!root) {
		root=(struct tree*)malloc(sizeof(struct tree));
		root->info = x;
		root->left = NULL;
		root->right = NULL;
		return(root);
	}
	if(root->info > x)
	     root->left = insert(root->left,x);
	else {
		if(root->info < x)
			root->right = insert(root->right,x);
	}
	return(root);
}

 struct tree *search(struct tree *root, int x) {
	struct tree *ptr;
	ptr=root;
	while(ptr) {
		if(x>ptr->info)
		     ptr=ptr->right;
		else if(x<ptr->info)
		     ptr=ptr->left;
		else
		    break;
	}
	return ptr;
 }


void postorder(struct tree *root) {
	if(root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf(" %d",root->info);
		free(root);
	}
	return;
}


int main(void){

    time_t start, koniec;
    double roznica;
    fstream drzewo, drzewosearch, drzewodelete;

	int tab1[] = {10, 4, 3, 5, 9, 7, 2, 8, 6, 0, 11, 1, 14, 17, 13, 15, 19, 12, 18, 16};
	int i,x, petla, y = 20000000;

	struct tree *a= NULL;
	struct tree *BST = NULL;

    drzewo.open("wynikidrzewo.txt", ios::out | ios::app); //dopisywanie wyników, tworzy nowy plik jesli brak
    drzewosearch.open("searchdrzewo.txt", ios::out | ios::app);
  //  drzewodelete.open("deletedrzewo.txt", ios::out | ios::app);

    time( & start );
    for (petla = 0; petla < y; petla++){
        for(i = 0; i < 20; i++){ //budowa drzewa
            BST = insert(BST,tab1[i]);
        }
    }
    time( & koniec );
    roznica = difftime( koniec, start );
    cout << "Obliczenia zajely Ci: " << roznica/y << " sekund\n";
    drzewo << roznica << "     " << roznica/y << " y to " << y << endl;
    drzewo.close();

    time( & start );
    for (petla = 0; petla < y; petla++){
        for(i = 0; i < 20; i++){ // test search
            a = search(BST,tab1[i]);
            x= a->info;
		//printf("%d \n", x);
        }
    }
	time( & koniec );
    roznica = difftime( koniec, start );
    cout << "Obliczenia zajely Ci: " << roznica/y << " sekund\n";
    drzewosearch << roznica << "     " << roznica/y << " y to " << y << endl;
    drzewosearch.close();

    postorder(BST); // usuwanie
	return 0;
}

