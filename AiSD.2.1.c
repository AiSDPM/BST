#include <stdio.h>

struct tree { //inicjacja drzewa
	int info;
	struct tree *prev;
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

struct tree *search(struct tree *root, int x) { //przeszukiwanie, trzeba poprawiæ
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

int main(void){
	int tab1[] = {1, 4, 3, 5, 9, 7, 2, 8, 6, 0, 11, 10, 14, 17, 13, 15, 19, 12, 18, 16};
	int i;
	struct tree *root;
	struct tree *BST;
	BST= new struct tree;
	root = BST;
	BTS->info = tab1[0];
	BTS->left = NULL;
	BTS->right = NULL;
	BTS->prev = root;
		
	for(i = 0; i < 20, i++){
		BST= new struct tree;
		BTS->info = tab1[i];
		BTS->left = NULL;
		BTS->right = NULL;	
		BTS->prev =insert(BTS, tab[i]);
	}

	return 0;
}
