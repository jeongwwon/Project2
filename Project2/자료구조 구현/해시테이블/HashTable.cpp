#include<iostream>
struct node {
	node* next;
	int value;
};
struct hash {
	node** head;
	int size;
};
void hashinitialize(hash* h,int size) {
	h->size = size;
	h->head = new node *[size];
	for (int i = 0; i < size; i++) {
		h->head[i] = new node;
		h->head[i]->next = NULL;
		h->head[i]->value = 0;
	}
}
bool hashvalue(hash* h, int index) {
	return h->head[index]->value;
}
void hashing(int* a, hash* h,int size) {
	for (int i = 0; i < size; i++) {
		int hashindex = a[i] % (h->size);
		//std::cout << "���� hashindex��:" << hashindex << std::endl;
		if (hashvalue(h, hashindex) == 0) {
			node* newnode = new node;
			newnode->value = a[i];
			newnode->next = NULL;
			h->head[hashindex]->next = newnode;
			h->head[hashindex]->value = 1;
			//std::cout << "���� hashindex������ key��:" << h->head[hashindex].value << std::endl;
		}
		else {
			node* cur,*head;
			node* newnode = new node;
			newnode->value = a[i];
			newnode->next = NULL;
			cur = h->head[hashindex]->next;
			head = h->head[hashindex];
			if (cur == NULL) {
				h->head[hashindex]->next = newnode;
				//std::cout << "���� hashindex������ key��:" << newnode->value << std::endl;
			}
			else {
				while (cur->next != NULL) {
					cur = cur->next;
				}
				newnode->next=head->next;
				head->next = newnode;
				//std::cout << "���� hashindex������ key��:" << newnode->value << std::endl;
			}
		}
	}
}
int hashfind(hash* h, int target) {
	node* cur;
	for (int i = 0; i < h->size; i++) {
		cur = h->head[i]->next;
		if (cur->value == target){
				//std::cout << "ã�� �������� index:" << i << ',' << "ù��° ���" << std::endl;
				return 1;
			}
		int count = 1;
		while (cur != NULL) {
			if (cur->value == target) {
				//std::cout << "ã�µ������� index:" << i << ',' << count << "��° node" << std::endl;
				return 1;
			}
			cur = cur->next;
			count++;
		}
	}
	return 0;
}
void display(hash* h,int size) {
	std::cout << "display ����" << std::endl;
	node* cur;
	for (int i = 0; i < size; i++) {
		std::cout << std::endl;
		std::cout << "���� hash index:" << i << std::endl;
		std::cout << h->head[i]->value << ' ';
		cur = h->head[i]->next;
		if (cur == NULL) {
			std::cout << 0 << std::endl;
		}
		else {
			while (cur != NULL) {
				std::cout << cur->value << ' ';
				cur = cur->next;
			}
			std::cout << std::endl;
		}
	}
}
int main() {
	hash h;
	int hashsize = 9;
	int a[] = { 77,36,69,18,23,96,100,15,21,45,54,17,97,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118};    
	int arsize = sizeof(a) / sizeof(a[0]);
	hashinitialize(&h, hashsize);
	hashing(a, &h, arsize);
	display(&h,hashsize);
	std::cout << std::endl;
	if (hashfind(&h, 77)) {
		std::cout << "����" << std::endl;
	}
	else {
		std::cout << "���� x" << std::endl;
	}
}