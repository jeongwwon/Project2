#include<iostream>

class tree {
public:
	tree* left;
	tree* right;
	int value;
};

tree* addnode(tree* t, int data) {
	if (!t) {
		tree* t = new tree;
		t->left = NULL;
		t->right = NULL;
		t->value = data;
	}
	else if (data < t->value) {
		t->left = addnode(t->left, data);
	}
	else if (t->value < data) {
		t->right=addnode(t->right,data);
	}
	return t;
}
int get_order(int* inorder,int begin,int end,int target){
	for (int i = begin; i < end; i++) {
		if (inorder[i] == target)
			return i;
}
}
tree* restore(int* preorder, int* inorder, int begin, int end) {
	static int preidx = 0;
	tree* newnode = NULL;
	if (begin <= end) {
		newnode = new tree;
		newnode->value = preorder[preidx++];
		newnode->right = newnode->left = 0;
		int inidx = get_order(inorder, 0, 5, newnode->value);
		if (inidx == -1) {
			delete newnode;
			return NULL;
		}
		newnode->left = restore(preorder, inorder, begin, inidx - 1);
		newnode->right = restore(preorder, inorder, inidx + 1, end);
	}
	return newnode;
}
void display(tree* t) {
	if (t) {
		display(t->left);
		std::cout << t->value << std::endl;
		display(t->right);
	}
}
int main() {
	tree* root = NULL;
	int inorder[6] = { 1,2,4,5,3,6 };
	int preorder[6] = { 4,2,5,1,6,3 };
	root = restore(preorder, inorder, 0, 5);
	display(root);
}


