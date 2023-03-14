#include<iostream>
/*Complete binary tree:������level�� �����ϰ� �� ä���� Ʈ��,������ level �� ���ʿ��� ���������� ä��
  Full bianry tree:�ڽ��� �ƿ� ���ų� �θ��� �ڽ��� ���� tree
  Perfect binary tree:��� leaf�� ������ ���� ��ä��������*/

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
		t = new tree;
		t->value = data;
		t->left = NULL;
		t->right = NULL;
	}
	else if(data<t->value){
		t->left = addnode(t->left, data);
	}
	else if (t->value < data) {
		t->right = addnode(t->right, data);
	}
	return t;
}
tree* findmax(tree* t) {
	if (t) {
		while (t->right)
			t = t->right;
	}
	return t;
}

tree* findmin(tree* t) {
	if (t->left) {
		t = findmin(t->left);
	}
	return t;
}
tree* remove(tree* t, int deldata) {
	tree* temp;
	if (t) {
		if (deldata == t->value) {
			if (t->left == NULL && t->right == NULL) {
				free(t);
				return NULL;
			}
			else {
				if (t->left == NULL) {
					temp = t->right;
					free(t);
					return temp;
				}
				if (t->right == NULL) {
					temp = t->left;
					free(t);
					return temp;
				}
				temp = findmax(t->left);
				t->value = temp->value;
				t->left = remove(t->left, temp->value);
			}

		}
		else {
			if (deldata < t->value) {
				t->left = remove(t->left, deldata);
			}
			else{
				t->right = remove(t->right, deldata);
			}
		}
		return t;
	}
}
/*������ȸ�� ������ȸ�� Ʈ�� ����
  ���� ��ȸ�� root �Ǻ�
  ���� ��ȸ���� �Ǻ��� ������ȸ�� ���� �������� ù��°��=root*/
int get_inorder_index(int* inorder, int begin, int end, int target) {
	for (int i = begin; i <= end; i++) {
		if (inorder[i] == target) {
			return i;
		}
	}
}
tree* tree_restore(int* preorder, int* inorder, int begin, int end) {
	static int preidx = 0;
	static int count = 0;
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
			std::cout <<"��� ��:"<< newnode->value << "count:" << ++count << std::endl;
			newnode->right = tree_restore(preorder, inorder, inidx + 1, end);
		}
	return newnode;
}
int main() {
	tree* root = nullptr;
	int preorder[6] = { 1,2,4,5,3,6 };
	int inorder[6] = { 4,2,5,1,6,3 };
	root = tree_restore(preorder, inorder, 0, 5);
	display(root);
	
}