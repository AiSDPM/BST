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

void deleteTree(struct tree *root) {
	if(root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf(" %d",root->info);
		free(root);
	}
	return;
}


int height (struct tree *root, int h,int max)
{
	if(root != NULL) {
		h++;
		printf("Poziom %d : %d \n",root->info, max);
		max = height(root->left, h, max);
		max = height(root->right, h, max);
		h--;
	}
	else
	{
		
		if (h>max)
		{max=h;}
	}
	return (max);
}


void inorder(struct tree *root) {
	if(root != NULL) {
		inorder(root->left);
		printf(" %d",root->info);
		inorder(root->right);
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

	x= height(BST,0,0);
	printf("\n\n\n %d", x);
    deleteTree(BST); // usuwanie
	return 0;
}

