#include <iostream>

class node {
public:
	int data;
	node* next;
};
class list {
public:
	int top,maxsize;
	node* head;
	list(int size) {
		maxsize = size;
		top = -1;
		
	};
	bool isfull(),isempty();
	int pop();
	void push(int data);
	void print();
};

bool list::isempty() {
	if (top == -1) {
		std::cout << "스택이 비었습니다" << std::endl;
		return 0;
	}
	else
		return 1;
}
bool list::isfull() {
	if (top == maxsize-1) {
		std::cout << "스택이 꽉찼습니다." << std::endl;
		return 0;
	}
	else
		return 1;
}
void list::push(int data) {
	node* newnode = new node;
	newnode->data = data;
	newnode->next = NULL;
	if (isfull()) {
		if (head == NULL) {
			head = newnode;
			std::cout << "인덱스:" << ++top << "에 data:" << data << "가 삽입되었습니다." << std::endl;
		}
		else {
			node* temp = head;
			for (int i = 0; i < top;i++){// 0 1 2
				temp = temp->next;
		}
			temp->next = newnode;
			std::cout << "인덱스:" << ++top << "에 data:" << data << "가 삽입되었습니다." << std::endl;
	}
		}
	else
		std::cout << "데이터가 가득 찼습니다." << std::endl;
}
void list::print() {
	for (node* temp=head; temp!=NULL; temp=temp->next) {
		std::cout << temp->data << ' ';
	}
}
int main() {
	list t(5);
	t.push(1);
	t.push(2);
	t.push(3);
	t.push(4);
	t.push(4);
	t.print();


}
