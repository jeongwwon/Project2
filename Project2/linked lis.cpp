#include<iostream>
class node {
public:
	int data;
	node* next;
};
class list {
public:
	int count;
	list(int size);
	node* head;
	int queue[100] = {0,};
	void is_full(), is_empty();
	void enqueue(int data);
	void dequeue();
	void print();
};
list::list(int size) {
	queue[size] = { 0, };
	count = 0;
}

void list::is_full() {
	if (head == count) {
		std::cout<<
	}
}
