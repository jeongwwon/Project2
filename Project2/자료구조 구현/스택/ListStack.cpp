#include<iostream>
class node {
public:
	int data;
	node* next;
};

class stack{
public:
	int count;
	node* head;
public:
	stack() {
		head = NULL;
		count = 0;
	}
	void push(int data);
	void pop();
	void remove(int index);
	void print();
};

void stack::push(int data) {
	node* newnode = new node;
	newnode->data = data;
	newnode->next = NULL;
	if (head == NULL) {
		head = newnode;    // count=1
		count++;
		std::cout << "data:" << data << " " << " inserted!" << std::endl;
	}
	// list가 비어있을때
	else {
		node* temp = head; // 비어있지 않다면 head를 가르키는 포인터 temp 지정
		for (int i = 0; i < count-1; i++) // 2push , count=3
		{
			temp = temp->next;   // 0 1 
		}	
			temp->next = newnode;  //(*temp).next=newnode
			count++;
			std::cout << "data:" << data << "  " << "inserted!" << std::endl;
		}
}
void stack::pop() {
	if (head == NULL) {
		std::cout << "there is no NODE" << std::endl;
	}
	node* temp = head;   //초기 head값은 첫번째 데이터 0 
	for (int i = 0; i < count-2/*2*/; i++)  // count=3 
	{
		temp = temp->next;      // 0 1 2 
	}     // 
	std::cout << "pop operated and deleted!" << std::endl;
	delete temp->next;
	temp->next = NULL;
	count--;
}
	
void stack::print()
{
	for (node* temp = head; temp != NULL; temp = temp->next)
	{
		std::cout << temp->data << " ";
	}
	std::cout << std::endl;
}

int main()
{

	stack llist;
	for (int i = 0; i < 3; i++) {
		llist.push(i);
	}

	llist.pop();
	//llist.pop();
	llist.print();
	std::cout << llist.count;
}