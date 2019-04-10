#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;
struct tree { //inicjacja drzewa
	int info;
	struct tree *left;
	struct tree *right;
};

struct tree* newElement(int x)
{
    struct tree *root =(struct tree*)malloc(sizeof(struct tree));
    root->info = x;
    root->left = NULL;
    root->right = NULL;
    return root;
}

struct tree* insert(struct tree *root, int x) { //budowa drzewa
	if(!root) {
		root = newElement(x);
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
void deleteTree(struct tree *root) {
	if(root != NULL) {
		deleteTree(root->left);
		deleteTree(root->right);
		// cout<< root->info<< "  ";
		free(root);
	}
	return;
}
void inorder(struct tree *root, int *tab, int *i) {
	if(root != NULL) {
		inorder(root->left,tab,i);
		tab[*i]=root->info;
		*i = *i+1;
		inorder(root->right,tab,i);
	}
	return;
}

int height (struct tree *root, int h,int maks)
{
	if(root != NULL) {
		h++;
		maks = height(root->left, h, maks);
		maks = height(root->right, h, maks);
		h--;
	}
	else
	{

		if (h>maks)
		  {maks=h;
		  }
	}
	return (maks);
}

struct tree *makeAVL(int tab[], int start, int end) {
    if (start > end)
        return NULL;
    int mid = (start + end)/2;
    struct tree *root = newElement(tab[mid]);
    root->left = makeAVL(tab, start, mid - 1);
    root->right = makeAVL(tab, mid + 1, end);
    return root;
}



int main(){

    fstream inBST,outAVL,outBST;
    outAVL.open("AVL.txt", ios::out | ios::app); //dopisywanie wynikow, tworzy nowy plik jesli brak
    outBST.open("BST.txt", ios::out | ios::app);
    int i,x;
    struct tree *BST = NULL;
    struct tree *AVL = NULL;
    int tab [1500000];
    for(int j = 1; j<16;j++){
        cout<< j <<endl;
        BST = NULL;
        inBST.open("dane.txt", ios::in);
        for(i = 0; i < 100000*j; i++){
            inBST>>x;
            BST = insert(BST,x);
            tab[i]=x;
            }
        inBST.close();
        x= height(BST,0,0);
        outBST << "Wysokosc BST: " << x <<endl;
        x=0;
        AVL = NULL;
        inorder(BST,tab,&x);
        AVL = makeAVL(tab,0, j*100000-1);
        x= height(AVL,0,0);
        outAVL << "Wysokosc AVL: " << x <<endl;// usuwanie
        //cout<< "BST:" <<endl;
        deleteTree(BST);
        //cout<< "AVL:" <<endl;
        deleteTree(AVL);// usuwanie
        //cout<< endl<<endl;
	}
	outAVL.close();
	outBST.close();
	return 0;
}
