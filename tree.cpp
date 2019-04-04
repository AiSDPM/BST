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


void deleteTree(struct tree *root) {
	if(root != NULL) {
		deleteTree(root->left);
		deleteTree(root->right);
		//printf(" %d",root->info);
		free(root);
	}
	return;
}


int main(){

    fstream drzewo, drzewosearch, drzewodelete,plik_in;
	int i,x;
	struct tree *BST = NULL;
    drzewo.open("TreeInsert.txt", ios::out | ios::app); 
    drzewosearch.open("TreeSearch.txt", ios::out | ios::app);
    drzewodelete.open("TreeDelete.txt", ios::out | ios::app);

    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

    for(int j = 1; j<16;j++){

    	BST = NULL;
    	cout<< j << endl;
	    plik_in.open("dane.txt", ios::in);
    	start = std::chrono::high_resolution_clock::now();
    	for(i = 0; i < 20000*j; i++){
                 plik_in>>x;
            	 BST = insert(BST,x);
   	 }
   	 end = std::chrono::high_resolution_clock::now();
    	std::chrono::duration<double> elapsed_seconds = end-start;
    	drzewo << "Tworzenie: " <<elapsed_seconds.count() << endl;
    	plik_in.close();
	    
    	plik_in.open("C:\\Users\\Michal\\PycharmProjects\\untitled2\\venv\\Include\\dane.txt", ios::in);
    	start = std::chrono::high_resolution_clock::now();
    	for(i = 0; i < 20000*j; i++){
              	  plik_in>>x;// test search
          	  a = search(BST,x);
    	}
   	end = std::chrono::high_resolution_clock::now();
    	plik_in.close();
    	elapsed_seconds = end-start;
    	drzewosearch << "Przeszukanie: " <<elapsed_seconds.count() << endl;

    	start = std::chrono::high_resolution_clock::now();
    	deleteTree(BST);
    	end = std::chrono::high_resolution_clock::now();
    	elapsed_seconds = end-start;
    	drzewodelete << "Usuniecie: " <<elapsed_seconds.count() << endl;
    }
    drzewo.close();
    drzewosearch.close();
    drzewodelete.close();
    return 0;
}

