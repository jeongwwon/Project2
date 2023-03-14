#include<iostream>
class tree {
public:
	int value;
	tree* left;
	tree* right;
};
void display(tree* t) {
	if (t) {
		display(t->left);
		std::cout << t->value << std::endl;
		display(t->right);
	}
}
int get_inorder_index(int* inorder, int begin, int end, int target) {
	for (int i = begin; i <= end; i++) {
		if (inorder[i] == target) {
			return i;
		}
	} 
}
tree* tree_restore(int* preorder, int* inorder, int begin, int end) {
	static int preidx = 0;
	tree* newnode = NULL;
	if (begin <= end) {
		newnode = new tree;
		newnode->value = preorder[preidx++];
		newnode->left = newnode->right = NULL;
		int inidx = get_inorder_index(inorder, begin, end, newnode->value);
		if (inidx == -1) {
			delete newnode;
			return NULL;
		}
		newnode->left = tree_restore(preorder, inorder, begin, inidx - 1);
		newnode->right = tree_restore(preorder, inorder, inidx + 1, end);
	}
	else {
		delete newnode;
		return NULL;
	}
	return newnode;
}
int main() {
	tree* root = nullptr;
	int preorder[6] = { 1,2,3,4,5,6 };
	int inorder[6] = { 4,2,5,1,6,3 };
	root = tree_restore(preorder, inorder, 0, 5);
	display(root);

}