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
		std::cout << t->value << ' ';
		display(t->right);
	}
}
tree* addnode(tree* t, int data) {
	if (!t) {
		t =new tree;
		t->value = data;
		t->left = NULL;
		t->right = NULL;
	}
	if (data < t->value) {
		t->left = addnode(t->left,data);
	}
	if (t->value < data) {
		t->right = addnode(t->right, data);
	}
	return t;
}
int get_order(int* ord, int begin, int end, int target) {
	for (int i = begin; i <= end; i++) {
		if (ord[i] == target) {
			return i;
		}
	}
}
tree* restore(int* pre, int* ord, int begin, int end) {
	static int paridx = 0;
	int idx = -1;
	tree* newnode = new tree;
	if (begin <= end) {
		newnode->value = ord[paridx++];
		int idx = get_order(ord, begin, end, newnode->value);
		if (idx == -1) {
			delete newnode;
			return NULL;
		}
		newnode->left = restore(pre, ord, begin, idx - 1);
		newnode->right = restore(pre, ord, idx + 1, end);
		return newnode;
	}
	else {
		delete newnode;
		return NULL;
	}
}
tree* findmax(tree* t) {
	if (t) {
		while (t->right) {
			t = t->right;
			return t;
		}
	}
}
tree* remove(tree* t, int data) {
	tree* temp;
	if (t) {
		if (t->value < data) {
			t->right = remove(t->right, data);
		}
		if (data < t->value) {
			t->left = remove(t->left, data);
		}
		if (t->value == data) {
			if (t->left == NULL && t->right == NULL) {
				temp = t;
				free(t);
				return NULL;
			}
			else if (t->left == NULL) {
				temp = t->right;
				free(t);
				return temp;
			}
			else if (t->right == NULL) {
				temp = t->left;
				free(t);
				return temp;
			}
				temp = findmax(t->left);
				t->value = temp->value;
				t->left = remove(t->left, temp->value);
			}
	}
	return t;
}

int main() {
	tree* root = nullptr;
	int preorder[9] = { 8 ,4, 2, 1, 3, 7, 10, 9, 15 };
	int inorder[9] = { 1, 2, 3, 4, 7, 8, 9, 10, 15 };
	root = restore(preorder, inorder, 0, 8);
	remove(root, 15);
	display(root);

}