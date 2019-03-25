#include <stdio.h>

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
	int tab1[] = {10, 4, 3, 5, 9, 7, 2, 8, 6, 0, 11, 1, 14, 17, 13, 15, 19, 12, 18, 16};
	int i,x;
	struct tree *a= NULL;
	struct tree *BST = NULL;

	for(i = 0; i < 20; i++){ //budowa drzewa
		BST = insert(BST,tab1[i]);
	}

	for(i = 0; i < 20; i++){ // test search
		a = search(BST,tab1[i]);
		x= a->info;
		printf("%d \n", x);
	}

    postorder(BST); // usuwanie
	return 0;
}

