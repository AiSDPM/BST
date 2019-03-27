#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <chrono>

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
		printf(" %d",root->info);
		free(root);
	}
	return;
}


int height (struct tree *root, int h,int max)
{
	if(root != NULL) {
		h++;
		max = height(root->left, h, max);
		max = height(root->right, h, max);
		h--;
	}
	else
	{

		if (h>max)
		  max=h;
	}
	return (max);
}

struct tree *makeAVL(struct tree *root, struct tree *node,int l, int p, int *tab) {
    if (l>p)
        return root;
    int mid = (l+p)/2;
    node = newElement(tab[mid]);
    node->left = makeAVL(root, node, l, mid-1,tab);
	node->right = makeAVL(root,node, mid+1, p ,tab);

}



int main(void){
	int tab1[] = {10, 4, 3, 5, 9, 7, 2, 8, 6, 0, 11, 1, 14, 17, 13, 15, 19, 12, 18, 16};
	int i,x;
	struct tree *BST = NULL;

	for(i = 0; i < 20; i++){ //budowa drzewa
		BST = insert(BST,tab1[i]);
	}

	x= height(BST,0,0);
    deleteTree(BST); // usuwanie
    free(BST);

    struct tree *AVL = NULL;
    int len = sizeof(tab1)/sizeof(tab1[0]);
    std::sort(tab1, tab1+ len);

    AVL = makeAVL(AVL,AVL, 0, len-1, tab1);
    x= height(AVL,0,0);
	deleteTree(AVL); // usuwanie
    free(AVL);

	return 0;
}
